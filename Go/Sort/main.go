package main

import "fmt"

// 冒泡排序
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
// 算法原理：重复地走访要排序的数列，一次比较两个元素，如果顺序错误就交换它们
func bubbleSort(arr []int) []int {
    n := len(arr)
    for i := 0; i < n-1; i++ {
        // 标记是否发生交换
        swapped := false
        for j := 0; j < n-i-1; j++ {
            if arr[j] > arr[j+1] {
                // 交换元素
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = true
            }
        }
        // 如果没有发生交换，说明已经有序
        if !swapped {
            break
        }
    }
    return arr
}

// 选择排序
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
// 算法原理：每次从未排序部分选择最小元素，放到已排序部分的末尾
func selectionSort(arr []int) []int {
    n := len(arr)
    for i := 0; i < n-1; i++ {
        // 找到未排序部分的最小值索引
        minIndex := i
        for j := i + 1; j < n; j++ {
            if arr[j] < arr[minIndex] {
                minIndex = j
            }
        }
        // 将最小值交换到已排序部分的末尾
        arr[i], arr[minIndex] = arr[minIndex], arr[i]
    }
    return arr
}

// 插入排序
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
// 算法原理：将未排序元素逐个插入到已排序部分的正确位置
func insertionSort(arr []int) []int {
    n := len(arr)
    for i := 1; i < n; i++ {
        key := arr[i]
        j := i - 1
        
        // 将比key大的元素向后移动
        for j >= 0 && arr[j] > key {
            arr[j+1] = arr[j]
            j--
        }
        // 插入key到正确位置
        arr[j+1] = key
    }
    return arr
}

// 快速排序
// 时间复杂度：平均O(n log n)，最坏O(n^2)
// 空间复杂度：O(log n)
// 算法原理：分治法，选择一个基准元素，将数组分为两部分，递归排序

// 分区函数，返回基准元素的正确位置
func partition(arr []int, low, high int) int {
    pivot := arr[high] // 选择最后一个元素作为基准
    i := low - 1       // 较小元素的索引
    
    for j := low; j < high; j++ {
        if arr[j] < pivot {
            i++
            arr[i], arr[j] = arr[j], arr[i]
        }
    }
    // 将基准元素放到正确位置
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return i + 1
}

// 快速排序主函数
func quickSort(arr []int, low, high int) []int {
    if low < high {
        // 获取分区索引
        pi := partition(arr, low, high)
        
        // 递归排序左半部分
        quickSort(arr, low, pi-1)
        // 递归排序右半部分
        quickSort(arr, pi+1, high)
    }
    return arr
}

// 归并排序
// 时间复杂度：O(n log n)
// 空间复杂度：O(n)
// 算法原理：分治法，将数组分成两半分别排序，然后合并两个有序数组

// 合并两个有序数组
func merge(arr []int, l, m, r int) {
    n1 := m - l + 1
    n2 := r - m
    
    // 创建临时数组
    L := make([]int, n1)
    R := make([]int, n2)
    
    // 拷贝数据到临时数组
    for i := 0; i < n1; i++ {
        L[i] = arr[l+i]
    }
    for j := 0; j < n2; j++ {
        R[j] = arr[m+1+j]
    }
    
    // 合并临时数组
    i, j, k := 0, 0, l
    for i < n1 && j < n2 {
        if L[i] <= R[j] {
            arr[k] = L[i]
            i++
        } else {
            arr[k] = R[j]
            j++
        }
        k++
    }
    
    // 拷贝剩余元素
    for i < n1 {
        arr[k] = L[i]
        i++
        k++
    }
    for j < n2 {
        arr[k] = R[j]
        j++
        k++
    }
}

// 归并排序主函数
func mergeSort(arr []int, l, r int) []int {
    if l < r {
        m := l + (r-l)/2
        
        // 递归排序左半部分
        mergeSort(arr, l, m)
        // 递归排序右半部分
        mergeSort(arr, m+1, r)
        // 合并两个有序数组
        merge(arr, l, m, r)
    }
    return arr
}

func main() {
    arr := []int{64, 34, 25, 12, 22, 11, 90}
    
    fmt.Println("原始数组：", arr)
    
    // 复制数组用于不同排序算法
    arr1 := make([]int, len(arr))
    copy(arr1, arr)
    fmt.Println("\n冒泡排序结果：", bubbleSort(arr1))
    
    arr2 := make([]int, len(arr))
    copy(arr2, arr)
    fmt.Println("选择排序结果：", selectionSort(arr2))
    
    arr3 := make([]int, len(arr))
    copy(arr3, arr)
    fmt.Println("插入排序结果：", insertionSort(arr3))
    
    arr4 := make([]int, len(arr))
    copy(arr4, arr)
    fmt.Println("快速排序结果：", quickSort(arr4, 0, len(arr4)-1))
    
    arr5 := make([]int, len(arr))
    copy(arr5, arr)
    fmt.Println("归并排序结果：", mergeSort(arr5, 0, len(arr5)-1))
}
