// sslLab.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct SYM {
	char *name;
	int index;
}*SYMTAB = NULL;
int SYMi = 0;

struct Data {
	char *data;
}*DTAB = NULL;
int Datai = 0;

void addToSYM(int i, char *name, int index) {
	if (SYMTAB == NULL) {
		SYMTAB = (struct SYM*) malloc(sizeof(struct SYM));
	}
	else {
		SYMTAB = (struct SYM*) realloc(SYMTAB, sizeof(struct SYM));
	}
	SYMTAB[i].name = (char*)malloc(sizeof(name));
	strcpy(SYMTAB[i].name, name);
	//SYMTAB[i].index = (int*)malloc(sizeof(int));
	SYMTAB[i].index = index;
}

void addToDTAB(int i, char *data) {
	if (DTAB == NULL) {
		DTAB = (struct Data*) malloc(sizeof(struct Data));
	}
	else {
		DTAB = (struct Data*) realloc(DTAB, sizeof(struct Data));
	}
	DTAB[i].data = (char*)malloc(sizeof(data));
	strcpy(DTAB[i].data, data);
}

int* LookUp(char *name, int i) {
	int j = 0;
	for (j = 0; j <= i; j++) {
		if (SYMTAB != NULL) {
			if (strcmp(SYMTAB[j].name, name)) {
				return &SYMTAB[j].index;
			}
		}
	}
	return NULL;
}

int main(void) {
	FILE *fp = fopen("Source.cpp", "r");
	FILE *fi = fopen("macroFileInter.cpp", "a");
	char *data = (char*) malloc(sizeof(char)*256);
	if (fp == NULL) {
		printf("File couldn't be opened!!!\n");
	}
	else {
		char *temp = (char*)malloc(sizeof(char) * 256);
		while (fgets(data, 50, fp) != NULL) {
			int t = 0;
			for (int i = 0; i < strlen(data); i++) {
				temp[t] = data[i];
				t++;
				if (data[i + 1] == ' ') {
					i++;
					temp[t] = '\0';
					if (strcmp(temp, "#define")) {
						t = 0;
						for (int j = 1; j < strlen(data); j++) {
							if (data[i + j] == ' ') {
								i = i + j;
								break;
							}
							temp[t] = data[i + j];
							t++;
						}
						temp[t] = '\0';
						t = 0;
						int *p = LookUp(temp, SYMi);
						if (p != NULL) {
							printf("MACRO DEFINED AGAIN");
						}
						else {
							addToSYM(SYMi, temp, Datai);
							int flag = 0;
							for (int j = 1; j < strlen(data); j++) {
								//while (data[i + j] == ' ') {
								//	j++;
								//}
								if (data[i + j] == '{') {
									flag = 1;
								}
								else {
									flag = 0;
								}
								j++;
								//while (data[i + j] == ' ') {
									//j++;
								//}
								if (flag == 0) {
									t = 0;
									while ((i + j) < strlen(data)) {
										if (data[i + j] == ' ') {
											temp[t] = '\0';
											t++;
											i = i + j;
											break;
										}
										printf("%c", data[i + j]);
										//temp[t] = data[i + j];
										t++;
										j++;
									}
								}
								else {
									t = 0;
									while ((i + j) < strlen(data)) {
										if (data[i + j] == '}') {
											temp[t] = '\0';
											t++;
											i = i + j;
											break;
										}
										temp[t] = data[i + j];
										t++;
									}
								}
							}
							addToDTAB(Datai, temp);
							SYMi++;
							Datai++;
						}
					}
					else {
						fputs(temp, fi);
					}
				}
			}

		}
	}
	return 0;
}
