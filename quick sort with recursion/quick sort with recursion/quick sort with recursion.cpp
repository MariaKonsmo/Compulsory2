// quick sort with recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <chrono>
#include <cstdlib>

using namespace std;

//quick sort with recurcion:
// swap function(This function takes two integer pointers a and b as arguments.It swaps the values pointed to by a and b by using a temporary 
//variable t.
void swap(int* a, int* b)
{
    //hiver a i t(temporary)
    int t = *a;
    //setter tallet som var i b i a:
    *a = *b;
    //så setter tallet i t(som hadde a) oppi b
    *b = t;
}

// Partition the array(matrise). It takes three arguments: arr (the array to be partitioned), low (starting point/first number of the subarray),
//  and high (the ending point/last number of the subarray).
int partition(int arr[], int low, int high)
{
    // Choosing the pivot, chooses the last element in the subarray as the pivot
    int pivot = arr[high];

    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (low - 1);

    //j (er "b" i swap funksjonen) er det neste tallet som blir testet i rekka, hvis j er mindre eller lik pivot så skal tallet swap nedover
    //i rekken og i ("a" i swap) skal flyttes et hak oppover
    for (int j = low; j <= high - 1; j++) {

        // If current tall er mindre enn  pivot
        if (arr[j] < pivot) {

            // så flytter i et hakk oppover
            i++;
            //swap funksjonen til tallene
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void quickSort(int arr[], int low, int high)
{
   //hvis tallet i low er lavere enn tallet i high, så starter den å sortere
   if (low < high) {

        // pi is partitioning index, arr[p]
        // is now at right place
         //kaller på posisjonen til pi(piviot) i partition
       int pi = partition(arr, low, high);

        // Separately sort elements before
       // partition and after partition
        // separerer tallene mellom pivot(pivot ca i midten), de som var less enn pivot til venstre og de som var mer til høyre, fortsetter
        //  å dele opp sånn til det er ferdigsortert.
        //sorterer til venstre
        quickSort(arr, low, pi - 1);
        //sorterer til høyre
       quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// function to measure the execution time of selection sort in milliseconds
long long measureselectionsorttimeinmilliseconds(int arr[], int n)
{
    auto start_time = std::chrono::high_resolution_clock::now();
    
    //call quicksort function
    quickSort(arr,0, n - 1);
    
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