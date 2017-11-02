#include<string.h>
#include<stdio.h>
struct
{
	int fl;
	char name[10],f[10][10];

}dir,dir2[2];
void main()
{
	int cc;
	do{
		printf("\n1.single level \n2.two level \n3.hierarchial \n4.exit");
		scanf("%d",&cc);
		if(cc==1){
			int i,ch,j;
			char f[10];
			dir.fl=0;
			printf("enter name of directory:");
			scanf("%s",dir.name);
			do{
				char d[10];
				printf("\nsingle level directory \n1.create   2.delete   3.display 4.return to main menu");
				printf("enter choice");
				scanf("%d",&ch);
				switch(ch){
					case 1: printf("enter name :");
						scanf("%s",f);
						for(i=0;i<dir.fl;i++){
							if(strcmp(f,dir.f[i])==0){
								printf("name already exist");
								break;
							}
						}
						if(i==dir.fl){
							strcpy(dir.f[i],f);
							dir.fl++;
							printf("file %s added to the directory",f);
						}
						break;
					case 2: printf("enter name of file to be deleted:");
						scanf("%s",f);
						for(i=0;i<(dir.fl);i++){
							if(strcmp(f,dir.f[i])==0){
								strcpy(dir.f[i],dir.f[(dir.fl)-1]);
								printf("\nfile deleted from list");
								break;
							}
						}
						if(i==dir.fl){
							printf("\nfile doesnt exist");
						}
						else{
							dir.fl--;
						}
					        break;
					case 3: if(dir.fl==0){
							printf("\ndirectory empty");
						}
						else{
							printf("\ndirectory		files");
							printf("%s\t\t\t",dir.name);
							for(i=0;i<(dir.fl);i++){
								printf("%s\t",dir.f[i]);
							}
						}
						break;
					case 4: break;
					default : printf("\ninvalid");
				}
			}while(ch<4);
		}
		else if(cc==2){
			int d=0,b=0,c,q,i,ch;
			do{
				printf("\ntwo level directory\n1.create directory\t2.delete existing directory\t3.modify existing directory\t3.close\nenter choice:");
				scanf("%d",&c);
				if(c==1){
					if(d==2){
						char d[10];
						printf("\ndirectory  already exists:");
					}
					else{
						printf("\nenter directory name:");
						scanf("%s",dir2[b].name);
						printf("\ndirectory %s created",dir2[b]);
					}
				}
				else if(c==2){
					char p[20],s[10];
					printf("\nenter name:");
					scanf("%s",s);
					for(b=0;b<2;b++){
							char d[10];
							if(strcmp(dir2[b].name,s)==0){
									char f[10];
									do{
										printf("\n1.create file	2.delete file\t3.go back\nenter choice:");
										scanf("%d",&ch);
										switch(ch){
											case 1: printf("enter name :");
												scanf("%s",f);
												for(i=0;i<dir2[b].fl;i++){
													if(strcmp(f,dir2[b].f[i])==0){
														printf("\nname already exists");
														break;
													}
												}
												if(i==dir2[b].fl){
													strcpy(dir2[b].f[i],f);
													dir2[b].fl++;
													printf("\n%s added to directory",f);

												}
												break;
											case 2:	printf("\nenter the file name to be deleted:");
												scanf("%s",f);
												for(i=0;i<(dir2[b].fl);i++){
													if(strcmp(dir2[b].f[i],f)==0){
														strcpy(dir2[b].f[i],dir2[b].f[(dir2[b].fl)-1]);
														printf("\nfile %s deleted",f);
														break;
													}
												}
												if(i==dir2[b].fl){
													printf("\nfile doesnt exists:");
												}
												else{
													dir2[b].fl--;
												}
												break;
											case 3: if(dir2[b].fl==0){
													printf("\ndirectory is empty");
												}
												else{
													printf("\ndirectory\tfiles\n");
													printf("%s\t\t\t",dir2[b].name);
													for(i=0;i<dir2[b].fl;i++){
														printf("%s\t",dir2[b].f[i]);
													}

												}
												break;
											default: printf("\ninvalid");
										}
									}while(ch<4);
								}
							}
							if(b==20){
								printf("\n directory doesnt exist");
							}
					}
				}
				printf("\ndo you wish to continue?(1:y/2:n)");
				scanf("%d",&q);
			}while(q==1);
		}
		else if(cc==3){
			int i,j,ch,d=0,b,q,c;
			char root[20];
			printf("\nenter root directory name:");
			scanf("%s",root);
			do{
				printf("\nHIRARCHIAL:\n1.create new directory\t2.modify exsting directory\t3.exit");
				printf("enter choice:");
				scanf("%d",&c);
				if(c==1){
					if(d==2){
						printf("\nregistry full..cannot create new registery:");
					}
					else{
						printf("\nenter name of directory:");
						scanf("%s",dir2[b].name);
						printf("\nDirectory %s created",dir2[b].name);
					}
				}
				else if(c==2){
					char p[15],s[10];
					printf("\nenter name of the directory:");
					scanf("%s",s);
					for(b=0;b<20;b++){
						if(strcmp(dir2[b].name,s)==0){
									char f[10];
									char d[10];
									do{
										printf("\n\tmenu:\n1.create new file\t2.delete file\t3.display current directory files \t4.display  files of other directories\t5go to main menu");
										printf("\nenter your choice:");
										scanf("%d",&ch);
										switch(ch){
											case 1: printf("\nenter file name:");
												scanf("%s",f);
												for(i=0;i<(dir2[b].fl);i++){
													if(strcmp(dir2[b].name,f)==0){
														printf("\nfile with same name already exists");
														break;
													}
												}
												int k;
												if(i==dir2[b].fl){
													strcpy(dir2[b].f[i],f);
													printf("\nis the current file public?(1.yes/2.no):");
													scanf("%d",&k);
													if(k==1){
														dir2[b].pass[dir2[b].fl]=1;
													}
													else{
														dir2[b].pass[dir2[b].fl]=0;
														dir2[b].fl++;
														printf("\nfile created");
													}
												}
												break;
											case 2: printf("\nenter name of file to be deleted:");
												scanf("%s",f);
												for(i=0;i<dir2[b].fl;i++){
													if(strcmp(dir2[b].f[i],f)==0){
														strcpy(dir2[b].f[i],dir2[b].f[(dir2[b].fl)-1]);
														printf("\nfile deleted from directory");
														break;
													}
												}
												if(i==dir2[b].fl){
													printf("\nfile doesnt exist");
												}
												else{
													dir2[b].fl--;
												}
												break;
											case 3: if(dir2[b].fl==0){
													printf("\ndirectory empty");
												}
												else{
													printf("\ndirectory\t\tfiles");                                                                                                        printf("\ndirectory\tfiles\n");
                                                                                                        printf("%s\t\t\t",dir2[b].name);
                                                                                                        for(i=0;i<dir2[b].fl;i++){
                                                                                                                printf("%s\t",dir2[b].f[i]);
                                                                                                        }
												}
												break;
											case 4:
												printf("\nenter directory name to display files");
												scanf("%s",d);
												if(i==20){
													printf("\ninvalid directory name");
												}
												else{
													for(j=0;j<dir2[b].fl;j++){
														if(dir2[b].pass[j]==1){
															printf("%s:",dir2[i].f[j]);
														}
													}
												}
												break;
											default :printf("\ninvalid");
										}
									}while(ch<5);
								}
						}
						if(b==20){
							printf("\ndirectory doesnt exists");
						}
					}
					printf("\ndo you wish to continue?(1.yes/2.no):");
					scanf("%d",&q);
				}
				else{
					break;
				}
			}while(q==1);

		}while(cc<4);

}

    
