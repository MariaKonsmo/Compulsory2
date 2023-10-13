// iterative selection sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <chrono>
#include <cstdlib>

using namespace std;

// iterativ selection sort:
void SelectionSort(int arr[], int size) {
	int small, pos, temp;
	for (int i = 0; i < size - 1; i++) {
		small = arr[i];
 	pos = i;
		
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < small) {
				small = arr[j];
				pos = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[pos];
		arr[pos] = temp;
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
    
    //call selection sort 
    SelectionSort(arr, n);
    
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