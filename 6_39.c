#include <stdio.h>

int recursiveMinimum ( int a [], int size){

if (size == 0){
  return  a[size];
} 
  int b = recursiveMinimum(a, size -1);
  if (a[size] < b){
      return a[size];
  }
  else return b;
}

int main (int argc, char *argv[])
{  
  int aw [] = {0,100,200,300,400,-100,600,700,-800,900,1000};
  printf ("%d \n" , recursiveMinimum(aw,10));
 }
