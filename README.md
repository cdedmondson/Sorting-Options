# Sorting-Options

This program reads in data from a file given by the user and writes output to a separate file also
specified by the user. The program then reads in the information from the file, line by line, and
creates a vector with the given integer values.

The program then prompts the user about which sorting algorithm they would like to use in order to
sort the vector. The four sorting algorithms implemented are: selection sort, merge sort, quick sort,
and insertion sort. Once a sorting algorithm is selected, the program displays step by step every
change that the sorting algorithm does on its journey to completely sorting the integer
values of the vector.  The output file should then contain the sorted values of the vector with a
single integer on each line.

For example:

Sorting Options:
----------------------------------------------
[+] Enter file for input: input.txt
[+] Enter file for output: output.txt
[?] What sorting algorithm would you like to use? 
    1.  Selection Sort
    2.  Merge Sort
    3.  Quick Sort
    4.  Insertion Sort
(Enter an integer value for your selection): 4

Original Vector:[14, 7, 3, 12, 9, 11, 6, 2]

Vector is now being sorted:

[14, 14, 3, 12, 9, 11, 6, 2]
[7, 14, 14, 12, 9, 11, 6, 2]
[7, 7, 14, 12, 9, 11, 6, 2]
[3, 7, 14, 14, 9, 11, 6, 2]
[3, 7, 12, 14, 14, 11, 6, 2]
[3, 7, 12, 12, 14, 11, 6, 2]
[3, 7, 9, 12, 14, 14, 6, 2]
[3, 7, 9, 12, 12, 14, 6, 2]
[3, 7, 9, 11, 12, 14, 14, 2]
[3, 7, 9, 11, 12, 12, 14, 2]
[3, 7, 9, 11, 11, 12, 14, 2]
[3, 7, 9, 9, 11, 12, 14, 2]
[3, 7, 7, 9, 11, 12, 14, 2]
[3, 6, 7, 9, 11, 12, 14, 14]
[3, 6, 7, 9, 11, 12, 12, 14]
[3, 6, 7, 9, 11, 11, 12, 14]
[3, 6, 7, 9, 9, 11, 12, 14]
[3, 6, 7, 7, 9, 11, 12, 14]
[3, 6, 6, 7, 9, 11, 12, 14]
[3, 3, 6, 7, 9, 11, 12, 14]
[2, 3, 6, 7, 9, 11, 12, 14]

Vector is now sorted!
