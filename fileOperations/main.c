#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct{
	char dname[10], fname[10][10], fn[10];
	int fcnt, cnt;
}dir, two[2][10];

void main(void){
	int n, m=0, a, i, j=0, flag, x=0, u, choice, dv=0;
	char ps[10], nfdel[10], pswd[10], xyz[10], nddel[10], usr1[10], usr2[10];
	int ss, b, f, h, y;
	char nd[10], newdir[10];
	printf("TWO LEVEL DIRECTORY\n---------------------------------------------------------------\n");
	printf("Set a password of user1:\t");
	scanf("%s", usr1);
	printf("Password set successfully.... please use this password to login to user1\n");
	printf("Set a password of user2:\t");
	scanf("%s", usr2);
	printf("Password set successfully.... please use this password to login to user2\n");

	do{
		printf("\n1.user1\n2.user2\n3.exit\n");
		scanf("%d", &n);
		if(n==1||n==2){
			if(n==1){
				strcpy(pswd, usr1);
				u=0;
			}
			else if(n==2){
				u=1;
				strcpy(pswd, usr2);
			}
			printf("PASSWORD:\n");
			scanf("%s", ps);
			if(strcmp(ps, pswd)==0){
				printf("Password Accepted....\n\n\n*****************************USER%d***************************\n", u+1);
				do{
					printf("\n1.ENTER \n2.CREATE DIRECTORY\n3. DELETE A DIRECTORY\n4. LIST\n5. CREATE FILE\n6. DELETE FILE\n7.EXIT\n");
					scanf("%d", &b);
					switch(b){
						case 1: printf("Name of Directory:\t");
							scanf("%s",xyz);
							flag=0;
							for(x=0; x<m; x++){
								if(strcmp(two[u][x].dname, xyz)==0){
									flag=1;
										do{
											printf("\n1. add file\n2. delete\n3. list\n4. exit\n");
											scanf("%d", &a);
											switch(a){
												case 1: flag = 0;
													printf("name of the new file:\n");
													scanf("%s", nd);
													for(two[u][x].cnt=0; two[u][x].cnt<two[u][x].fcnt; two[u][x].cnt++){
														if(strcmp(nd, two[u][x].fname[two[u][x].cnt])==0){
															flag=1;
															printf("sorry..... file name already exists\n");
														}
													}
													if(flag==0){
														strcpy(two[u][x].fname[two[u][x].cnt], nd);
														two[u][x].fcnt++;
														printf("\nfile created\n");
													}
													break;
												case 2: flag=0;
													printf("enter the name of file to delete\n");
													scanf("%s", nd);
													for(two[u][x].cnt=0;two[u][x].cnt<two[u][x].fcnt;two[u][x].cnt++){
														if(strcmp(nd, two[u][x].fname[two[u][x].cnt])==0){
															flag=1;
															printf("File found.... \n");
															while(two[u][x].cnt<two[u][x].fcnt){
																strcpy(two[u][x].fname[two[u][x].cnt], two[u][x].fname[two[u][x].cnt+1]);
																two[u][x].cnt++;
															}
															printf("deleted.....\n");
															two[u][x].fcnt--;
														}
													}
													if(flag==0){
														printf("file doesnt exist\n");
													}
													break;
												case 3: if(two[u][x].fcnt==0){
														printf("\nempty\n");
													}else{
														 printf("files are: \n");
														 for(two[u][x].cnt=0;two[u][x].cnt<two[u][x].fcnt; two[u][x].cnt++){
														 	printf("%s\n",two[u][x].fname[two[u][x].cnt]);
														 }
													}
													
													break;
											}
								}while(a!=4);
								printf("\nexiting from directory %s...\n", two[u][x].dname);
							}
						}
						if(flag==0){
							printf("Directory does not exist\n");
						}
						break;
					case 2: flag = 0;
						printf("Name of new Directory:\t");
						scanf("%s", newdir);
						for(y=0;y<m;y++){
							if(strcmp(newdir, two[u][y].dname)==0){
								flag=1;
								printf("Sorry.. this name already exists\n");
							}
						}
						if(flag==0){
							strcpy(two[u][x].dname, newdir);
							printf("Directory created successfully......\n");
							m++;
							x++;
						}
						break;
					case 3: flag=0;
						printf("name of directory:\t");
						scanf("%s",nddel);
						for(x=0;x<m;x++){
							if(strcmp(two[u][x].dname, nddel)==0){
								flag = 1;
								h=x;
								while(h<m){
									strcpy(two[u][h].dname, two[u][h+1].dname);
									h++;
								}
								printf("Directory along with its files is deleted\n");
								m--;
							}
						}
						if(flag==0){
							printf("Directory does not exist\n");
						}
						break;
				}
			}
		}
	}
}
