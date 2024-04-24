#include <stdio.h>

#include <vector>

using std::vector;


class Solution {
public:
  void combine(int n, int k)
  {
    backTracking(n, k, 1);
  }
private:
  vector<vector<int>> result;
  vector<int> path;

  void backTracking(int n, int k, int startIndex)
  {
    if(path.size() == k) {
      result.emplace_back(path);
      return;
    }

    for (auto i = startIndex; i <= n; i++) {
      path.emplace_back(i);
      backTracking(n, k, i + 1);
      path.pop_back();
    }
  }

    void backTrackingPruning(int n, int k, int startIndex)
  {
    if(path.size() == k) {
      result.emplace_back(path);
      return;
    }

    for (auto i = startIndex; i <= n - (k - path.size()) +1 ; i++) {
      path.emplace_back(i);
      backTrackingPruning(n, k, i + 1);
      path.pop_back();
    }
  }
};

int main()
{
  Solution solution;
  solution.combine(4, 2);
  getchar();
}