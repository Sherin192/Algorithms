#include <iostream>
#include <cstdlib>

//--------------------------------------------------------------------------------------------------------
//Proble Statement:
// Given an integer n, find the last digit of the nth Fibonacci number Fn (that is, Fn mod 10).
//Input: The input consists of a single integer n. 
//Output: Output the last digit of Fn.
//--------------------------------------------------------------------------------------------------------

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
int getFibonacciLastDigitFast(const int n)
{
    if (n <= 1)
        return n;
    
    int * fib = new int [n + 1];
    
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        fib[i] = (fib[i - 1] % 10) + (fib[i -2] % 10);
    }
    return fib[n] % 10;
}

void testFib()
{
    while(true)
    {
        int randFib = rand() % 10 + 1;

        int res1 = get_fibonacci_last_digit_naive(randFib);
        int res2 = getFibonacciLastDigitFast(randFib);

        if (res1 != res2)
        {   
            std::cerr << "Wrong answer for ( " << randFib <<" ): " << res1 << ' ' << res2 << '\n';
            break;
        }
        else 
            std::cerr << "OK\n"; 
    }
}

int main() {
    //testFib();
    int n;
    std::cin >> n;
    int c = getFibonacciLastDigitFast(n);
    std::cout << c << '\n';
    }
