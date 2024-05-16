#include <stdio.h>
#include <stdint.h>

// #pragma pack(2)
typedef union
{
  int32_t n[4];
  double  d;
  char    name[2];
}UN;

struct Data
{
  char    c[2];
  UN      user;
  int32_t age;
};

// #pragma pack(8)
struct Test
{
  char  x1;
  char  x2;
  float x3;
  char  x4;
};

struct testlength1
{
  int   x1;
  char  x2;
  short x3;
  char  x4;
};

typedef struct
{
  char bb2;//1个字节对齐 1000
  int aa2; //4个字节对齐 1111
  short cc2;//2个字节对齐 11
  char dd2; //1个字节对齐 10
} testlength2;

#pragma pack()

#pragma

int main()
{
  printf("sizeof(int32_t)=%llu sizeof(int64_t)=%llu sizeof(int)=%llu sizeof(long)=%llu sizeof(long int)=%llu sizeof(long long)=%llu sizeof(float)=%llu sizeof(double)=%llu \n", sizeof(int32_t), sizeof(int64_t), sizeof(int), sizeof(long), sizeof(long int), sizeof(long long), sizeof(float), sizeof(double));
  printf("sizeof(short)=%llu, sizeof(int long)=%llu \n", sizeof(short int), sizeof(int long));
  auto s1 = sizeof(UN);
  auto s2 = sizeof(Data);
  printf("s1=%llu s2=%llu \n", s1, s2);

  testlength1 test1;
  printf("sizeof(Test)=%I64u sizeof(testlength1)=%I64u\n", sizeof(Test), sizeof(testlength1));

  testlength2 test2{'a', 3, 4, 'b'};
  printf("sizeof(Test)=%I64u sizeof(testlength2)=%I64u\n", sizeof(Test), sizeof(testlength2));
  void* ptr2 = &test2;
  for (size_t i = 0; i < sizeof(test2); i++) {
    printf("*ptr2+%d = %d\n", i, *(char*)(ptr2+i));
  }
}