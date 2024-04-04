#include <string>

using std::string;

class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.length() != t.length()) return false;

      int arr[26] = {0};
      for (size_t i = 0; i < s.length(); i++)
      {
        arr[s[i] - 'a']++;
        arr[t[i] - 'a']--;
      }

      for (auto item : arr)
      {
        if(item != 0)
          return false;
      }

      return true;
    }
};

int main()
{
  string s = "anagram";
  string t = "nagaram";

  Solution solution;
  solution.isAnagram(s, t);
}