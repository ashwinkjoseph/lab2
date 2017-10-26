#include<stdio.h>
void main(){
	int a[10]={5,1,6,7,2,8,9,3,10,4};
	printf("\n****\n");
	printf("a={");
	for(int i=0;i<10;i++)
		printf(",%d",a[i]);
	printf("}\n");
	for(int i=0;i<10;i++){
		for(int j=i;j<10;j++){
			if(a[i]>a[j]){
				int t;
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	printf("\na={");
	for(int i=0;i<10;i++){
		printf(",%d",a[i]);
	}
	printf("}");
}
