#include <stdio.h>

long long factorial(int number) {
    if (number <= 1) 
        return 1;
    else
        return number * factorial(number-1);
}

long long factorialSum(int maxItem) {
    long long sum = 0;
    int i = 1;
    for (; i <= maxItem; ++i) {
        sum += factorial(i);
    }
    return sum;
}

int main() {
    printf("%lld\n", factorialSum(20));
    return 0;
}
