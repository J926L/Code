#include <stdio.h>
#include <math.h>

int main(void) {
    // 使用Gauss-Legendre算法快速计算圆周率
    double a = 1.0;
    double b = 1.0 / sqrt(2.0);
    double t = 0.25;
    double p = 1.0;
    double a_next;

    // 迭代足够次数，10次已经可以获得双精度下约15位数字的精度
    for (int i = 0; i < 10; i++) {
        a_next = (a + b) / 2.0;
        b = sqrt(a * b);
        t = t - p * (a - a_next) * (a - a_next);
        a = a_next;
        p *= 2.0;
    }

    double pi = (a + b) * (a + b) / (4.0 * t);
    printf("Computed value of pi: %.15f\n", pi);

    return 0;
}