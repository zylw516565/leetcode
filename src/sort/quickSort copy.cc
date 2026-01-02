
#include <stdio.h>

#include <vector>

using std::vector;

class Solution {
public:
  vector<int> quick_sort(vector<int>& nums)
  {
    quick_sort_c(nums, 0, nums.size()-1);
    return nums;
  }

  void quick_sort_c(vector<int>& nums, int left, int right)
  {
    if(left >= right) return;

    // int pivot = partition(nums, left, right);

  }

  int partition(vector<int>& nums, int left, int right)
  {
  }

};

int main()
{
  vector<int> input{5,1,1,2,0,0};
  Solution solution;
  auto res = solution.quick_sort(input);
  getchar();
}