#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

void printVec(const vector<int>& vec)
{
    std::cout << "[ " << std::endl;
    for(auto n : vec) {
      std::cout << n << " " << std::endl;
    }
    std::cout << " ]" << std::endl;
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      std::sort(nums.begin(), nums.end());

      vector<vector<int>> result;
      for(std::size_t i = 0; i < nums.size() - 2; i++) {
        if (nums[i] > 0) {
          return result;
        }

        if(i > 0 && nums[i] == nums[i-1])
          continue;

        auto left = i + 1;
        auto right = nums.size() - 1;

        while (right > left)
        {
          auto sum = nums[i] + nums[left] + nums[right];
          if(sum > 0) {
            right--;
          } else if(sum < 0) {
            left++;
          } else {
            result.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
            while (right > left && nums[right] == nums[right - 1]) right--;
            while (right > left && nums[left] == nums[left + 1]) left++;

            // 找到答案时，双指针同时收缩
            right--;
            left++;
          }
        }
      }

      return result;
    }
};

int main()
{
  vector<int> input{-1,0,1,2,-1,-4};

  Solution solution;
  auto res = solution.threeSum(input);
  std::cout << "[ " << std::endl;
  for(auto item : res) {
    std::cout << "[ " << std::endl;
    for(auto n : item) {
      std::cout << n << " " << std::endl;
    }
    std::cout << " ]" << std::endl;
  }
  std::cout << " ]" << std::endl;
}