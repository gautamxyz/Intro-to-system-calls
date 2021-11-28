# Assumptions made

1. Number of characters in input files for q1 and q2 can stored in long long int and won't exceed the max value that can be stored in long long int data type.
2. In q3 it is assumed that the "Assignment" directory will be present in the same directory as q3.c. The input file may/may not be present in the same directory as  q3.c
3. In q3 if the diretory "Assignment" is not found, then a single line message displaying "Directory is created: No" will be displayed on terminal and program will terminate.
4. In if "Assignment" is present but any/both of the output files are not present in it then a message saying that that output file is not presented will be printed on terminal and permissions of those file(s) won't be checked (obviously!).
5. Reversing large files of around 1gb took different times. Sometimes it took 18s and sometimes only 5s.(no assumption here, just stating)
6. While the codes in q1, q2 would work for file sizes like 0.5 gb, 1 gb, 2gb etc but it may be problematic to run them on very big file sizes like 20 gb.
7. It is assumed that string length of input file won't exceed 85 characters.
8. In q1 and q2 if the input files given as arguments don't exist then error will be printed on the terminal and program will terminate.