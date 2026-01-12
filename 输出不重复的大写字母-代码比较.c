/**题目：本题要求编写程序，顺序输出给定字符串中所出现过的大写英文字母，
每个字母只输出一遍；若无大写英文字母则输出“Not Found”。
输入格式：
输入为一个以回车结束的字符串（少于80个字符）。
输出格式：
按照输入的顺序在一行中输出所出现过的大写英文字母，每个字母只输出一遍*/
/*#include<stdio.h>
int main()
{
	char a[80], b[80];
	gets(a);
	int i = 0, flag = 0, j = 0, t;
	while (a[i] != '\0')
	{
		{
			int prompt = 0;
			for (t = 0; t < j; t++)
			{
				if (a[i] == b[t])prompt = 1;
			}
			if ('A' <= a[i] && a[i] <= 'Z' && prompt == 0)
			{
				printf("%c", a[i]);
				b[j] = a[i];
				j++;
				flag = 1;
			}
		}
		i++;

	}
	if (flag == 0)
	{
		printf("Not Found");
	}
}*/ 
//法二：建立二十六个字母的有序的表示出现次数的数组 
#include<stdio.h>
int main()
{
	char a[80];
	int seen[26] = {0};
	gets(a);
	int i = 0, flag = 0;
	while (a[i] != '\0')
	{
		if ('A' <= a[i] && a[i] <= 'Z')
		{
			int index = a[i] - 'A';      //这里不需要循环 直接定位到具体的字母 
			if (!seen[index])
			{
				printf("%c", a[i]);
				flag = 1;
				seen[index] = 1;
			}
		}
		i++;
	}
	if (flag == 0)
	{
		printf("Not Found");
	}
}