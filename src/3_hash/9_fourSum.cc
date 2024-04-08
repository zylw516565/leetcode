#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      std::sort(nums.begin(), nums.end());

      vector<vector<int>> result;
      for(std::size_t i = 0; i < nums.size(); i++) {
        //剪枝1
        if(nums[i] > target && nums[i] >= 0) {
          break;
        }

        //去重
        if(i > 0 && nums[i] == nums[i-1]) {
          continue;
        }

        for(auto j = i + 1; j < nums.size(); j++) {
          //剪枝2
          if(nums[i] + nums[j] > target && (nums[i] + nums[j] >= 0)) {
            break;
          }

        if(j > i + 1 && nums[j] == nums[j-1]) {
          continue;
        }

          auto left = j + 1;
          auto right = nums.size() - 1;
          while (right > left)
          {
            auto sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
            if((long)sum > target) right--;
            else if((long)sum < target) left++;
            else {
              result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
              // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
              while (right > left && nums[right] == nums[right - 1]) right--;
              while (right > left && nums[left] == nums[left + 1]) left++;

              // 找到答案时，双指针同时收缩
              right--;
              left++;
            }
          }
        }
      }

      return result;
    }
};

int main()
{
  auto target = 1000000000;
  vector<int> input{0,0,0,1000000000,1000000000,1000000000,1000000000};

  Solution solution;
  solution.fourSum(input, target);
}