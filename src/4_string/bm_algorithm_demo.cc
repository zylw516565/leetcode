#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    const int MaxSize = 256;
public:
  void generateBC(const string& needle, vector<char>& bc)
  {
    for(int i = 0; i < needle.size(); i++) {
      if(needle[i] < bc.size()) {
        bc[needle[i]] = i;
      }
    }
  }

  int bm(const string& haystack, const string& needle)
  {
    vector<char> bc(MaxSize, -1);
    generateBC(needle, bc);

    int i = 0;
    while(i <= haystack.size() - needle.size()) {
      int j;
      for(j = needle.size() - 1; j >=0; j--) {
        if(needle[j] != haystack[i+j]) break;
      }

      if(j < 0) {
        return i;
      }

      //i = si - xi;
      i = i + j - bc[haystack[i+j]];
    }
  }

};

int main()
{
  Solution objSolution;
  int nRet;
  // nRet = objSolution.bm("abcdefg", "def");
  nRet = objSolution.bm("aaaaaaaaaa", "baaa");
  printf("nRet = %d\n", nRet);
}