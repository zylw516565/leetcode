#include <set>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      int record[300] = {0};
      vector<int> result;

      for(auto num : nums1) {
        auto idx = num/sizeof(int);
        auto offset = num%sizeof(int);

        record[idx] |= 1 << offset;
      }

      for(auto num : nums2) {
        auto idx = num/sizeof(int);
        auto offset = num%sizeof(int);
        if((record[idx] >> offset) & 1) {
          result.emplace_back(num);
          record[idx] &= (~(1 << offset));
        }
      }

      return result;
    }

    vector<int> intersectionV2(vector<int>& nums1, vector<int>& nums2) {
      std::set<int> res;
      vector<int> result;

      for(auto num : nums1) {
        res.insert(num);
      }

      for(auto num : nums2) {
        auto iter = res.find(num);
        if(res.end() != iter) {
          result.emplace_back(num);
          res.erase(num);
        }
      }

      return result;
    }
};

int main()
{

}