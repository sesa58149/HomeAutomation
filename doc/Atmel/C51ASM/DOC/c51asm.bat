@echo off

rem use these three lines to pop up a shell and display results
cd %~sp1
c51asm %1
pause

rem use these three lines to close the shell immediately and leave the results in a log file
rem cd %~sp1
rem c51asm %1  >> c51asm.log
rem cls