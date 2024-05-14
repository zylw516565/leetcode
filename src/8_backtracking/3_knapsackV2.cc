#include <vector>

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

int main()
{
  backtracking(0, 0);
}