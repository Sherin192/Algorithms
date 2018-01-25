#include <iostream>
#include <vector>

//--------------------------------------------------------------------------------------------------------
//Proble Statement:
//Given two integers n and m, output Fn mod m (that is, the remainder of Fn when divided by m).
//Input: The input consists of two integers n and m given on the same line (separated by a space). 
//Output: Output Fn mod m.
//--------------------------------------------------------------------------------------------------------

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current % m;
    }

    return current % m;
}

//For any integer n the sequence of Fibonacci numbers % m is periodic.
//The Pisano Period is the lenght of the period of the sequence.
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

void test_fibonacci_huge()
{
  while(true)
  {
      long long n1 = rand() % 1000 + 2;
      long long n2 = rand() % 1000 + 2;
      unsigned long long res1 = get_fibonacci_huge_fast(n1, n2);
      unsigned long long res2 = get_fibonacci_huge_naive(n1,n2);

      if (res1 != res2)
      {   
          std::cerr << "Wrong answer for ( " << n1 << ", " << n2 <<" ): " << res1 << ' ' << res2 << '\n';
          break;
      }
      else 
            std::cerr << "OK\n";
  }
}

int main() {
    long long n, m;

    //test_fibonacci_huge();
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
