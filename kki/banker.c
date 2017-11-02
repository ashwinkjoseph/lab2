#include<stdio.h>
void main()
{
	int work[5],avl[5],alloc[10][10],l;
	int need[10][10],n,m,i,j,avail[10],max[10][10],k,count,fcount=0,pr[10];
	char finish[10]={'f','f','f','f','f','f','f','f','f','f'};
	printf("\nenter no of process:");
	scanf("%d",&n);
	printf("\nenter no of resources:");
	scanf("%d",&m);
	printf("\nenter total no of resources:");
	for(i=1;i<=m;i++){
		scanf("%d",&avail[i]);
	}
	printf("\nenter max resources requested by each process allocation matrix");
	for(i=1;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&max[i][j]);}}
	printf("\nprocess allocation matrix\n");
	for(i=1;i<=n;i++){
		for(j=0;j<=m;j++){
			scanf("%d",&alloc[i][j]);}}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			need[i][j]=max[i][j]-alloc[i][j];}}
	for(i=1;i<=n;i++){
		k=0;
		for(i=0;i<=m;i++){
			k=k+alloc[i][j];
		}
		avl[i]=avl[i]-k;
		work[i]=avl[i];
	}
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			count=0;
			for(j=1;j<=m;j++){
				if((finish[i]='f')&&(need[i][j]<=work[i]))
					count++;
			}
		}
	}
	if(count==m){
		for(i=1;k=m;i++){
			work[i]=work[i]+alloc[i][1];
			finish[i]='t';
			pr[k]=i;
			break;
	        }
   	   	for(i=1;k=n;i++);
			printf("%d",pr[i]);
	}
	else
		printf("system is not in safe state");

}
