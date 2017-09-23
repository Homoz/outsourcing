#include <stdio.h>

// PI / 4 = 1 - 1/3 + 1/5 - 1/7 ...
// amount 表示上述等式右边有多少项
double pi(int amount) {
    int i = 0;
    double sum = 0.0;
    double sign = 1.0;
    for (; i < amount; ++i) {
        double item = sign / (2*i + 1);
        sign = -sign;
        sum += item;
    }
    
    return 4 * sum;
}

int main() {
    printf("%f\n", pi(200));
    return 0;
}
