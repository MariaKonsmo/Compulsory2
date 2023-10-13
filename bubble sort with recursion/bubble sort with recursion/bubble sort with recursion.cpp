// bubble sort with recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <chrono>
#include <cstdlib>
//#include <bits/stdc++.h>??



using namespace std;
void bubbleSort(int arr[], int n)
{
    //lager swaperne i og j
    int i;
    int j;
    bool swapped;
    //lager to loops. flytter og bytter bortover til høyre, hvis tallet er lavere enn til høyre swapper tallene med swaperne i og j. hvis 
    //høyere swaper ikke og fortsetter til de kommer til slutten der det høyeste tallet er, og så starter de på nytt til alt er sortert
    //i riktig rekkefølge. når alt er sortert breaker loopen og den stopper.
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
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

    //call quicksort function
    bubbleSort(arr, n);

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

        cout << "Time taken by Selection Sort for " << n << " elements: " << time_taken << " milliseconds" << std::endl;


        // Print all the numbers in correct order
        printArray(arr, n);

    }
    return 0;
}