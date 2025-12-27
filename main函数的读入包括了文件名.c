#include <stdio.h>
#include <string.h>
int less(char s[], char t[])
{
   //#1_begin--------------
    return (strcmp(s,t)<0)                      ; // <--第1空, 请把解答写在分号左边, 务必确保begin与end之间仅有一行内容
   //#1_end================
}

int main(int n, char **pv)
{
   int i, j, k, count;
   char *v[100];
   //#2_begin--------------
   char *pt                       ; // <--第2空, 请把解答写在分号左边, 务必确保begin与end之间仅有一行内容
   //#2_end================
   count = n - 1;
   for(i=0; i<count; i++)
   {
      v[i] = 
         //#3_begin--------------
         pv[i+1]                       ; // <--第3空, 请把解答写在分号左边, 务必确保begin与end之间仅有一行内容
         //#3_end================
   }
   for(i=0; i<count-1; i++)
   {
      k=i;
      for(j=i+1; j<=count-1; j++)
      {
         if(less(v[j], v[k]))
            k = j;         
      }
      pt = v[i];
      v[i] = v[k];
      v[k] = pt;
   }
   for(i=0; i<count; i++)
   {
      printf("%s ", v[i]);
   }
   putchar('\n');
   return 0;
}
