#include<stdio.h>

struct SYM{
	char *name;
	int *index;
}*SYMTAB=NULL;

struct Data{
	char *data;
}*DTAB=NULL;

void addToSYM(int i, char *name, int index){
	if(SYMTAB==NULL){
		SYMTAB = (struct SYM*) malloc(sizeof(struct SYM));
	}
	else{
		SYMTAB = realloc(SYMTAB, sizeof(struct SYM));
	}
	SYMTAB[i].name = (char*) malloc(sizeof(name));
	strcpy(SYMTAB[i].name, name);
	SYMTAB[i].index = (int*) malloc(sizeof(int));
	*SYMTAB[i].index = index;
}

void addToDTAB(int i, char *data){
	if(DTAB==NULL){
		DTAB = (struct Data*) malloc(sizeof(struct Data));
	}
	else{
		DTAB = realloc(DTAB, sizeof(struct Data));
	}
	DTAB[i].data = (char*) malloc(sizeof(data));
	strcpy(DTAB[i].data, data);
}

int* LookUp(char *name, int i){
	int j = 0; 
	for(j=0; j<=i; j++){
		if(strcmp(SYMTAB[i].name, name)){
			return *SYMTRAB[i].index;
		}
	}
	return NULL;
}

int main(void){
	FILE *fp = fopen("macroFile.c", "r");
	if(fp==	NULL){
		printf("File couldn't be opened!!!\n");
	}
	else{
		while(fgets(data, 50, fp)!=NULL){
			
		}
	}
	return 0;
}
