/*****************************************************************
Joseph Ashwin Kottapurath
33, S5R, CSE
*****************************************************************/
#include<stdio.h>
#include<stdlib.h>


int mutex=1, full=0, x[4], empty=5, j=0, i=0;

int wait (int s){
	return (--s);
}

int signal(int s){
	return(++s);
}

void producer(){
	empty=wait(empty);
	mutex=wait(mutex);
	if(i!=5){
		x[i++]=i;
		printf("\n producer item %d",i);
	}
	else
		printf("buffer is full!\n");
	mutex=signal(mutex);
	full=signal(full);
}

void consumer(){
	full=wait(full);
	mutex=wait(mutex);
	if(i!=j){
		printf("\n consumer consumes item %d",++j);
	}
	else
		printf("buffer is empty\n");
	mutex=signal(mutex);
	empty=signal(empty);
}

int main(){

	int n;

	do{
		printf("\n1.producer\n2.consumer\n3.exit\n");
		printf("enter your choice\n");
		scanf("%d",&n);
		switch(n){
			case 1:if((mutex==1)&&(empty!=0))
					producer();
				else
					printf("buffer is full!\n");
			break;
			case 2:
				if((mutex==1)&&(full!=0))
					consumer();
				else
					printf("buffer is empty\n");
			break;
			case 3:
			break;
			default:printf("enter a valid choice\n");
		}
	}while(n!=3);
}
