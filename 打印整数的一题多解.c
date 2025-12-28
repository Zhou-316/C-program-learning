//分析一道一题多解 tag：递归，sprintf
//题目要求：输入一个整数n，按从高位到低位的顺序打印出每一位数字，每个数字占一行。
#include <stdio.h>

void printdigits( int n );

int main()
{
    int n;
    scanf("%d", &n);
    printdigits(n);
    return 0;
}
//法一：用sprintf转换为字符串，字符串打印即可
void printdigits( int n ){
   char a[12];
   sprintf(a,"%d",n);
   printf("%c",a[0]);
   int i=1;
   while(a[i]!='\0'){
   printf("\n%c",a[i]);
   i+=1;
   }
}
/*sprintf函数用法：int sprintf(char *str, const char *format, ...);可以将各种形式的数据化为字符串
例如int num = 123;
double pi = 3.14159;

// 将整数转为字符串
sprintf(str, "%d", num); 
// 此时 str 内容为 "123"

// 将浮点数转为字符串（保留2位小数）
sprintf(str, "%.2f", pi);
// 此时 str 内容为 "3.14"*/
  
   
//法二：用递归的方法打印每一位数字
/*void printdigits( int n ){//“先前进再后退”的思想
   if(n<10){
       printf("%d\n",n);
       return;//返回
   }
   printdigits(n/10);
   printf("%d\n",n%10);
}*/

//法三：用循环的方法打印每一位数字，也比较简洁，缺陷在于位数有限（当然sprintf也有限）
/*void printdigits( int n ){
    int a[10];//假设输入的数字不超过10位
    int i=0;
    while(n>0){
         a[i]=n%10;//取最后一位数字
         n=n/10;//去掉最后一位数字
         i++;
    }
    for(int j=i-1;j>=0;j--){//倒序打印
         printf("%d\n",a[j]);
    }
    }*/

//法四：先计算出位数，然后依次取出每一位数字打印（比较复杂）
/*void printdigits( int n ){
    int count=0;
    int temp=n;
    while(temp>0){
        temp=temp/10;
        count++;
    }
    int divisor=1;
    for(int i=1;i<count;i++){
        divisor=divisor*10;//这里没有引入pow函数，所以......(苦笑)
    }
    for(int i=0;i<count;i++){
        int digit=n/divisor;
        printf("%d\n",digit);
        n=n%divisor;
        divisor=divisor/10;
    }
}*/