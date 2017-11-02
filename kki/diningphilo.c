//kiran.k.k
//S5R
//classno: 34
//dining phelosopher problem


#include <stdio.h>
#define n 4
int c=0,i;
struct fork
{
    int taken;
}avail[n];

struct philosopher
{
    int left;
    int right;
}philostatus[n];

void gofordinner(int pid)
{
if((philostatus[pid].left==10)&&(philostatus[pid].right==10))
{

}
else
    if((philostatus[pid].left==1)&&(philostatus[pid].right==1))
{
printf("\nphilosopher %d completed dinner",pid+1);
philostatus[pid].left=philostatus[pid].right=10;
int otherfork=pid-1;
if(otherfork==-1)
    otherfork=n-1;
avail[pid].taken=avail[otherfork].taken=0;
printf("\nphilosopher %d released fork %d and %d",pid+1,pid+1,otherfork+1);
c++;
}
else
    if((philostatus[pid].left==1)&&(philostatus[pid].right==0))
{
    if(pid==n-1)
    {
        if(avail[pid].taken==0)
        {
            avail[pid].taken=philostatus[pid].right=1;
            printf("\n philosopher %d taken %d fork",pid+1,pid+1);
            printf("\n philosopher %d is thinking",pid+1);

        }
    }
    else
    {
        int dup=pid;
        pid-=1;
        if(pid==-1)
            pid=n-1;
        if(avail[pid].taken==0)
        {
            avail[pid].taken=philostatus[dup].right=1;
            printf("\n fork %d taken by philosopher %d",pid+1,dup+1);
               printf("\n philosopher %d is eating",dup+1);
        }
        else
        {
            printf("\n philosopher %d waiting for fork %d",dup+1,pid+1);
             printf("\n philosopher %d is hungry",dup+1);
        }

    }
}
else if(philostatus[pid].left==0)
{
if(pid==n-1)
{
    if(avail[pid-1].taken==0)
    {
        avail[pid-1].taken=philostatus[pid].left=1;
        printf("\n fork %d taken by philosopher %d",pid+1,pid);
        printf("\n philosopher %d is thinking",pid);
    }
    else
    {
        printf("\n philosopher %d waiting for fork %d",pid+1,pid);
             printf("\n philosopher %d is hungry",pid+1);
    }
}
else
{
    if(avail[pid].taken==0)
    {
        avail[pid].taken=philostatus[pid].left=1;
        printf("\n fork %d taken by philosopher %d",pid+1,pid+1);
        printf("\n philosopher %d is thinking",pid+1);
    }
    else
    {
          printf("\n philosopher %d is waiting",pid+1);
            printf("\n philosopher %d is hungry",pid+1);
    }
}
}
else
{}
}
void main()
{
    for(i=0;i<n;i++)
        avail[i].taken=philostatus[i].left=philostatus[i].right=0;
    c=0;
    while(c<n)
    {
        for(i=0;i<n;i++)
        gofordinner(i);
    }
}

