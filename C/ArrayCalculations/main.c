#include <stdio.h>
#include <windows.h>

int main() {
    
    int intArr[5] = {1, 2, 3, 4, 5};
    short shortArr[5] = {10, 20, 30, 40, 50};
    long longArr[5] = {100L, 200L, 300L, 400L, 500L};
    long long longLongArr[5] = {1000LL, 2000LL, 3000LL, 4000LL, 5000LL};
    unsigned unsignedArr[5] = {1, 2, 3, 4, 5};
    char charArr[5] = {'a', 'b', 'c', 'd', 'e'};
    float floatArr[5] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    double doubleArr[5] = {1.11, 2.22, 3.33, 4.44, 5.55};

    // 计算int数组的和
    int intSum = 0;
    for (int i = 0; i < 5; i++) {
        intSum += intArr[i];
    }
    printf("int数组的和: %d\n", intSum);

    // 计算float数组的平均值
    float floatSum = 0.0f;
    for (int i = 0; i < 5; i++) {
        floatSum += floatArr[i];
    }
    printf("float数组的平均值: %.2f\n", floatSum / 5);

    // 计算double数组的最大值
    double maxDouble = doubleArr[0];
    for (int i = 1; i < 5; i++) {
        if (doubleArr[i] > maxDouble) {
            maxDouble = doubleArr[i];
        }
    }
    printf("double数组的最大值: %.2f\n", maxDouble);

    // 其他类型的计算类似...

    return 0;
}