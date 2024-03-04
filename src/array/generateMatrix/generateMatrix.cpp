#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      if (n <= 0) return vector<vector<int>>();
      vector<vector<int>> matrix(n, vector<int>(n,0));
      int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
      int loop = n/2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
      int mid = n/2;  // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
      int count = 1;  // 用来给矩阵中每一个空格赋值
      int offset = 1; // 需要控制每一条边遍历的长度，每次循环右边界收缩一位
      int row, column;

      while (loop--)
      {
        row = startx, column = starty;

        for (; column < n - offset; column++) {
          matrix[row][column] = count++;
        }

        for (; row < n - offset; row++) {
          matrix[row][column] = count++;
        }

        for (; column > starty; column--) {
          matrix[row][column] = count++;
        }

        for (; row > startx; row--) {
          matrix[row][column] = count++;
        }

        //设置下一个圈的起始位置
        startx++;
        starty++;
        offset++;
      }

      //处理中间位置
      if (n%2)
        matrix[mid][mid] = count;

      return matrix;
    }
};

int main()
{
  // vector<vector<int>> matrix(4, vector<int>(4,0));

  Solution solution;
  auto matrix = solution.generateMatrix(3);

  std::cout << "[";
  for (auto vec : matrix) {
    std::cout << "[";
    for (auto elment : vec) {
      std::cout << elment << " ";
    }
    std::cout << "]";
  }
  std::cout << "]" << std::endl;
  getchar();
}