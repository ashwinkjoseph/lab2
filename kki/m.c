#include<stdio.h>
void main()
{
	int a[10][10],i,j,n,m;
	printf("\nEnter M:");
	scanf("%d",&m);
	printf("\nEnter N:");
	scanf("%d",&n);
	printf("\n****\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("\np[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("matrix:\n");
	for(i=0;i<m;i++){
		printf("\n");
		for(j=0;j<n;j++){
			printf(" %d",a[i][j]);
		}
	}
}
