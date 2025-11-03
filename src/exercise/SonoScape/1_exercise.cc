#include <iostream>

int main()
{
  int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
  std::cout << "sizeof(a)=" << sizeof(a) << "  sizeof(int)=" << sizeof(int) <<  "  count of (a) = " << sizeof(a)/sizeof(int) << std::endl;

  int* b  = (int*)a;
  int* b2 = a[0];
  int* b3 = &a[0][0];
  for (size_t i = 0; i < sizeof(a)/sizeof(int); i++){
    std::cout << b[i] << " ";
  }
  std::cout << std::endl;

  for (size_t i = 0; i < sizeof(a)/sizeof(int); i++){
    std::cout << b2[i] << " ";
  }
  std::cout << std::endl;

  for (size_t i = 0; i < sizeof(a)/sizeof(int); i++){
    std::cout << b3[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}