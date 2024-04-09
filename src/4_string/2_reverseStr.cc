#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    string reverseStr(string s, int k) {
      auto size_ = static_cast<int>(s.size());
      for (int i = 0; i < size_; i += (2*k)) {
        auto left = i, right = 0;
        if((size_ - i) < k)
          right = s.size() - 1;
        else
          right = i + k - 1;
 
        while (right > left) {
          std::swap(s[right--], s[left++]);
        }
      }

      return s;
    }
};

int main()
{
  string input{"abcdefg"};
  Solution solution;
  std::cout << solution.reverseStr(input, 2) << std::endl;
}