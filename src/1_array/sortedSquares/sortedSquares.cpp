#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
  vector<int> sortedSquares(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    vector<int> res(nums.size());
    int end = res.size() - 1;
    while (left <= right && end >= 0) {
        if (std::abs(nums[left]) >= std::abs(nums[right])) {
            res[end--] = (nums[left]*nums[left]);
            left++;
        } else {
             res[end--] = (nums[right]*nums[right]);
            right--;
        }
    }

    return res;
  }
};

int main()
{
  vector<int> input{-4,-1,0,3,10};

  Solution solution;
  auto res = solution.sortedSquares(input);

  std::cout << "[";
  for (auto r : res){
    std::cout << r << " ";
  }
  std::cout << "]" << std::endl;
}