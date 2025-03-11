#include <stdio.h>

// 快速排序
void quick_sort(int arr[], int left, int right) {
    if (left >= right) return;
    
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;
    
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
}

// 归并排序
void merge(int arr[], int left, int mid, int right) {
    int temp[right - left + 1];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    
    for (int m = 0; m < k; m++) {
        arr[left + m] = temp[m];
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {5, 2, 8, 1, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // 测试快速排序
    int quick_arr[n];
    for (int i = 0; i < n; i++) quick_arr[i] = arr[i];
    quick_sort(quick_arr, 0, n - 1);
    printf("快速排序结果: ");
    for (int i = 0; i < n; i++) printf("%d ", quick_arr[i]);
    
    // 测试归并排序
    int merge_arr[n];
    for (int i = 0; i < n; i++) merge_arr[i] = arr[i];
    merge_sort(merge_arr, 0, n - 1);
    printf("\n归并排序结果: ");
    for (int i = 0; i < n; i++) printf("%d ", merge_arr[i]);
    
    return 0;
}
