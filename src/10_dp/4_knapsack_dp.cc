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

    for (int i = cap; i >= 0; --i) {
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

    for (int i = cap; i >= 0; --i) {
      if(states[i] == true) return i;
    }
    
    return 0;
  }

  int knapsack_V3(vector<int>& weight, vector<int>& value, int cap)
  {
    vector<vector<int>> states(weight.size(), vector<int>(cap+1, -1));
    states[0][0] = 0;
    if(weight[0] <= cap) {
      states[0][weight[0]] = value[0];
    }

    for (int i = 1; i < weight.size(); i++) {
      for (int j = 0; j <= cap; j++) { //第i物品不放入
        if(states[i-1][j] >= 0) states[i][j] = states[i-1][j];
      }

      for (int j = 0; j <= cap - weight[i]; j++) {
        if(states[i-1][j] >= 0) { 
           int v = states[i-1][j] + value[i];
           if(v > states[i][j+weight[i]]) {
            states[i][j+weight[i]] = v;
           }
        }
      }
    }

    int maxValue = -1;
    for (int i = 0; i <= cap; ++i) {
      if(states[weight.size()-1][i] > maxValue) {
         maxValue = states[weight.size()-1][i];
      }
    }

    return maxValue;
  }

  vector<int> double11(vector<int>& goods, int cap)
  {
    vector<vector<bool>> states(goods.size(), vector<bool>(cap+1, false));
    states[0][0] = 0;
    if(goods[0] <= cap) {
      states[0][goods[0]] = true;
    }

    for (int i = 1; i < goods.size(); i++) {
      for (int j = 0; j <= cap; j++) { //第i物品不放入
        if(states[i-1][j] == true) states[i][j] = states[i-1][j];
      }

      for (int j = 0; j <= cap - goods[i]; j++) {
        if(states[i-1][j] == true) states[i][j+goods[i]] = true;
      }
    }

    int totalPrice = 200;
    for (; totalPrice <= cap; ++totalPrice) {
      if(states[goods.size()-1][totalPrice] == true) break;
    }

    vector<int> result;
    for (int i = goods.size()-1; i >= 0 && totalPrice >= 0; --i) {
      if(states[i][totalPrice] == true) {
        result.emplace_back(i);
        totalPrice -= goods[i];
      }
    } 

    return result;
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

  vector<int> value  = {3, 4, 8, 9, 6};  // 物品重量
  auto res3 = solution.knapsack_V3(weights, value, cap);
  std::cout << res3 << std::endl;
}