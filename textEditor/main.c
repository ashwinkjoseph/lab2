/*
Text Editor
Joseph Ashwin Kottapurath
33, S5R
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct file{
	char *name;
	int *indexOn;
	char *body;	
};

struct file createFile(char name[]){
	struct file f;
	f.name = (char*) malloc(sizeof(char)*256);
	strcpy(f.name, name);
	f.body = (char*) malloc(sizeof(char)*256);
	f.indexOn = (int*) malloc(sizeof(int));
	*f.indexOn = 0;
	return f;
	
}

void readFile(struct file f){
	int i;
	printf("\n\nReading File\n\n");
	for(i = 0; i<strlen(f.body); i++){
		printf("%c", f.body[i]);
	}
	printf("\n");
}

void writeFile(struct file f){
	char c;
	while(1){
		scanf("%c", &c);
		if(c==':'){
			scanf("%c", &c);
			if(c=='w'){
				scanf("%c", &c);
				if(c=='q'){
					break;
				}else{
					if(*f.indexOn%256<3){
						f.body = realloc(f.body, sizeof(char)*256);
					}
					strcat(f.body, ":w");
					*f.indexOn += 2;
				}
			}else{
				if(*f.indexOn%256<2){
					f.body = realloc(f.body, sizeof(char)*256);
				}
				strcat(f.body, ":");
				*f.indexOn = *f.indexOn + 1;
			}
		}else{
			if(*f.indexOn%256<2){
				f.body = realloc(f.body, sizeof(char)*256);
			}
			f.body[*f.indexOn] = c;
			*f.indexOn = *f.indexOn + 1;
		}
	}
}

void deleter(struct file f){
	int start;
	int end;
	readFile(f);
	printf("Enter the index to start deleting from: ");
	scanf("%d", &start);
	printf("Enter the index to stop deleting at: ");
	scanf("%d", &end);
	int i = 0;
	int k;
	char *temp = (char*) malloc(sizeof(char)*256);
	for(k = 0; k<start; k++){
		if(k%256<2){
			temp = realloc(temp, sizeof(char)*256);
		}
		temp[k] = f.body[k];
	}
	i = k;
	*(f.indexOn) = k;
//	printf("FROM END+1: %d and length: %d\n", (end+1), strlen(f.body));
	for(k = (end+1); k<strlen(f.body); k++){
		if(i%256<2){
			temp = realloc(temp, sizeof(char)*256);
		}
		temp[i] = f.body[k];
		i++;
	}
	free(f.body);
	printf("Heres the temp: ");
	printf("%s", temp);
	printf("\n");
	f.body = (char*) malloc(sizeof(temp));
	strcpy(f.body, temp);
}

void navigateTo(struct file f){
	int index;
	printf("Enter the index to navigateTo: ");
	scanf("%d", &index);
	if((index<strlen(f.body))&&(index>=0)){
		*f.indexOn = index;
	}
	else{
		printf("Index out of Range\n");
	}
}

int main(void){
	printf("Enter the name of the File: ");
	char *name;
	scanf("%ms", &name);
	struct file f = createFile(name);
	while(1){
		int c;
		printf("What do you want? \n1. Write To File\n2.Read File\n3. Navigate to an index\n4. Delete certain words");
		scanf("%d", &c);
		switch(c){
			case 1: writeFile(f);
				break;
			case 2: readFile(f);
				break;
			case 3: navigateTo(f);
				break;
			case 4: deleter(f);
				break;
			default: printf("Wrong Option!!!\n");
		}
	}
	return 0;
}
