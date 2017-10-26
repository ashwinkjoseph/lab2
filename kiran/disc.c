#include<stdio.h>
void main()
{
	int ch,n,i,j,c[25],h,temp,x,hm,dif,start,end,choice;
	do{
	printf("\n**********************************\n\n");
	printf("\nMENU\n1.FCFS   2.SCAN   3.C-SCAN 4.EXIT\nEnter your choice   :  ");
	scanf("%d",&ch);
	if(ch<4){
	printf("Enter the no. of cyllinders    :  ");
	scanf("%d",&n);
	printf("Enter start,end positions");
	scanf("%d,%d",&start,&end);
	printf("Enter the cyllinder positions \n");
	for(i=0;i<n;i++)
		scanf("%d",&c[i]);
	printf("Enter current head position   : ");
	scanf("%d",&h);
	hm=0;
	}
	if(ch==1)
	{
		printf("Order of disk scheduling is \n");
		for(i=0;i<n;i++)
		{
			if(c[i]>=h)
			{
				dif=c[i]-h;
				hm+=dif;
				h=c[i];
				printf("%d\t",c[i]);
			}
			else
			{
				dif=h-c[i];
				hm+=dif;
				h=c[i];
				printf("%d\t",c[i]);
			}
		}
		printf("\nTotal head movement:  %d\n",hm);
	}
	else if(ch==2)
	{
		for(i=0;i<n;i++)
  	{
 	 		for(j=0;j<n-i-1;j++)
   		{
   			if(c[j]>c[j+1])
    		{
      		temp=c[j];
					c[j]=c[j+1];
					c[j+1]=temp;
      	}
			}
		}
		printf("Order of disk scheduling is \n");
		i=0;
		while(c[i]<h)
			i++;
		if((end-h)<(h-start))
		{
			x=i;
			for(i=x;i<n;i++)
			{   printf("%d\t",c[i]);
					dif=c[i]-h;
					hm+=dif;
					h=c[i];
			}
			dif=end-h;
			hm+=dif;
			h=end;
			for(j=x-1;j>=0;j--)
			{
					dif=h-c[i];
					hm+=dif;
					printf("%d\t",c[i]);
					h=c[i];
			}
		}
		else
		{
			if(c[i]==h)
				x=i;
			else
				x=i-1;
			for(j=x;j>=0;j--)
			{
					dif=h-c[j];
					hm+=dif;
					h=c[j];
					printf("%d\t",c[j]);
			}
			dif=h-start;
			hm+=dif;
			h=start;
			for(i=x+1;i<n;i++)
			{
					dif=c[i]-h;
					hm+=dif;
					h=c[i];
					printf("%d\t",c[i]);
			}
		}
	printf("\nHead movement =   %d\n",hm);
	}
	else if(ch==3)
	{
		for(i=0;i<n;i++)
  	{
 	 		for(j=0;j<n-i-1;j++)
   		{
   			if(c[j]>c[j+1])
    		{
      		temp=c[j];
					c[j]=c[j+1];
					c[j+1]=temp;
      	}
			}
		}
		i=0;
		while(c[i]<h)
			i++;
		if((end-h)>(h-start))
		{
			x=i;
			for(i=x;i<n;i++)
			{
					dif=c[i]-h;
					hm+=dif;
					h=c[i];
					printf("%d\t",c[i]);
			}
			dif=end-h;
			hm+=dif;
			h=start;
			hm=hm+end-start;
			for(i=0;i<x;i++)
			{
					dif=c[i]-h;
					hm+=dif;
					h=c[i];
					printf("%d\t",c[i]);
			}
		}
		else
		{
			if(c[i]==h)
				x=i;
			else
				x=i-1;
			for(i=x;i>=0;i--)
			{
					dif=h-c[i];
					hm+=dif;
					h=c[i];
					printf("%d\t",c[i]);
			}
			dif=h-start;
			hm=hm+dif+199;
			h=end;
			for(i=n-1;i>x;i--)
			{
					dif=h-c[i];
					hm+=dif;
					h=c[i];
					printf("%d\t",c[i]);
			}
		}
		printf("\nTotal head movement=  %d \n",hm);
	}
	if(ch<4)
	{printf("Do you want to continue(1.yes 2.no)?");
	scanf("%d",&choice);}
	}while(choice==1 &&ch<4);
}
