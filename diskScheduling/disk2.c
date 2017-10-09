#include<stdio.h>
void main()
{
	int a[20],b[20],n,i,j,temp,p,s,m,x,t=0;
	printf("enter the head position\n");
	scanf("%d",&a[0]);
	s=a[0];
	printf("enter previous head position\n");
	scanf("%d",&p);
	printf("enter max track limit\n");
	scanf("%d",&m);
	printf("Enter the number of processes\n");
	scanf("%d", &n);
	printf("enter processes in request order\n");
	for(i=1;i<(n+1);i++){
//		printf("Before");
		printf("i: %d \t n+1 %d \t", i, (n+1)); 
		if(a[i]){	
			scanf("%d", &a[i]);
		}
		else{
			printf("\n No Luck \n");
			printf("%p", &a[i]);
		}
//		printf("After");
	}
	printf("Before");
	if(a[i]){
		a[i]=m;
	}
	else{
		printf("\nnope a[%d]: %p\n", i, &a[i]);
	}
	if(a[i+1]){
		a[i+1]=0;
	}
	else{
		printf("\nnope a[%d]: %p\n", i+1, &a[i+1]);
	}
	if(a[n+1]){
		a[n+1]=m;
	}
	else{
		printf("\nnope a[%d]: %p\n", n+1, &a[n+1]);
	}
	if(a[i+1]){
		a[i+1]=0;
	}
	else{
		printf("\nnope a[%d]: %p\n", n+2, &a[n+2]);
	}
	//a[i+1]=0;
	printf("After");
	//printf("Before");
	for(i=n+1;i>=0;i--){
		for(j=0;j<=i;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	//printf("After");
	for(i=1;i<=n+1;i++){
		if(s==a[i])
			x=i;
	}
	j=0;
	if(s<p){
		for(i=x;i>0;i--){
			t+=(a[i]-a[i-1]);
			b[j++]=a[i];
		}
		t+=(a[i+1]-a[0]);
		b[j++]=a[0];
		for(i=x+1;i<n+1;i++){
			t+=(a[i+1]-a[i]);
			b[j++]=a[i];
		}
		b[j++]=a[i];
	}
	else{
		for(i=x;i<n+2;i++){
			t+=(a[i+1]-a[i]);
			b[j++]=a[i];
		}
		t+=a[n+1]-a[x-1];
		b[j++]=a[n+2];
		for(i=x-1;i>=0;i++){
			t+=(a[i]-a[i-1]);
			b[j++]=a[i];
		}
		b[j++]=a[i];
	}
	printf("processing order\n");
	for(i=0;i<n+1;i++)
		printf("\t%d",b[i]);
	printf("total head movement:%d",t);
}
