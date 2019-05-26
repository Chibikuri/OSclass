#include<stdio.h>

int fact(int n){
  int m;
  if (n == 0){
    return 1;
  }
  m = fact(n - 1);
  printf("%p\n", &m);
  return m;
}

int main(){
  int i = 15;
  fact(i);
  return 0;
}