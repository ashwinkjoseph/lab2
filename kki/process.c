#include<stdio.h>
int insertprocess(int prc[3][100],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<4;){
			switch(j){
				case 0: printf("process id:");
				break;
				case 1: printf("arrival time:");
				break;
				case 2: printf("burst time:");
				break;
				case 3: printf("priority:");
				break;
				default: return -1;
				break;
			}
			scanf("%d",&prc[i][j]);
			j++;
		}
	}
}
int displayprocesstable(int prc[3][100],int n){
	printf("PRCID---AT---BT---PRIO\n");
	for(int i=0;i<n;i++){
		printf("\n");
		for(int j=0;j<4;j++){
			printf("  ");
			printf("%d",prc[i][j]);
		}
	}printf("\n");
}
int main()
{
 int prc[3][100];
 int i,j,choice,n;
 printf("****************Process time calculation*****************\n");
 printf("1.first come first serve 2.shortest job first 3.round robin 4.priority \n");
 printf("Enter process choice:");
 scanf("%d",&choice);
 if(choice==1){
	printf("\t||First come first serve||\n");
	printf("enter no of processes:");
        scanf("%d",&n);
	insertprocess(prc,n);
	displayprocesstable(prc,n);
	printf("\nsorted according to arrival time\n");
	 for(i=0;i<n;i++){
			//there IS ANOTHER LOOP TO PUT HERE LOL:)
			for(j=0;j<n-1;j++){
                        int temp;
                        if(prc[i][1]>prc[i+1][1]){
                                temp=prc[i][1];
                                prc[i][1]=prc[1+1][1];
                                prc[i+1][1]=temp;
                        }
        	}
	}

	/*for(i=0;i<n;i++){
		int temp1;
		if(prc[i][1]>prc[i+1][1]){
			temp1=prc[i][1];
			prc[i][1]=prc[i+1][1];
			prc[i+1][1]=temp1;}
	}*/

	displayprocesstable(prc,n);

 }
}
