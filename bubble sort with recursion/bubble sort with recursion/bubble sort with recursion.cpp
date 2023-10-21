// bubble sort with recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <chrono>
#include <cstdlib>
//#include <bits/stdc++.h>??



using namespace std;

// Swap two elements in an array
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Recursive Bubble Sort function
void bubbleSort(int arr[], int n, int pass) {
    // Base case: If no swaps are made, the array is already sorted
    if (pass >= n - 1) {
        return;
    }

    bool swapped = false;

    // Perform a single pass of Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
            swapped = true;
        }
    }

    // If no elements were swapped in this pass, the array is sorted.
    if (!swapped) {
        return;
    }

    // Recursively call the function for the next pass
    bubbleSort(arr, n, pass + 1);
}


// Function to print an array

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << " " << arr[i];
}

// function to measure the execution time of selection sort in milliseconds
long long measureselectionsorttimeinmilliseconds(int arr[], int n)
{
    auto start_time = std::chrono::high_resolution_clock::now();

    //call bubblesort function
    bubbleSort(arr, n, 0);

    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    return duration.count();
}

// Driver program
int main()
{
    const int sizes[] = { 10, 100, 1000, 10000 };

    for (int i = 0; i < 4; i++) {
        int n = sizes[i];
        int* arr = new int[n];

        //Initialize the array with random values
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 10000; // Random values between 0 and 9999
        }


        // Measure the time taken by Selection Sort in milliseconds
        long long time_taken = measureselectionsorttimeinmilliseconds(arr, n);

        cout << "Time taken by Bubble Sort for " << n << " elements: " << time_taken << " milliseconds" << std::endl;


        // Print all the numbers in correct order
        printArray(arr, n);

    }
    return 0;
}