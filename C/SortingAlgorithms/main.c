#include <stdio.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Original array: \n");
    printArray(arr, n);
    
    // Bubble Sort
    bubbleSort(arr, n);
    printf("\nArray after Bubble Sort: \n");
    printArray(arr, n);
    
    // Reset array
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    
    // Selection Sort
    selectionSort(arr2, n);
    printf("\nArray after Selection Sort: \n");
    printArray(arr2, n);
    
    // Reset array
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    
    // Insertion Sort
    insertionSort(arr3, n);
    printf("\nArray after Insertion Sort: \n");
    printArray(arr3, n);
    
    return 0;
}

// Bubble Sort implementation
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Selection Sort implementation
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        
        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort implementation
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Utility function to print an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
