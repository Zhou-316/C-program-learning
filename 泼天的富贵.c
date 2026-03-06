#include<stdio.h>
int main()
{
	int n, d, k;
	scanf("%d %d %d", &n, &d, &k);
	int a[n][d];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < d; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int r, rmax[n];
	for (int i = 0; i < n; i++)
	{
		int flag=0;
		for (int j = 0; j <= d - k; j++)
		{
			int g=0,breaked=0;
			while(g<k-1){
				if(a[i][j+g]>=a[i][j+g+1]){
					breaked=1;
					break;
				} 
                g++;
			}
			if (breaked==0)
			{
				r = a[i][j + k-1] - a[i][j];
				if (flag == 0 || r > rmax[i])
				{
					rmax[i] = r;
					flag=1;
				}
			}
		}
		if (flag == 0){
		   rmax[i] = 0;
        }
	}
	int rbest = rmax[0];
	for (int i = 1; i < n; i++)
	{
		if (rmax[i] > rbest)
		{
			rbest = rmax[i];
		}
	}
	printf("%d/%d\n", rbest, k);
	int flash = 0;
	for (int i = 0; i < n; i++)
	{
		if (rmax[i] == rbest && flash == 0)
		{
			flash = 1;
			printf("%d", i + 1);
		}
		else if (rmax[i] == rbest && flash == 1)
		{
			printf(" %d", i + 1);
		}
	}
}



