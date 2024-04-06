#include <unordered_set>
#include <iostream>

class Solution {
  public:
  int getSum(int n) {
      int sum = 0;
      while(n) {
        int remainder = n % 10;
        n /= 10;
        sum += remainder * remainder;
      }

      return sum;
  }

  bool isHappy(int n) {
    std::unordered_set<int> resultSet;

    while(1)
    {
      int sum = getSum(n);
      if(1 == sum)
        return true;

      if(resultSet.find(sum) != resultSet.end())
        return false;
      else
        resultSet.insert(sum);
      n = sum;
    }
  }
};

int main()
{
  int n = 19;
  Solution solution;
  solution.isHappy(n);
  return 0;
}