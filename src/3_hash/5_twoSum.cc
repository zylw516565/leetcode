#include <map>
#include <vector>
#include <iostream>

using std::map;
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int, int> resMap;
      for (int i = 0; i < nums.size(); i++)
      {
         auto iter = resMap.find(target - nums[i]);
         if(iter != resMap.end()) {
          return vector<int>{i, iter->second};
         } else {
          resMap[nums[i]] = i;
         }
      }

      return vector<int>();
    }
};

int main()
{
  int target = 9;
  vector<int> input {2,7,11,15};
  Solution solution;

  auto res = solution.twoSum(input, target);
  std::cout << "[";
  for(auto item : res) {
    std::cout << item << " ";
  }
  std::cout << "]" << std::endl;
}