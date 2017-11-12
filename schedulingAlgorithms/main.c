#include<stdio.h>
#include<stdlib.h>

struct process{
	int pid;
	int timeNeeded;
	int timeAllotted;
	int waitingTime;
	int priority;
	int arrivalTime;
}processes[30];

int iindex = 0;
int totalTime = 0;

void printit(){
	for(int i=0; i<iindex; i++){
		printf("i: %d\n", i);
		printf("pid: %d, timeNeeded: %d, timeAllotted: %d, waitingTime: %d, priority: %d, arrivalTime: %d\n", processes[i].pid, processes[i].timeNeeded, processes[i].timeAllotted, processes[i].waitingTime, processes[i].priority, processes[i].arrivalTime);
	}
}

void roundRobin(int btime){
	printf("\nRound Robin\n");
	int j = 0;
	int i = 0;
	int flag = 0;
	while(flag<iindex){
		if(processes[i].timeNeeded>0){
			processes[i].timeAllotted += (processes[i].timeNeeded - btime)>=0? (btime):processes[i].timeNeeded;
			j = i+1;
			while(j!=i){
				if(processes[j].timeNeeded>0){
					processes[j].waitingTime+= (processes[i].timeNeeded - btime)>=0? (btime):processes[i].timeNeeded;
				}
				j++;
				if(j>=iindex){
					j = 0;
				}
			}
			processes[i].timeNeeded = (processes[i].timeNeeded - btime)>=0? (processes[i].timeNeeded-btime):0;
			if(processes[i].timeNeeded < 1){
				flag++;
				printf("Flag: %d, iindex: %d, i: %d\n", flag, iindex, i); 
			}
		}
		i++;
		i = i%iindex;
	}
	printit();
}

void addProcess(int arrivalTime, int timeNeeded, int priority){
	processes[iindex].pid = iindex;
	processes[iindex].timeNeeded = timeNeeded;
	processes[iindex].timeAllotted = 0;
	processes[iindex].waitingTime = 0;
	processes[iindex].priority = priority;
	processes[iindex].arrivalTime = arrivalTime;
	iindex++;
}

void fcfs(){
	printf("\nFCFS\n");
	for(int i=0; i<iindex; i++){
		processes[i].timeAllotted = processes[i].timeNeeded;
		if(processes[i].arrivalTime>totalTime){
			processes[i].waitingTime = 0;
		}
		else{
			processes[i].waitingTime = totalTime - processes[i].arrivalTime;
		}
		totalTime += processes[i].timeNeeded;
	}
	printit();
}

void sjf(){
	printf("\nSJF\n");
	for(int i = 0; i<iindex; i++){
		for(int j = i+1; j<iindex; j++){
			if(processes[i].timeNeeded>processes[j].timeNeeded){
				struct process process1 = processes[i];
				processes[i] = processes[j];
				processes[j] = process1;
			}
		}
	}
	for(int i = 0; i<iindex; i++){
		processes[i].timeAllotted = processes[i].timeNeeded;
		if(processes[i].arrivalTime>totalTime){
			processes[i].waitingTime = 0;
			totalTime = 0;
		}
		else{
			processes[i].waitingTime = totalTime - processes[i].arrivalTime;
		}
		totalTime += processes[i].timeNeeded;
	}
	printit();
}

void priority(){
	printf("\nPriority\n");
	for(int i = 0; i<iindex; i++){
		for(int j = i+1; j<iindex; j++){
			if(processes[i].priority<processes[j].priority){
				struct process process1 = processes[i];
				processes[i] = processes[j];
				processes[j] = process1;
			}
		}
	}
	for(int i = 0; i<iindex; i++){
		processes[i].timeAllotted = processes[i].timeNeeded;
		if(processes[i].arrivalTime>totalTime){
			processes[i].waitingTime = 0;
		}
		else{
			processes[i].waitingTime = totalTime - processes[i].arrivalTime;
		}
		totalTime += processes[i].timeNeeded;
	}
	printit();
}

int main(void){
	printf("Enter the number of processes: ");
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int arrivalTime;
		int timeNeeded;
		int priority;
		printf("Enter the arrivalTime, timeNeeded and priority of the process: ");
		scanf("%d %d %d", &arrivalTime, &timeNeeded, &priority);
		addProcess(arrivalTime, timeNeeded, priority);
	}
//	fcfs();
//	sjf();
//	roundRobin(2);
	priority();
	return 0;
}
