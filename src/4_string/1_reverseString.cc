#include <vector>

using std::vector;

class Solution {
public:
    void reverseString(vector<char>& s) {
      auto left = 0;
      auto right = s.size() - 1;

      while (right > left)
      {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;

        left++;
        right--;
      }
    }
};