#include <stdio.h>
int main ()
{
 int a,b,c,d,var[]={a,b,c,d}, const_[]={10,5,2,1}, n,i;
 printf ("nhap n: ");
 scanf ("%d",&n);
 for (i=0;i<4;i++)
  {
   var[i]=n/const_[i];
   n=n%const_[i];
   };
 for (i=0;i<4;i++)
  printf ("%d\n",var[i]);
 return 0;
}
