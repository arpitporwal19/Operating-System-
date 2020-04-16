#include<stdio.h>
int main()
{
	int x;
	int y[10],gift[10],ytime[10];
	printf("*************************************************************************\n");
	printf("*************************Welcome to the Gift Shop************************\n");
	printf("*************************************************************************\n");
	for(x=0;x<10;x++)
	{
		printf("-----------------------------------");
		printf("\nEnter the details of student %d",x+1);
		y[x]=x;
		printf("\nEnter the no. of gifts: ");
		scanf("%d",&gift[x]);
		printf("Enter the arrival time: ");
		scanf("%d",&ytime[x]);
		printf("-----------------------------------");
		printf("\n\n");
	}
	printf("\n---------------------------------------------");
	printf("\nWe are sorting the data according to gifts\n");
	int k,j;
	for(x=0;x<10;x++)
	{
		for(j=x;j<10;j++)
		{
			if(ytime[x]>=ytime[j])
			{
				if(ytime[x]==ytime[j])
				{
					if(gift[x]<gift[j])
					{
						k=ytime[x];
						ytime[x]=ytime[j];
						ytime[j]=k;
					
						k=gift[x];
						gift[x]=gift[j];
						gift[j]=k;
				
						k=y[x];
						y[x]=y[j];
						y[j]=k;
					}
				}
			
			}
		}
	}
	printf("---------------------------------------------");
	printf("\nStudent\t\tGifts\t\tArrvial time\n");
	printf("---------------------------------------------");
	for(x=0;x<10;x++)
	{
		printf("\n%d\t\t%d\t\t%d",y[x],gift[x],ytime[x]);
	}
	printf("\n---------------------------------------------");
	printf("\n\n---------------------------------------------");
	printf("\nOrder of the billing");
	printf("\n---------------------------------------------");
	for(x=0;x<10;x++)
	{
		printf("\n%d",y[x]);
	}
	return 0;
}
