@echo off
color f0
title AvrDude GUI Command Window
@echo.
@echo. trying to connect to device...
avrdude -p ATMEGA8 -c avrisp -P COM9  -U lock:r:"D:\innovation\Pumping Solution\Atmel\Atmega8\Development Board from Explore\win32_executable\lock_bits.raw":r
avrdudeGUI.exe -done
pause