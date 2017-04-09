#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
  int n = 1234;
  printf("%x\n",&n);

  char buf[100];
  scanf("%s",buf);
  printf(buf);
  printf("\n");
  return 0;
}
