#include <iostream>
#include <cassert>

//--------------------------------------------------------------------------------------------------------
//Proble Statement:
//Given an integer n, find the nth Fibonacci number Fn. 
//Input: The input consists of a single integer n. 
//Output: Output Fn.
//--------------------------------------------------------------------------------------------------------

//naive algorithm for computing a Fibonacci number.
int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}
//fast algorithm for computing a Fibonacci number.
int fibonacci_fast(const int n) {
    int * fib = new int[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

//function to compare the fast solution with the naive one
void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;
    //test_solution();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
