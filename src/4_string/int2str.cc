#include <iostream>

bool int2str(int num, char* str, int bufSize)
{
  auto absNum = std::abs(num);

  char* arr = new char[bufSize];

  *arr++ = '\0';
  while (absNum) {
    auto a = absNum % 10;
    absNum = absNum / 10;
    *arr++ = a + '0';
  }
  if(num < 0) *arr = '-';

  while (*arr) {
    *str++ = *arr--;
  }

  delete []arr;
  return true;
}

int main()
{
  int num = 3456;
  char str[256] = {0};
  auto res = int2str(num, str, sizeof(str));
  std::cout << res << " " << str << std::endl;
}