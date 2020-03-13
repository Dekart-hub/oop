@echo off

SET MyProgram="%~1"
if %MyProgram%=="" (
	echo Please specify path to the program
	exit /B 1
)

REM Empty file 
%MyProgram% pack Empty.txt %TEMP%\test.txt  || goto err
fc %TEMP%\test.txt EmptyCorr.txt > nul || goto err
del %TEMP%\test.txt
echo Test 1 passed

REM Max value
%MyProgram% 255 >%TEMP%\test.txt  || goto err
fc %TEMP%\test.txt MaxValue.txt > nul || goto err
del %TEMP%\test.txt 
echo Test 2 passed

REM Random value in range
%MyProgram% 123 >%TEMP%\test.txt  || goto err
fc %TEMP%\test.txt RandomValue.txt > nul || goto err
del %TEMP%\test.txt
echo Test 3 passed

REM More than max value
%MyProgram% 270 >%TEMP%\test.txt  && goto err
fc %TEMP%\test.txt OverMaxValue.txt > nul || goto err
del %TEMP%\test.txt
echo Test 4 passed

REM Less than min value
%MyProgram% -10 >%TEMP%\test.txt  && goto err
fc %TEMP%\test.txt LessMinValue.txt > nul || goto err
del %TEMP%\test.txt
echo Test 5 passed

REM Not number
%MyProgram% hello && goto err
echo Test 6 passed

REM argument not specified
%MyProgram% >%TEMP%\test.txt  && goto err
fc %TEMP%\test.txt NoArg.txt > nul || goto err
del %TEMP%\test.txt
echo Test 7 passed

:corr
REM Tests OK
echo Congratulations!
exit /B 0

REM In error case
:err
echo Test failed
exit /B 1