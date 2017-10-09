#include<stdio.h>
int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n,r;
void input();
void show();
void cal();
int main()
{
int i,j;
printf("banker's algorithm\n");
input();
show();
cal();
return 0;
}
void input()
{
int i,j,c;
printf("enter no. of processes\n");
scanf("%d",&n);
printf("enter no of resource instances\n");
scanf("%d",&r);
printf("enter the maximum matrix\n");
for(i=0;i<n;i++)
{
for(j=0;j<r;j++)
{
scanf("%d",&max[i][j]);
}
}
printf("enter the allocation matrix\n");
for(i=0;i<n;i++)
{
for(j=0;j<r;j++)
{
scanf("%d",&alloc[i][j]);
}
}
printf("enter the available resources\n");
for(j=0;j<r;j++)
{
scanf("%d", &avail[j]);
}
}
void show()
{
int i,j;
printf("procees\tallocation\tmax\tavailable");
for(i=0;i<n;i++)
{
printf("\np[%d]\t",i+1);
for(j=0;j<r;j++)
{
printf("%d",alloc[i][j]);
}
printf("\t");
for(j=0;j<r;j++)
{
printf("%d",max[i][j]);
}
printf("\t");
if(i=0)
{
for(j=0;j<r;j++)
{
printf("%d",avail[j]);
}
}
}
}
void cal()
{
int finish[100],temp,need[100][100],flag=1,k,c1=0;
int safe[100];
int i,j;
for(i=0;i<n;i++)
{
finish[i]=0;
}
//finish need matrix
for(i=0;i<n;i++)
{
for(j=0;j<r;j++)
{
need[i][j]=max[i][j]-alloc[i][j];
}
}
printf("\n");
while(flag)
{
flag=0;
for(i=0;i<n;i++)
{
int c=0;
for(j=0;j<r;j++)
{
if((finish[i]==0)&&(need[i][j]==avail[j]))
{
c++;
if(c==r)
{
for(k=0;k<r;k++)
{
avail[k]+=alloc[i][j];
finish[i]=1;
flag=1;
}
printf("p[%d]->",i);
if(finish[i]==1)
{
i=n;
}
}
}
}

}
}
int c = 0;
for(i=0;i<n;i++)
{
if(finish[i]==1)
{
c++;
}
else
{
printf("p[%d]->",i);
}
}
if(c==n)
{
printf("system is in safe state\n");
}
else
{
printf("\n process are in dead lock\n");
printf("system is in unsafe state\n");
}
}
































