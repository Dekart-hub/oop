@echo off

SET MyProgram="%~1"
if %MyProgram%=="" (
	echo Please specify path to the program
	exit /B 1
)

REM Copy empty file
%MyProgram% Empty.txt "%TEMP%\output.txt" || goto err
fc Empty.txt "%TEMP%\output.txt" > nul || goto err
echo Test 1 passed

REM Copy not empty file
%MyProgram% NotEmpty.txt "%TEMP%\output.txt" || goto err
fc NotEmpty.txt "%TEMP%\output.txt" > nul || goto err
echo Test 2 passed

REM Copy missing file
%MyProgram% MissingFile.txt "%TEMP%\output.txt" && goto err
echo Test 3 passed

REM If output file isn`t specified
%MyProgram% MissingFile.txt && goto err
echo Test 4 passed

REM If input and output files aren`t specified
%MyProgram% && goto err
echo Test 5 passed


REM Tests OK
exit /B 0

REM In error case
:err
echo Test failed
exit /B 1