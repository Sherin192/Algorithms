#include <iostream>
#include <vector>
#include <array>
using std::vector;

int optimal_weight(int W, const vector<int> &w) 
{
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int optimal_weight_dynamic(int W, const std::vector<int> &values)
{
  int** array = new int*[values.size() + 1];

  for (int i = 0; i < values.size() + 1; ++i)
  {
    array[i] = new int[W + 1]{0};
  }

  int n = values.size() + 1;

  for (int i = 1; i < n; ++i)
  {
      for (int w = 1; w < W + 1; ++w)
      {
        array[i][w] = array[i - 1][w];
        if (values[i - 1] <= w)
        {    
            int val = array[i - 1][w - values[i - 1]] + values[i - 1];
            if (array[i][w] < val)
            {
              array[i][w] = val;
            }
        }
      } 
  }

  int result = array[values.size()][W]; 
  for (int i = 0; i < values.size() + 1; ++i)
  {
    delete[] array[i];
  }
  delete[] array;
  
  return result;
}


int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }

  std::cout << optimal_weight_dynamic(W, w) << '\n';
  return 0;
}
