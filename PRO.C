#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void menu();
void load();
void add();
void modify();
void delect();
void view();
void search();
struct student{
   char name[30];
   char mobile[30];
   char rollno[10];
   char course[30];
   char branch[50];

};
void main(){

  int gd=DETECT,gm;
  clrscr();
  initgraph(&gd,&gm,"c://turboc3//bgi");
  setcolor(RED);
  setbkcolor(CYAN);
  settextstyle(1,0,4);
  outtextxy(2,12,"Student Record Management System");
    outtextxy(250,50,"(SRMS)");

  outtextxy(5,100,"********************************************************");

  settextstyle(1,0,2);
  outtextxy(150,220,"Press a Key To Continue....");
  getch();
  menu();
 }

 void load()
 {
      int i,gd=DETECT,gm;
      initgraph(&gd,&gm,"c:\\turboc3\\bgi");
      setcolor(WHITE);
   for(i=35;i<555;i++)
   {
	 line(25+i,170,25+i,200);
   }
       setcolor(GREEN);
       for(i=35;i<555;i++)   //Here is another bar green which is
   {                           //by particuar for loop.
       line(25+i,170,25+i,200);  //Here it increasing the size of green.
       delay(1);
       setcolor(WHITE);
       settextstyle(SMALL_FONT,0,16); //this is for font
	   outtextxy(220,220,"LOADING....");
       delay(1);
       setcolor(GREEN);
       settextstyle(SMALL_FONT,HORIZ_DIR,16);
       delay(0.05);
     }
       clrscr();

   }

void menu(){
int ch;
int gd=0,gm;
char m;
clrscr();
initgraph(&gd,&gm,"c://turboc3//bgi");
setcolor(BLUE);
setbkcolor(CYAN);
settextstyle(1,0,5);
outtextxy(100,25,"----MENU----");
settextstyle(1,0,1);
outtextxy(25,80,"Enter the appropriate number to perform the following task");
settextstyle(1,0,3);
setcolor(YELLOW);
outtextxy(25,120,"1)-ADD Record");
outtextxy(25,160,"2)-VIEW Record");
outtextxy(25,200,"3)-MODIFY Record");
outtextxy(25,240,"4)-SEARCH Record");
outtextxy(25,280,"5)-DELECT Record");
outtextxy(295,120,"6)-EXIT");
settextstyle(1,0,1);
setcolor(BLUE);
outtextxy(25,360,"Plzz enter your choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
add();
	break;
   case 2:
	view();
	break;
   case 3:
       modify();
       break;
   case 4:
       search();
       break;
   case 5:
       delect();
       break;
    case 6:
       exit(1);
   default:
       outtextxy(25,420,"Invalid choice");
  getch();
  exit(1);
}

  getch();
}
   void add(){
	FILE *fp;
       struct student std;//Creating object for structure student
       char another = 'y';
       clrscr();
	  fp=fopen("srec.txt","ab+");
	if(fp==NULL){
	       outtextxy(10,5,"Error is found");
	  exit(1);
       }
	   fflush(stdin);


	  while(another=='y')
	 {
		setcolor(YELLOW);
		setbkcolor(BLUE);
	   outtextxy(150,30,"<----ADD RECORD---->");
	   outtextxy(60,60,"Enter the detail of student");
	   setcolor(DARKGRAY);
	   outtextxy(80,90,"Enter Name:");
		  gets(std.name);
	   setcolor(LIGHTBLUE);
	     outtextxy(220,90,std.name);

	   setcolor(DARKGRAY);
	   outtextxy(80,120,"Enter Mobile number(upto 10 digits) :");
		gets(std.mobile);
		 setcolor(LIGHTBLUE);
	   outtextxy(450,120,std.mobile);
		  setcolor(DARKGRAY);
	  outtextxy(80,150,"Enter your course:");
		 gets(std.course);
		   setcolor(LIGHTBLUE);
	  outtextxy(300,150,std.course);
		setcolor(DARKGRAY);
	  outtextxy(80,180,"Enter your Branch:");
		gets(std.branch);
		setcolor(LIGHTBLUE);
	  outtextxy(280,180,std.branch);
		setcolor(DARKGRAY);
	  outtextxy(85,210,"Enter Roll no.(upto 3 digits only) :");
	  gets(std.rollno);
		setcolor(LIGHTBLUE);
	  outtextxy(450,210,std.rollno);
		    fwrite(&std,sizeof(std),1,fp);
		      fflush(stdin);
			fclose(fp);
		setcolor(YELLOW);
		outtextxy(90,230,"Record is succesfully added........");
	   outtextxy(90,260,"Plzz enter a key to continue..........");
    getch();
   menu();
}
}
void view()
{
	 FILE *fp;
       int i=1;
   char n[30];
   struct student std;
   clrscr();
  load();
  setcolor(GREEN);
printf("||| Name of student   |||   mobile  |||   rollno |||   course  ||| branch ");
printf("\n------------------------------------------------------------------------------\n");
fp=fopen("srec.txt","rb+");
	if(fp==NULL)
	{
       printf("Error ||||");
       getch();
       exit(1);
	}

      while(fread(&std,sizeof(std),1,fp)==1){
      setbkcolor(BLUE);
printf("\n\t%2s\t\t%s\t%s\t%s\t%s\t%s\n",std.name,std.mobile,std.rollno,std.course,std.branch);

      i++;
}
      fclose(fp);
     printf("\n\n\nPlzz enter a key to continue......");
  getch();
  menu();

}

  void search(){
	    FILE *fp;
      struct student std;
    char stname[25];
  clrscr();
    settextstyle(1,0,4);
       setbkcolor(LIGHTGRAY);
       setcolor(MAGENTA);
    outtextxy(10,30,"<-----Search Record------>");
    settextstyle(1,0,2);
    setcolor(YELLOW);
    outtextxy(10,80,"For searching plzz enter student Rollno..:-");
	fflush(stdin);
       gets(stname);
	   fp=fopen("srec.txt","rb+");
	  if(fp==NULL)
	  {
	  outtextxy(10,60,"Found a Error!!!");
	  getch();
	exit(1);
	  }
	  while(fread(&std,sizeof(std),1,fp)==1){
	    if(strcmp(stname,std.rollno)==0)
	  {
	    load();
	  settextstyle(1,0,5);
	  setcolor(MAGENTA);
	outtextxy(100,50,"Student Details");
	outtextxy(100,95,"*******************");
	settextstyle(1,0,1);
	setcolor(LIGHTBLUE);
	outtextxy(50,150,"Name:-");
	outtextxy(120,150,std.name);
	outtextxy(50,180,"Mobile NO:-");
	outtextxy(160,180,std.mobile);
	outtextxy(50,210,"Roll NO:-");
	outtextxy(150,210,std.rollno);
	outtextxy(50,240,"Course:-");
	outtextxy(140,240,std.course);
	outtextxy(50,270,"Branch:-");
	outtextxy(150,270,std.branch);
}
}
     fclose(fp);
     setbkcolor(LIGHTGRAY);
   setcolor(MAGENTA);
   outtextxy(120,400,"Press a key to continue........");
 getch();
 menu();
}
void modify(){

    char stname[25];
       FILE *fp;
       struct student std;
       clrscr();
       outtextxy(150,30,"<---Modify Record--->");
       outtextxy(10,55,"Enter the student rollno.. for modifiation");
	    fflush(stdin);
	    gets(stname);
      fp= fopen("srec.txt","rb+");
	  if(fp==NULL)
	  {
	    outtextxy(11,89,"Error in opening file");
	    getch();
	    exit(1);
	  }
	    rewind(fp);
	    fflush(stdin);
      while(fread(&std,sizeof(std),1,fp)==1)
	 {
	    if(strcmp(stname,std.rollno)==0){
	      setcolor(DARKGRAY);
	   outtextxy(80,90,"Enter Name:");
		  gets(std.name);
	   setcolor(LIGHTBLUE);
	     outtextxy(220,95,std.name);
	   setcolor(DARKGRAY);
	   outtextxy(80,120,"Enter Mobile number:");
		gets(std.mobile);
		 setcolor(LIGHTBLUE);
	   outtextxy(300,120,std.mobile);
		  setcolor(DARKGRAY);
	  outtextxy(80,150,"Enter your course:");
		 gets(std.course);
		   setcolor(LIGHTBLUE);
	  outtextxy(300,150,std.course);
		setcolor(DARKGRAY);
	  outtextxy(80,180,"Enter your Branch:");
		gets(std.branch);
		setcolor(LIGHTBLUE);
	  outtextxy(280,180,std.branch);
		setcolor(DARKGRAY);
	  outtextxy(85,210,"Enter Roll no. :");
		gets(std.rollno);
		setcolor(LIGHTBLUE);
	  outtextxy(260,210,std.rollno);
	  fseek(fp,sizeof(std),SEEK_CUR);
		    fwrite(&std,sizeof(std),1,fp);
		      fflush(stdin);
		      break;
		 }
	  }
	   fclose(fp);
	   setcolor(RED);
	   outtextxy(90,260,"Record is Modified successfully...");
	   setcolor(BLUE);
	   outtextxy(90,290,"Plzz enter a key to continue..........");
    getch();
   menu();
}

void delect()
{
     char stname[25];
     FILE *fp,*ft;
     struct student std;
     clrscr();
     outtextxy(100,50,"<---Delete Record--->");
     outtextxy(50,80,"Enter the student roll no.. for delect the record");
     fflush(stdin);
     gets(stname);
     fp=fopen("srec.txt","rb+");
       if(fp==NULL)
	 {
	   outtextxy(50,85,"Error in opening file");
	   getch();
	   exit(1);
	 }
	   ft=fopen("trec.txt","wb+");
	       if(ft==NULL){
	     outtextxy(50,85,"Error in opening file");
	     getch();
	     exit(1);
       }

	while(fread(&std,sizeof(std),1,fp)==1){
	    if(strcmp(stname,std.rollno)!=0)
		fwrite(&std,sizeof(std),1,ft);
	    }
	      fclose(fp);
	      fclose(ft);
	      remove("srec.txt");

	rename("trec.txt","srec.txt");
	load();
	       setcolor(RED);
			 settextstyle(1,0,1);
	    outtextxy(90,130,"Record delected sucessfully");
	    setcolor(BLUE);
	    outtextxy(90,160,"Plzz enter a key to continue..........");
		   getch();
		   menu();

}

