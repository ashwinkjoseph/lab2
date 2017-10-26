//Reshma Joshy
//roll no.:49
//S4R
//Program:Scheduling Algorithms
#include<stdio.h>
void cal(int at[],int bt[],int *n)
{
  int i,j,wt[20],tat[20];
  double avwt,avtat;
  wt[0]=0;
  for(i=0;i<*n;i++)
  {
    wt[i]=0;
    for(j=0;j<i;j++)
    {
      wt[i]=wt[i]+bt[j];
    }
  }
  for(i=0;i<*n;i++)
  {
    wt[i]=wt[i]-at[i];
    tat[i]=bt[i]+wt[i];
    avwt=avwt+wt[i];
    avtat=avtat+tat[i];
  }
  avwt=avwt*1.0/(*n);
  avtat=avtat*1.0/(*n);
  printf("\nWaiting time=%f",avwt);
  printf("\nTurnaround time=%f",avtat);
}
void main()
{
  int n,at[20],bt[20],p[20],s,t,u,ch,i,j,tq,rt[20],remain,time,c;
  do{
  printf("Enter the no. of processes  ");
  scanf("%d",&n);
  printf("Menu\n1.FCFS 2.SJF 3.RoundRobin 4.Priority 5.Exit\nEnter your choice");
  scanf("%d",&ch);
  if(ch==1)
    {
    for(i=0;i<n;i++)
    {
    printf("\nEnter the arrival time of process %d : ",i+1);
    scanf("%d",&at[i]);
    printf("Enter the burst time of process %d : ",i+1);
    scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++)
     {
       for(j=0;j<n-i-1;j++)
        {
          if(at[j]>at[j+1])
          {
            t=at[j];
            s=bt[j];
            at[j]=at[j+1];
            bt[j]=bt[j+1];
            at[j+1]=t;
            bt[j+1]=s;
          }
        }
     }
     cal(at,bt,&n);
  }
  else if(ch==2)
  {
    for(i=0;i<n;i++)
    {
    printf("\nEnter the arrival time of process %d :",i+1);
    scanf("%d",&at[i]);
    printf("Enter the burst time of process %d : ",i+1);
    scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++)
     {
       for(j=0;j<n-i-1;j++)
        {
          if(bt[j]>bt[j+1])
          {
            t=at[j];
            s=bt[j];
            at[j]=at[j+1];
            bt[j]=bt[j+1];
            at[j+1]=t;
            bt[j+1]=s;
          }
        }
     }
  time=0;
  for(i=0;i<n-1;i++)
  {
    if(at[i]>time)
    {
      j=i+1;
      while(at[j]>time)
       { j++; }
      t=at[j];
      s=bt[j];
      while(j>i)
       {
          at[j]=at[j-1];
          bt[j]=bt[j-1];
          j--;
       }
      at[j]=t;
      bt[j]=s;
    }
    time=time+bt[i];
  }
  cal(at,bt,&n);
  }
  else if(ch==3)
  {
    int flag=0,wt1=0,tat1=0,pr[20],v;
    remain=n;
    for(i=0;i<n;i++)
    {
    printf("\nEnter the arrival time of process %d : ",i+1);
    scanf("%d",&at[i]);
    pr[i]=i+1;
    printf("Enter the burst time of process %d : ",i+1);
    scanf("%d",&bt[i]);
    }
    printf("Enter the time quantum\n");
    scanf("%d",&tq);
    for(i=0;i<n;i++)
     {
       for(j=0;j<n-i-1;j++)
        {
          if(at[j]>at[j+1])
          {
            t=at[j];
            s=bt[j];
            v=pr[j];
            at[j]=at[j+1];
            bt[j]=bt[j+1];
            pr[j]=pr[j+1]; 
            at[j+1]=t;
            bt[j+1]=s;
            pr[j+1]=v;
          }
        }
     }
    for (i=0;i<n;i++)
    {
          rt[i]=bt[i];
    }
    for(time=0,i=0;remain!=0;)
    {
      if(rt[i]<=tq && rt[i]>0)
      { 
        time+=rt[i];
        rt[i]=0;
        flag=1;
        printf("P%d ",pr[i]);
      }
      else if(rt[i]>0)
       {
         rt[i]-=tq;
         time+=tq;
         printf("P%d ",pr[i]);
       }
      if(rt[i]==0 && flag==1)
        {
          remain--;
          wt1+=time-at[i]-bt[i];
          tat1+=time-at[i];
          flag=0;
        }
      if(i==n-1)
      {
        i=0;
      }
      else if(at[i+1]<=time)
         {i++;}
      else
         {i=0;}
    }
   printf("\nWaiting time=%f",(wt1*1.0/n));
   printf("\nTurnaround time=%f\n",(tat1*1.0/n));
  }
  else if(ch==4)
    {
    for(i=0;i<n;i++)
    {
    printf("\nEnter the arrival time of process %d:  ",i+1);
    scanf("%d",&at[i]);
    printf("Enter the burst time of process %d:  ",i+1);
    scanf("%d",&bt[i]);
    printf("Enter the priority of process %d:  ",i+1);
    scanf("%d",&p[i]);
    }
    for(i=0;i<n;i++)
     {
       for(j=0;j<n-i-1;j++)
        {
          if(p[j]>p[j+1])
          {
            t=at[j];
            s=bt[j];
            u=p[j];
            at[j]=at[j+1];
            bt[j]=bt[j+1];
            p[j]=p[j+1];
            at[j+1]=t;
            bt[j+1]=s;
            p[j+1]=u;
          }
        }
     }
  time=0;
  for(i=0;i<n-1;i++)
  {
    if(at[i]>time)
    {
      j=i+1;
      while(at[j]>time)
       { j++; }
      t=at[j];
      s=bt[j];
      u=p[j];
      while(j>i)
       {
          at[j]=at[j-1];
          bt[j]=bt[j-1];
          p[j]=p[j-1];
          j--;
       }
      at[j]=t;
      bt[j]=s;
      p[j]=u;
    }
    time=time+bt[i];
  }
  cal(at,bt,&n);
  }
 else
{}
if(ch<5)
 {
   printf("\nDo you want to continue?(1.yes 2.no)");
   scanf("%d",&c);
 }
}while(c==1);
}
