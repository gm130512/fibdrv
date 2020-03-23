#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define false true
typedef enum { false, true } bool;

// time : O(logn)
unsigned long fast_fib(int n, bool clz)
{
    unsigned long a = 0, b = 1;
    int i = clz ? 31 - __builtin_clz(n) : 31;
    for (; i >= 0; i--) {
        unsigned long long t1, t2;
        t1 = a * (b * 2 - a);
        t2 = b * b + a * a;
        a = t1;
        b = t2;
        if ((n & (1 << i)) == 1) {
            t1 = a + b;
            a = b;
            b = t1;
        }
    }
    return a;
}

unsigned long easy_fib(int n)
{
    unsigned long fab[92];
    fab[0] = 0;
    fab[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        fab[i] = fab[i - 1] + fab[i - 2];
    }
    return fab[n];
}
long elapse(struct timespec start, struct timespec end)
{
    return ((long) 1.0e9 * end.tv_sec + end.tv_nsec) -
           ((long) 1.0e9 * start.tv_sec + start.tv_nsec);
}
int main()
{
    struct timespec t1, t2;

    for (int i = 2; i < 93; i++) {
        // easy
        clock_gettime(CLOCK_REALTIME, &t1);

        easy_fib(i);

        clock_gettime(CLOCK_REALTIME, &t2);
        printf("%d ", i);
        printf("%ld ", elapse(t1, t2));

        // fast w/o clz
        clock_gettime(CLOCK_REALTIME, &t1);

        fast_fib(i, false);

        clock_gettime(CLOCK_REALTIME, &t2);
        printf("%ld ", elapse(t1, t2));

        // fast with clz
        clock_gettime(CLOCK_REALTIME, &t1);

        fast_fib(i, true);

        clock_gettime(CLOCK_REALTIME, &t2);
        printf("%ld\n", elapse(t1, t2));
    }
    return 0;
}