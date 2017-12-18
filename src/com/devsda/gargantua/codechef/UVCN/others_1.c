#include<stdio.h>
#include<stdlib.h>
main()
{
	int t,n,i,sum=0,min=1<<30,count=0,minno=0;
	scanf("%d",&t);

	while(t--)
	{	count=0,sum=0;
		scanf("%d",&n);
		int ar[n];
		for(i=0;i<n;i++)
		{scanf("%d",&ar[i]);
		sum+=ar[i];
		}
		if(n%2==0)
		minno=sum/n+1;
		else
		minno=sum/n;

		for(i=0;i<n;i++)
		{
			if(ar[i]==minno)
			continue;
			else
			count+=(abs)(minno-ar[i]);
		}
		printf("%d\n",count);
	}
}
