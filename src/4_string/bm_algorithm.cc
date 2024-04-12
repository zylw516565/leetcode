#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::string;

class Solution {
  private:
    const int SIZE = 256;
  public:

  void generateBC(string& needle, vector<char>& bc)
  {
    for (std::size_t i = 0; i < needle.size(); i++) {
      if(needle[i] < bc.size()) {
        bc[needle[i]] = i;
      }
    }
  }

  int strStr(string haystack, string needle) {
    vector<char> bc(SIZE, -1);
    generateBC(needle, bc);

    std::size_t i = 0;
    while (i <= haystack.size() - needle.size()) {
      auto j = needle.size() - 1;
      while (j >= 0 && haystack[i+j] == needle[j]) {
        j--;
      };

      if(j < 0) {
        return i;
      }

      i += j - bc[haystack[i+j]];
    }

    return -1;
  }
};

int main()
{

}