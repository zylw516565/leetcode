#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.empty()) return 0;

        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int i = g.size() - 1;
        int j = s.size() - 1;
        int count = 0;
        while(i >= 0 && j >= 0) {
            if(s[j] >= g[i]) {
                i--; j--;
                count++;
            } else {
                i--;
            }
        }

        return count;
    }
};

int main()
{
  vector<int> g{1,2,3};
  vector<int> s{1,1};
  Solution solution;
  solution.findContentChildren(g, s);
}