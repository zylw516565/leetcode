
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

    int pivot = partition(nums, left, right);
    quick_sort_c(nums, left, pivot - 1);
    quick_sort_c(nums, pivot + 1, right);
  }

  int partition(vector<int>& nums, int left, int right)
  {
    auto pivot = nums[right];
    auto i = left;
    for (size_t j = left; j < right; j++) {
      if(nums[j] < pivot) {
        std::swap(nums[i], nums[j]);
        i++;
      }
    }

    std::swap(nums[i], nums[right]);
    return i;
  }
};

int main()
{
  vector<int> input{5,1,1,2,0,0};
  Solution solution;
  auto res = solution.quick_sort(input);
  getchar();
}