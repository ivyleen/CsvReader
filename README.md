Task:

Write a command-line application that loads a CSV file containing a first line with string column names, followed by the same number of
columns of positive integers. The application should take one argument which is the path to the file, then subsequently take a single character command that will perform one of the
following actions:
'p': print the contents of all columns
'+': print the sum of all columns
'm': print the maximum of all columns
'a': add each row together and print a single column containing the result.

To build:
g++ --std=c++17 main.cpp -o csvReader

To display available options:
./csvReader text.txt h


Example output:

$ ./csvReader text.txt h
You've asked for help. Available options are:
'p': print the contents of all columns
'+': print the sum of all columns
'm' : print the maximum of all columns
'a' : add each row together and print a single column containing the result.
'h' : display available options

$ ./csvReader text.txt p
Option 'p': print the contents of all columns.
Column1      Column2      Column3

    7           3           1
    4           3           8
    9           4           1
    1           1           1

$ ./csvReader text.txt +
Option '+': print the sum of all columns.
Column1      Column2      Column3

   21          11          11

$ ./csvReader text.txt m
Option 'm': print the maximum of all columns.
Column1      Column2      Column3

    9           4           8

$ ./csvReader text.txt a
Option 'a': add each row together and print a single column containing the result.
Sum of each row

     11
     15
     14
      3
