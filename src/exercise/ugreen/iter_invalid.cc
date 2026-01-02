#include <iostream>
#include <vector>
#include <list>
#include <map>

#include <string.h>

using namespace std;

int main()
{
  //1. vector中的迭代器失效
  //insert 操作导致的失效
  // vector<int> nums = {1, 2, 3, 4, 5};
  // auto it = nums.begin() + 2;
  // nums.insert(nums.begin(), 0);
  // cout << *it << endl;

  //删除元素导致的失效
  // vector<int> nums2 = {1, 2, 3, 4, 5};
  // for(auto it2 = nums2.begin(); it2 != nums2.end(); it2++) {
  //   if(*it2 == 3) {
  //     nums2.erase(it2);
  //     cout << *it2 << endl; // 不要继续使用it，危险操作！可能崩溃
  //   }
  // }

  //2. list中的迭代器失效
  list<int> nums3 = {1, 2, 3, 4, 5};
  auto it3 = nums3.begin();
  it3++;
  nums3.erase(it3);
  // it3 = nums3.erase(it3);
  cout << *it3 << endl;

  //3. map/set中的迭代器失效
  map<int, string> myMap = {{1, "one"}, {2, "two"}, {3, "three"}};
  auto it = myMap.begin();
  // myMap.erase(it); // it失效
  it = myMap.erase(it);
  cout << it->first << " " << it->second << endl;
  // 不能再使用it

  uint8_t arr[] = {1, 2, 3, 4, 5};
  vector<uint8_t> vecNums = {1, 2, 3, 4, 5};
  memcpy(vecNums.data(), arr, sizeof(arr));

  getchar();
}