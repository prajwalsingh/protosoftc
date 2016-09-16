#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

				 typedef struct
				 {
				 char logid[200];
				 char pass[200];
				 char fname[200];
				 char lname[200];
				 }Info;

				 typedef struct
				 {
				 char userid[200];
				 char pass[200];
				 char fname[200];
				 char lname[200];
				 int  pcomb[4][1];
				 }Login;

             typedef struct
             {
             char wall[2000];
             }Group;

             typedef struct
             {
             char type[100];
             char date[100];
             int  time;
             char timehms;
             char about[500];
             }Sgame;

             typedef struct
             {
              char id[200];
              char pass[200];
              char fname[200];
              char lname[200];
              int  pcomb1[4][1];
             }Frnd;

             typedef struct
             {
              char id[200];
              char pass[200];
              char fname[200];
              char lname[200];
             }Frndrqst;
/******************************FUNCTION PROTOTYPE**************************/
			   int  screen_1();
			   int  screen_2();
			   void screen_3();
			   void for_all();
			   void password();
 	    	   void sucsess();
			   int  fpresent(char p[200]);
            void savedetail1(Login *inf1,FILE*);
			   int  logincheck(Login *log1);
			   void logconfm(Login*,char p[200]);
			   void welcome(Login *log3);
			   int  screen_4(Login *log4,char p[200]);
			   void profpic(Login *log5);
			   void profscreen(Login *log6,char p[200]);
			   void read(Login *all);
            void screen_5(char p[200]);
            void wallpost(char p[200]);
            void storearea(Login *log7,char p[200]);
            void game(char p[200]);
            void rgame(char p[200]);
            void seesave(char p[200]);
            void seegame(char p[200]);
            void friends(char p[200]);
            int  searchf(char p[200]);
            void makefrnd(char p[200],char f[200]);
            int  checkr(char p[200],int *q);
            void seefrnrqst(char p[200]);
            void finalFRQ(int,char p[200]);
            void acptfrnd(char p[200],char frnd[200],int);
            void seefrnlist(char p[200]);
            int  checkonline(char p[200]);
            void seeonline(char p[200]);
            void startchat(char p[200],char fid[200],char frfname[100],char frlname[100],char frnid[200]);
            void message(char p[200]);
            void link(char path1[200],char path2[200]);
/**********************************************************************************************************************************/

/*****************************************************GLOBAL VARIABLE**************************************************************/
			    Info  *inf;
			    Login *log;
             Group *gp;
			    FILE *f=NULL,*f1,*f2,*f3;
             Sgame *gam;
             Frnd  *frnd;
             Frndrqst *frst;
			    char roota;
             int  point=0;
             char path1[200]={"c:\\PSOFT\\"};
/**********************************************************************************************************************************/

int main()
{
int ch;
y:
ch=0;
system("cls");
ch=screen_1();
switch(ch)
{
case 1:
screen_2();
break;
case 2:
screen_3();
break;
case 3:
exit(0);
}
goto y;
}

int screen_1()
{
int i,j,k,ch;
p:
system("cls");
i=0;j=0;k=0;ch=0;
for(i=0;i<78;i++)
printf("=");
printf("\n");
for(i=5;i<21;i++)
{
if(i==5)
for_all();
printf("||");
for(j=0;j<75;j++)
{
printf(" ");
if(i==11 && j==30)
{
printf("1. SignUp");
k=0;
break;
}
else if(i==13 && j==30)
{
printf("2. Login");
k=-1;
break;
}
}
if(i==11 || i==13)
for(j=k;j<35;j++)
printf(" ");
printf("||");
printf("\n");
}
printf("||\t\t\t\t\t\t     Made By : Prajwal Singh ||\n\n");
printf("\t\t Enter Your Choise [(3) For Exit] : ");
fflush(stdin);
scanf("%d",&ch);
if(ch!=1 && ch!=2 && ch!=3)
goto p;
return ch;
}

int screen_2()
{
int i=0,j=0,check=0;
char path[200]={"c:\\PSOFT\\"},cpy1[200];
inf=(Info*)malloc(sizeof(Info));
  x:
  for_all();
    for(i=0;i<78;i++)
  printf("=");
  printf("\n\n\t\t <----Enter (*) To Exit !!Not Work in Password------>");
  printf("\n\n\n");
      for(i=0;i<20;i++)
      printf(" ");
      printf("Enter Id For Log In : ");   fflush(stdin);
      gets(inf->logid);
      if(strcmp(inf->logid,"*")==0)
        return;
      if(strlen(inf->logid)<=3)
      {
       printf("\n\n\t\t\tID NAME IS TOO SHORT\n\n\t\t\t TRY ANOTHER ID NAME MORE THAN 3 Character..\n\n\t\t\t PRESS ANY KEY FOR CONTINUE..");
       getch();
       goto x;
      }
      check=fpresent(inf->logid);
      if(check==-1)
      goto x;
      for(i=0;i<20;i++)
      printf(" ");
      fflush(stdin);
      printf("Enter Password      : ");   fflush(stdin);
      password(inf,0);
      printf("\n");
      for(i=0;i<20;i++)
      printf(" ");
      fflush(stdin);
      printf("Enter First Name    : ");   fflush(stdin);
      gets(inf->fname);
      if(strcmp(inf->fname,"*")==0)
        return;
      for(i=0;i<20;i++)
      printf(" ");
      fflush(stdin);
      printf("Enter Last Name     : ");   fflush(stdin);
      gets(inf->lname);
      if(strcmp(inf->lname,"*")==0)
        return;
      strcat(path,inf->logid);
      f=fopen(path,"w");
      fprintf(f,"%s",inf->logid);
      fprintf(f,"\n%s",inf->pass);
      fprintf(f,"\n%s",inf->fname);
      fprintf(f,"\n%s",inf->lname);
      fclose(f);
      sucsess();
}

void for_all()
{
int i=0,j=0,k=0;
system("cls");
  for(i=0;i<78;i++)
  printf("=");
printf("\n");
  for(i=0;i<5;i++)
  {
  printf("||");
  for(j=0;j<75;j++)
  {
  printf(" ");
    if(i==3 && j==28)
    {
    printf("PROTOSOFT");
    k=-2;
    break;
    }

    else if(i==4 && j==28)
    {
    printf("---------");
    k=-2;
    break;
    }
  }
  if(i==3 || i==4)
    for(j=k;j<35;j++)
    printf(" ");
printf("||");
printf("\n");
}
}

/*********************************************************************************************************************************
                                                    PASSWORD   MANAGER
*********************************************************************************************************************************/

void password(Info *infpass,int show)
{
int i=0,end=0,j=0,k=0;
char pass[200]={'\0'},ch;
  while(end!=13)
  {
  fflush(stdin);
  ch=getch();
  end=ch;
    if(end!=13 && end!=8)
    {
    printf("*");
    pass[i]=ch;
    i++;
    }
    if(i>0)
    {
     if(end==8)
    {
    system("cls");
    i--;
    for_all();
    for(j=0;j<78;j++)
    printf("=");
    if(show!=1)
    printf("\n\n\t\t <----Enter (*) To Exit !!Not Work in Password------>");
    printf("\n\n");
    for(k=0;k<20;k++)
    printf(" ");
    printf("Enter Id For Log in : %s",infpass->logid);
    printf("\n");
    for(k=0;k<20;k++)
    printf(" ");
    printf("Enter Password      : ");
    for(j=0;j<i;j++)
    printf("*");
    }
    else if(end==13)
    break;
   }
  }
  pass[i]='\0';
  strcpy(infpass->pass,pass);
}

/*********************************************************************************************************************************
*********************************************************************************************************************************/

void sucsess()
{
long int j=0;
printf("\n\n\n");
for(j=0;j<78;j++)
printf("*");
printf("\n\t\t\\\\             // ||== ||   ==== ===== ||\\\\ //|| ||== ");
printf("\n\t\t  \\\\  //\\\\   //   ||== ||   ||   || || ||  =  || ||==");
printf("\n\t\t    \\\\     \\\\     ||== ||== ==== ===== ||     || ||==");
printf("\n\t\t\t\t\t To Protosoft                                      ");
printf("\n\n\t\t\t\t\t Your Id Will Created \n\t\t\t You Are Redirected To Main Page With in 5 sec");
for(j=0;j<99999999;j++)
{printf("");printf("");printf("");}
}

int fpresent(char p[200])
{
char path[200]={"c:\\PSOFT\\"};
strcat(path,p);
f=fopen(path,"r");
if(f!=NULL)
{
printf("\n\n\t\t This Id Name Is Already Present Try Another Name\n\t\t Press Enter For Continue");
fclose(f);
getch();
return -1;
}
return 0;
}

void savedetail1(Login *inf1,FILE *f2)
{
fprintf(f2,"%s",inf1->userid);
fprintf(f2,"\n%s",inf1->pass);
fprintf(f2,"\n%s",inf1->fname);
fprintf(f2,"\n%s",inf1->lname);
}

void screen_3()
{
int i=0,ch=0;
v:
for_all();
log=(Login*)malloc(sizeof(Login));
printf("\n\n");
  for(i=0;i<20;i++)
  printf(" ");
printf("User ID : ");
fflush(stdin);
gets(log->userid);
  for(i=0;i<20;i++)
  printf(" ");
printf("Password : ");
password(log,1);
ch=logincheck(log);
if(ch==13)
goto v;
if(ch==77 || ch==109)
ch=0;
}

/*********************************************************************************************************************************
                                                     LOGIN CHECK & GIVE ACCESS
*********************************************************************************************************************************/
int logincheck(Login *log1)
{
int ch;
char p[200],path[200]={"c:\\PSOFT\\"};
Login *log2;
log2=(Login*)malloc(sizeof(Login));
strcat(path,log1->userid);
f=fopen(path,"r");
  if(f!=NULL)
  {
  fflush(stdin);
  fscanf(f,"%s",log2->userid); fflush(stdin);
  fscanf(f,"\n%s",log2->pass); fflush(stdin);
  fscanf(f,"\n%s",log2->fname); fflush(stdin);
  fscanf(f,"\n%s",log2->lname);
  fclose(f);
				if(strcmp(log1->pass,log2->pass)==0)
				{
				 logconfm(log2,path);
				 return 0;
            }

    else
    {
    printf("\n\n\n\t\t\t Either ID OR PASSWORD IS INCORRECT \n\t\t\t Press Enter For Try Again Or\n\t\t\t Press M for Back To Main Page");
    fclose(f);
    p:
    fflush(stdin);
    ch=getch();
    if(ch!=13 && ch!=109 && ch!=77)
    goto p;
    return ch;
    }
  }
  else
  {
  printf("\n\n\n\t\t\t Either ID OR PASSWORD IS INCORRECT  \n\t\t\t Press Enter For Try Again Or\n\t\t\t Press M for Back To Main Page");
  z:
  fflush(stdin);
  ch=getch();
  if(ch!=13 && ch!=109 && ch!=77)
  goto z;
  return ch;
  }
return 0;
}

/*********************************************************************************************************************************
*********************************************************************************************************************************/

/*********************************************************************************************************************************
                                                           HOME PAGE
*********************************************************************************************************************************/
void logconfm(Login *log3,char p[200])
{
char cpy1[200],cpy2[200],ch1[200]={"vis.pj"},ch2[200]={"acs.pj"},cpy3[200],cpy4[200],cpy5[200];
int  asc=0;
clrscr();
strcpy(cpy1,p);
strcpy(cpy2,p);
strcat(cpy1,ch1);
strcat(cpy2,ch2);
f1=fopen(cpy2,"r");
  if(f1!=NULL)
    {
      fscanf(f1,"%d",&asc);
      fclose(f1);
    }
  else
    {
      f1=fopen(cpy2,"w");
      fprintf(f1,"%d",1);
      fclose(f1);
    }
 if(asc!=1)
 {
  f1=fopen(cpy2,"w");
  fprintf(f1,"%d",1);
  fclose(f1);
  f=fopen(cpy1,"w");
  fprintf(f,"%d",1);
  fclose(f);
 // welcome(log3);
  screen_4(log3,p);
 }
 else
 {
  printf("\n\n\n\n\n\t\t\t YOU ALLREADY LOGIN WITH YOUR ACCOUNT\n\n\t\t\t PRESS ANY KEY TO GO BACK...\n");
  getch();
 }
}
/*********************************************************************************************************************************
*********************************************************************************************************************************/

void welcome(Login *log3)
{
int i=0,j=0,k=0,l=2,a=0,b=0,c=0,d=30,m=0;
long int de=0;
 while(k<50)
 {
   if(k<40)
   {
    while(i<a)
    {printf("\n");i++;}
    while(j<b)
    {printf(" ");j++;}
    printf("%s %s",log3->fname,log3->lname);
    while(m<d)
    { printf(" ");
    if(d>0)
    m++;
    }
    printf("WELCOME TO PROTOSOFT");
    for(de=0;de<99999999;de++){}
    clrscr();
   }
   else
   {
     while(i<a)
     {
     printf("\n");
     i++;
     }
     while(m<d)
     {
     printf(" ");
     m++;
     }
     printf("WELCOME TO PROTOSOFT");
     while(j<b)
     {
     printf(" ");
     j++;
     }
     printf("%s %s",log3->fname,log3->lname);
     for(de=0;de<99999999;de++){}
    clrscr();
   }
       if(l>14)
    l=2;
    textcolor(l);
 if((k/5)%2==0)
  a++;
 else
 a--;
  b++;
  l++;
  d--;
 k++;
  i=0;j=0,m=0;
  if(d==0)
  {
  d=20;
  b=10;
  }
 }
}

/*********************************************************************************************************************************
                                                       HOME SCREEN 2
*********************************************************************************************************************************/

int screen_4(Login *log4,char p[200])
{
int i,j,k,ch;
char ch1;
char cpy1[200],cpy2[200],cpy3[200],cpy4[200],ch2[200]={"vis.pj"},ch3[200]={"acs.pj"};
x:
clrscr();
i=0,j=0,k=0,ch=0;
for(i=0;i<80;i++)
printf("");
profpic(log4);
printf("\n  P:Change Profile Pic\n  1.Store Data \t\t\t\t\t 2.Friends\n  3.Messages \t\t\t\t\t 4.See Save Data \n  5.Pictures \t\t\t\t\t 6.Exit");
printf("\n");
for(i=0;i<80;i++)
printf("");
screen_5(p);
printf("\nEnter Your Choise : ");
fflush(stdin);
scanf("%c",&ch1);
ch=ch1;
 system("cls");
  switch(ch)
  {
  case 80:
  profscreen(log4,p);
  break;
  case 52:
  seesave(p);
  break;
  case 87:
  wallpost(p);
  break;
  case 49:
  storearea(log4,p);
  break;
  case 50:
  friends(p);
  break;
  case 51:
  message(p);
  break;
  case 54:
  strcpy(cpy1,p);
  strcat(cpy1,ch2);
  f=fopen(cpy1,"w");
  fprintf(f,"%d",0);
  fclose(f);
  strcpy(cpy2,p);
  strcat(cpy2,ch3);
  f=fopen(cpy2,"w");
  fprintf(f,"%d",0);
  fclose(f);
  exit(1);
  break;
  }
goto x;
}
/*********************************************************************************************************************************
*********************************************************************************************************************************/

void profpic(Login *log5)
{
int i=0,a=0,j=0;
read(log5);
  for(i=0;i<5;i++)
  {
      if(log5->pcomb[i][1]==1)
      {
      a=log5->pcomb[i][0];
      break;
      }
    }
printf("\n||");
for(i=1;i<=50;i++)
{
  printf("%c",a);
    if(i%10==0)
    {
    printf("||");
	  if(i==10)
	    for(j=0;j<5;j++)
	     if(log5->pcomb[j][1]==2)
	     {
	     a=log5->pcomb[j][0];
	     break;
	     }
	  if(i==20)
	    for(j=0;j<5;j++)
	     if(log5->pcomb[j][1]==3)
	     {
	     a=log5->pcomb[j][0];
	     break;
	     }
	  if(i==30)
	    for(j=0;j<5;j++)
	     if(log5->pcomb[j][1]==4)
	     {
	     a=log5->pcomb[j][0];
	     break;
	     }
	  if(i==40)
	    for(j=0;j<5;j++)
	     if(log5->pcomb[j][1]==5)
	     {
	     a=log5->pcomb[j][0];
	     break;
	     }
    if(i==20){printf("\t\t\t Name   : %s %s",log5->fname,log5->lname);}
    else if(i==40){printf("\t\t\t User ID : %s",log5->userid);}
    printf("\n||");
   }
}
for(i=0;i<10;i++)
printf("=");
printf("||");
}

void profscreen(Login *log6,char p[200])
{
int i,a,b,re=0,j;
char cpy2[200]={'\0'};
p:
system("cls");
i=0;a=4;b=1;j=0;
printf("\n\t\t\t\t PROFILE PIC \n\t\t\t\t ------- ---");
for(i=0;i<5;i++)
{printf("\n%d> %c",(i+1),(i+1));}
if(i%2!=0)
printf("\n");
printf("\n Select Combination Of Logo To Make Profile Pic");
printf("\n Exmaple: First combo: 2,Second Combo: 4 And Postion for 1: 2,Positon For 4 : 1\n");
printf("(%d)->||",b);b++;
for(i=1;i<=50;i++){
printf("%c",a);
if(i%10==0){printf("||"); printf("\n(%d)->||",b);b++; if((i/10)%2==0) a=4; else a=2;}
}
for(i=0;i<10;i++)printf("=");printf("||");
if(re<1){printf("\n Enter First Combo : ");fflush(stdin);scanf("%d",&log6->pcomb[0][0]); if((log6->pcomb[0][0]>5) || (log6->pcomb[0][0])<0){printf("Wrong Choise");getch();goto p;}}else {printf("\n Enter First Combo: %d",log6->pcomb[0][0]);}
if(re<2){printf("\n Enter Position For First Combo : ");fflush(stdin);scanf("%d",&log6->pcomb[0][1]);if((log6->pcomb[0][1])>5 || (log6->pcomb[0][1])<0){printf("Wrong Choise");getch();re=1;goto p;}}else{printf("\n Enter First Combo Position : %d",log6->pcomb[0][1]);}
if(re<2){printf("\n Enter Second Combo : ");fflush(stdin);scanf("%d",&log6->pcomb[1][0]); if((log6->pcomb[1][0]>5) || (log6->pcomb[1][0])<0){printf("Wrong Choise");getch();goto p;}}else {printf("\n Enter First Combo: %d",log6->pcomb[1][0]);}
if(re<3){printf("\n Enter Position For Second Combo : ");fflush(stdin);scanf("%d",&log6->pcomb[1][1]);if((log6->pcomb[1][1])>5 || (log6->pcomb[1][1])<0){printf("Wrong Choise");getch();re=2;goto p;}}else {printf("\n Enter Second Combo Position : %d",log6->pcomb[1][1]);}
if(re<3){printf("\n Enter Third Combo : ");fflush(stdin);scanf("%d",&log6->pcomb[2][0]); if((log6->pcomb[2][0]>5) || (log6->pcomb[2][0])<0){printf("Wrong Choise");getch();goto p;}}else {printf("\n Enter First Combo: %d",log6->pcomb[2][0]);}
if(re<4){printf("\n Enter Position For Third Combo : ");fflush(stdin);scanf("%d",&log6->pcomb[2][1]);if((log6->pcomb[2][1])>5 || (log6->pcomb[2][1])<0){printf("Wrong Choise");getch();re=3;goto p;}}else {printf("\n Enter Third Combo Position : %d",log6->pcomb[2][1]);}
if(re<4){printf("\n Enter Fourth Combo : ");fflush(stdin);scanf("%d",&log6->pcomb[3][0]); if((log6->pcomb[3][0]>5) || (log6->pcomb[3][0])<0){printf("Wrong Choise");getch();goto p;}}else {printf("\n Enter First Combo: %d",log6->pcomb[3][0]);}
if(re<5){printf("\n Enter Position For Fourth Combo : ");fflush(stdin);scanf("%d",&log6->pcomb[3][1]);if((log6->pcomb[3][1])>5 || (log6->pcomb[3][1])<0){printf("Wrong Choise");getch();re=4;goto p;}}else {printf("\n Enter Fourth Combo Position : %d",log6->pcomb[3][1]);}
if(re<5){printf("\n Enter Fifth Combo : ");fflush(stdin);scanf("%d",&log6->pcomb[4][0]); if((log6->pcomb[4][0]>5) || (log6->pcomb[4][0])<0){printf("Wrong Choise");getch();goto p;}}else {printf("\n Enter Fifth Combo: %d",log6->pcomb[4][0]);}
if(re<6){printf("\n Enter Position For Fifth Combo : ");fflush(stdin);scanf("%d",&log6->pcomb[4][1]);if((log6->pcomb[4][1])>5 || (log6->pcomb[4][1])<0){printf("Wrong Choise");getch();re=5;goto p;}}
f3=fopen("pic","w");
printf("\n Hi............");getch();
fprintf(f3,"%s",log6->userid);
fprintf(f3,"\n%s",log6->pass);
fprintf(f3,"\n%s",log6->fname);
fprintf(f3,"\n%s",log6->lname);
printf("\n Hi............");
fflush(stdin);
  for(i=0;i<5;i++)
  {
    for(j=0;j<2;j++)
    fprintf(f3,"\n%d",log6->pcomb[i][j]);
  }

}

void read(Login *all)
{
int i=0,j=0;
char cpy1[200];
fflush(stdin);
link(cpy1,all->userid);
f=fopen(cpy1,"r");
fscanf(f,"%s",all->userid);
fscanf(f,"\n%s",all->pass);
fscanf(f,"\n%s",all->fname);
fscanf(f,"\n%s",all->lname);
printf("\n");
for(i=0;i<5;i++)
  for(j=0;j<2;j++)
  fscanf(f,"\n%d",&all->pcomb[i][j]);
fclose(f);
}

void screen_5(char p[200])
{
int i=0,point1=0,j=0;
char copy[200]={'\0'},post[2000]={'\0'},ch[200]={'\0'},ch1;
printf("\n\t\t\t\tWall Post\n\t\t\t\t---- ----\n");
strcpy(copy,p);
strcat(copy,"point.pj");
f=fopen(copy,"r");
if(f!=NULL)
{
fscanf(f,"%d",&point1);
fscanf(f,"\n%c",&ch1);
point=point1;
fclose(f);
}
if(point!=0)
{
  for(i=1;i<=point1;i++)
  {
    for(j=0;j<80;j++)
    printf("=");
    for(j=0;p[j]!='\0';j++)
    ch[j]=p[j];
    ch[j]=ch1;
    j++;
    ch[j]='\0';
    f=fopen(ch,"r");
    fgets(post,2000,f);
    fclose(f);
    printf("\n Post %d : %s\n",i,post);
    point--;
    printf("\n Total Comments : 0 \t\t Likes : 0 \n\n");
    for(j=0;j<80;j++)
    printf("=");
    printf("\n");
    ch1--;
  }
	  printf("\n\t\t Enter W For Write Wall Post.....\n\n");
  point=point1;
}
else
{
for(i=0;i<78;i++)
printf("=");
printf("\n\n\n\t\t Enter W For Write Wall Post.....\n\n");
for(i=0;i<78;i++)
printf("=");
}
printf("\n");
}

void wallpost(char p[200])
{
int i=0,a=64;
char copy[200],ch[200]={'\0'},ch1='A';
clrscr();
strcpy(copy,p);
strcat(copy,"point.pj");
if(point!=0)
{
f=fopen(copy,"r");
fscanf(f,"%d",&point);
fscanf(f,"\n%c",&ch1);
fclose(f);
a=ch1;
}
point++;
a++;
if(a>91)
a=a+32;
f=fopen(copy,"w");
fprintf(f,"%d",point);
fprintf(f,"\n%c",a);
fclose(f);
ch1=a;
gp=(Group*)malloc(sizeof(Group));
printf("\n\t\t\t Wall Post\n\t\t\t ---- ----\n\n\n");
printf("\n Enter Post Want To Share (!Careful : Continue Writing Without \n Press Enter  For New Line If You Press Enter It Submit Your Post.And in Home New Post Are  Always Have 1 Place. \n You Also Use Similey Press (Left alt+Num keyPad Number eg: Lalt+1))\nOnly 25 older post are kept \n Write Your Post=> ");
gets(gp->wall);
for(i=0;p[i]!='\0';i++)
ch[i]=p[i];
ch[i]=ch1;
i++;
ch[i]='\0';
f=fopen(ch,"w");
fprintf(f,"%s",gp->wall);
fclose(f);
}

void storearea(Login *log7,char p[200])
{
int ch;
p:
ch=0;
clrscr();
printf("\n\t\t\t Store Data\n\t\t\t ----- ----");
printf("\n\n Type Of Data You Want To Save : \n 1.Daily Life \n 2.Game \n\n Enter Your Choise(3.Home) : ");
fflush(stdin);
scanf("%d",&ch);
if(ch!=1 && ch!=2 &&ch!=3)
goto p;
switch(ch)
{
case 1:
//dailylife();
break;
case 2:
game(p);
break;
case 3:
break;
}
if(ch==1 || ch==2)
goto p;
}

void game(char p[200])
{
int ch;
p:
clrscr();
ch=0;
printf("\n\t\t\t Game Information \n\t\t\t ---- -----------");
printf("\n\n Select Type Of Game : \n 1.Rubics Cube \n\n\n\n Enter Your Choise(2.Home): ");
fflush(stdin);
scanf("%d",&ch);
if(ch!=1 && ch!=2)
goto p;
switch(ch)
{
case 1:
rgame(p);
break;
case 2:
break;
}
if(ch==1)
goto p;
}

void rgame(char p[200])
{
char ch[100];
int i=0;
gam=(Sgame*)malloc(sizeof(Sgame));
clrscr();
printf("\n\t\t\t Rubics Cube Information\n\t\t\t ------ ---- -----------\n");
strcpy(gam->type,"Rubics Cubes");
printf("\n\n Enter Date(DD/MM/YY) : ");fflush(stdin);
gets(gam->date);
printf("\n Enter How Time Taken To Solve Cube(ex: 1,2,3,.... ) : ");fflush(stdin);
scanf("%d",&gam->time);
printf("\n Enter Hour(H),Minute(M) Or Second(S) : ");fflush(stdin);
scanf("%c",&gam->timehms);
printf("\n Enter Something About Game : ");fflush(stdin);
gets(gam->about);
strcpy(ch,p);
strcat(ch,"rgame.pj");
f=fopen(ch,"a");
fprintf(f,"\nGame Type : %s",gam->type);
fprintf(f,"\nDate      : %s",gam->date);
fprintf(f,"\nTime      : %d%c",gam->time,gam->timehms);
fprintf(f,"\nAbout     : %s\n",gam->about);
for(i=0;i<80;i++)
fprintf(f,"-");
fclose(f);
}

void seesave(char p[200])
{
char ch[200],ch1;
int ch2=0,tot=0;
x:
ch2=0;
clrscr();
printf("\n\t\t\t Save Details \n\t\t\t ---- -------\n\n\n\n 1.Daily Life \n\n 2.Game \n\n Enter Your Choise(3.Home) : ");fflush(stdin);
scanf("%d",&ch2);
if(ch2!=1 && ch2!=2 && ch2!=3)
goto x;
switch(ch2)
{
case 2:
clrscr();
printf("\n\t\t\t Game Details \n\t\t\t ---- -------\n\n");
strcpy(ch,p);
strcat(ch,"rgame.pj");
fflush(stdin);
f=fopen(ch,"r");
while(!feof(f))
{
ch1=fgetc(f);
printf("%c",ch1);
}
printf("\n\n Press Any Key For Go Back...");
getch();
break;
case 3:
break;
}
if(ch2==1 || ch2==2)
goto x;
}

void friends(char p[200])
{
int i=0,ch,rqst=0,totf=0,online=0;
x:
clrscr();
ch=0;
printf("\n\t\t\t\t Friends\n\t\t\t\t -------\n\n");
for(i=0;i<80;i++)
printf("");
rqst=checkr(p,&totf);
online=checkonline(p);
printf("\n\n  1.Home \t\t\t\t\t\t 2.Search Friends\n  3.Friend Request(%d) \t\t\t\t\t 4.Friend List(%d) \n  5.Online Friends(%d)",rqst,totf,online);
printf("\n");
for(i=0;i<80;i++)
printf("");
printf("\n\n\n  Enter Your Choice : ");
fflush(stdin);
scanf("%d",&ch);
switch(ch)
{
case 1:
break;
case 2:
searchf(p);
break;
case 3:
if(rqst!=0){
seefrnrqst(p);
}
else {
clrscr(); printf("\n\n\n\n\n\n\t\t\t YOU HAVE 0 FRIEND REQUEST \n\n\t\t\t PRESS ANY KEY TO GO BACK");}
getch();
break;
case 4:
if(totf!=0)
{seefrnlist(p);}
else{ clrscr(); printf("\n\n\n\n\n\t\t\t        NO FRIENDS........  \n\n\t\t\t PRESS ANY KEY TO GO BACK");}
getch();
break;
case 5:
seeonline(p);
break;
}
if(ch==2 || ch==3 || ch==4 || ch==5 || ch==6)
goto x;

else if(ch!=1)
goto x;
}

/**********************************************************************************************************************************
                                                    SEARCH FRIEND
**********************************************************************************************************************************/

int searchf(char p[200])
{
int i=0,a=0,j=0,opt=0,tot=0,stop=0;
char searchn[200]={'\0'},cpy1[200],ch,cpy2[200],cpy3[200],ch2[200]={"totfr.pj"},ch3[200]={"frl.pj"},chk[200],cpy4[200];
frnd=(Frnd*)malloc(sizeof(Frnd));
strcpy(cpy2,p); strcpy(cpy3,p);
strcat(cpy2,ch2); strcat(cpy3,ch3);
f=fopen(cpy2,"r"); fscanf(f,"%d",&tot); fclose(f);
x:
clrscr();
printf("\t\t\tSearch Friends\n\t\t\t------ -------\n\n\n Enter (*) star to exit..\n\n\n\t\t Enter Friends ID (To Search) : ");
fflush(stdin);
gets(searchn);
if(strcmp(searchn,"*")==0)
return;
link(cpy1,searchn);
if(strcmp(cpy1,p)==0)
{
printf("\n\n\n\t\t\t You Try To search Your Own Id\n\n\t\t\t Search Your Friend Id Press \n\n\t\t\t Any Key To Try Again...");
getch();
goto x;
}
f=fopen(cpy3,"r");
  if(f!=NULL)
 {
  for(i=0;i<tot;i++)
  {
    fscanf(f,"%s\n",chk);
    link(cpy4,chk);
      if(strcmp(cpy4,cpy1)==0)
      {
        printf("\n\n\n\t\t\t You Already Friend With %s ...\n\n\t\t\t Press Any Key To Search Again..",chk);
        stop=-1;
        getch();
        break;
      }
  }
  fclose(f);
    if(stop==-1)
    {
    stop=0;
    goto x;
    }
 }

f2=fopen(cpy1,"r");
  if(f2==NULL)
  {
   printf("\n\n\n\n\t\t Sorry,No Friend Found...ID Not Present.\n\n\t\tPress Any Key TO Try Again Or Press (H) For Home : ");
   fflush(stdin); ch=getch();
   if(ch!='H')goto x;
   fclose(f2);
  }
  else
  {
   clrscr();
   fscanf(f2,"%s",frnd->id);
   fscanf(f2,"\n%s",frnd->pass);
   fscanf(f2,"\n%s",frnd->fname);
   fscanf(f2,"\n%s",frnd->lname);
   for(i=0;i<4;i++)
     for(j=0;j<1;j++)
     {
       fscanf(f2,"\n%d",&frnd->pcomb1[i][j]);
       if(i==4)break;
     }
   fclose(f2);

   for(i=0;i<80;i++)
   printf("");
   printf("\n\t\t\t\t Friend Found\n\t\t\t\t ------ -----\n  1.Send Friend Request \t\t\t\t\t 2.Back\n");
   printf("\n");
   for(i=0;i<80;i++)
   printf("");

  for(i=0;i<5;i++)
  {
      if(frnd->pcomb1[i][1]==1)
      {
      a=frnd->pcomb1[i][0];
      break;
      }
    }
printf("\n||");
for(i=1;i<=50;i++)
{
  printf("%c",a);
    if(i%10==0)
    {
    printf("||");
	  if(i==10)
	    for(j=0;j<5;j++)
	     if(frnd->pcomb1[j][1]==2)
	     {
	     a=frnd->pcomb1[j][0];
	     break;
	     }
	  if(i==20)
	    for(j=0;j<5;j++)
	     if(frnd->pcomb1[j][1]==3)
	     {
	     a=frnd->pcomb1[j][0];
	     break;
	     }
	  if(i==30)
	    for(j=0;j<5;j++)
	     if(frnd->pcomb1[j][1]==4)
	     {
	     a=frnd->pcomb1[j][0];
	     break;
	     }
	  if(i==40)
	    for(j=0;j<5;j++)
	     if(frnd->pcomb1[j][1]==5)
	     {
	     a=frnd->pcomb1[j][0];
	     break;
	     }
    if(i==20){printf("\t\t\t Name   : %s %s",frnd->fname,frnd->lname);}
    else if(i==40){printf("\t\t\t User ID : %s",frnd->id);}
    printf("\n||");
   }
}
for(i=0;i<10;i++)
printf("=");
printf("||");
 printf("\n\n\n\n\t\t Enter Your Choise : ");
 scanf("%d",&opt);
 if(opt==1)
  makefrnd(p,cpy1);
 }
}

/*********************************************************************************************************************************
**********************************************************************************************************************************/

/*********************************************************************************************************************************
                                                               SEND FRIEND REQUEST
**********************************************************************************************************************************/
void makefrnd(char p[200],char frn1[200])
{
char ch[200]={"fr.pj"},ch1[200]={"frn.pj"},cpy[200],cpy1[200],send[200];
int fn=0;
strcpy(cpy,frn1);
strcpy(cpy1,frn1);
strcat(cpy,ch1);
strcat(cpy1,ch);
f=fopen(cpy,"r");
  if(f!=NULL)
  {
    fscanf(f,"%d",&fn);
    fclose(f);
    fn++;
    f=fopen(cpy,"w");
    fprintf(f,"%d",fn);
    fclose(f);
  }
  else
  {
    fn++;
    f2=fopen(cpy,"w");
    fprintf(f2,"%d",fn);
    fclose(f2);
   }

f1=fopen(p,"r");
fscanf(f1,"%s",send);
fclose(f1);

f1=fopen(cpy1,"a");
fprintf(f1,"\n%s",send);
fclose(f1);
}
/*********************************************************************************************************************************
**********************************************************************************************************************************/


/**********************************************************************************************************************************
                                                    Number Of Friend Request AND FRIEND
**********************************************************************************************************************************/

int checkr(char p[200],int *q)
{
char ch1[200]={"frn.pj"},ch2[200]={"totfr.pj"},cpy[200],cpy1[200];
int  tot=0;

strcpy(cpy,p);
strcpy(cpy1,p);
strcat(cpy,ch1);
strcat(cpy1,ch2);

f1=fopen(cpy,"r");
  if(f1!=NULL)
     fscanf(f1,"%d",&tot);
fclose(f1);
f1=fopen(cpy1,"r");
  if(f1!=NULL)
     fscanf(f1,"%d",&(*q));
fclose(f1);

return tot;
}
/*********************************************************************************************************************************/
/*********************************************************************************************************************************
                                                    SEE FRIEND REQUEST
*********************************************************************************************************************************/
void seefrnrqst(char p[200])
{
int i=0,tot=0,opt=0;
char ch1[200]={"frn.pj"},cpy[200],cpy1[200],ch2[200]={"fr.pj"},str1[200],cpy2[200];
frst=(Frndrqst*)malloc(sizeof(Frndrqst));
p:
clrscr();

strcpy(cpy,p);
strcpy(cpy1,p);
strcat(cpy,ch1);
strcat(cpy1,ch2);
f1=fopen(cpy,"r");
fscanf(f1,"%d",&tot);
fclose(f1);

 printf("\n\t\t\t Friend Request List \n\t\t\t ------ ------- ---- \n\n\n\n");

 f=fopen(cpy1,"r");

 for(i=0;i<tot;i++)
 {
  fscanf(f,"\n%s",str1);
     link(cpy2,str1);
    f1=fopen(cpy2,"r");fflush(stdin);
     fscanf(f1,"%s",frst->id);fflush(stdin);
     fscanf(f1,"\n%s",frst->pass);fflush(stdin);
     fscanf(f1,"\n%s",frst->fname);fflush(stdin);
     fscanf(f1,"\n%s",frst->lname);fflush(stdin);
     printf("\n %d. %s %s (%s)",(i+1),frst->fname,frst->lname,frst->id);
     fclose(f1);
 }
 fclose(f);

 printf("\n\n\n\n Enter Serial Number To See Request Details : ");fflush(stdin);
 scanf("%d",&opt);
 if(opt>0 && opt<=tot)
 {
   finalFRQ(opt,p);
 }
 else
 {
 printf("\n\n There Is No Friend Request At This Serial Number. (TRY AGAIN) ");
 getch();
 goto p;
 }
}

/**********************************************************************************************************************************
                                                            SEE FRIEND REQUEST LIST FRIEND DETAILS
**********************************************************************************************************************************/
void finalFRQ(int opt,char p[200])
{
char ch1[200]={"frn.pj"},cpy[200],cpy1[200],cpy2[200],ch2[200]={"fr.pj"},str1[200],str2[200],cpy3[200];
int i=0,ii=0,j=0,tot=0,a=0,opt1=0;
frnd=(Frnd*)malloc(sizeof(Frnd));
clrscr();

strcpy(cpy,p);
strcpy(cpy1,p);
strcat(cpy,ch1);
strcat(cpy1,ch2);

f=fopen(cpy,"r");
fscanf(f,"%d",&tot);
fclose(f);

f1=fopen(cpy1,"r");
for(ii=1;ii<=tot;ii++)
{
 fscanf(f1,"%s\n",str1);
   link(cpy3,str1);
   f2=fopen(cpy3,"r");
   fscanf(f2,"%s",frnd->id);
   fscanf(f2,"\n%s",frnd->pass);
   fscanf(f2,"\n%s",frnd->fname);
   fscanf(f2,"\n%s",frnd->lname);
   for(i=0;i<4;i++)
     for(j=0;j<1;j++)
     {
       fscanf(f2,"\n%d",&frnd->pcomb1[i][j]);
       if(i==4)break;
     }
     fclose(f2);


  if(ii==opt)
  {
   strcpy(cpy2,frnd->id);
   link(str2,cpy2);
   for(i=0;i<80;i++)
   printf("");
   printf("\n\t\t\t\t Friend Details\n\t\t\t\t ------ -------\n  1.Accept Friend Request \t\t\t\t\t 2.Back\n");
   printf("\n");
   for(i=0;i<80;i++)
   printf("");

  for(i=0;i<5;i++)
  {
      if(frnd->pcomb1[i][1]==1)
      {
      a=frnd->pcomb1[i][0];
      break;
      }
    }
printf("\n||");
for(i=1;i<=50;i++)
{
  printf("%c",a);
    if(i%10==0)
    {
    printf("||");
	  if(i==10)
	    for(j=0;j<5;j++)
	     if(frnd->pcomb1[j][1]==2)
	     {
	     a=frnd->pcomb1[j][0];
	     break;
	     }
	  if(i==20)
	    for(j=0;j<5;j++)
	     if(frnd->pcomb1[j][1]==3)
	     {
	     a=frnd->pcomb1[j][0];
	     break;
	     }
	  if(i==30)
	    for(j=0;j<5;j++)
	     if(frnd->pcomb1[j][1]==4)
	     {
	     a=frnd->pcomb1[j][0];
	     break;
	     }
	  if(i==40)
	    for(j=0;j<5;j++)
	     if(frnd->pcomb1[j][1]==5)
	     {
	     a=frnd->pcomb1[j][0];
	     break;
	     }
    if(i==20){printf("\t\t\t Name   : %s %s",frnd->fname,frnd->lname);}
    else if(i==40){printf("\t\t\t User ID : %s",frnd->id);}
    printf("\n||");
    }
  }
  }
 }
 for(i=0;i<10;i++)
    printf("=");
    printf("||");
 fclose(f1);
 printf("\n\n\n\n\t\t Enter Your Choice : ");
    scanf("%d",&opt1);
 if(opt1==1)
 acptfrnd(p,str2,opt);
}

/**********************************************************************************************************************************
**********************************************************************************************************************************/

/**********************************************************************************************************************************
                                                      REQUEST ACCEPT
**********************************************************************************************************************************/
void acptfrnd(char p[200],char frnd[200],int opt)
{
  char ch1[200]={"frl.pj"},cpy1[200],cpy2[200],ch2[200]={"totfr.pj"},ch3[200]={"frn.pj"},ch4[200]={"fr.pj"},ch5[200]={"buff.pj"},cpy3[200],cpy4[200],cpy5[200],str1[200],cpy6[200],cpy7[200];
  char accp[200];
  int  a=0,b=0,tot=0,ii=0,i=0;

strcpy(cpy1,p);
strcpy(cpy2,p);
strcpy(cpy3,p);
strcpy(cpy4,p);
strcpy(cpy5,p);
strcpy(cpy6,frnd);
strcpy(cpy7,frnd);
strcat(cpy1,ch1);
strcat(cpy2,ch2);
strcat(cpy3,ch3);
strcat(cpy4,ch4);
strcat(cpy5,ch5);
strcat(cpy6,ch1);
strcat(cpy7,ch2);

f=fopen(cpy3,"r");
fscanf(f,"%d",&b);
tot=b;
b--;fclose(f);
f=fopen(cpy3,"w");
fprintf(f,"%d",b);
fclose(f);

f1=fopen(cpy4,"r");
f2=fopen(cpy5,"w");
for(ii=1;ii<=tot;ii++)
{
fscanf(f1,"\n%s",str1);
if(ii!=opt)
fprintf(f2,"%s\n",str1);
}
fclose(f1);
fclose(f2);

f1=fopen(cpy4,"w");
f2=fopen(cpy5,"r");
for(ii=0;ii<b;ii++)
{
fscanf(f2,"%s\n",str1);
fprintf(f1,"\n%s",str1);
}
fclose(f1);
fclose(f2);


f2=fopen(cpy2,"r");
  if(f2==NULL)
  {
   a++;
   f1=fopen(cpy2,"w");
   fprintf(f1,"%d",a);
   fclose(f1);
  }
  else
  {
   fscanf(f1,"%d",&a);
   fclose(f1);
   a++;
   f1=fopen(cpy2,"w");
   fprintf(f1,"%d",a);
   fclose(f1);
  }
f=fopen(frnd,"r"); fscanf(f,"%s",accp); fclose(f);
f=fopen(cpy1,"a");
fprintf(f,"%s\n",accp);
fclose(f);

a=0;
f2=fopen(cpy7,"r");
   if(f2==NULL)
   {
   a++;
   f1=fopen(cpy7,"w");
   fprintf(f1,"%d",a);
   fclose(f1);
   }
   else
   {
   fscanf(f2,"%d",&a);
   fclose(f2);
   a++;
   f1=fopen(cpy7,"w");
   fprintf(f1,"%d",a);
   fclose(f1);
   }
f=fopen(p,"r"); fscanf(f,"%s",accp); fclose(f);
f=fopen(cpy6,"a");
fprintf(f,"%s\n",accp);
fclose(f);

}
/**********************************************************************************************************************************
**********************************************************************************************************************************/

/**********************************************************************************************************************************
                                                       SEE FRIEND LIST
**********************************************************************************************************************************/
void seefrnlist(char p[200])
{
  char  ch1[200]={"frl.pj"},cpy1[200],cpy2[200],cpy3[200],ch2[200]={"totfr.pj"},fid[200],fname[200],cpy4[200];
  int   i=0,ii=0,tot=0,see=0,j=0,a=0,op=0;
  frnd=(Frnd*)malloc(sizeof(Frnd));
  clrscr();
  strcpy(cpy1,p);
  strcpy(cpy2,p);
  strcat(cpy1,ch1);
  strcat(cpy2,ch2);
  printf("\n\t\t\t\t\t FRIENDS LIST \n\t\t\t\t\t ------- ---- \n\n");
  f=fopen(cpy2,"r");
  fscanf(f,"%d",&tot);
  fclose(f);
  f1=fopen(cpy1,"r");
  for(i=0;i<tot;i++)
  {
    fscanf(f1,"\n%s",fname);
    link(cpy4,fname);
     f=fopen(cpy4,"r");
     fscanf(f,"%s",frnd->id);
     fscanf(f,"\n%s",frnd->pass);
     fscanf(f,"\n%s",frnd->fname);
     fscanf(f,"\n%s",frnd->lname);
     printf("\n %d. %s %s (%s)",i+1,frnd->fname,frnd->lname,frnd->id);
     fclose(f);
  }
  fclose(f1);
  printf("\n\n Enter Friends Serial Number To See Details Or Message ( Enter -1 TO Exit) : ");
  scanf("%d",&see);
  if(see!=-1)
 {
  f1=fopen(cpy1,"r");
   for(ii=1;ii<=tot;ii++)
   {
    fscanf(f1,"\n%s",fid);
     if(see==ii)
     {
      link(cpy4,fid);
      f=fopen(cpy4,"r");
      fscanf(f,"%s",frnd->id);
      fscanf(f,"\n%s",frnd->pass);
      fscanf(f,"\n%s",frnd->fname);
      fscanf(f,"\n%s",frnd->lname);
      for(i=0;i<4;i++)
      for(j=0;j<1;j++)
      {
        fscanf(f,"\n%d",&frnd->pcomb1[i][j]);
        if(i==4)break;
      }
      fclose(f);

     clrscr();
     for(i=0;i<80;i++)
     printf("");
     printf("\n\t\t\t\t Friend Details\n\t\t\t\t ------ -------\n 1.Message\n");
     printf("\n");
     for(i=0;i<80;i++)
     printf("");


    for(i=0;i<5;i++)
       if(frnd->pcomb1[i][1]==1)
       {
       a=frnd->pcomb1[i][0];
       break;
       }
    printf("\n||");
   for(i=1;i<=50;i++)
   {
    printf("%c",a);
      if(i%10==0)
      {
        printf("||");
	     if(i==10)
        for(j=0;j<5;j++)
	       if(frnd->pcomb1[j][1]==2)
	       {
	       a=frnd->pcomb1[j][0];
	       break;
	       }
	    if(i==20)
	      for(j=0;j<5;j++)
	       if(frnd->pcomb1[j][1]==3)
	       {
	       a=frnd->pcomb1[j][0];
	       break;
	       }
	    if(i==30)
	      for(j=0;j<5;j++)
	       if(frnd->pcomb1[j][1]==4)
	       {
	       a=frnd->pcomb1[j][0];
	       break;
	       }
	      if(i==40)
	        for(j=0;j<5;j++)
	         if(frnd->pcomb1[j][1]==5)
	         {
	         a=frnd->pcomb1[j][0];
	          break;
            }
           if(i==20){printf("\t\t\t Name   : %s %s",frnd->fname,frnd->lname);}
           else if(i==40){printf("\t\t\t User ID : %s",frnd->id);}
           printf("\n||");
        }
       }
       for(i=0;i<10;i++)
         printf("=");
         printf("||");
     }
   }
   fclose(f1);
  }
  printf("\n\n\n Enter Your Choice (Or Enter Any Key To Go Back To Home Except 1) : ");
  scanf("%d",&op);
  if(op==1)
  {
   link(cpy3,frnd->id);
   startchat(p,cpy3,frnd->fname,frnd->lname,frnd->id);
  }
}
/**********************************************************************************************************************************
**********************************************************************************************************************************/

/**********************************************************************************************************************************
                                                               CHECK FRIEND ONLINE OR NOT
**********************************************************************************************************************************/
int checkonline(char p[200])
{
  char  ch1[200]={"frl.pj"},cpy1[200],cpy2[200],ch2[200]={"totfr.pj"},fid[200],fname[200],cpy3[200],ch3[200]={"vis.pj"},cpy4[200]={'\0'};
  int   i=0,tot=0,see=0,j=0,online=0;
  clrscr();
  strcpy(cpy1,p);
  strcpy(cpy2,p);
  strcat(cpy1,ch1);
  strcat(cpy2,ch2);
  f=fopen(cpy2,"r");
  fscanf(f,"%d",&tot);
  fclose(f);
  f1=fopen(cpy1,"r");
  for(i=0;i<tot;i++)
  {
    fscanf(f1,"\n%s",fid);
    strcpy(cpy3,fid);
    strcat(cpy3,ch3);
    link(cpy4,cpy3);
    f=fopen(cpy4,"r");
      if(f!=NULL)
      {
        fscanf(f,"%d",&see);
        if(see==1)
        online++;
      }
    fclose(f);
    see=0;
  }
  fclose(f1);
 return online;
}
/**********************************************************************************************************************************
**********************************************************************************************************************************/

void seeonline(char p[200])
{

  char  ch1[200]={"frl.pj"},cpy1[200],cpy2[200],ch2[200]={"totfr.pj"},fid[200],fname[200],cpy3[200],ch3[200]={"vis.pj"},cpy4[200]={'\0'},cpy5[200]={'\0'};
  char  cpy6[200];
  int   i=0,tot=0,see=0,j=0,online=0,frp=0,a=0;
  frnd=(Frnd*)malloc(sizeof(Frnd));
  p:
  clrscr();
  strcpy(cpy1,p);
  strcpy(cpy2,p);
  strcat(cpy1,ch1);
  strcat(cpy2,ch2);
  f=fopen(cpy2,"r");
  fscanf(f,"%d",&tot);
  fclose(f);
  f1=fopen(cpy1,"r");
  for(i=0;i<tot;i++)
  {
    fscanf(f1,"\n%s",fid);
    strcpy(cpy3,fid);
    strcat(cpy3,ch3);
    link(cpy4,cpy3);
    f=fopen(cpy4,"r");
      if(f!=NULL)
      {
        fscanf(f,"%d",&see);
        if(see==1)
        {
          link(cpy6,fid);
          f2=fopen(cpy6,"r");
          printf("\n\t\t\t\t\t FRIENDS ONLINE \n\t\t\t\t\t ------- ---- \n\n");
          fscanf(f2,"%s",frnd->id);
          fscanf(f2,"\n%s",frnd->pass);
          fscanf(f2,"\n%s",frnd->fname);
          fscanf(f2,"\n%s",frnd->lname);
          printf("\n %d. %s %s (%s)",j+1,frnd->fname,frnd->lname,frnd->id);
          j++;
          fclose(f2);
        }
      }
    fclose(f);
  }
  a=j;
  fclose(f1);  j=0;
  if(see==0){
  printf("\n\n\n\n\t\t\t\t No Friends Are Online \n\n\t\t\t\t Press Any Key To Go Back"); getch();}
  else
  {
  printf("\n\n Select Friend To Start Chat (Or Enter -1 To Go Back) : ");
  scanf("%d",&frp);
    if(frp!=-1 && frp<=a)
    {
       f1=fopen(cpy1,"r");
        for(i=0;i<tot;i++)
        {
           fscanf(f1,"\n%s",fid);
           strcpy(cpy3,fid);
           strcat(cpy3,ch3);
           link(cpy4,cpy3);
           f=fopen(cpy4,"r");
            if(f!=NULL)
             {
              fscanf(f,"%d",&see);
              if(see==1)
              {
                 if(frp==(j+1))
                 {
                 link(cpy6,fid);
                 f2=fopen(cpy6,"r");
                 fscanf(f2,"%s",frnd->id);
                 fscanf(f2,"\n%s",frnd->pass);
                 fscanf(f2,"\n%s",frnd->fname);
                 fscanf(f2,"\n%s",frnd->lname);
                 fclose(f2);
                 link(cpy5,frnd->id);
                 startchat(p,cpy5,frnd->fname,frnd->lname,frnd->id);
                 }
               j++;
               }
              }
           fclose(f);
          }
         fclose(f1);
      }
     else if(frp==-1){}
     else{printf("\n\n No Friend Present...Press Any Key To Try Again...."); getch(); goto p;}
  }
}

/**********************************************************************************************************************************
                                                     CHAT MANAGER
**********************************************************************************************************************************/
void startchat(char p[200],char fid[200],char frfname[100],char frlname[100],char frnid[200])
{
char cpy1[200]={'\0'},cpy2[200]={'\0'},cpy3[200]={'\0'},cpy4[200]={'\0'},ch,cpy5[200],msg[100],msg1[100];
int  time=0,b=0,i=0;
long int k=0;
frnd=(Frnd*)malloc(sizeof(Frnd));
clrscr();
f2=fopen(p,"r");
fscanf(f2,"%s",frnd->id);
fscanf(f2,"\n%s",frnd->pass);
fscanf(f2,"\n%s",frnd->fname);
fscanf(f2,"\n%s",frnd->lname);
fclose(f2);
strcpy(cpy1,p); strcpy(cpy2,frnd->id); strcpy(cpy3,frnid); strcpy(cpy4,fid);
strcat(cpy1,cpy3); strcat(cpy4,cpy2); strcat(cpy1,"ch.pj"); strcat(cpy4,"ch.pj");
strcpy(cpy5,cpy1); strcat(cpy5,"temp.pj");

  while((strcmp(msg,"*")!=0))
   {
     i=0;
     msg[i]='\0';
     p:
     while(!kbhit())
     {
      clrscr();
      printf("\n\t\t\t\t MESSAGE (%s %s)\n\t\t\t\t ------- \n\n Enter  P: Send Photo\t\t M: Send Music \t\t V: Send Video \n\n #Enter (*)star To  Exit\n\n\n ",frfname,frlname);
      printf("\n %s %s (You) => \n Type Your Message Here : %s \n\n",frnd->fname,frnd->lname,msg);
      printf(" MESSAGE FROM %s %s  : \n ",frfname,frlname);
      f=fopen(cpy4,"r");
      if(f!=NULL)
      {
        while(!feof(f))
        {
         ch=getc(f);
         printf("%c",ch);
        }
      }
      for(k=0;k<9999999;k++){printf("");}

      fclose(f);
     }
     while(kbhit())
     {
      msg[i]=getch();
      i++;
     }
     for(k=0;k<999999;k++){printf("");}
       msg[i]='\0';
       b=msg[i-1];
       if(b!=13)
       goto p;

      time++;
      f2=fopen(cpy5,"r");
      if(f2!=NULL)
      {
      fscanf(f2,"%d",&time);
      fclose(f2);
      if(time==10)
      time=0;
      time++;
      f2=fopen(cpy5,"w");
      fprintf(f2,"%d",time);
      fclose(f2);
     }
     else
     {
      f2=fopen(cpy5,"w");
      fprintf(f2,"%d",time);
      fclose(f2);
     }
     if(time!=10)
     f1=fopen(cpy1,"a");
     else
     f1=fopen(cpy1,"w");
     strcpy(msg1,msg);
     msg1[i-1]='\0';
     if(strcmp(msg1,"*")!=0 && strcmp(msg1,"")!=0 && strcmp(msg1," ")!=0 && strcmp(msg1,"  ")!=0 && strcmp(msg1,"   ")!=0 && strcmp(msg1,"    ")!=0)
     fprintf(f1,"->%s\n",msg);
     fclose(f1);
     msg[i-1]='\0';
     if(strcmp(msg1,"*")!=0 && strcmp(msg1,"")!=0)
     printf("\n \t\t Message Sent..");
     else if(strcmp(msg1,"")==0 || strcmp(msg1," ")!=0 || strcmp(msg1,"  ")!=0 || strcmp(msg1,"   ")!=0 || strcmp(msg1,"    ")!=0)
     printf("\n \t\t Blank Not Sent...");
     else if(strcmp(msg1,"*")==0)
     printf("\n \t\t GOOD BYE....");
          for(k=0;k<9999999;k++){printf("");printf("");}
  }
}
/**********************************************************************************************************************************
**********************************************************************************************************************************/

/**********************************************************************************************************************************
                                                     MESSAGE
**********************************************************************************************************************************/
void message(char p[200])
{
 char cpy1[200]={'\0'},cpy2[200]={'\0'},cpy3[200]={'\0'},cpy4[200]={'\0'},chk[200]={'\0'},cpy5[200],id[200];
 int tot=0,check=0,inc=0,i=0,srch=0;
  frnd=(Frnd*)malloc(sizeof(Frnd));
 clrscr();
 strcpy(cpy1,p); strcat(cpy1,"totfr.pj");  strcpy(cpy2,p); strcat(cpy2,"frl.pj");
 f=fopen(cpy1,"r");
 fscanf(f,"%d",&tot);
 fclose(f);
 f=fopen(p,"r");
 fscanf(f,"%s",id);
 fclose(f);
 printf("\n\t\t\t\t Message History\n\t\t\t\t ------- -------\n\n\n");
 f=fopen(cpy2,"r");
   for(i=0;i<tot;i++)
   {
      fscanf(f,"%s\n",chk);
      link(cpy5,chk);
      f2=fopen(cpy5,"r");
      fscanf(f2,"%s",frnd->id);
      fscanf(f2,"\n%s",frnd->pass);
      fscanf(f2,"\n%s",frnd->fname);
      fscanf(f2,"\n%s",frnd->lname);
      fclose(f2);
       link(cpy4,chk); strcpy(cpy3,id); strcat(cpy3,"ch.pj"); strcat(cpy4,cpy3);
       f1=fopen(cpy4,"r");
         if(f1!=NULL)
         {
          printf("\n\n%d.%s %s (%s)",(inc+1),frnd->fname,frnd->lname,frnd->id);
          check=1;
          inc++;
          fclose(f1);
         }
       else
       {
        strcpy(cpy3,p); strcpy(cpy4,frnd->id); strcat(cpy4,"ch.pj"); strcat(cpy3,cpy4);
       f1=fopen(cpy3,"r");
         if(f1!=NULL)
         {
          printf("\n\n%d.%s %s (%s)",(inc+1),frnd->fname,frnd->lname,frnd->id);
          check=1;
          inc++;
          fclose(f1);
         }
        }
   }
 fclose(f);

  if(check==0)
  {
   printf("\n\n\n\n\n\n\t\t\t NO OLDER CHAT HISTORY PRESENT\n\n\t\t\t PRESS ANY KEY TO GO BACK");
   getch();
  }
  else
  {
   printf("\n\n Enter Serial Number To Start Or See Friend Chat (ex : 1.xyz you enter : 1) : "); fflush(stdin);
   scanf("%d",&srch);
     /******************************************************************************/
      f=fopen(cpy2,"r");
       for(i=0;i<tot;i++)
       {
        fscanf(f,"%s\n",chk);
         if(srch==(i+1))
         {
          link(cpy5,chk);
          f2=fopen(cpy5,"r");
          fscanf(f2,"%s",frnd->id);
          fscanf(f2,"\n%s",frnd->pass);
          fscanf(f2,"\n%s",frnd->fname);
          fscanf(f2,"\n%s",frnd->lname);
          fclose(f2);
           link(cpy4,chk); strcpy(cpy3,id); strcat(cpy3,"ch.pj"); strcat(cpy4,cpy3);
           f1=fopen(cpy4,"r");
           if(f1!=NULL)
           {
            fclose(f1);
            startchat(p,cpy5,frnd->fname,frnd->lname,frnd->id);
           }
           else
           {
           strcpy(cpy3,p); strcpy(cpy4,frnd->id); strcat(cpy4,"ch.pj"); strcat(cpy3,cpy4);
           f1=fopen(cpy3,"r");
           if(f1!=NULL)
           {
            fclose(f1);
            startchat(p,cpy5,frnd->fname,frnd->lname,frnd->id);
           }
           }
        }
    }
     fclose(f);
    /*****************************************************************************/
  }
}
/**********************************************************************************************************************************
**********************************************************************************************************************************/

/****************************************************** LINK TO FILE **************************************************************/
void link(char path1[200],char path2[200])
{
strcpy(path1,"c:\\PSOFT\\");
strcat(path1,path2);
}
/*********************************************************************************************************************************/
