/*
Title: hw5_2.cpp
Abstract: This program displays the performance of mergesort and quicksort.
Author: Delaney N.
ID: 1117
Date: 12/6/21
*/

//Geeksforgeeks mergesort retrieved from https://www.geeksforgeeks.org/merge-sort/
//Geeksforgeeks quicksort retrieved from https://www.geeksforgeeks.org/cpp-program-for-quicksort/

#include <iostream> 
#include <sys/time.h>
#include <chrono>
#include <ctime>

void merge(int array[], int const left, int const mid, int const right);
void mergeSort(int array[], int const begin, int const end);
void swap(int* a, int* b);
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void printArray(int A[], int size);


// Driver Code 
int main() 
{
    //array length
    std::cout << "Enter input size: ";
    static int length;
    std::cin >> length;
    std::cout << std::endl;
    while (length < 0)
    {
        std::cout << "Input size cannot be negative" << std::endl;
        std::cin >> length;
    }
    
    //arrays to sort
    int* mergeArray = new int[length];
    int* quickArray = new int[length];
    //populate arrays
    for (int i = 0; i < length; i++)
    {
        int random = rand() % 10000000; //0 - 9,999,999 
        mergeArray[i] = random;
        quickArray[i] = random;
    }
    
    //Timing
    std::string output = "===================== Execution Time ====================\n";
    
    //Mergesort
    auto start_time = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    mergeSort(mergeArray, 0, length-1);
    auto end_time = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    double execution_time = 1.0 * (end_time - start_time)/1000000;
    output += "Merge sort:   " + std::to_string(execution_time) + " milliseconds\n";
    
    //Quicksort
    start_time = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    quickSort(quickArray, 0, length-1);
    end_time = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    execution_time = 1.0 * (end_time - start_time)/1000000;
    output += "Quick sort:   " + std::to_string(execution_time) + " milliseconds\n";
    
    output += "=========================================================\n";
    std::cout << output << std::endl;
}

//Geeksforgeeks mergesort
//Retrieved from https://www.geeksforgeeks.org/merge-sort/

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
 
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes



//Geeksforgeeks quicksort
//Retrieved from https://www.geeksforgeeks.org/cpp-program-for-quicksort/
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}