#include<stdio.h>
void main(){
	int a[40];
	int p,j,i,max,n,c,g,temp;
	int s=0;
	printf("\nenter position of head pointer:");
	scanf("%d",&p);
	g=p;
	printf("\nenter max track length :");
	scanf("%d",&max);
	printf("\nenter no of process:");
	scanf("%d",&n);
	printf("\nenter processes in requested order:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	while(1){
		printf("\nenter choices for disk sheduling :");
		printf("\n1.FCFS 2.SCAN 3.C-SCAN ");
		printf("\nEnter your choice :");
		scanf("%d",&c);
		p=g;
		if(c==1){
			printf("sheduled order for FCFS IS \n");
			for(i=0;i<n;i++){
				if(a[i]>p){
					temp=a[i]-p;
					s+=temp;
					p=a[i];
					printf("%d   ",a[i]);
				}
				else{
					temp=p-a[i];
					s+=temp;
					p=a[i];
					printf("%d  ",a[i]);
				}
			}
		}
		else if(c>3){break;}
		else{
			printf("\nsceduled order SCAN is\n");
			for(i=0;i<n;i++){
				for(j=1;j<n;j++){
					if(a[i]>a[j]){
						temp=a[i];
						a[i]=a[j];
						a[j]=temp;
					}
				}
			}
		}
		if(c==2){
			p=g;
			for(i=0;i<n;i++){
				if(a[i]>g){
					j=i;
					break;
				}
			}
			for(i=j-1;i>=0;i--){
				s+=(p-a[i]);
				p=a[i];
				printf("%d",a[i]);
				s+=(a[i]-p);
				p=a[i];
				printf("%d  ",a[i]);
			}
		}
		else{
			for(i=0;i<n;i++){
				if(a[i]>g){
					j=i;
					break;
				}
			}
			for(i=j;i<n;i++){
				s+=(a[i]-p);
				p=a[i];
				printf("%d  ",a[i]);
			}
			s+=(max-1);
			s+=(max-1-p);
			p=0;
			for(i=0;i<=j-1;i++){
				s+=(a[i]-p);
				p=a[i];
				printf("%d  ",a[i]);
			}
		}
		printf("\n total seek time %d\n\n",s);
	}
}
