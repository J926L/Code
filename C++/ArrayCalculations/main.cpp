#include <iostream>
#include <algorithm>

// 函数声明
void printArray(int arr[], int size);
int calculateSum(int arr[], int size);
double calculateAverage(int arr[], int size);
int findMin(int arr[], int size);
int findMax(int arr[], int size);
void sortArray(int arr[], int size);
bool searchArray(int arr[], int size, int target);

int main() {
    const int SIZE = 5;
    int numbers[SIZE] = {5, 2, 8, 1, 9};

    std::cout << "数组计算程序\n";
    
    std::cout << "原始数组: ";
    printArray(numbers, SIZE);

    std::cout << "\n数组总和: " << calculateSum(numbers, SIZE);
    std::cout << "\n数组平均值: " << calculateAverage(numbers, SIZE);
    std::cout << "\n最小值: " << findMin(numbers, SIZE);
    std::cout << "\n最大值: " << findMax(numbers, SIZE);

    sortArray(numbers, SIZE);
    std::cout << "\n排序后的数组: ";
    printArray(numbers, SIZE);

    int searchValue = 8;
    if (searchArray(numbers, SIZE, searchValue)) {
        std::cout << "\n值 " << searchValue << " 在数组中找到";
    } else {
        std::cout << "\n值 " << searchValue << " 未在数组中找到";
    }

    return 0;
}

// 函数实现
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

int calculateSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

double calculateAverage(int arr[], int size) {
    return static_cast<double>(calculateSum(arr, size)) / size;
}

int findMin(int arr[], int size) {
    return *std::min_element(arr, arr + size);
}

int findMax(int arr[], int size) {
    return *std::max_element(arr, arr + size);
}

void sortArray(int arr[], int size) {
    std::sort(arr, arr + size);
}

bool searchArray(int arr[], int size, int target) {
    return std::binary_search(arr, arr + size, target);
}
