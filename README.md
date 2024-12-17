Handing program.

Two Modes of Handling Program:
First:
./program.exe [mode] [min] [max] [x] [y]
mode = 0 | 0 - to generate new mesh [int]
min - from (which) temperature [double]
max - to (which) temperature [double]
x,y - size of mesh [int]

Second:
./program.exe [mode] [feature]
mode = 1 | 1 - to getting temperatures from file
[feature]:
SETTER:
1 - change one element [x] [y] [new_value]
2 - change row [no_row] [second_no_row]
3 - change column [no_column] [second_no_column]
GETTER:
4 - get minimum temperature
5 - get maximum temperature
6 - get average of temperatures [unit = C | F | K]
