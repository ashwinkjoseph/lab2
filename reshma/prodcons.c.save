//NAME:RESHMA JOSHY
//ROLL NO:49
//BATCH:S5R
//PROGRAM:PRODUCER-CONSUMER PROBLEM
#include<stdio.h>
#include<stdlib.h>
int x=0,ch,mutex=1,full=0,empty,a[20],i;
int wait(int s)
{
	return --s;
}
int signal(int s)
{
	return ++s;
}
void produce()
{
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	printf("\nEnter the item   :  ");
	scanf("%d",&a[x]);
	x++;
	printf("\nProducer produced  item %d",a[x]);
	mutex=signal(mutex);
}
void consume()
{
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("\nConsumer consumed item %d",a[0]);
	for(i=0;i<x;i++)
			a[i]=a[i+1];
	x--;
	mutex=signal(mutex);
}
void main()
{
	printf("\nEnter buffersize  :  ");
		scanf("%d",&empty);
	do{
		printf("\nMENU\n1.Produce an item   2.Consume an item   3.Exit \nEnter your choice   :  ");
		scanf("%d",&ch);
		if(ch==1)
			{
				if((mutex==1) && (empty!=0))
				{
					produce();
				}
				else
				{
					printf("\nFull buffer. Can't produce more  ");
				}
			}
	else if(ch==2)
			{
				if((mutex==1) && (full!=0))
					consume();
				else
				{
					printf("\nEmpty buffer. Can't consume");
				}
			}
	}while(ch<3);
}
