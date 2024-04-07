#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
      std::unordered_map<int, int> map_;
      for (size_t i = 0; i < nums1.size(); i++) {
        for (size_t j = 0; j < nums2.size(); j++){
          auto sum = nums1[i] + nums2[j];

          auto iter = map_.find(sum);
          if(iter != map_.end()) {
            iter->second++;
          } else {
            map_.insert(std::make_pair(sum, 1));
          }
        }
      }

      int count(0);
      for (size_t i = 0; i < nums3.size(); i++) {
        for (size_t j = 0; j < nums4.size(); j++) {
          auto diff = 0 - (nums3[i] + nums4[j]);
          auto iter = map_.find(diff);
          if(iter != map_.end()) {
            count += iter->second;
          }
        }
      }

      return count;
    }
};

int main()
{

}