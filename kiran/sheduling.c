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
			printf("\n*************************\n");
			printf("BURST TIME:	ARRIVAL TIME:\n");
	                for(i=0;i<n;i++)
	                        printf("%d\t 	%d\t\n",bt[i],at[i]);
        do{

		printf("1.FCFS   2.SJF   3.RR   4.PRIORITY\n");
	        printf("Select your choice of process:");
	        scanf("%d",&choice);
		if(choice==1){

		        //sorting arrival time and also burst time
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
			wt[0]=0;//waiting time for first process is 0
			//calculating wt
			int k=0;
			for(i=1;i<n;i++){
				for(j=0;j<i;j++){
					wt[i]=k+bt[j];
					k+=wt[i];
					total+=wt[i];
				}
			}
			//calculating turn-around time
			for(i=0;i<n;i++){
				tat[i]=wt[i]+bt[i];
				total1+=tat[i];
			}
			/*avarage of turnaround as well as waiting time*/
			avwt=total/n;
			avtat=(total1/n);
			printf("\n**************************\n");
	                printf("BURST TIME:\n");
	                for(i=0;i<n;i++)
	                        printf(" %d,",bt[i]);
			printf("\nARRIVAL TIME:\n");
			for(i=0;i<n;i++)
				printf(" %d,",at[i]);
			printf("\nWAITING TIME:\n");
			for(i=0;i<n;i++)
				printf(" %d,",wt[i]);
			printf("\nTURN AROUND TIME:\n");
			for(i=0;i<n;i++)
				printf(" %d,",tat[i]);
			printf("\nAvarage waiting time:%d\nAvarage turn-around time:%d\n",avwt,avtat);
		}
		else if(choice==2){
			//shortest job first calculations
			printf("Enter no of processes:");
        	        scanf("%d",&n);
	                printf("Enter...\n");
	                for(i=0;i<n;i++){
	                        printf("\nburst time:");
	                        scanf("%d",&bt[i]);
                        	printf("\narrival time:");
                        	scanf("%d",&at[i]);
	                }
			printf("\nBURST TIME:");
			for(i=0;i<n;i++)
				printf("%d,",bt[i]);
			printf("\nARRIVAL TIME:");
			for(i=0;i<n;i++)
				printf("%d,",at[i]);
			//sorting arrival time and also burst time
                        for(i=0;i<n;i++){
                                for(j=i;j<n;j++){
                                        if(at[i]>at[j]){
                                                t=at[i];
                                                at[i]=at[j];
                                                at[j]=t;0
                                                t2=bt[i];
                                                bt[i]=bt[j];
                                                bt[j]=t2;
                                        }
                                }
                        }
	                printf("\n*********************************\n");
	                printf("\nBURST TIME:");
		        for(i=0;i<n;i++)
			                 printf("%d,",bt[i]);
			printf("\nARRIVAL TIME");
			for(i=0;i<n;i++)
					printf("%d,",at[i]);
			//calculating waiting time
			int min=0;
			for(i=0;i<n;i++){
				bt[0]=min;
				for(j=1;j<n;j++){
					if(bt[j]<min){
						min=bt[j];
						t=at[i];
						at[i]=at[j];
						at[j]=t;
			}	}	}	wt[i]=at[i];
		}
		else if(choice==3){
			//round robin calculations:read value(time quantum )to do calculation
			printf("Enter no of processes:");
                	scanf("%d",&n);
			int q;
			printf("\nInput Time Quantum:");
			scanf("%d",&q);
                	printf("Enter...\n");
                	for(i=0;i<n;i++){
                	        printf("\nburst time:");
                	        scanf("%d",&bt[i]);
 	               	        printf("\narrival time:");
                	        scanf("%d",&at[i]);
                	}
                	printf("\n*****************************\n");
                	printf("BURST TIME:     ARRIVAL TIME:\n");
			printf("Time Quantum:%d",q);
                	for(i=0;i<n;i++)
                	        printf("%d\t    %d\t\n",bt[i],at[i]);

		}
		else if(choice==4){
			//priority calculations:read extra priority array
			printf("Enter no of processes:");
		        scanf("%d",&n);
                	printf("Enter...\n");
                	for(i=0;i<n;i++){
                	        printf("\nBurst time:");
                	        scanf("%d",&bt[i]);
                	        printf("\nArrival time:");
                	        scanf("%d",&at[i]);
				printf("\nPriority:");
				scanf("%d",&prio[i]);
                	}
                	printf("\n*******************************\n");
                	printf("PRIORITY:	BURST TIME:     ARRIVAL TIME:\n");
                	for(i=0;i<n;i++)
                	        printf("%d\t    %d\t	%d\t\n",prio[i],bt[i],at[i]);
                        //sorting arrival time and also burst time
                        for(i=0;i<n;i++){
                                for(j=i;j<n;j++){
                                        if(at[i]>at[j]){
                                                t=at[i];
                                                at[i]=at[j];
                                                at[j]=t;
                                                t=bt[i];
                                                bt[i]=bt[j];
                                                bt[j]=t;
						t=prio[i];
						prio[i]=prio[j];
						prio[j]=t;
                                        }
                                }
                        }
			for(i=0;i<n;i++){
				for(j=i;j<n;j++){
					if(prio[i]>prio[j]){
						t2=prio[i];
						prio[i]=prio[j];
						prio[j]=t2;
					}
				}
			}
			//calculating waiting time
		}
		else{
			printf("Invalid choice\n");
		}
	printf("Do you wish to continue?(0/1):");
	scanf("%d",&choice1);
	}while(choice1==1);


}

