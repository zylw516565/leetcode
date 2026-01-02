#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    void insertionSort(vector<int>& nums) {
      for (std::size_t i = 1; i < nums.size(); i++) {
        int value = nums[i];
        auto j = i - 1;
        while (j>=0 && nums[j] > value) {
          nums[j+1] = nums[j];
          j--;
        }

        nums[j+1] = value;
      }
    }
};

int main() {
  vector<int> nums = {5, 2, 4, 6, 1, 3};
  Solution().insertionSort(nums);
  for (auto i : nums) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;

}