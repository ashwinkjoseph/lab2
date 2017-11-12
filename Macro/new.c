#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct SYM{
	char *name;
	int *index;
}*SYMTAB=NULL;

struct Data{
	char *data;
}*DTAB=NULL;

int SYMi = 0;
int Datai = 0;

void addToSYM(char *name){
	if(SYMTAB==NULL){
		SYMTAB = (struct SYM*) malloc(sizeof(struct SYM));
	}
	else{
		SYMTAB = realloc(SYMTAB, sizeof(struct SYM));
	}
	SYMTAB[SYMi].name = (char*) malloc(sizeof(name));
	strcpy(SYMTAB[SYMi].name, name);
	SYMTAB[SYMi].index = (int*) malloc(sizeof(int));
	*SYMTAB[SYMi].index = Datai;
	SYMi++;
}

void addToDTAB(char *data){
	if(DTAB==NULL){
		DTAB = (struct Data*) malloc(sizeof(struct Data));
	}
	else{
		DTAB = realloc(DTAB, sizeof(struct Data));
	}
	DTAB[Datai].data = (char*) malloc(sizeof(data));
	strcpy(DTAB[Datai].data, data);
}

int* LookUp(char *name, int i){
	if(SYMi>1){	
		int j = 0; 
		for(j=0; j<i; j++){
			if(strcmp(SYMTAB[i].name, name)==0){
				return SYMTAB[i].index;
			}
		}
	}else{
		if(SYMTAB!=NULL){
			if(strcmp(SYMTAB[0].name, name)==0){
				return SYMTAB[0].index;
			}
		}
	}
	return NULL;
}

int main(void){
	FILE *fp = fopen("macroFile.c", "r");
	FILE *fo = fopen("macroFileInter.c", "w");
	char *data = (char*) malloc(sizeof(char));
	char *token;
	int *p = NULL;
	if(fp==	NULL){
		printf("File couldn't be opened!!!\n");
	}
	else{	
		while(fgets(data, 1024, fp)!=NULL){
			token = strtok(data, " ");
			if(token!=NULL){
				if(strcmp(token, "#define")==0){
					token = strtok(NULL, " ");
					if(token!=NULL){
						p = LookUp(token, SYMi);
						if(p!=NULL){
							printf("The Macro has already been defined");
						}else{
							addToSYM(token);
							token = strtok(NULL, " ");
							if(token!=NULL){
								token[strlen(token)-1] = '\0';
								addToDTAB(token);
							}
						}
						p = NULL;
					}
				}
				else{
					while(token!=NULL){
						p = NULL;
						p = LookUp(token, SYMi);
						if(p==NULL){
							fputs(token, fo);
							fputs(" ", fo);
						}else{
							fputs(DTAB[*p].data, fo);
							fputs(" ", fo);
						}
						token = strtok(NULL, " ");
					}
					fputs("\n", fo);
				}
			}
		}
	}
	return 0;
}
