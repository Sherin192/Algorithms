#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

//--------------------------------------------------------------------------------------------------------
//Proble Statement:
//Given an integer n, compute the minimum number of operations needed to obtain the number n starting from the number 1. 
//Input:  The input consists of a single positive integer greater than 0.
//Output: In the first line, output the minimum number k of operations needed to get n from 1. 
//In the second line output a sequence of intermediate numbers. That is, the second line should contain positive integers 
//a0,a2,...,ak−1 such that a0 = 1, ak−1 = n and for all 0 ≤ i < k−1, ai+1 is equal to either ai + 1, 2ai, or 3ai. 
//If there are many such sequences, output any one of them.
//--------------------------------------------------------------------------------------------------------
 

std::vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

std::vector<int> optimal_sequence_dynamic(int n)
{
  std::vector<std::pair<int, std::vector<int>>> dynamic_sequence;
  std::vector<int> sequence;
  dynamic_sequence.push_back(std::make_pair(0, std::vector<int>{1}));
  dynamic_sequence.push_back(std::make_pair(0, std::vector<int>{1}));
  sequence.push_back(1);
  for (int i = 2; i <= n; ++i)
  {
    if (i % 2 != 0)
    {
      if (i % 3 != 0)
      {
        dynamic_sequence.push_back(std::make_pair(dynamic_sequence.back().first + 1, dynamic_sequence.back().second));
        dynamic_sequence.back().second.push_back(i);
      }
      else
      {
         int index = i / 3;
        dynamic_sequence.push_back(std::make_pair(dynamic_sequence[index].first + 1, dynamic_sequence[index].second));
        dynamic_sequence.back().second.push_back(i);      
      }
    }
    else
    {
      int index = 0;
      if (i % 3 == 0)
      {
        index = dynamic_sequence[i / 3] > dynamic_sequence[i / 2] ? i / 2 : i / 3;
      }
      else
        index = i / 2;

      if (dynamic_sequence.back().first > dynamic_sequence[index].first)  
      {
        dynamic_sequence.push_back(std::make_pair(dynamic_sequence[index].first + 1, dynamic_sequence[index].second));
        dynamic_sequence.back().second.push_back(i);
      }     
      else
      {
        dynamic_sequence.push_back(std::make_pair(dynamic_sequence.back().first + 1, dynamic_sequence.back().second));
        dynamic_sequence.back().second.push_back(i);
      }

    }
  }
  return dynamic_sequence.back().second;
}

int main() {
  int n;
  std::cin >> n;
  
  std::vector<int> sequence2 = optimal_sequence_dynamic(n);

  std::cout << (sequence2.size() - 1) << std::endl;
   for (size_t i = 0; i < sequence2.size(); ++i) {
     std::cout << sequence2[i] << " ";
   }
}
