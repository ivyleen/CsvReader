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

$ g++ --std=c++17 main.cpp -o csvReader

$ ./csvReader text.txt m

Option 'm': print_t the maximum of all columns.

Column1      Column2      Column3
    9           4           8
