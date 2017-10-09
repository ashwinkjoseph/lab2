#include<stdio.h>

int main(void){
	int time = 0;
	int tempTime = 0;
	int timeTaken = 0;
	int i = 0;
	int programs[30][2];
	char choice;
	while(1){
		printf("Enter the Arrival Time of the program");
		scanf("%d %d", &tempTime, &timeTaken);
		if(tempTime>time){
			programs[i][0]=0;
			time = time + timeTaken;
			programs[i][1]=timeTaken;
		}
		else{
			programs[i][0]=time-tempTime;
			time = time + timeTaken;
			programs[i][1]=programs[i][0]+timeTaken;
		}
		printf("Do you have another Program? (Y/N)");
		scanf("%s", &choice);
		if(choice=='Y'||choice=='y'){
			i = i + 1;
		}
		else{
			break;
		}
	}
	int k = 0;
	while(k<=i){
		printf("%d %d \n", programs[k][0], programs[k][1]);
		k++;
	}
}
