#include <iostream>
#include <cstdlib>

//--------------------------------------------------------------------------------------------------------
//Proble Statement:
//Given two integers a and b, find their least common multiple.
//Input: The two integers a and b are given in the same line separated by space.  
//Output: Output the least common multiple of a and b.
//--------------------------------------------------------------------------------------------------------

unsigned long long lcm_naive(int a, int b) 
{
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

unsigned long long lcm_fast(unsigned long long a, unsigned long long b)
{
  unsigned long long A = a;
  unsigned long long B = b;
  if (b == 1)
    return a;
  else if (a == 1)
    return b;
  while(A != B)
  {
    if (B < A)
      B += b;
    else if (A < B)
      A += a; 

  }
    return A;
}

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

unsigned long long lcm_faster(unsigned long long a, unsigned long long b)
{
  int gcd = gcd_fast(a, b);
  unsigned long long multRes = a * b;

  unsigned long long lcm = multRes / gcd;
  return lcm;
}

void test_lcm()
{
  while(true)
  {
      int n1 = rand() % 10 + 2;
      int n2 = rand() % 10 + 2;
      unsigned long long res1 = lcm_naive(n1, n2);
      unsigned long long res2 = lcm_faster(n1,n2);

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

  //test_lcm();
  unsigned long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_faster(a, b) << std::endl;
  
  return 0;
}
