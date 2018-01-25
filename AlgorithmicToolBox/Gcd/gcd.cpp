#include <iostream>
#include <cstdlib>

//--------------------------------------------------------------------------------------------------------
//Proble Statement:
//Given two integers a and b, find their greatest common divisor. 
//Input: The two integers a,b are given in the same line separated by space. 
//Output: Output GCD(a,b).
//--------------------------------------------------------------------------------------------------------
 
//Slow solution to the problem
int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}
//Fast solution to the problem
int gcd_fast(int a, int b)
{
  if (b > a)
    std::swap(a,b);
  if (b == 0)
    return a;
  else
  {
    int rest = a % b;
    gcd_fast(b, rest);
  }
}

//Test that compares the two solution and will break only if there is a
//result that doesn't match.
void test_gcd()
{
  while(true)
  {
      int n1 = rand() % 100000 + 1;
      int n2 = rand() % 19999 + 1;
      int res1 = gcd_naive(n1, n2);
      int res2 = gcd_fast(n1,n2);

      if (res1 != res2)
        {   
            std::cerr << "Wrong answer for ( " << n1 << ", " << n2 <<" ): " << res1 << ' ' << res2 << '\n';
            break;
        }
        else 
            std::cerr << "OK\n";
  }
}

int main() 
{
  //test_gcd();

  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
