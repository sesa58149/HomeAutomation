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
	PD5 & PD6
	PD5 low level
	PD6 High level
*/
/*
	Level LED Pin @ PC
	PC6-- High 
	PC5- Low
*/
/* Out put Pins @ PC

PC0-- Motor relay Input
PC1-- Motor Status indicator ON/OFF
*/


typedef unsigned char DEF_BOOL ;
#define DEF_TRUE	1
#define DEF_FALSE	0
#define ERR_CODE_LEVEL_INDICATOR_FAIL	0X10
#define NO_ERROR						0x00

#define INPUT_LINE	0x7F // Port D input port
#define OUTPUT_LINE 0xF0 // Port C output port (PC5-- errstatus PC6-- RST pin)

#define LED_ERROR_CODE_FLUSH_RATE_OTH_MS		500
#define LED_ERROR_CODE_FLUSH_RATE_SUMP_MS	1000
#define LED_NO_ERROR_FLUSH_RATE_MS			2000
// PORT-C  OUTPUT
#define LED_PIN				4
#define OTH_MOTOR			0
#define OTH_MOTOR_STATUS	1

#define OTH_INPUT_START_PIN	5
#define OTH_INPUT_LED_STATUS_PIN_START	4
#define OTH_INPUT_LED_STATUS_PIN0	4
#define OTH_INPUT_LED_STATUS_PIN1	5
#define OTH_LOW_LEVEL	5
#define OTH_HIGH_LEVEL	6
	

#define LED_OFF() (PORTC|=(1<<5))
#define LED_ON() (PORTC&=~(1<<5))

#define OTH_STATUS_OFF() (PORTC|=(1<<OTH_MOTOR_STATUS))
#define OTH_STATUS_ON() (PORTC&=~(1<<OTH_MOTOR_STATUS))

#define OTH_MOTOR_ON() (PORTC|=(1<<OTH_MOTOR))
#define OTH_MOTOR_OFF() (PORTC&=~(1<<OTH_MOTOR))

static unsigned char err_code = NO_ERROR;

void changeInputLedStatus(unsigned char led_input)
{
	
	switch(led_input)
	{
		case 0x00: // OFF BOTH LED
		PORTC|=(1<<OTH_INPUT_LED_STATUS_PIN0);
		PORTC|=(1<<OTH_INPUT_LED_STATUS_PIN1);
		break;
		case 0x01: // ON LOW &OFF HIGH
		PORTC|=(1<<OTH_INPUT_LED_STATUS_PIN0);
		PORTC&=~(1<<OTH_INPUT_LED_STATUS_PIN1);
		break;
		case 0x02: // OFF LOW & ON HIGH -- WILL NEVER HAPPEN --ERROR CASE
		PORTC&=~(1<<OTH_INPUT_LED_STATUS_PIN0);
		PORTC|=(1<<OTH_INPUT_LED_STATUS_PIN1);
		break;
		case 0x03:// ON BOTH LED
		PORTC&=~(1<<OTH_INPUT_LED_STATUS_PIN0);
		PORTC&=~(1<<OTH_INPUT_LED_STATUS_PIN1);
		break;
	}
}
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
/*
Oth motor	- PC0
Oth LED		- PC1

PC5--- oth Low level
PC6 ----oth High Level
*/
static unsigned char last_input =0x00;

int main(void)
{
	unsigned char input_data;
	unsigned char oth_in=0;
	unsigned short led_flush_rate = LED_NO_ERROR_FLUSH_RATE_MS;
	
	/* OUTPUT PINS*/
	DDRC |= ( (1<< OTH_MOTOR)|(1<<OTH_MOTOR_STATUS) |(1<<OTH_INPUT_LED_STATUS_PIN0)|(1<<OTH_INPUT_LED_STATUS_PIN1)   );
	
	/* INPUT PINS*/
	DDRD &= ~( (1<<OTH_LOW_LEVEL) | (1<<OTH_HIGH_LEVEL)  );
	
	/* Set the pul-up register for input port*/
	PORTD=INPUT_LINE;
		
	/* Configure default motor as off */
	OTH_MOTOR_OFF();
	OTH_STATUS_OFF();
	changeInputLedStatus(oth_in); // Level LED to default value
	
	while(1)
	{
		
		//LED_ON();
		
		input_data = (PIND & INPUT_LINE);
		
		oth_in = (input_data & ( (1<<OTH_LOW_LEVEL) | (1<<OTH_HIGH_LEVEL) ) );
		oth_in >>= OTH_INPUT_START_PIN; // BRING input pins @ Pin1Pin0 position		
		switch(oth_in)
		{
			case TANK_STATUS_EMPTY: // tank Empty
			{
				/*
					switch on motor 
					switch on motor status
				*/
				
				OTH_MOTOR_ON();
				OTH_STATUS_ON();							
				
				err_code = NO_ERROR;
				led_flush_rate = LED_NO_ERROR_FLUSH_RATE_MS;
				
			}
			break;
			
			case TANK_STATUS_LOW_LEVEL: //    high -- no water & Low -- Water
			err_code = NO_ERROR;
			break;
			
			case TANK_STATUS_ERR_LEVEL: // high== water  & Low --No Water  
			err_code = ERR_CODE_LEVEL_INDICATOR_FAIL;
			led_flush_rate = LED_ERROR_CODE_FLUSH_RATE_OTH_MS;
			
			break;
			
			case TANK_STATUS_FULL: // tank Full
			{				
				/*
					switch off motor 
					switch off motor status
				*/	
							
				OTH_MOTOR_OFF();
				OTH_STATUS_OFF();
								
				err_code = NO_ERROR;
				led_flush_rate = LED_NO_ERROR_FLUSH_RATE_MS;
				
			}
			
		}
		/* change the input Led status only if the value are change in last values */
		
		if(last_input != oth_in)
		{
			changeInputLedStatus(oth_in);
			last_input = oth_in;
		}	
		app_delay_ms(led_flush_rate);
		
		//LED_OFF();
		
		app_delay_ms(led_flush_rate);
	}
}