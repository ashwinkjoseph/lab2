//Kiran.k.k
//Classno:34
//S5R
//Implimenting Producer Consumer problem.
#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty,x=0,y,i,j,a[10];
int main()
{
	int n,b,ch;
	void producer();
	void consumer();
	int wait(int);
	int signal(int);
	printf("\nenter buffer size:");
	scanf("%d",&b);
	empty=b;
	j=b;
	do{
		printf("\n1.producer\n2.consumer\n3.exit\n");
		printf("\nenter choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1: if((mutex==1)&&(empty!=0)){
					producer();
				}
				else
					printf("\nBuffer is FULL");
				break;
			case 2: if((mutex==1)&&(full!=0)){
					 consumer();
				}
				else
					printf("\nBuffer EMPTY");
				break;
			case 3: exit(0);
			default : printf("\ninvalid option");
		}
	}while(1);
		return 0;
}

int wait(int s){
	return(--s);
}

int signal(int s){
	return (++s);
}
void producer(){
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	printf("\nEnter item to be produced:");
	x++;
	scanf("%d",&a[x]);
	printf("\nitem %d produced",a[x]);
	mutex=signal(mutex);
}

void consumer(){
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("\nconsumer consumed item %d",a[1]);
	for(i=0;i<x;i++)
		a[i]=a[i+1];
	x--;
	mutex=signal(mutex);
}
