#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
  int knapsack(vector<int>& weight, int cap)
  {
    vector<vector<bool>> states(weight.size(), vector<bool>(cap+1, false));
    states[0][0] = true;
    if(weight[0] <= cap) {
      states[0][weight[0]] = true;
    }

    for (int i = 1; i < weight.size(); i++) {
      for (int j = 0; j <= cap; j++) { //第i物品不放入
        if(states[i-1][j] == true) states[i][j] = states[i-1][j];
      }
      
      for (int j = 0; j <= cap - weight[i]; j++) { //第i物品放入背包
        if(states[i-1][j] == true) states[i][j+weight[i]] = true;
      }
    }

    for (int i = cap; i >= 0; i++) {
      if(states[weight.size() - 1][i] == true) return i;
    }
    
    return 0;
  }

  int knapsack_V2(vector<int>& weight, int cap)
  {
    vector<bool> states(cap+1, false);
    states[0] = true;
    if(weight[0] <= cap) {
      states[weight[0]] = true;
    }

    for (int i = 1; i < weight.size(); i++) {      
      for (int j = cap-weight[i]; j >= 0; --j) { //第i物品放入背包
        if(states[j] == true) states[j+weight[i]] = true;
      }
    }

    for (int i = cap; i >= 0; i++) {
      if(states[i] == true) return i;
    }
    
    return 0;
  }
};

int main()
{
  int cap = 9;
  vector<int> weights = {2, 2, 4, 6, 3};
  Solution solution;
  auto res = solution.knapsack(weights, cap);
  std::cout << res << std::endl;

  auto res2 = solution.knapsack_V2(weights, cap);
  std::cout << res2 << std::endl;
}