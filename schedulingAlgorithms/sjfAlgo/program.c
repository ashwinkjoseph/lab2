#include<stdio.h>

int sameTimePrograms[40][2];
int programs[30][2];
int count = 0;

int allocate(int counts){
	int i;
	int totalTime = 0;
	printf("I'm allocating");
	//printf("\ncount: %d", count);
	for(i = count; i < (count+counts); i++){
		int k = i - count;
		while(k >= 0){
			programs[i][0] += sameTimePrograms[k][1];
			k--;
		}
		programs[i][1] = sameTimePrograms[i][1] + programs[i][0];
		totalTime += programs[i][1];
	}
	count += counts - 1;
	return totalTime;
}

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

	while(i<30){
		printf("Please enter the program arrival Time");
		scanf("%d", &tempTime);
		printf("Please enter the time taken by the program to complete");
		scanf("%d", &timeTaken);
		i++;
		programs[i][0] = tempTime;
		programs[i][1] = timeTaken;
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
				int smallest2 = programs[smallest][1];
				if(smallest2>programs[j][1]){
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
		int temp[2];
		temp[0] = programs[i][0];
		temp[1] = programs[i][1];
		programs[i][0] = programs[smallest][0];
		programs[i][1] = programs[smallest][1];
		programs[smallest][0] = temp[0];
		programs[smallest][1] = temp[1];
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
		printf("%d, %d\n",programs[i][0], programs[i][1]);
	}

}
