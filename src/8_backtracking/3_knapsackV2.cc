#include <vector>
#include <iostream>

using std::vector;

// 回溯算法实现。注意：我把输入的变量都定义成了成员变量。

int maxW = 0; // 结果放到maxW中
vector<int> weight = {2, 2, 4, 6, 3};  // 物品重量
int maxCount = 5; // 物品个数
int maxCap = 9; // 背包承受的最大重量

auto mem = vector<vector<bool>>(5, vector<bool>(10, false));

void backtracking(int i, int cw) { // 调用f(0, 0)
  if (cw == maxCap || i == maxCount) { // cw==w表示装满了，i==n表示物品都考察完了
    if (cw > maxW) maxW = cw;
    return;
  }

  if(mem[i][cw]) return;  //重复状态
  mem[i][cw] = true;      //记录这个状态
  backtracking(i+1, cw);  // 选择不装第i个物品
  if (cw + weight[i] <= maxCap) {
    auto w = weight[i];
    backtracking(i+1,cw + w); // 选择装第i个物品
  }
}

class Solution {
  int maxValue = 0; // 结果放到maxValue中
  vector<int> weight = {2, 2, 4, 6, 3};  // 物品重量
  vector<int> value  = {3, 4, 8, 9, 6};  // 物品重量
  int maxCount = 5; // 物品个数
  int maxCap = 9; // 背包承受的最大重量

public:
  int getMaxValue() {return maxValue;}

  void knapsack(int i, int cw, int cv)
  {
    if(cw == maxCap || i == maxCount) {
      if(cv > maxValue) maxValue = cv;
      return;
    }

    knapsack(i+1, cw, cv);
    if (cw + weight[i] <= maxCap) {
      auto w = weight[i];
      auto v = value[i];
      knapsack(i+1,cw + w, cv + v); // 选择装第i个物品
    }
  }
};

int main()
{
  backtracking(0, 0);

  Solution solution;
  solution.knapsack(0, 0, 0);
  auto res = solution.getMaxValue();
  std::cout << res << std::endl;
}