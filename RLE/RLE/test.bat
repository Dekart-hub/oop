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

REM pack 255 symbols
%MyProgram% pack 255Symb.txt %TEMP%\test.txt  || goto err
fc %TEMP%\test.txt 255SymbCorr.txt > nul || goto err
del %TEMP%\test.txt
echo Test 2 passed

REM pack 256 symbols
%MyProgram% pack 256Symb.txt %TEMP%\test.txt  || goto err
fc %TEMP%\test.txt 256SymbCorr.txt > nul || goto err
del %TEMP%\test.txt
echo Test 3 passed

REM pack 257 symbols
%MyProgram% pack 257Symb.txt %TEMP%\test.txt  || goto err
fc %TEMP%\test.txt 257SymbCorr.txt > nul || goto err
del %TEMP%\test.txt
echo Test 4 passed

REM 255 symbols unpack
%MyProgram% unpack 255SymbCorr.txt %TEMP%\test.txt  || goto err
fc %TEMP%\test.txt 255Symb.txt > nul || goto err
del %TEMP%\test.txt
echo Test 5 passed

REM 256 symbols unpack
%MyProgram% unpack 256SymbCorr.txt %TEMP%\test.txt  || goto err
fc %TEMP%\test.txt 256Symb.txt > nul || goto err
del %TEMP%\test.txt
echo Test 6 passed

REM 255 symbols unpack
%MyProgram% unpack 257SymbCorr.txt %TEMP%\test.txt  || goto err
fc %TEMP%\test.txt 257Symb.txt > nul || goto err
del %TEMP%\test.txt
echo Test 7 passed

REM incorrect arguments count
%MyProgram% %TEMP%\test.txt  && goto err
fc %TEMP%\test.txt NoArg.txt > nul || goto err
del %TEMP%\test.txt
echo Test 8 passed

REM incorrect arguments count
%MyProgram% unpack EvenPacked.txt %TEMP%\test.txt  || goto err
del %TEMP%\test.txt
echo Test 9 passed

:corr
REM Tests OK
echo Congratulations!
exit /B 0

REM In error case
:err
echo Test failed
exit /B 1