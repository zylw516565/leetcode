#include <stdio.h>
#include <iostream>

void strcpy(char* dst, char* src)
{
  while ((*dst++ = *src++));

  // char tmp = '\0';
  // while (tmp = (*dst++ = *src++)) {
  //   std::cout << tmp << " " << std::endl;
  // }
}

int main()
{
  char szDst[20] = {0};
  char* szSrc = "hello";

  strcpy(szDst, szSrc);
  printf("szDst(%s), szSrc(%s)\n", szDst, szSrc);


  // char* szSrc = "hello";
  // std::string strSrc = "hello";
  // strcpy(szDst, strSrc.data());
  // printf("szDst(%s), szSrc(%s)\n", szDst, strSrc.data());
  return 0;
}