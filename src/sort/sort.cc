#include <stdio.h>

#include <vector>

using std::vector;

class Solution {
public:
  vector<int> merge_sort(vector<int>& nums)
  {
    merge_sort_inner(nums, 0, nums.size() - 1);
    return nums;
  }
private:
  void merge_sort_inner(vector<int>& nums, int left, int right)
  {
    if(left >= right) return;

    int mid = (left + right)/2;
    merge_sort_inner(nums, left, mid);
    merge_sort_inner(nums, mid + 1, right);
    merge(nums, left, right);
  }

  void merge(vector<int>& nums, int left, int right)
  {
    auto mid = (left + right) / 2;
    auto i = left; auto j = mid + 1; auto k = 0;
    vector<int> tmp(right - left + 1);
    while (i <= mid && j <= right) {
      if(nums[i] < nums[j]) {
        tmp[k++] = nums[i++];
      } else {
        tmp[k++] = nums[j++];
      }
    }

    //如果i区间还有剩余数据,则把剩余全部放入tmp数组中
    while (i <= mid) {
      tmp[k++] = nums[i++];
    }

    //如果j区间还有剩余数据,则把剩余全部放入tmp数组中
    while (j <= right) {
      tmp[k++] = nums[j++];
    }

    //最后把tmp中排序后的数据拷贝到源数据中
    i = left; k = 0;
    while (i <= right){
      nums[i++] = tmp[k++];
    }
  }
};

int main()
{
  vector<int> input{5,1,1,2,0,0};
  Solution solution;
  auto res = solution.merge_sort(input);
  getchar();
}