/*
Joseph Ashwin Kottapurath
S5R, 33,
Banker's Algorithm
*/

#include<stdio.h>
void main()
{
	int n,m,max[20][20],need[20][20],alloc[20][20],avail[20],i,j,k=0,t,pr[20],x=0,y,flag,maxim[20];
	printf("Enter the no. of processes  :  ");
	scanf("%d",&n);
	printf("\nEnter the no. of resources  :  ");
	scanf("%d",&m);
  printf("Enter the maximun no. of each resources    :  ");
	for(i=0;i<m;i++)
	{
		scanf("%d",&maxim[i]);
	}
	printf("Enter the maximum no. of each resources required by the processes : ");
	for(i=0;i<n;i++)
	{
		printf("\nEnter maximum no. of resouces for process %d  :",i+1);
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter the no. of each resources allocated by the processes : ");
	for(i=0;i<n;i++)
	{
		printf("\nEnter no. of allocated resouces for process %d  :",i+1);
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}

	for(i=0;i<m;i++)
		avail[i]=maxim[i];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			avail[j]-=alloc[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(maxim[j]<max[i][j])
				flag=1;
			else
				flag=0;
		}
	}
	if(flag==0){
	for(i=0;i<n;i++)
	{ 
		t=0;
		for(j=0;j<m;j++)
		{
			if(need[i][j]==0)
				t++;
			else if(need[i][j]>avail[j])
				break;
		}
		if(j==m && t<m)
		{
			for(j=0;j<m;j++)
			{
				avail[j]+=alloc[i][j];
				need[i][j]=0;
			}
			k++;
			pr[x]=i+1;
			x++;
			y=0;
		}
		else
				y++;
		if(y>n)
			break;
		if(k==n)
			break;
		if(i==n-1)
			i=-1;
	}
	if(x<n-1)
		printf("\nProcess is not in a safe state\n");
	else
	{
		printf("\nProcess is in a safe state and the safe sequence is    ");
		for(i=0;i<n;i++)
			printf("P%d\t",pr[i]);
	}
	}
	else
		printf("\nNo. of resources required by process is greater than total no. of resources");
}
