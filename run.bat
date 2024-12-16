@echo off
rem Create directories build/executable and build/object_files if they do not exist
if not exist build\object-files mkdir build\object-files

rem Compile the .c source files to .o object files
gcc -c src\main.c -o build\object-files\main.o
gcc -c src\temperature.c -o build\object-files\temperature.o
gcc -c src\generate-structure.c -o build\object-files\generate-structure.o
gcc -c src\io.c -o build\object-files\io.o
gcc -c src\set-temperature.c -o build\object-files\set-temperature.o
gcc -c src\get-temperature.c -o build\object-files\get-temperature.o
gcc -c src\converting.c -o build\object-files\converting.o

rem Link object files into an executable
gcc build\object-files\main.o build\object-files\temperature.o build\object-files\generate-structure.o build\object-files\io.o build\object-files\set-temperature.o build\object-files\get-temperature.o build\object-files\converting.o -o program.exe

rem End of script
