#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"BigInteger.h"

int main()
{
  char arr[]="1234";
  int k;
  int l=strlen(arr);
  struct BigInteger n1=initialize("538");
  struct BigInteger n2=initialize("567");
  display(n1);
  printf(" + ");
  display(n2);
  struct BigInteger n3=add(n1,n2);
  printf(" = ");
  display(n3);
  printf("\nHello\n");
  struct BigInteger n4=sub(n1,n2);
  display(n1);
  printf(" + ");
  display(n2);
  printf(" = ");
  display(n4);
  printf("\n");
  return 0;
}