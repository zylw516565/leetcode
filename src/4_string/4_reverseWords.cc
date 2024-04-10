#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    void removeExtraSpaces(string& s)
    {
      int slow{0};
      for (std::size_t i = 0; i < s.size(); i++) {
        if(s[i] != ' ') { //不是空格的字符,才处理
          if(slow != 0) {s[slow++] = ' ';} //手动添加空格
          while (i < s.size() && s[i] != ' ') {
            s[slow++] = s[i++];
          }
        }
      }

      s.resize(slow);
    }

    void reverse(string& s, int begin, int end)
    {
      for (std::size_t i = begin, j = end; i < j; ++i, --j) {
        std::swap(s[i], s[j]);
      }
    }

    string reverseWords(string s) {
      removeExtraSpaces(s); //去除多余空格
      reverse(s, 0, s.size() - 1);  //翻转整个字符串

      int start = 0;
      for (std::size_t i = 0; i <= s.size(); i++) {
        if(i == s.size() || s[i] == ' ') { //到末尾或遇到空格,说明是一个单词
          reverse(s, start, i - 1);
          start = i + 1;
        }
      }

      return s;
    }
};

int main()
{
  string input{"the sky is blue"};
  Solution solution;
  std::cout << solution.reverseWords(input) << std::endl;
}