#include<stdio.h>
void main()
{
	int alloc[10][10],max[10][10],need[10][10],avail[10],temp[10];
	int work[10];
	int i,j,k,n,m,count=0,c=0;
	char finish[10];
	printf("\nenter no of processes:\t");
	scanf("%d",&n);
	printf("\nenter no of resources:\t");
	scanf("%d",&m);
	for(i=0;i<n;i++){
		finish[i]='n';
	}
	printf("\nenter max requirement matrix\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&max[i][j]);
		}
	}
	for(i=0;i<m;i++){
		temp[i]=0;
	}
	printf("\nenter allocation matrix\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&alloc[i][j]);
			temp[j]+=alloc[i][j];
		}
	}
	printf("\nenter maximum resources:\t");
	for(i=0;i<m;i++){
		scanf("%d",&avail[i]);
	}
	for(i=0;i<m;i++){
		avail[i]=avail[i]-temp[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	while(1){
		for(i=0;i<n;i++){
			c=0;
			for(j=0;j<m;j++){
				if((need[i][j]<=avail[j]) && (finish[i]=='n')){
					c++;
				}
			}
			if(c==m){
				for(k=0;k<m;k++){
					avail[k]+=alloc[i][k];
				}
				finish[i]='y';
				printf("p%d\t",i+1);
				work[i]=i;
				count++;
			}
		}
		if(count==m){
			break;
		}
	}
}
