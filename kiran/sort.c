\#include<stdio.h>
void main()
{
	int a[10][3];
	int i,j,n,m;
	printf("m?");
	scanf("%d",&m);
	for(i=0;i<m;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<m;i++){
                printf(" ");
                for(int j=0;j<3;j++){
                        printf("%d",a[i][j]);
                }printf("\n");
	}
	for(i=0;i<m;i++){
			int temp;
			if(a[i][1]>a[i+1][1]){
				temp=a[i][1];
				a[i][1]=a[1+1][1];
				a[i+1][1]=temp;
			}
	}
	  for(int i=0;i<m;i++){
                printf(" ");
                for(int j=0;j<3;j++){
                        printf("%d",a[i][j]);
                }printf("\n");
        }

}
