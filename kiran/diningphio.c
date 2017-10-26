#include<stdio.h>
#define n 4
int completedphilo=0,i;
struct fork{
	int taken;
}forkavil[n];
struct philosp{
	int left;
	int right;
}philostatus[n];
void gofordinner(int philid){
	if(philostatus[philid].left==10 && philostatus[philid].right==10){
		printf("philosopher %d completed his dining\n",philid+1);
	}
	else if(philostatus[philid].left==1 && philostatus[philid].right==1){
		printf("philosopher %d completed his dinner\n",philid+1);
		philostatus[philid].left=philostatus[philid].right=10;
		int otherfork=(philid-1);
		if(otherfork==(-1)){
			otherfork=(n-1);
			forkavil[philid].taken=forkavil[otherfork].taken=0;
			printf("philosopher %d released fork %d and fork %d\n",philid+1,philid+1,otherfork+1);
			completedphilo+=1;
			printf("\n\n*%d",completedphilo);
		}
	}
	else if(philostatus[philid].left==1 && philostatus[philid].right==0){
		if(philid==(n-1)){
			if(forkavil[philid].taken==0){
				forkavil[philid].taken=philostatus[philid].right=1;
				printf("fork %d taken by the philosopher %d\n",philid+1,philid+1);
			}
			else{
				printf("philosopher %d is waitingfor fork %d\n",philid+1,philid+1);
			}
		}else{
			int dupphilid=philid;
			philid-=1;
			if(philid=(-1)){
				philid=(n-1);
			}
			if(forkavil[philid].taken==0){
				forkavil[philid].taken=philostatus[dupphilid].right=1;
				printf("fork %d taken by philosopher %d\n",philid+1,dupphilid+1);
			}
			else{
				printf("philosopher %d is waiting for fork %d\n",dupphilid+1,philid+1);

			}
		}
	}
	else if(philostatus[philid].left==0){
		if(philid==(n-1)){
			if(forkavil[philid-1].taken==0){
				forkavil[philid-1].taken=philostatus[philid].left=1;
				printf("fork %d taken by philosopher %d\n",philid,philid+1);
			}
			else{
				printf("philosopher %d is waiting for fork %d\n",philid+1,philid);
			}
		}
		else{
			if(forkavil[philid].taken==0){
				forkavil[philid].taken=philostatus[philid].left=1;
				printf("fork %d taken by philosopher %d\n",philid+1,philid+1);
			}
			else{
				printf("philosopher %d is waiting for fork %d\n",philid+1,philid+1);
			}
		}
	}
	else{}
}

int main(){
	for(i=0;i<n;i++){
		forkavil[i].taken=philostatus[i].left=philostatus[i].right=0;
	}
	while(completedphilo<n){
			for(i=0;i<n;i++)
				gofordinner(i);
			printf("\ntill now no. of philosophers completed dining are %d\n",completedphilo);
	}
	/*gofordinner(0);
	gofordinner(1);
	gofordinner(2);
	gofordinner(3);
	gofordinner(4);
*/
	return 0;


}
