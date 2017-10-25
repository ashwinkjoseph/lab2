#include <sys/types.h>
#include <sys/dir.h>
#include <sys/param.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define FALSE 0
#define TRUE !FALSE

extern int alphasort(); //Inbuilt sorting function

char pathname[MAXPATHLEN];

void die(char *msg)
{
  perror(msg);
  exit(0);
}

int file_select(struct direct *entry)
{
    if ((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0))
	return (FALSE);
    else
	return (TRUE);
}

void ls(){
    int count,i;
    struct direct **files;

    printf("Current Working Directory = %s\n",pathname);
    count = scandir(pathname, &files, file_select, alphasort);

    /* If no files found, make a non-selectable menu item */
    if(count <= 0)
	die("No files in this directory\n");

    printf("Number of files = %d\n",count);
    for (i=1; i<count+1; ++i)
	printf("%s  ",files[i-1]->d_name);
    printf("\n"); /* flush buffer */
}

void cd(char dirname[]){
	printf("%s", dirname);
}

int checkDir(char dirname[]){
    int count,i;
    struct direct **files;

    printf("Current Working Directory = %s\n",pathname);
    count = scandir(pathname, &files, file_select, alphasort);

    /* If no files found, make a non-selectable menu item */
    if(count <= 0)
	die("No files in this directory\n");

//    printf("Number of files = %d\n",count);
    for (i=1; i<count+1; ++i)
    	if(strcmp(files[i-1]->d_name, dirname)==0){
    		return(1);
    	} /* flush buffer */
    return(0);
}

int main()
{
	int choice;
	char dirname[20];
	int i, lindex;
	char absfilename[100];
	char fileName[100];
	char data[50] ;
	FILE *fp ;
	char line[100];
	char tempToFile[500];
	if(!getcwd(pathname, sizeof(pathname)))
		die("Error getting pathname\n");
	do{
		int n;
		printf("Choose from below:\n");
		printf("1. List Files in Current Directory\n");
		printf("2. Move to directory(within this direcory)\n");
		printf("3. Move to a directory using absolute path\n");
		printf("4. Create a Directory\n");
		printf("5. Move Back\n");
		printf("6. Read a file\n");
		printf("7. Write to a file\n");
		printf("8. Create a new file\n");
		scanf("%d", &n);
		switch(n){
			case 1: ls();
				break;
			case 2: printf("Enter Directory Name\n");
				scanf("%s", dirname);
				if(checkDir(dirname)){
					strcat(pathname, "/");
					strcat(pathname, dirname);
					cd(pathname);
				}
				else{
					printf("That Directory doesn't Exist\n");
				}
				break;
			case 3: printf("Enter Absolute path\n");
				char absolutePath[100];
				scanf("%s", pathname);
				cd(pathname);
				break;
			case 4: printf("Enter name of directory\n");
				scanf("%s", dirname);
				char tempPath[200];
				strcat(tempPath, pathname);
				strcat(tempPath, "/");
				strcat(tempPath, dirname);
				if(mkdir(tempPath)==0){
					printf("Success\n");
				}
				else{
					printf("Error Occured\n");
				}
				break;
			case 5: lindex = strlen(pathname)-1;
				while(pathname[lindex]!='/'){
					lindex--;
				}
				char tempPathName[100];
				i =0;
				for(i = 0; i<lindex; i++){
					tempPathName[i] = pathname[i];
				}
				tempPathName[i] = '\0';
				strcpy(pathname, tempPathName);
				break;
			case 6: printf("Enter the name of the file\n");
				
				scanf("%s", fileName);
				
				strcat(absfilename, pathname);
				strcat(absfilename, "/");
				strcat(absfilename, fileName);
				if(checkDir(fileName)){
					FILE *fp ;
					 char data[50] ;
					 printf("Im here too");
					 printf( "Opening the file %s in read mode\n", fileName ) ;
					 fp = fopen( fileName, "r" ) ;
					 if ( fp == NULL )
					 {
						 printf( "Could not open file %s\n", fileName ) ;
						 return 1;
					 }
					 printf( "Reading the file %s\n", fileName ) ;
					 while( fgets ( data, 50, fp ) != NULL )
					 printf( "%s" , data ) ;
					 printf("Closing the file %s\n", fileName) ;
					 fclose(fp) ;
				}
				else{
					printf("That File doesn't Exist\n");
				}
				break;
			case 7: printf("Enter the name of the file\n");
				scanf("%s", fileName);
				strcat(absfilename, pathname);
				strcat(absfilename, "/");
				strcat(absfilename, fileName);
				 printf("Im here too");
				 printf( "Opening the file %s in append mode\n", fileName ) ;
				 fp = fopen( fileName, "a" ) ;
				 if ( fp == NULL )
				 {
					 printf( "Could not open file %s\n", fileName ) ;
					 return 1;
				 }
				 
				  while(1){
				 	scanf("%s", line);
				 	if(strcmp(":wq", line)==0){
				 		break;
				 	}else{
				 		fputs(line, fp) ;   
						fputs("\n", fp) ;
				 	}
				 }
				 printf("Closing the file %s\n", fileName) ;
				 fclose(fp) ;
				break;
			case 8: printf("Enter the name of the file\n");
				scanf("%s", fileName);
				strcat(absfilename, pathname);
				strcat(absfilename, "/");
				strcat(absfilename, fileName);
				 
				 printf("Im here too");
				 printf( "Opening the file %s in append mode\n", fileName ) ;
				 fp = fopen( fileName, "w" ) ;
				 if ( fp == NULL )
				 {
					 printf( "Could not open file %s\n", fileName ) ;
					 return 1;
				 }
				 while(1){
				 	scanf("%s", line);
				 	if(strcmp(":wq", line)==0){
				 		break;
				 	}else{
				 		fputs(line, fp) ;   
						fputs("\n", fp) ;
				 	}
				 }
				 printf("Closing the file %s\n", fileName) ;
				 fclose(fp) ;
				break;
			default: printf("Unsupported Operation\n");
		}
		printf("Do you wish to perform another operation?(1/0)\n");
		scanf("%d", &choice);
	}while(choice==1);
}
