#include<stdio.h>
#include<math.h>
#include<time.h>

#define n 4

unsigned int x[n+1]={0},i,k,b,z=0;

bool uygun(int k)
{
	i=1;
	while(i<k)
	{
		if((x[i]==x[k]) || ((abs(x[i]-x[k])==abs(i-k))))
			return false;
		i++;
	}
	return true;
}

void func(int m)
{
	x[1]=0;
	k=1;
	while(k>0)
	{
		x[k]++;
		while(x[k]<=m && !uygun(k))
			x[k]++;
		if(x[k]<=m)
		{
			if(k==m)
			{
				z++;
				printf("%3d) ",z);
				for(b=1;b<=m;b++)
					printf("%d ",x[b]);
				printf("\n");
			}
			else
			{
				k++;
				x[k]=0;
			}
		}
		else k--;
	}
}

int main()
{
	clock_t start, end;
    start = clock();
	func(n);
	end = clock();
 	printf("\nThe time was: %f\n\n", (float) (end - start) / CLK_TCK);	
	return 0;
}
