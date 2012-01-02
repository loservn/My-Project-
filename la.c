 #include "stdio.h"
 int  main()
 {
 int i=0;
 char s='y';

 while(s=='y')
 {
 printf("\n\t\ti: %d\n",i++);
 scanf("%c",&s);
 }
 printf("\n gia tri cua s: %c",s);
 exit(1);
 }


