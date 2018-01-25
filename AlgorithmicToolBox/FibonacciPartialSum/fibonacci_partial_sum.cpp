#include <iostream>
#include <vector>
using std::vector;

//--------------------------------------------------------------------------------------------------------
//Proble Statement:
//Given two non-negative integers m and n, where m ≤ n, find the last digit of the sum Fm + Fm+1 + ...+ Fn. 
//Input:  The input consists of two non-negative integers m and n separated by a space. 
//Output: Output the last digit of Fm + Fm+1 +...+ Fn. 
//--------------------------------------------------------------------------------------------------------


long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum += current;
    }

    return sum % 10;
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

std::vector<int> getPisanoPeriod(long long n, long long m)
{

    std::vector<int> period;
    period.push_back(0);
    period.push_back(1);
    do
    {
        period.push_back((period[period.size() - 1] + period[period.size() - 2]) % m);
    }while(period[period.size() - 1] != 1 || period[period.size() - 2] != 0);

    period.erase(period.end() - 2, period.end());
    return period;
} 

long long get_fibonacci_huge_fast(long long n, long long m)
{
    std::vector<int> PisanoPeriod = getPisanoPeriod(n, m);
    int index = n % PisanoPeriod.size();

    return PisanoPeriod[index];
}

long long get_fibonacci_partial_sum_fast(long long from, long long to)
{

        long long res = get_fibonacci_huge_fast(to + 2, 10) - get_fibonacci_huge_fast(from + 1, 10);

        if (res < 0)
            res = 10 + res;

        return res;
}


void test_fibonacci_partial_sum()
{
  while(true)
  {
      long long n1 = rand() % 100000 + 1;
      long long n2 = rand() % 100000 + 1;
        
        if (n2 < n1)
            std::swap(n1, n2);
      unsigned long long res1 = get_fibonacci_partial_sum_fast(n1, n2);
      unsigned long long res2 = get_fibonacci_partial_sum_naive(n1, n2);

      if (res1 != res2)
      {   
          std::cerr << "Wrong answer for ( " << n1 << " " << n2 <<" ): " << res1 << ' ' << res2 << '\n';
          break;
      }
      else 
            std::cerr << "OK\n";
  }
}

int main() {
    long long from, to;

    //test_fibonacci_partial_sum();
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
