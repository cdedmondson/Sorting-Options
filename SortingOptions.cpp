/*******************************************************************
*
*   File: SortingOptions.cpp
*   Author: Cameron Edmondson
*   Class: CS 2560–C++
*   Assignment: program 3
*   Date last modified: 09/27/2019
*
*   This program reads in data from a file given by the user and writes output to a separate file also
*   specified by the user. The program then reads in the information from the file, line by line, and
*   creates a vector with the given integer values.
*
*   The program then prompts the user about which sorting algorithm they would like to use in order to
*   sort the vector. The four sorting algorithms implemented are: selection sort, merge sort, quick sort,
*   and insertion sort. Once a sorting algorithm is selected, the program displays step by step every
*   change that the sorting algorithm does on its journey to completely sorting the integer
*   values of the vector.  The output file should then contain the sorted values of the vector with a
*   single integer on each line.
*
* *****************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

bool doesFileExist(const string &);

void writeDataToFile(vector<int> &, int);

void printVector(vector<int> &a, int);

void printRecursive(vector<int> &, int, int);

void sortingOption(vector<int> &, int, int);

void selectionSort(vector<int> &, int);

void merge(vector<int> &, int, int, int);

void mergeSort(vector<int> &, int, int);

int partition(vector<int> &, int, int);

void quickSort(vector<int> &, int, int);

int insertionSort(vector<int> &, int);

void userInput();

void readDataFromFile(string, string, int);

string outputFileName;    // Create space to hold output file name
vector<int> solutionVector; // Stored sorted vector


//####################################### Does File Exist Function Begin##########################################
/*
 * Function: doesFileExist
 * Purpose: Takes file name as parameter and returns
 * true if the file exists else it returns false.
 */
bool doesFileExist(const string &FILENAME) {
    ifstream file(FILENAME.c_str());
    return file.good();
}
//#########################################Does File Exist Function End##########################################

//#########################################Write Data To File Function Begin#####################################
/*
 * Function: writeDataToFile
 * Purpose: Write sorted vector to solution to file specified by user
 */
void writeDataToFile(vector<int> &vector, int n) {

    ofstream outputFileStream;    // Create output file stream
    outputFileStream.open(outputFileName);  // Open output file for writing
    for (int i = 0; i < n; i++) {
        outputFileStream << vector[i] << "\n";
    }
    outputFileStream.close();
}
//#########################################Write Data To File Function End#######################################

//#########################################Print Vector Function Begin###########################################
/*
 * Function: printVector
 * Purpose: Utility function for
 * printing vector with brackets.
 */
void printVector(vector<int> &a, int n) {
    printf("\n[");
    for (int i = 0; i < n; i++)
        if (i != n - 1) {
            printf("%d, ", a[i]);
        } else
            printf("%d", a[i]);
    printf("]");
}
//#########################################Merge Function End####################################################

//#########################################Print Recursive Function Begin########################################
/*
 * Function: printRecursive
 * Purpose: Print and format sub-vectors of recursive algorithms
 */
void printRecursive(vector<int> &vector, int start, int end) {

    printf("\n[");
    for (int i = start; i < end; i++)
        if (i != end - 1) {
            printf("%d, ", vector[i]);
        } else
            printf("%d", vector[i]);
    printf("]");

}
//#########################################Print Recursive Function End##########################################

//#########################################Sorting Option Function Begin#########################################
/*
 * Function: sortingOption
 * Purpose: Simple utility function that calls the appropriate sorting algorithm
 * (1. Selection Sort 2. Merge Sort 3. Quick Sort 4. Insertion Sort) based on
 * users selection.
 */
void sortingOption(vector<int> &vector, int selection, int vectorSize) {

    switch (selection) {
        case 1:
            selectionSort(vector, vectorSize);
            break;
        case 2:
            mergeSort(vector, 0, vectorSize - 1);
            break;
        case 3:
            quickSort(vector, 0, vectorSize - 1);
            break;
        case 4:
            insertionSort(vector, vectorSize);
            break;
    }

}
//#########################################Sorting Option Function End##########################################

//#########################################Selection Sort Function Begin########################################
/*
 * Function: selectionSort
 * Purpose:  Performs selection sort on data passed by reference
 * and prints each step to console.
 */
void selectionSort(vector<int> &vector, int vectorSize) {

    int min;
    int temp;

    for (int i = 0; i < vectorSize - 1; i++) {
        min = i;

        printVector(vector, vectorSize);

        for (int j = i + 1; j < vectorSize; j++) {
            if (vector[j] < vector[min]) {
                min = j;
            }
            temp = vector[i];
            vector[i] = vector[min];
            vector[min] = temp;

            printVector(vector, vectorSize);
        }
    }

    solutionVector = vector;

}
//#########################################Selection Sort Function End#########################################

//#########################################Merge Function Begin################################################
/*
 * Function: merge
 * Purpose:  Merges left and right sub vectors to vector.
 */
void merge(vector<int> &vector, int start, int endV, int midPoint) {

    int low, mid, index;
    low = start;
    mid = midPoint + 1;
    index = 0;
    int tempVector[endV - start + 1];

    while (low <= midPoint && mid <= endV) {
        if (vector[low] < vector[mid]) {
            tempVector[index++] = vector[low++];
        } else {
            tempVector[index++] = vector[mid++];
        }
    }

    for (int i = low; i <= midPoint; i++) {
        tempVector[index++] = vector[low++];
    }

    for (int j = mid; j <= endV; j++) {
        tempVector[index++] = vector[mid++];
    }

    for (low = start; low <= endV; low++) {
        vector[low] = tempVector[low - start];
    }

} // End Merge function
//#########################################Merge Function End################################################

//#####################################Mergesort Begin#######################################################
/*
 * Function: mergeSort
 * Purpose:  Break unsorted vector into left and right sub-vectors
 */
void mergeSort(vector<int> &vector, int low, int high) {

    //  If there exists only one element vector is already sorted
    if (low < high) {

        // Find the midPoint of vector
        int midPoint = (low + high) / 2;

        // Perform Merge sort on the left side of sub-vector recursively
        mergeSort(vector, low, midPoint);
        // Perform Merge sort on the right side of sub-vector recursively
        mergeSort(vector, midPoint + 1, high);
        //  Merge the left and right sub-vectors
        merge(vector, low, high, midPoint);

    }

    solutionVector = vector;

}  // End Merge sort function
//#####################################Mergesort End#####################################################

//#####################################Partition Begin###################################################
/*
 * Function: partition
 * Purpose:  Partitions and sorts each sub-vector
 */
int partition(vector<int> &vector, int start, int end) {

    // Set pivot to last element in vector
    int pivot = vector[end];

    // Start partition index at index 0
    int partitionIndex = start;

    printRecursive(vector, start, end);

    // Declare temporary variables for swapping values
    int swapVector_i, swapPartitionIndex;

    /*
     * Start at index vector[i] and compare each element to pivot.
     * If element at index "i" is less than or equal to pivot,
     * swap the partition index and vector[i] index values.
     */
    for (int i = start; i < end; i++) {
        if (vector[i] <= pivot) {
            swapVector_i = vector[i];
            swapPartitionIndex = vector[partitionIndex];
            vector[i] = swapPartitionIndex;
            vector[partitionIndex] = swapVector_i;
            partitionIndex++;
        }
    }

    // After vector is sorted swap end of vector "pivot" with partition index
    swapVector_i = vector[partitionIndex];
    swapPartitionIndex = vector[end];
    vector[end] = swapVector_i;
    vector[partitionIndex] = swapPartitionIndex;

    return partitionIndex;
} // End Partition function
//#####################################Partition End########################################################

//#####################################QuickSort Begin######################################################
/*
 * Function: quickSort
 * Purpose:  Recursively chop unsorted vector into halves
 */
void quickSort(vector<int> &vector, int start, int end) {

    // If there exists more than one element in the vector divide and conquer
    if (start < end) {

        int partitionIndex = partition(vector, start, end);
        quickSort(vector, start, partitionIndex - 1);
        quickSort(vector, partitionIndex + 1, end);
        printRecursive(vector, start, end);
    }

    solutionVector = vector;

} // End QuickSort function
//#####################################QuickSort End#######################################################

//#####################################Insertionsort Begin#################################################
/*
 * Function: insertionSort
 * Purpose: Sort unordered vector
 */
int insertionSort(vector<int> &vector, int vectorSize) {

    for (int i = 1; i < vectorSize; i++) {

        // Assume first element is the smallest value
        int smallestValue = vector[i];

        int counter = i - 1;

        /*
         * While counter is greater than zero and the element to
         * the left of the next value is greater swap positions
         */
        while (counter >= 0 && vector[counter] > smallestValue) {
            vector[counter + 1] = vector[counter];
            counter = counter - 1;
            printVector(vector, vectorSize);
        } // End while loop

        vector[counter + 1] = smallestValue;  // Assign smallest value to index 0

    } // End for loop

    printVector(vector, vectorSize);

    solutionVector = vector;

} // End insertion sort function
//#####################################Insertionsort End#####################################################

//###########################################User Input Function Begin#######################################
/*
 * Function: userInput
 * Purpose: Prompts user for an input and output name
 */
void userInput() {

    //**************** Variable Declaration Begin **************************
    string inputFileName;    // Create space in memory to hold input file name
    int selection;
    //**************** Variable Declaration End **************************

    //**************** Prompt User Begin **************************
    cout << "\n\nSorting Options:";
    cout << "\n----------------------------------------------\n";

    cout << "[+] Enter file for input: "; // Prompt user for file path
    getline(cin, inputFileName);    // Read file as vector string from user

    cout << "[+] Enter file for output: ";
    getline(cin, outputFileName);

    cout << "[?] What sorting algorithm would you like to use? " << endl;
    cout << "    1.  Selection Sort" << endl;
    cout << "    2.  Merge Sort" << endl;
    cout << "    3.  Quick Sort" << endl;
    cout << "    4.  Insertion Sort" << endl;
    cout << "(Enter an integer value for your selection): ";
    cin >> selection;
    //**************** Prompt User End ***************************

    do {
        // If input file does not exist print warning
        // Else file does exist set valid path equal to true
        if (!doesFileExist(inputFileName)) {
            cout << "\n----------------------------------------------";
            cout << "\n[!] Unable to open file " + inputFileName;
            cout << "\n[!] Please provide vector valid input file: "; // Prompt user for file name
            cin >> inputFileName;    // Read file as vector string from user
        } else {
            readDataFromFile(inputFileName, outputFileName, selection);
        }
    } while (!doesFileExist(inputFileName));

}
//###########################################User Input Function End#########################################

//######################################Read Data From File Function Begin###################################
/*
 * Function: readDataFromFile
 * Purpose: Takes and input file name and output file name as parameters
 * and reads each line of input file checks if it's vector palindrome then
 * writes out put to output file.
 */
void readDataFromFile(string inputFileName, string outputFileName, int selection) {

    //**************** Variable Declaration Begin **************************
    ifstream inputFileStream;    // Create input file stream
    ofstream outputFileStream;    // Create output file stream
    string line;    // Hold each line read from file
    vector<int> data;
    //**************** Variable Declaration End **************************

    inputFileStream.open(inputFileName);    // Open input file for reading
    outputFileStream.open(outputFileName.c_str());  // Create output file for writing

    while (getline(inputFileStream, line)) {
        data.push_back(stoi(line));
    }

    cout << "\nOriginal Vector:";
    printf("[");
    for (int i = 0; i < data.size(); i++)
        if (i != data.size() - 1) {
            printf("%d, ", data[i]);
        } else
            printf("%d", data[i]);
    printf("]");

    cout << "\n\nVector is now being sorted:\n";

    sortingOption(data, selection, data.size());

    // Close file streams
    inputFileStream.close();
    outputFileStream.close();

}
//###################################### Read Data From File Function End ####################################

int main() {

    userInput();

    writeDataToFile(solutionVector, solutionVector.size());

    cout << "\n\nVector is now sorted!";

    return 0;
}