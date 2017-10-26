//sheduling algorithm
#include<stdio.h>
void main()
{
        int bt[10],at[10],wt[10],p[10],prio[10],tat[10];
        int i,j,t2,choice,n,x,t,avtat=0,total=0,total1=0,avwt=0;
        int choice1;
        printf("\t::Sheduling Algorithm Time Calculation::\n");
        printf("Enter no of processes:");
        scanf("%d",&n);
        printf("Enter...\n");
        for(i=0;i<n;i++){
             printf("\nburst time:");
             scanf("%d",&bt[i]);
             printf("\narrival time:");
             scanf("%d",&at[i]);
        }
        printf("Select your choice of process:");
	printf("1.FCFS   2.SJF   3.RR   4.PRIORITY\n");
	scanf("%d",&choice);
	if(choice==1){
		//sorting op
        	for(i=0;i<n;i++){
       		     for(j=i;j<n;j++){
        	        if(at[i]>at[j]){
                	   t=at[i];
               	 	   at[i]=at[j];
                	   at[j]=t;
               		   t2=bt[i];
               		   bt[i]=bt[j];
                  	   bt[j]=t2;
                        }
                     }
                }

	}
	else if(choice==2){
