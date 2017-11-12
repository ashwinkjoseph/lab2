//Joseph Ashwin Kottapurath
//33 S5R
//Scheduling Algorithm
#include<stdio.h>
void main()
{
int n,a[20],b[10],t[10],w[10],temp[10],i,j,m,c=0,q=10,p[20],tem;
int time=0,s,ch;
int bt[20],wt[20],tat[20],pr[20],total=0,pos;
float att=0,awt=0;
double avg_wt,avg_tat;
int remain,flag=0,ts,e;
int sum_wait=0,sum_turnaround=0,at[10],rt[10];
do
{
att = 0;
awt = 0;
avg_wt = 0;
avg_tat = 0;
remain = 0;
ts = 0;
printf("menu\n*********\n1:fcfs\n2:sjfs\n3:roundrobin\n4:priority\n5:exit\n");
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:

for(i=0;i<n;i++)
{
a[i]=0,b[i]=0,w[i]=0;
temp[i]=0;
}
printf("enter no. of process\n");
scanf("%d",&n);
printf("enter burst time\n");
for(i=0;i<n;i++)
scanf("%d",&b[i]);
printf("enter arrivaltime\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);

for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
{
c=a[j];
a[j]=a[j+1];
a[j+1]=c;

q=b[j];
b[j]=b[j+1];
b[j+1]=q;
}
}
}
temp[0]=0;//temp

for(i=0;i<n;i++)
temp[i+1]=temp[i]+b[i];
w[0]=0;
for(i=1;i<n;i++)
{
w[i]=temp[i]-a[i];
awt=awt+w[i];
}
for(i=0;i<n;i++)
{
t[i]=temp[i+1]-a[i];
att=att+t[i];
}

awt=awt/n;
att=att/n;
printf("\n\tprocess\twaitingtime\tturnaroundtime\n");
for(i=0;i<n;i++)
{
printf("\tp[%d]\t\t%d\t%d\n",i,w[i],t[i]);
}
printf("average waitingtime is %f\n",awt);
printf("average turnaroundtime is %f\n",att);
//return 0;
break;


case 2:

for(i=0;i<n;i++)
{
a[i]=0,b[i]=0,w[i]=0;
temp[i]=0,t[i]=0;
}
printf("enter no. of process\n");
scanf("%d",&n);
printf("enter burst time\n");
for(i=0;i<n;i++)
scanf("%d",&b[i]);
printf("enter arrivaltime\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);

for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(b[j]>b[j+1])
{
c=a[j];
a[j]=a[j+1];
a[j+1]=c;

q=b[j];
b[j]=b[j+1];
b[j+1]=q;
}
}
}
time=0;
for(i=0;i<n;i++)
{
if(a[i]>time)
{
j=j+1;
while(a[j]>time)
{
j++;
}
m=a[j];
s=b[j];
while(j>i)
{
a[j]=a[j-1];
b[j]=b[j-1];
}
a[j]=m;
b[j]=s;
}
time=time+b[i];
}

temp[0]=0;//temp

for(i=0;i<n;i++)
temp[i+1]=temp[i]+b[i];
w[0]=0;
for(i=1;i<n;i++)
{
w[i]=temp[i]-a[i];
awt=awt+w[i];
}
for(i=0;i<n;i++)
{
t[i]=temp[i+1]-a[i];
att=att+t[i];
}

awt=awt/n;
att=att/n;
printf("\n\tprocess\twaitingtime\tturnaroundtime\n");
for(i=0;i<n;i++)
{
printf("\tp[%d]\t\t%d\t%d\n",i,w[i],t[i]);
}
printf("average waitingtime is %f\n",awt);
printf("average turnaroundtime is %f\n",att);
//return 0;
break;

case 3:

printf("enter no. of processes\n");
scanf("%d",&n);
remain=n;
printf("enter the processes\n");
for(i=0;i<n;i++)
{
scanf("%d",&p[i]);
}
for(i=0;i<n;i++)
{
printf("enterbursttime for process p[%d]\n",i+1);
scanf("%d",&bt[i]);
//rt[i]=bt[i];
}
for(i=0;i<n;i++)
{
printf("enterarrivaltime for process p[%d]\n",i+1);
scanf("%d",&at[i]);
}
for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(at[j]>at[j+1])
{
c=at[j];
at[j]=at[j+1];
at[j+1]=c;

q=bt[j];
bt[j]=bt[j+1];
bt[j+1]=q;

e=p[j];
p[j]=p[j+1];
p[j+1]=e;
}
}
}
printf("enter time slice\n");
scanf("%d",&ts);
for(i=0;i<n;i++)
{
rt[i]=bt[i];
}

//printf("process\tturnaround\twaiting\n");
for(time=0,i=0;remain!=0;)
{
if(rt[i]<=ts&&rt[i]>0)
{

time+=rt[i];
rt[i]=0;
flag=1;
printf("p[%d]\t",p[i]);
}

else if(rt[i]>0)
{
rt[i]-=ts;
time+=ts;
printf("p[%d]\t",p[i]);
}

if(rt[i]==0&&flag==1)
{
remain--;  //n
//printf("p[%d]\t",i+1,time-at[i],time-at[i]-bt[i]);
sum_wait+=time-at[i]-bt[i];
sum_turnaround+=time-at[i];
flag=0;
}

if(i==n-1)
{
i=0;
}
else if(at[i+1]<=time)
{
i++;
}
else
{
i=0;
}
}//for
printf("\naverage waitingtime=%f\n",sum_wait*1.0/n);
printf("average turnaroundtime=%f\n",sum_turnaround*1.0/n);
//return 0;
break;

case 4:
printf("enter total no. of process\n");
scanf("%d",&n);
printf("enter burst time and priority\n");
for(i=0;i<n;i++)
{
printf("p[%d]=",i+1);
printf("bursttime:");
scanf("%d",&bt[i]);
printf("priority:");
scanf("%d",&pr[i]);
p[i]=i+1;
}
for(i=0;i<n;i++)
{
pos=i;
for(j=i+1;j<n;j++)
{
if(pr[j]<pr[pos])  //compares the position pos and priority or bursttime 
pos=j;
}
tem=pr[i];
pr[i]=pr[pos];
pr[pos]=tem;     //sorted priority

tem=bt[i];
bt[i]=bt[pos];
bt[pos]=tem;    //sorted bursttime

tem=p[i];
p[i]=p[pos];
p[pos]=tem;    //sorted process
}
wt[0]=0;//waiting time of first process is 0


for(i=1;i<n;i++)
{
wt[i]=0;
for(j=0;j<i;j++)
wt[i]+=bt[j];
total+=wt[i];
}
avg_wt=(float)total/n;  //av. waiting time
total=0;
printf("priority\tbursttime\twaitingtime\tturnaroundtime\n");
for(i=0;i<n;i++)
{
tat[i]=bt[i]+wt[i];
total+=tat[i];
printf("p[%d]\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
}
avg_tat=(float)total/n;
printf("average waitingtime=%f\n",avg_wt);
printf("average turnaroundtime=%f\n",avg_tat);
//return 0;
break;
case 5:printf("exit\n");
}//switch closes
}//do
while(ch<5);
}

