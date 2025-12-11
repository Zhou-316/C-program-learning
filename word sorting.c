#include<stdio.h>
#include<string.h>
int main(){
   char word[21][11];
   int n=0;
   char *p[21];
   while(1){//输入单词，直到输入#结束
      scanf("%s",word[n]);
      p[n]=word[n];//指针数组p指向word数组的每个单词
      if(*word[n]=='#'){
         break;
      }
      n++;
   }//冒泡排序;
   for(int j=0;j<n;j++){
      for(int k=j;k<n;k++){
         if(strlen(p[j])>strlen(p[k])){
            char *temp=p[k];//交换指针，而不是交换内容
            p[k]=p[j];
            p[j]=temp;
         }
      }
   }
   for(int t=0;t<n;t++){
      printf("%s ",p[t]);//注意这里不能写成word[t]，word数组没有变，变的只是指针数组p，他们指向的内容变了
   }
   
}