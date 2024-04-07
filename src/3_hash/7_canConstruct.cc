#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      unordered_map<char, int> umap;
      for(auto item : magazine) {
        umap[item]++;
      }

      for(auto item : ransomNote) {
         if(umap.find(item) == umap.end()) {
          return false;
         } else {
          umap[item]--;
          if(umap[item] <= 0)
            umap.erase(item);
         }
      }

      return true;
    }
};

int main()
{
  
}