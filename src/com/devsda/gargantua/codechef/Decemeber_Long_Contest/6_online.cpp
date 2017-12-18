#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 64001
int acc[41][41][41];

int main()
{
	int t,n,i,j,k,p,cube[41][41][41],totalsc,cb[41],sq[41],cs,occ,minc,mc,l;
	char a[MAX],b[MAX];
	double flp;

	for(i=1;i<=40;i++)
	{
		cb[i]=(i*i*i);
    }

	scanf("%d",&t);

    //fscanf(fp,"%d",&t);
	//memset(acc,0,sizeof(acc));

	while(t--) {
        scanf("%d%d",&n,&p); getchar();		gets(a);;gets(b);

		l=0;

		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(k=1;k<=n;k++)
				{
					if(a[l]==b[l])
						cube[i][j][k]=1;
					else
						cube[i][j][k]=0;
					l++;
					acc[i][j][k]=acc[i-1][j][k]+(acc[i][j-1][k]-acc[i-1][j-1][k])+((acc[i][j][k-1]-acc[i][j-1][k-1])-(acc[i-1][j][k-1]-acc[i-1][j-1][k-1]))+cube[i][j][k];
					printf("%d ",acc[i][j][k]);

				}
				printf("\n");
			}
			printf("\n");
		}
		totalsc=acc[n][n][n];

		flp=p;
		occ=0;
		for(cs=n;cs>=2;cs--)
		{
					minc=ceil((cb[cs]*flp)/100);
					if(minc>totalsc)
                      continue;
                   for(i=1;i<=n-cs+1;i++)
				   {
						for(j=1;j<=n-cs+1;j++)
						{
							for(k=1;k<=n-cs+1;k++)
							{
					   			mc=acc[i+cs-1][j+cs-1][k+cs-1]-acc[i-1][j+cs-1][k+cs-1]-(acc[i+cs-1][j-1][k+cs-1]-acc[i-1][j-1][k+cs-1])-(acc[i+cs-1][j+cs-1][k-1]-acc[i-1][j+cs-1][k-1])+(acc[i+cs-1][j-1][k-1]-acc[i-1][j-1][k-1]);
		                        if(mc>=minc)
		                        {
		                         occ++;
		                         printf("\n%d %d %d",i,j,k);
						        }
						        //else
								//k+=(((minc-mc)-1)/(sq[cs]));


							}
		            	}
		            	if((totalsc-acc[i][n][n])<minc)
		            	 break;
		       	   }
		           if(occ)
		            break;

	    }
	    printf("\n");
	    if(totalsc==0 )
	    {
	    	if(p)
	    		printf("-1");
	    	else
	    	    printf("%d 1",n);
	    }
	    else
	    {
	    	if(cs==1)
	    		printf("%d %d",cs,totalsc);
	    	else
				printf("%d %d",cs,occ);
	    }
	}
}
