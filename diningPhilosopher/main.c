#include<stdio.h>
#define n 4

int c=0, i;
struct fork{
	int t;
}f[n];

struct philosopher{
	int left;
	int right;
}pstat[n];

void gofordinner(int pid){
	if((pstat[pid].left==10)&&(pstat[pid].right==10)){
		printf("\nphilosopher %d completed dinner\n", pid+1);
	}
	else if((pstat[pid].left==1)&&(pstat[pid].right==1)){
		printf("\nphilosopher %d completed dinner\n", pid+1);
		pstat[pid].left=pstat[pid].right=10;
		int ofork=pid-1;
		if(ofork==1){
			ofork = n-1;
		}f[pid].t = f[ofork].t = 0;
		printf("\nphilosopher %d released fork %d and %d\n", pid+1,pid+1, ofork+1);
		c++;
	}
	else if((pstat[pid].left==1)&&(pstat[pid].right==0)){
		if(pid==(n-1)){
			if(f[pid].t == 0){
				f[pid].t = pstat[pid].right = 1;
				printf("\nfork %d taken by philosopher %d\n", pid+1, pid+1);
			}
			else{
				printf("\nphilosopher %d waiting for fork %d\n", pid+1, pid+1);
			}
		}
		else{
			int did = pid;
			pid -= 1;
			if(pid==-1){
				pid = n-1;
			}
			if(f[pid].t==0){
				f[pid].t = pstat[did].right = 1;
				printf("\nfork %d taken by philosopher %d\n", pid+1, did+1);
			}
			else{
				printf("\nphilosopher %d is waiting for fork %d\n", did+1, pid+1);
			}
		}
	}
	else if(pstat[pid].left==0){
		if(pid==(n-1)){
			if(f[pid-1].t==0){
				f[pid-1].t = pstat[pid].left = 1;
				printf("\nfork %d taken by philosopher %d\n", pid+1, pid+1);
			}
			else{
				printf("\nphilosopher %d is waiting for fork %d\n", pid+1, pid+1);
			}
		}
		else{
			if(f[pid].t==0){
				f[pid].t=pstat[pid].left=1;
				printf("\nfork %d taken by philosopher %d\n", pid+1, pid+1);
			}
			else{
				printf("\nphilosopher %d is waiting for fork %d\n", pid+1, pid+1);
			}
		}
	}
}

int main(){
	for(i=0; i<n; i++){
		f[i].t = pstat[i].left = pstat[i].right = 0;
	}
	while(c<n){
		for(i=0; i<n; i++){
			gofordinner(i);
		}
		printf("\nphilosopher %d has completed eating\n",c);
	}
	return 0;
}
