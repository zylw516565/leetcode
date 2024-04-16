
#include <stdio.h>

#include <vector>

using std::vector;

class Solution {
public:
  vector<int> quick_sort(vector<int>& nums)
  {
    quick_sort_c(nums, 0, nums.size() - 1);
    return nums;
  }

  void quick_sort_c(vector<int>& nums, int left, int right)
  {
    if(left >= right) return;

    int mid = partition(nums, left, right);
    quick_sort_c(nums, left, mid - 1);
    quick_sort_c(nums, mid + 1, right);
  }

  int partition(vector<int>& nums, int left, int right)
  {

  }

};

int main()
{
  
}