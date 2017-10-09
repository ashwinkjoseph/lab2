#include<stdio.h>

int programs[30][3];
int count = 0;

/*void checkAllocate(int count){
	if((count%3)==0){
		allocate();
	}
}*/

int main(void){
	int time = 0;
	int tempTime = 0;
	int timeTaken = 0;
	int i=0;
	int full = 0;
	int totalTime = 0;
	char choice;
	int n = 0;
	int j = 0;
	int smallest = 0;
	int priority = 0;

	while(i<30){
		printf("Please enter the program arrival Time");
		scanf("%d", &tempTime);
		printf("Please enter the time taken by the program to complete");
		scanf("%d", &timeTaken);
		printf("Please enter the priority of the program");
		scanf("%d", &priority);
		i++;
		programs[i][0] = tempTime;
		programs[i][1] = timeTaken;
		programs[i][2] = priority;
		printf("Is there another program?(Y/N)");
		scanf("%s", &choice);
		if(choice=='Y'||choice=='y'){
			//do nothing
		}
		else{
			break;
		}
	}

	n = i + 1;
	
	printf("\n");
	for(i = 0; i < n; i++){
		int smallest = i;
		j = i + 1;
		if(programs[smallest][0] == programs[j][0]){
			while(programs[smallest][0] == programs[j][0]){
				int smallest2 = programs[smallest][2];
				if(smallest2>programs[j][2]){
					smallest = j;
				}
				j++;
			}
		}
		else{
			for(j=i+1; j<n; j++){
			
				if(programs[smallest][0]>programs[j][0]){
					smallest = j;
				}
			}
		}
		int temp[3];
		temp[0] = programs[i][0];
		temp[1] = programs[i][1];
		temp[2] = programs[i][2];
		programs[i][0] = programs[smallest][0];
		programs[i][1] = programs[smallest][1];
		programs[i][2] = programs[smallest][2];
		programs[smallest][0] = temp[0];
		programs[smallest][1] = temp[1];
		programs[smallest][2] = temp[2];
	}

/*
	printf("\nAfter sorting: \n");
	for(i=0; i<n; i++){
		printf("%d, %d\n",programs[i][0], programs[i][1]);
	}
*/

	for(i=0;i<n;i++){
		tempTime = programs[i][0];
		timeTaken = programs[i][1];
		if(tempTime>=time){
			programs[i][0]=0;
			time = time + timeTaken;
			programs[i][1]=timeTaken;
		}
		else{
			programs[i][0]=time-tempTime;
			time = time + timeTaken;
			programs[i][1]=programs[i][0]+timeTaken;
		}
	}


	printf("\nAfter allocation: \n");
	for(i=1; i<n; i++){
		printf("%d, %d, %d\n",programs[i][0], programs[i][1], programs[i][2]);
	}

}
