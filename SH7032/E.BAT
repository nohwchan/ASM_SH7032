ECHO OFF
del c:\sh\apy\*.zip
del *.lst
pkzip apy.zip
move apy.zip c:\sh\apy\zip
