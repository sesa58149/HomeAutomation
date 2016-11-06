/*
 * ControllerMainApp.c
 *
 * Created: 1/30/2016 5:02:07 PM
 *  Author: SESA58149
 */ 


/*
 * Deoghar_Motor_Controller.c
 *
 * Created: 12/6/2015 3:11:50 PM
 *  Author: Pawan Modi
 */ 

/* Application Without external clock and use only for max 1Mhz*/
#define F_CPU 1000000UL // clock speed

#include <avr/io.h>
#include <util/delay.h>


/*  In Put pins
	PD5,PD6 and PD7
	PD5 low level
	PD6 High level
*/
/*
	Level LED Pin @ PC
	PC6-- High 
	PC5- Low
*/
/* Out put Pins @ PC

PC0-- Motor1
PC1-- Motor2
*/
/*
input pins

PC2	->LOW LEVEL
PC3 ->MIDDLE LEVEL
PC4 ->HIGH LEVEL
*/

typedef unsigned char DEF_BOOL ;
#define DEF_TRUE	1
#define DEF_FALSE	0
#define ERR_CODE_LEVEL_INDICATOR_FAIL	0X10
#define NO_ERROR						0x00

#define INPUT_LINE	0xF0 // Port D input port
#define OUTPUT_LINE 0x70 // Port C output port (PC5-- err status PC6-- RST pin)

#define LED_ERROR_CODE_FLUSH_RATE_OTH_MS		500
#define LED_ERROR_CODE_FLUSH_RATE_SUMP_MS	1000
#define LED_NO_ERROR_FLUSH_RATE_MS			2000
// PORT-C  OUTPUT
#define MODULE_STATUS_PIN	5
#define CNTRL_MOTOR0		0
#define CNTRL_MOTOR1		1

#define INPUT_START_PIN		2

#define INPUT_LED_STATUS_PIN0	2
#define INPUT_LED_STATUS_PIN1	3
#define INPUT_LED_STATUS_PIN2	4

#define INPUT_PIN_LOW_LEVEL		5
#define INPUT_PIN_MIDDLE_LEVEL	6
#define INPUT_PIN_HIGH_LEVEL	7
	

#define LED_OFF() (PORTC|=(1<<5))
#define LED_ON() (PORTC&=~(1<<5))

#define CNTRL_MOTOR1_ON() (PORTC|=(1<<CNTRL_MOTOR1))
#define CNTRL_MOTOR1_OFF() (PORTC&=~(1<<CNTRL_MOTOR1))

#define CNTRL_MOTOR0_ON() (PORTC|=(1<<CNTRL_MOTOR0))
#define CNTRL_MOTOR0_OFF() (PORTC&=~(1<<CNTRL_MOTOR0))
#define INPUT_LED_STATUS_PIN_MASK	0xE3//0b11100011
#define INPUT_PIN_MASK				0xE0 //0b1110 0000 pd7,6,5


#define LED_STATUS_OFF() (PORTC|=( (1<<INPUT_LED_STATUS_PIN0)|(1<<INPUT_LED_STATUS_PIN1)|(1<<INPUT_LED_STATUS_PIN2)) )
static unsigned char TimerTriggerd=0;
static unsigned long timeOutInSec;
static unsigned char last_input = 0;

void timerHandler(void);

/* delay in ms of 100 multiple*/
void app_delay_ms(unsigned short delay)
{
	do
	{
		_delay_ms(100);
		delay-=100;
	}while(delay >100);
	
}

enum{
	TANK_STATUS_EMPTY,
	TANK_STATUS_LOW_LEVEL,
	TANK_STATUS_ERR_LEVEL,
	TANK_STATUS_FULL
}TANK_STATUS;


void changeInputLedStatus(unsigned char led_input)
{
	
	unsigned char val = (PORTC & INPUT_LED_STATUS_PIN_MASK);
	led_input = 0x1C; // off all input led default 0b0001 1100
	PORTC = (val|led_input);
}


void handleInputPins(unsigned char led_input)
{
	static unsigned char firstTime = 1;	
	unsigned char SensorIn;
	unsigned char val = (PORTC & INPUT_LED_STATUS_PIN_MASK);
	led_input &= INPUT_PIN_MASK; // PD5,PD6,PD7  yyy0 0000
	led_input >>=0x03; // shift till PC2
	if( (led_input != last_input)||(firstTime ==1) )
	{
		firstTime = 0;	
		last_input = led_input;	
		PORTC = (val |led_input);
		SensorIn= led_input>> 0x02; // move to PC0
		SensorIn &= 0x03; //only 2 input PD5&PD6 
		
		if(SensorIn == 0x00) // no water--- input high->close ckt-- current flow--VCE--0v-- PDxyz->low (HighLevel=0 LowLevel=0 )
		{
			CNTRL_MOTOR1_ON();
			app_delay_ms(500);
			CNTRL_MOTOR0_ON();
			app_delay_ms(2000);
			CNTRL_MOTOR0_OFF();			
			//TimerTriggerd=1;
		}
		
		else if(SensorIn == 0x03) // full water--- input low->open ckt-- current blocked --VCE--5v-- PDxyz->high (HighLevel=1 LowLevel=1 )
		{
			CNTRL_MOTOR1_OFF();
			app_delay_ms(500);
			CNTRL_MOTOR0_OFF();
		}
		
	}	
}

void setTimoutforShutOffMotor( unsigned long timeout_minutes)
{
	timeOutInSec= timeout_minutes*60;
}
/*
motor0	- PC0
MOTOR1	- PC1
*/

int main(void)
{
	/* OUTPUT PINS*/
	DDRC |= ( (1<< MODULE_STATUS_PIN)|(1<< CNTRL_MOTOR0)|(1<<CNTRL_MOTOR1) |(1<<INPUT_LED_STATUS_PIN0)|(1<<INPUT_LED_STATUS_PIN1) |(1<< INPUT_LED_STATUS_PIN2)  );
	
	/* INPUT PINS*/
	DDRD &= ~( (1<<INPUT_PIN_LOW_LEVEL) | (1<<INPUT_PIN_MIDDLE_LEVEL) | (1<<INPUT_PIN_HIGH_LEVEL) );
	
	/* Set the pull-up register for input port*/
	PORTD=INPUT_LINE;
		
	/* Configure default motor as off */
	CNTRL_MOTOR0_OFF();
	CNTRL_MOTOR1_OFF();
	LED_STATUS_OFF();
	//setTimoutforShutOffMotor(15); // in Minutes
		
	while(1)
	{
		handleInputPins(PIND);
		app_delay_ms(1000);
		PORTC ^= (1<< MODULE_STATUS_PIN); // led on	
		//if(TimerTriggerd==1)
		//	timerHandler();		
	}
}

void timerHandler(void)
{
	static unsigned char timeCount=0;
	
	timeCount++;
	
	if(timeCount>=timeOutInSec)
	{
		CNTRL_MOTOR1_OFF();
		timeCount=0;
		TimerTriggerd=0;
	}
	
}