#include <iostream>
#include <climits>
#include <vector>

//--------------------------------------------------------------------------------------------------------
//Proble Statement:
//Given an integer n, find the last digit of the sum F0 + F1 +...+ Fn. 
//Input:  The input consists of a single integer n.
//Output: Output the last digit of F0 + F1 +...+ Fn. 
//--------------------------------------------------------------------------------------------------------

int fibonacci_sum_naive(unsigned long long n) {
    if (n <= 1)
        return n;

    unsigned long long previous = 0;
    unsigned long long current  = 1;
    unsigned long long sum      = 1;

    for (unsigned long long i = 0; i < n - 1; ++i) {
        unsigned long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum += current;
    }

    return sum % 10;
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


int fibonacci_sum_fast(unsigned long long n)
{       //Fn+2 - F2
    if (n > 3)
    {   
        long long res = get_fibonacci_huge_fast(n + 2, 10);

        if (res == 0)
            res = 9;
        else
            res--;
        return (res % 10);
    }
    else if(n < 2)
        return n;

    int a = 0;
    int b = 1;
    int c = 0;
    int sum = 1;
    for (int i = 0; i < n - 1; ++i)
    {
        c = a + b;
        a = b; 
        b = c;
        sum = (sum + c) % 10;
    }
    return sum;
}

void test_fibonacci_sum()
{
  while(true)
  {
      long long n = rand() % 200  + 832564823476;

      unsigned long long res1 = fibonacci_sum_fast(n);
      unsigned long long res2 = fibonacci_sum_naive(n);

      if (res1 != res2)
      {   
          std::cerr << "Wrong answer for ( " << n <<" ): " << res1 << ' ' << res2 << '\n';
          break;
      }
      else 
            std::cerr << "OK\n";
  }
}

int main() {
    unsigned long long n = 0;

    //test_fibonacci_sum();
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
