// Compulsory2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <chrono>
#include <cstdlib>


using namespace std;

//sorting algorythms:
// 1)
////quick sort with recurcion:
//// swap function(This function takes two integer pointers a and b as arguments.It swaps the values pointed to by a and b by using a temporary 
////variable t.
//void swap(int* a, int* b)
//{
//    //hiver a i t(temporary)
//    int t = *a;
//    //setter tallet som var i b i a:
//    *a = *b;
//    //så setter tallet i t(som hadde a) oppi b
//    *b = t;
//}
//
//// Partition the array(matrise). It takes three arguments: arr (the array to be partitioned), low (starting point/first number of the subarray),
////  and high (the ending point/last number of the subarray).
//int partition(int arr[], int low, int high)
//{
//    // Choosing the pivot, chooses the last element in the subarray as the pivot
//    int pivot = arr[high];
//
//    // Index of smaller element and indicates
//    // the right position of pivot found so far
//    int i = (low - 1);
//
//    //j (er "b" i swap funksjonen) er det neste tallet som blir testet i rekka, hvis j er mindre eller lik pivot så skal tallet swap nedover
//    //i rekken og i ("a" i swap) skal flyttes et hak oppover
//    for (int j = low; j <= high - 1; j++) {
//
//        // If current tall er mindre enn  pivot
//        if (arr[j] < pivot) {
//
//            // så flytter i et hakk oppover
//            i++;
//            //swap funksjonen til tallene
//            swap(&arr[i], &arr[j]);
//        }
//    }
//    swap(&arr[i + 1], &arr[high]);
//    return (i + 1);
//}
//
//// The main function that implements QuickSort
//// arr[] --> Array to be sorted,
//// low --> Starting index,
//// high --> Ending index
//void quickSort(int arr[], int low, int high)
//{
//    //hvis tallet i low er lavere enn tallet i high, så starter den å sortere
//    if (low < high) {
//
//        // pi is partitioning index, arr[p]
//        // is now at right place
//        //kaller på posisjonen til pi(piviot) i partition
//        int pi = partition(arr, low, high);
//
//        // Separately sort elements before
//        // partition and after partition
//        // separerer tallene mellom pivot(pivot ca i midten), de som var less enn pivot til venstre og de som var mer til høyre, fortsetter
//        //  å dele opp sånn til det er ferdigsortert.
//        //sorterer til venstre
//        quickSort(arr, low, pi - 1);
//        //sorterer til høyre
//        quickSort(arr, pi + 1, high);
//    }
//}
//
//// Driver code
//int main()
//{
//    //setter inn verdier i rekken
//    int arr[] = { 25, 34, 8, 10, 1, 18 };
//    int N = sizeof(arr) / sizeof(arr[0]);
//
//
//    // caller på functionen og printer ut det ferdigsortert
//    quickSort(arr, 0, N - 1);
//    printf("Sorted array: \n");
//    for (int i = 0; i < N; i++)
//        printf("%d ", arr[i]);
//    return 0;
//}

//2)
//bubble sort:
//void bubbleSort(int arr[], int n)
//{
//    //lager swaperne i og j
//    int i;
//    int j;
//    bool swapped;
//    //lager to loops. flytter og bytter bortover til høyre, hvis tallet er lavere enn til høyre swapper tallene med swaperne i og j. hvis 
//    //høyere swaper ikke og fortsetter til de kommer til slutten der det høyeste tallet er, og så starter de på nytt til alt er sortert
//    //i riktig rekkefølge. når alt er sortert breaker loopen og den stopper.
//    for (i = 0; i < n - 1; i++) {
//        swapped = false;
//        for (j = 0; j < n - i - 1; j++) {
//            if (arr[j] > arr[j + 1]) {
//                swap(arr[j], arr[j + 1]);
//                swapped = true;
//            }
//        }
//
//        // If no two elements were swapped
//        // by inner loop, then break
//        if (swapped == false)
//            break;
//    }
//}
//
//// Function to print an array
//void printArray(int arr[], int size)
//{
//    int i;
//    for (i = 0; i < size; i++)
//        cout << " " << arr[i];
//}
//
//// Driver program to test above functions
//int main()
//{
//    //setter tallene i arrayen.
//    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
//    int N = sizeof(arr) / sizeof(arr[0]);
//    bubbleSort(arr, N);
//    cout << "Sorted array: \n";
//    printArray(arr, N);
//    return 0;
//}

// iterativ selection sort:
//void SelectionSort(int arr[], int size) {
//	int small, pos, temp;
//	for (int i = 0; i < size - 1; i++) {
//		small = arr[i];
//		pos = i;
//		
//		for (int j = i + 1; j < size; j++) {
//			if (arr[j] < small) {
//				small = arr[j];
//				pos = j;
//			}
//		}
//		temp = arr[i];
//		arr[i] = arr[pos];
//		arr[pos] = temp;
//	}
//	for (int i = 0; i < size; i++) {
//		cout << arr[i] << " ";
//	}
//}
//
//int main() {
//	int arr[] = { 3,7,2,1,8,4,9 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	SelectionSort(arr, n);
//	return 0;
//
//}



// Function for Selection sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        // Find the minimum element in the remaining unsorted array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element with the current element
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
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

//// Function to measure the execution time of Selection Sort in milliseconds
//long long measureSelectionSortTimeInMilliseconds(int arr[], int n)
//{
//    auto start_time = std::chrono::high_resolution_clock::now();
//    selectionSort(arr, n);
//    auto end_time = std::chrono::high_resolution_clock::now();
//
//    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
//
//    return duration.count();
//}

// Driver program
int main()
{
    int arr[] = { 64, 25, 12, 22, 11, 10, 1, 5, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    ///*const int sizes[] = { 10, 100, 1000, 10000 };*/

    /*for (int i = 0; i < 4; i++) {
        int n = sizes[i];
        int* arr = new int[n];*/

        // Initialize the array with random values
        //for (int j = 0; j < n; j++) {
        //    arr[j] = rand() % 10000; // Random values between 0 and 9999
        //}
       
        // Measure the time taken by Selection Sort in milliseconds
        //long long time_taken = measureSelectionSortTimeInMilliseconds(arr, n);
        
        //cout << "Time taken by Selection Sort for " << n << " elements: " << time_taken << " milliseconds" << std::endl;
   //}
        // Function Call
        selectionSort(arr, n);
        cout << "Sorted array: \n";
        printArray(arr, n);
        return 0;
}