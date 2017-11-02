#include<stdio.h>
#include<string.h>
struct
{
	char dname[20],fn[10][10];
	int fl;
}dir3[2][20],dir2[2][20];
void main()
{
	int cc;
  do{
	printf("\nMAIN MENU\n 1.Single level  2.Two level 3.Hierarchy 4.Exit \nEnter your choice   :");
  scanf("%d",&cc);
  if(cc==1)
  {
   char u[2][20],p[2][20],un[20],pw[20],fn[20],f[20][20],x[20],d1[20];
  int c,d[2],b,q,ch,i,choice,j,ul=0,flen=0,flag=0,k,l;
	do{
	printf("\n\nMENU\n1.New user 2.User login 3.Exit\nEnter your choice  :");
	scanf("%d",&choice);
	if(choice==1)
	{
		if(ul<1)
		{	printf("Enter username  :  ");
			scanf("%s",u[0]);
					printf("\nEnter a password   :");
					scanf("%s",p[ul]);
					d[ul]=0;
					ul++;

		}
		else
			printf("\nTwo users already exist");
	}
	else if(choice==2)
	{
		printf("\nEnter username  :  ");
		scanf("%s",un);
		for(i=0;i<ul;i++)
		{
			if(strcmp(u[i],un)==0)
				break;
		}
		if(i==ul)
			printf("\nInvalid username\n");
		else
		{
			printf("Enter your password   :");
			scanf("%s",pw);
			if(strcmp(p[i],pw)==0)
				{
					printf("\nSuccessfully logged in");
					do{
						printf("\n\nMENU\n1.Create file\t2.Delete file\t3.Create directory \t4.Create files inside 	directory\t5.Delete files from directory\t6.List directories and files\t7.Return to main menu \nEnter your choice  :  ");
					scanf("%d",&c);
					if(c==1)
					{
			     printf("Enter filename  :  ");
						scanf("%s",fn);
						for(j=0;j<flen;j++)
						{if(strcmp(fn,f[j])==0)
								break;
						}
						if(j==flen)
						{strcpy(f[flen],fn);
						flen++;
						printf("File %s added",fn);}
						else
							printf("file aleady exist\n");
					}
					else if(c==2)
					{
						printf("Enter filename  :  ");
						scanf("%s",fn);
						flag=0;
						for(j=0;j<flen;j++)
						{if(strcmp(fn,f[j])==0)
							{strcpy(f[j],f[flen-1]);
							flen--;	
							flag=1;
							printf("File %s deleted ",fn);
							break;}
						}
						if(flag==0)
							printf("File not found\n");
					}
					else if(c==3)
					{
					
    				if(d[i]==20)
    				{printf("\nCan't create more directories\n");}
    				else{
						printf("Enter a name for the directory  : ");
						scanf("%s",x);
						strcpy(dir2[i][d[i]].dname,x);
						printf("\nCreated the directory %s ",dir2[i][d[i]].dname);
						dir2[i][d[i]].fl=0;
						d[i]++;
						}
					}
					else if(c==4)
					{
						printf("\nEnter directory name  :  ");
						scanf("%s",d1);
						for(k=0;k<d[i];k++)
								{
									if(strcmp(dir2[i][k].dname,d1)==0)
										break;
								}
						if(k<d[i])
						{printf("Enter filename  :  ");
						scanf("%s",fn);
						for(j=0;j<dir2[i][k].fl;j++)
						{if(strcmp(fn,dir2[i][k].fn[j])==0)
								break;
						}
						if(j==dir2[i][k].fl)
						{strcpy(dir2[i][k].fn[dir2[i][k].fl],fn);
						dir2[i][k].fl++;
						printf("File %s added to directory %s",fn,dir2[i][k].dname);}
						else
							printf("file aleady exist\n");}
						else
							printf("\nInvalid directory name");
					}
					else if(c==5)
					{
						printf("\nEnter directory name  :  ");
						scanf("%s",d1);
						for(k=0;k<d[i];k++)
								{
									if(strcmp(dir2[i][k].dname,d1)==0)
										break;
								}
						if(k<d[i])
						{printf("Enter filename  :  ");
						scanf("%s",fn);
						for(j=0;j<dir2[i][k].fl;j++)
						{if(strcmp(fn,dir2[i][k].fn[j])==0)
								break;
						}
						if(j==dir2[i][k].fl)
						{printf("\nFile not found");}
						else
							{  
									strcpy(dir2[i][k].fn[j],dir2[i][k].fn[dir2[i][k].fl-1]);
                  dir2[i][k].fl--;
									printf("\nDeleted file %s from %s",fn,dir2[i][k].dname);	
							}
						}
						else
							printf("\nInvalid directory name");
					}
					else if(c==6)
					{
						printf("DIRECTORY NAME\t\t FILENAME\n");
						printf("Outside directories\t");
						for(j=0;j<flen;j++)
							printf("%s\t",f[j]);
						
						for(j=0;j<d[i];j++)
						{
							printf("\n%s\t\t",dir2[i][j].dname);
							for(k=0;k<dir2[i][j].fl;k++)
								printf("%s\t",dir2[i][j].fn[k]);
						}
					}
					}while(c<7);
				}
			else
				printf("\nIncorrect password");
		}
	}
	
	}while(choice<3);
  }
  else if(cc==2)
  {
char u[2][20],p[2][20],un[20],pw[20],fn[20],f[20][20][20],x[20],d1[20];
  int c,d[2],b,q,ch,i,choice,j,ul=0,flen[2],flag=0,k,l,to;
  for(to=0;to<20;to++)
     flen[to]=0;
	do{
	printf("\n\nMENU\n1.New user 2.User login 3.Exit\nEnter your choice  :");
	scanf("%d",&choice);
	if(choice==1)
	{
		if(ul<2)
		{	printf("Enter username  :  ");
			scanf("%s",un);
			for(j=0;j<ul;j++)
				{if(strcmp(u[j],un)==0)
				{
					printf("Username already exist\n");
					break;
				}}
			if(j==ul)
				{
					strcpy(u[ul],un);
					printf("\nEnter a password   :");
					scanf("%s",p[ul]);
					d[ul]=0;
					ul++;
				}
		}
		else
			printf("\nOne user already exist");
	}
	else if(choice==2)
	{
		printf("\nEnter username  :  ");
		scanf("%s",un);
		for(i=0;i<ul;i++)
		{
			if(strcmp(u[i],un)==0)
				break;
		}
		if(i==ul)
			printf("\nInvalid username\n");
		else
		{
			printf("Enter your password   :");
			scanf("%s",pw);
			if(strcmp(p[i],pw)==0)
				{
					printf("\nSuccessfully logged in");
					do{
						printf("\n\nMENU\n1.Create file\t2.Delete file\t3.Create directory \t4.Create files inside 	directory\t5.Delete files from directory\t6.List directories and files\t7.Return to main menu \nEnter your choice  :  ");
					scanf("%d",&c);
					if(c==1)
					{
			     printf("Enter filename  :  ");
						scanf("%s",fn);
						for(j=0;j<flen[i];j++)
						{if(strcmp(fn,f[i][j])==0)
								break;
						}
						if(j==flen[i])
						{strcpy(f[i][flen[i]],fn);
						flen[i]++;
						printf("File %s added",fn);}
						else
							printf("file aleady exist\n");
					}
					else if(c==2)
					{
						printf("Enter filename  :  ");
						scanf("%s",fn);
						flag=0;
						for(j=0;j<flen[i];j++)
						{if(strcmp(fn,f[i][j])==0)
							{strcpy(f[i][j],f[i][flen[i]-1]);
							flen[i]--;	
							flag=1;
							printf("File %s deleted ",fn);
							break;}
						}
						if(flag==0)
							printf("File not found\n");
					}
					else if(c==3)
					{
					
    				if(d[i]==20)
    				{printf("\nCan't create more directories\n");}
    				else{
						printf("Enter a name for the directory  : ");
						scanf("%s",x);
						strcpy(dir2[i][d[i]].dname,x);
						printf("\nCreated the directory %s ",dir2[i][d[i]].dname);
						dir2[i][d[i]].fl=0;
						d[i]++;
						}
					}
					else if(c==4)
					{
						printf("\nEnter directory name  :  ");
						scanf("%s",d1);
						for(k=0;k<d[i];k++)
								{
									if(strcmp(dir2[i][k].dname,d1)==0)
										break;
								}
						if(k<d[i])
						{printf("Enter filename  :  ");
						scanf("%s",fn);
						for(j=0;j<dir2[i][k].fl;j++)
						{if(strcmp(fn,dir2[i][k].fn[j])==0)
								break;
						}
						if(j==dir2[i][k].fl)
						{strcpy(dir2[i][k].fn[dir2[i][k].fl],fn);
						dir2[i][k].fl++;
						printf("File %s added to directory %s",fn,dir2[i][k].dname);}
						else
							printf("file aleady exist\n");}
						else
							printf("\nInvalid directory name");
					}
					else if(c==5)
					{
						printf("\nEnter directory name  :  ");
						scanf("%s",d1);
						for(k=0;k<d[i];k++)
								{
									if(strcmp(dir2[i][k].dname,d1)==0)
										break;
								}
						if(k<d[i])
						{printf("Enter filename  :  ");
						scanf("%s",fn);
						for(j=0;j<dir2[i][k].fl;j++)
						{if(strcmp(fn,dir2[i][k].fn[j])==0)
								break;
						}
						if(j==dir2[i][k].fl)
						{printf("\nFile not found");}
						else
							{  
									strcpy(dir2[i][k].fn[j],dir2[i][k].fn[dir2[i][k].fl-1]);
                  dir2[i][k].fl--;
									printf("\nDeleted file %s from %s",fn,dir2[i][k].dname);	
							}
						}
						else
							printf("\nInvalid directory name");
					}
					else if(c==6)
					{
						printf("DIRECTORY NAME\t\t FILENAME\n");
						printf("Outside directories\t");
						for(j=0;j<flen[i];j++)
							printf("%s\t",f[i][j]);
						
						for(j=0;j<d[i];j++)
						{
							printf("\n%s\t\t",dir2[i][j].dname);
							for(k=0;k<dir2[i][j].fl;k++)
								printf("%s\t",dir2[i][j].fn[k]);
						}
					}
					}while(c<7);
				}
			else
				printf("\nIncorrect password");
		}
	}
	
	}while(choice<3);
  } 
  else if(cc==3)
  {
   int shared[20][20][20];
	char u[2][20],p[2][20],un[20],pw[20],fn[20],f[20][20][20],x[20],d1[20];
  int c,d[10],b,q,ch,i,choice,j,ul=0,flen[20],flag=0,k,l,to;
  for(to=0;to<20;to++)
  {
    flen[to]=0;
   }
	do{
	printf("\n\nMENU\n1.New user 2.User login 3.Exit\nEnter your choice  :");
	scanf("%d",&choice);
	if(choice==1)
	{
		if(ul<10)
		{	printf("Enter username  :  ");
			scanf("%s",un);
			for(j=0;j<ul;j++)
				{if(strcmp(u[j],un)==0)
				{
					printf("Username already exist\n");
					break;
				}}
			if(j==ul)
				{
					strcpy(u[ul],un);
					printf("\nEnter a password   :");
					scanf("%s",p[ul]);
					d[ul]=0;
					ul++;
				}
		}
		else
			printf("Maximum no. of users");
	}
	else if(choice==2)
	{
		printf("\nEnter username  :  ");
		scanf("%s",un);
		for(i=0;i<ul;i++)
		{
			if(strcmp(u[i],un)==0)
				break;
		}
		if(i==ul)
			printf("\nInvalid username\n");
		else
		{
			printf("Enter your password   :");
			scanf("%s",pw);
			if(strcmp(p[i],pw)==0)
				{
					printf("\nSuccessfully logged in");
					do{
						printf("\n\nMENU\n1.Create file\t2.Delete file\t3.Create directory \t4.Create files inside 	directory\t5.Delete files from directory\t6.List directories and files\t7.Return to main menu \nEnter your choice  :  ");
					scanf("%d",&c);
					if(c==1)
					{
			     printf("Enter filename  :  ");
						scanf("%s",fn);
						for(j=0;j<flen[i];j++)
						{if(strcmp(fn,f[i][j])==0)
								break;
						}
						if(j==flen[i])
						{strcpy(f[i][flen[i]],fn);
						flen[i]++;
						printf("File %s added",fn);}
						else
							printf("file aleady exist\n");
					}
					else if(c==2)
					{
						printf("Enter filename  :  ");
						scanf("%s",fn);
						flag=0;
						for(j=0;j<flen[i];j++)
						{if(strcmp(fn,f[i][j])==0)
							{strcpy(f[i][j],f[i][flen[i]-1]);
							flen[i]--;	
							flag=1;
							printf("File %s deleted ",fn);
							break;}
						}
						if(flag==0)
							printf("File not found\n");
					}
					else if(c==3)
					{
					
    				if(d[i]==20)
    				{printf("\nCan't create more directories\n");}
    				else{
						printf("Enter a name for the directory  : ");
						scanf("%s",x);
						strcpy(dir3[i][d[i]].dname,x);
						printf("\nCreated the directory %s ",dir3[i][d[i]].dname);
            printf("\nDo you want to share the directory?(1.yes)");
            int sh;
            scanf("%d",&sh);
            if(sh==1)
             {
               printf("to which user?  :  ");
               int us;
               for(j=0;j<ul;j++)
               {
                 printf("%d. %s      ",j+1,u[j]); 
               }
               scanf("%d",&us);
               shared[us-1][i][d[i]]=1;
              }
						dir3[i][d[i]].fl=0;
						d[i]++;
						}
					}
					else if(c==4)
					{
						printf("\nEnter directory name  :  ");
						scanf("%s",d1);
						for(k=0;k<d[i];k++)
								{
									if(strcmp(dir3[i][k].dname,d1)==0)
										break;
								}
						if(k<d[i])
						{printf("Enter filename  :  ");
						scanf("%s",fn);
						for(j=0;j<dir3[i][k].fl;j++)
						{if(strcmp(fn,dir3[i][k].fn[j])==0)
								break;
						}
						if(j==dir3[i][k].fl)
						{strcpy(dir3[i][k].fn[dir3[i][k].fl],fn);
						dir3[i][k].fl++;
						printf("File %s added to directory %s",fn,dir3[i][k].dname);}
						else
							printf("file aleady exist\n");}
						else
							printf("\nInvalid directory name");
					}
					else if(c==5)
					{
						printf("\nEnter directory name  :  ");
						scanf("%s",d1);
						for(k=0;k<d[i];k++)
								{
									if(strcmp(dir3[i][k].dname,d1)==0)
										break;
								}
						if(k<d[i])
						{printf("Enter filename  :  ");
						scanf("%s",fn);
						for(j=0;j<dir3[i][k].fl;j++)
						{if(strcmp(fn,dir3[i][k].fn[j])==0)
								break;
						}
						if(j==dir3[i][k].fl)
						{printf("\nFile not found");}
						else
							{  
									strcpy(dir3[i][k].fn[j],dir3[i][k].fn[dir3[i][k].fl-1]);
                  dir3[i][k].fl--;
									printf("\nDeleted file %s from %s",fn,dir3[i][k].dname);	
							}
						}
						else
							printf("\nInvalid directory name");
					}
					else if(c==6)
					{
            printf("Outside directories\t");
						for(j=0;j<flen[i];j++)
							printf("%s\t",f[i][j]);
            printf("\nInside user directories");
            printf("\nDIRECTORY NAME\t FILENAME\n");
						for(j=0;j<d[i];j++)
						{
							printf("\n%s\t\t",dir3[i][j].dname);
							for(k=0;k<dir3[i][j].fl;k++)
								printf("%s\t",dir3[i][j].fn[k]);
						}
            printf("\nShared directories  : \n");
            printf("\nDIRECTORY NAME\t FILENAME\n");
            int oi;
            for(oi=0;oi<ul;oi++)
            {
              for(j=0;j<d[i];j++)
						{
              if ( shared[i][oi][j]==1)
							{printf("\n%s\t\t",dir3[oi][j].dname);
							for(k=0;k<dir3[oi][j].fl;k++)
								printf("%s\t",dir3[oi][j].fn[k]);}
						}
            }
					}
					}while(c<7);
				}
			else
				printf("\nIncorrect password");
		}
	}
	
	}while(choice<3);
  }
  else{}
  }while(cc<4);
}
