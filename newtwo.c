#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct directory{
	char dname[10];
	char fname[10][10];
	int cnt;
	int fcnt;
};
struct
{
char dname[10],fname[10][10],fn[10];
int fcnt,cnt;
}dir,two[2][10];
struct userstruct{
 char password[10];
 struct directory dir[10];
 char fname[10][10];
 struct directory shared;
 int cnt;
};
void main()
{
int n,m=0,a,i,j=0,flag,x=0,u,choice,fv=0;
char ps[10],nfdel[10],pswd[10],xyz[10],nddel[10];
struct userstruct users[2];
int ss,b,f,h,y;
char nd[10],newdir[10];
printf("TWO LEVEL DIRECTORY\n--------------------------------------------------\n");
printf("set a password of user1:\t");
scanf("%s",users[0].password);
printf("password set successfully... please use this password to login to user1\n");
printf("set a password of user2:\t");
scanf("%s",users[1].password);
printf("password set successfully... please use this password to login to user2\n");
for(i = 0; i<10; i++){
	users[1].dir[i].cnt = 0;
}
for(i = 0; i<10; i++){
	users[0].dir[i].cnt = 0;
}
users[0].cnt = 0;
users[1].cnt = 0;
users[1].shared.cnt = 0;
users[0].shared.cnt = 0;
do{
printf("\n1.user1\n2.user2\n3.exit\n");
scanf("%d",&n);
if(n==1||n==2)
{
    if(n==1){
   
   strcpy(pswd,users[0].password);
    u=0;}
    else if(n==2){
    u=1;
     strcpy(pswd,users[1].password);}
    printf("PASSWORD:\n");
    scanf("%s",ps);
    if(strcmp(ps,pswd)==0)
    {
     printf("password accepted...\n\n\n********************************USER%d**************************************\n",u+1);
      do{
       printf("\n1.ENTER   2.CREATE DIRECTORY    3.DELETE A DIRECTORY   4.LIST   5.CREATE FILE    6.DELETE FILE   7.EXIT 8.SHARED FILES 9.SHARE FILE\n");
       scanf("%d",&b);
       switch(b)
      {
     case 1:
{
printf("name of directory:\t");
      scanf("%s",xyz);
flag=0;
for(x=0;x<m;x++){
if(strcmp(users[u].dir[x].dname,xyz)==0)
{
flag=1;
     do{   
      printf("\n1.add file   2.delete    3.list   4.exit 5.share file\n");
      scanf("%d",&a);
      switch(a)
      {
       case 1:
       {
        flag=0;
        printf("name of new file:\n" );
        scanf("%s",nd);
        i = 0;
        for(i=0;i<users[u].dir[x].cnt;i++)
         {
         if(strcmp(nd,users[u].dir[x].fname[i])==0)
           {
           flag=1;
           printf("sorry...file name already exists\n"); 
           }
         }
        if(flag==0)
         {
         users[u].dir[x].cnt++;
         strcpy(users[u].dir[x].fname[users[u].dir[x].cnt],nd);
//        two[u][x].fcnt++;
        printf("\nfile created\n");
         } 
        break;
       }
       case 2:
       {
       flag=0;
       printf("enter the name of file to delete\n");
       scanf("%s",nd);
       i = 0;
       for(i=0;i<users[u].dir[x].cnt;i++)
      {
         if(strcmp(nd,users[u].dir[x].fname[i])==0)
        {
            flag=1;
            printf("file found...\n");
            while(i<users[u].dir[x].cnt)
            {
             strcpy(users[u].dir[x].fname[i],users[u].dir[x].fname[i+1]);
             i++;
           }
         printf("deleted...\n");
         users[u].dir[x].cnt--; 
        }
      }
     if(flag==0)
         printf("file does not exist\n");
       break;
       }
      case 3:
      {
      if(users[u].dir[x].cnt==0){
       printf("\nempty\n");}
       else{
      printf("files are\n");
      for(i=0;i<users[u].dir[x].cnt;i++)
      {   
             printf("%s\n",users[u].dir[x].fname[i]);
            
       }}

       break;
      }
      case 5:
       {
        flag=0;
        printf("name of file:\n" );
        scanf("%s",nd);
        i = 0;
        for(i=0;i<users[(u+1)%2].shared.cnt;i++)
         {
         if(strcmp(nd,users[(u+1)%2].shared.fname[i])==0)
           {
           flag=1;
           printf("sorry...file name already exists\n"); 
           }
         }
        if(flag==0)
         {
         users[(u+1)%2].shared.cnt++;
         strcpy(users[(u+1)%2].shared.fname[users[(u+1)%2].shared.cnt],nd);
//        two[u][x].fcnt++;
        printf("\nfile shared\n");
         } 
        break;
       }
      }
      }while(a!=4);
printf("\nexiting from directory...\n");
}
}
if(flag==0)
printf("directory does not exist\n");
break;
}
case 2:
{flag=0;
printf("name of new directory:\t");
scanf("%s",newdir);
for(y=0;y<m;y++)
{
    if(strcmp(newdir,users[u].dir[y].dname)==0){
                 flag=1;
             printf("sorry...this name already exists\n");}
}
if(flag==0)
{
strcpy(users[u].dir[y].dname,newdir);
printf("directory created successfully...\n");
m++;
x++; }    
break;
}
case 3:
{
flag=0;
printf("name of directory:\t");
scanf("%s",nddel);
for(x=0;x<m;x++){
if(strcmp(users[u].dir[x].dname,nddel)==0)
{
flag=1;
 h=x;
     while(h<m)
     {
      strcpy(users[u].dir[h].dname,users[u].dir[h+1].dname);
      h++;
     }

printf("directory along with its files is deleted\n");
m--;      
}
}
if(flag==0)
   printf("directory does not exist\n");
break;
}
case 4:
{
if(m==0&&fv==0)
      {
       printf("empty\n");
      }
      else
       {
    printf("directories are:\n"); 
    if(m==0)
       printf("empty...\n");
    
    for(x=0;x<m;x++)
     {
      printf("%s\n",users[u].dir[x].dname);
     }
     
    printf("files are:\n");
  if(fv==0)
       printf("empty...\n");
    else{
    for(i=0;i<fv;i++)
     {
      printf("%s\n",users[u].fname[i]);
     }
}
       }
break;
}
case 5:
{
   printf("name of new file:\t");
   scanf("%s",nd);
   flag=0;
   for(i=0;i<fv;i++)
   {
      if(strcmp(nd,users[u].fname[i])==0){
              flag=1;
              printf("file name already exists\n");
            }
}
if(flag==0) {
   strcpy(users[u].fname[i],nd);
   fv++;}


break;
}
   case 6:
{
printf("name of file to delete:\t");
scanf("%s",nd);
flag=0;
for(i=0;i<fv;i++){
if(strcmp(users[u].fname[i],nd)==0)
{
flag=1;
 h=i;
     while(h<fv)
     {
      strcpy(users[u].fname[h],users[u].fname[h+1]);
      h++;
     }

printf("file is deleted\n");
fv--;      
}
}
if(flag==0)
   printf("file doesnot exist\n");
break;
}
case 8:
{
if(users[u].shared.cnt==0)
      {
       printf("empty\n");
      }
      else
       {
     
    printf("files are:\n");
  if(users[u].shared.cnt==0)
       printf("empty...\n");
    else{
    for(i=0;i<users[u].shared.cnt;i++)
     {
      printf("%s\n",users[u].shared.fname[i]);
     }
}
       }
 break;
 }
case 9:
{
flag=0;
printf("name of file:\n" );
scanf("%s",nd);
i = 0;
for(i=0;i<users[(u+1)%2].shared.cnt;i++)
 {
 if(strcmp(nd,users[(u+1)%2].shared.fname[i])==0)
   {
   flag=1;
   printf("sorry...file name already exists\n"); 
   }
 }
if(flag==0)
 {
 users[(u+1)%2].shared.cnt++;
 strcpy(users[(u+1)%2].shared.fname[users[(u+1)%2].shared.cnt],nd);
//        two[u][x].fcnt++;
printf("\nfile shared\n");
 } 
break;
}
}    
    }while(b!=7);
     printf("exiting from user%d...\n",u+1);  
    }
   else
      printf("\nincorrect password.Try again...\n");
}
}while(n!=3);
}
