#include<stdio.h>
#include<stdlib.h>

struct process{
	int pid;
	int bt;
	int at;
}proc[10];
int limit, prio[10];

void display(){
	printf("\n\tPID\tBT\tAT\n");
	for(int i=0; i<limit; i++){
		printf("\t%d\t%d\t%d\n", proc[i].pid, proc[i].bt, proc[i].at);
	}
}

void roundRobin(){
	int remb[10], quan, wt[10];
	int i = 0;
	for(i=0; i<limit; i++){
		remb[i] = proc[i].bt;
	}
	printf("Enter the time quantum: ");
	scanf("%d", &quan);
	int t1, t2, t3;
	for(i=0; i<limit; i++){
		for(int j = i; j<limit; j++){
			if(proc[i].at>proc[j].at){
				t1 = proc[i].at;
				proc[i].at = proc[j].at;
				proc[j].at = t1;
				t2 = proc[i].bt;
				proc[i].bt = proc[j].bt;
				proc[j].bt = t2;
				t3 = proc[i].pid;
				proc[i].pid = proc[j].pid;
				proc[j].pid = t3;
				t1 = remb[i];
				remb[i]=remb[j];
				remb[j] = t1;
			}
		}
	}
	printf("\n\n");
	int t=0, done;
	while(1){
		done = 1;
		for(i = 0; i<limit; i++){
			if(remb[i]>0){
				done = 0;
				if(remb[i]>quan){
					t=t+quan;
					remb[i]=remb[i]-quan;
				}
				else{
					t+=quan;
					remb[i]=0;
					wt[i]=t-proc[i].bt-proc[i].at;
				}
				printf("P%d\t", proc[i].pid);
			}
		}
		if(done==1){
			break;
		}
	}
}

void main(){
	int choice;
	printf("\nEnter number of processes\n");
	scanf("%d", &limit);
	for(int i=0; i<limit; i++){
		printf("\nPROCESS %d: ", i+1);
		proc[i].pid = i+1;
		printf("\nEnter Burst Time: ");
		scanf("%d", &proc[i].bt);
		printf("\nEnter Arrival Time: ");
		scanf("%d", &proc[i].at);
	}
	display();
	roundRobin();
}
