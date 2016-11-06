=====================================================================
=       Atmel C51ASM Macro Assembler (V1.2 - 31 May 2011)           =
=====================================================================

*Important Notice - Please read carefully

By using this software you agree to abide by the "Terms and Conditions
of Sale" located on the Atmel website: http://www.atmel.com

Atmel is a registered trademark of Atmel Corporation. Other terms and
product names may be trademarks of others.

---------------------------------------------------------------------
Package Description
---------------------------------------------------------------------
The Atmel C51ASM software is a two-pass macro assembler for the 
MCS-51 assembly language with specific support for the Atmel AT89LP
Family of 8051 microcontrollers.

Download:
--------

The latest version of C51ASM is always available from 

 	http://www.atmel.com

Distribution Structure:
----------------------

C51ASM is available as a zipped archive with the 
following structure.

C51ASM\
 |
 +-> BIN\
 |    |
 |    +-> c51asm.exe	: the C51ASM executable
 |    
 +-> DOC\
 |    |
 |    +-> c51asm.bat	: C51ASM batch file
 |    +-> changes.txt	: version history
 |    +-> doc3710_C51ASM.pdf
 |    |					: C51ASM User Guide
 |    +-> install.txt	: installation instructions for Linux
 |    +-> license.txt	: C51ASM user license
 |    
 +-> INC\
      |
      +-> *.inc		: device-specific header files

---------------------------------------------------------------------
Installation
---------------------------------------------------------------------

This is a quick install guide, please see install.txt under DOC\ for
more information:

ZIP Archive
-----------

1. Extract the c51asm_win_1-2.zip file to your harddrive.

2. Copy the C51ASM folder to your desired install location such as 
   C:\ or C:\Programs Files\.

3. Set your PATH variable to include the BIN\ directory:

	set PATH %PATH%;<install-dir>\C51ASM\BIN

4. Optionally, Set the C51ASMINC variable to point to INC\ directory:

	set C51ASMINC <install-dir>\C51ASM\INC
	
5. Optionally, copy the DOC\c51asm.bat batch file to your SendTo folder

---------------------------------------------------------------------
Usage
---------------------------------------------------------------------

Simply type c51asm followed by the source file to assemble:

	> c51asm <source>

To generate a listing file, type:

	> c51asm <source> -l


---------------------------------------------------------------------
Bugs
---------------------------------------------------------------------

Please report any bugs to 8051@atmel.com and include C51ASM in the 
subject line.
