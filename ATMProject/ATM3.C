#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<time.h>
char acc[10][13]={"510201938200","510201938201","510201938202","510201938203","510201938204","510201938205","510201938206","5102019381207","5102019381208","5102019381209"},acc1[13],acc2[13],A[13];
char pin[3][5]={{"2345"},{"3456"},{"4567"}},pin1[5],pin2[5],P[5];
char name[20],name1[20],name2[20];
char branch[3][50]={{"Ameerpet"},{"Kompally"},{"Kondapur"}},branch1[10],branch2[10];
char mobile[11],mobile1[11],mobile2[11];
float balance,balance1,balance2;
long int maximumd,maximumw,minimum,maximumd1,maximumd2,maximumw1,maximumw2;
char id[10],id1[10],id2[10],ID[10];
int x,x1,r;
int withdraw1,withdraw2,deposit1,deposit2,transfer1,transfer2;
void ATM();
void display();
void Pin(int);
void menu();
void balanceenquiry();
void cashwithdrawal();
void moneytransfer();
void cashdeposit();
void pinchange();
void ministatement();
void termination();
void executivedata();
void BANK();
void accountcreation();
void applyfordebitcard();
void withdrawal();
void deposit();
void terminationb();
char executive[]="executive",exepin[]="0000";
struct statement
{
 float amount[5];
 char transaction[5][35];
 char time[5][30];
}s[10];
time_t t;
void main()
{
 char option;
 dh:
 clrscr();
 gotoxy(24,13);
 printf("WELCOME to VNRVJIET Collabaration");
 getch();
 clrscr();
 begin2:
 gotoxy(16,12);
 printf("1.Bank");
 gotoxy(56,12);
 printf("2.ATM");
 gotoxy(40,14);
 fflush(stdin);
 scanf("%c",&option);
 clrscr();
 if(option=='1'||option=='2')
  switch(option)
  {
   case '1': BANK();
			 break;
   case '2': ATM();
			 break;
  }
 else
 {
  again2:
    clrscr();
  gotoxy(34,13);
  printf("Invalid option");
  delay(2000);
   clrscr();
  gotoxy(29,10);
  printf("Do you want to continue(Y/N)");
  gotoxy(40,11);
  fflush(stdin);
  scanf("%c",&option);
  clrscr();
  if(option=='Y')
   goto begin2;
  else if(option=='N')
   goto dh;
  else
   goto again2;
 }

}
void ATM()
{
 int i,flag=0;
 FILE *fp;
 fp=fopen("bank.txt","r");
 fscanf(fp,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x,acc1,name1,&balance1,pin1,branch1,id1,mobile1,&maximumw1,&maximumd1,&withdraw1,&deposit1,&transfer1);
 fclose(fp);
 begin:
 clrscr();
 gotoxy(34,10);
 printf("Welcome to atm");
 gotoxy(22,12);
 printf("Please enter your unique id to proceed");
 gotoxy(22,14);
 printf("ID:");
 scanf("%s",ID);
 fp=fopen("bank.txt","r");
 for(r=0;r<x;r++)
 {
  fscanf(fp,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x1,acc1,name1,&balance1,pin1,branch1,id1,mobile1,&maximumw1,&maximumd1,&withdraw1,&deposit1,&transfer1);
  if(strcmp(ID,id1)==0)
  {
   flag=1;
   break;
  }
  else if(strcmp(ID,"executive")==0)
  {
   clrscr();
   Pin(4);
  }
 }
 fclose(fp);
 clrscr();
 if(flag==0)
 {
  gotoxy(31,11);
  printf("Invalid Unique ID");
  delay(3000);
  clrscr();
  goto begin;
 }
 else display();
 getch();
}
void display()
{
 char option;
 gotoxy(29,8);
 printf("Name       : %s",name1);
 gotoxy(29,10);
 printf("Account NO : XXXXXXXX%c%c%c%c",acc1[8],acc1[9],acc1[10],acc1[11]);
 gotoxy(29,12);
 printf("Branch     : %s",branch1);
 delay(2000);
 op:
 gotoxy(29,14);
 printf("Press Y to continue");
 gotoxy(29,15);
 printf("OR\n");
 gotoxy(29,16);
 printf("Press N to terminate");
 gotoxy(40,17);
 fflush(stdin);
 scanf("%c",&option);
 clrscr();
 if(option=='Y')
  Pin(0);
 else if(option=='N')
  termination();
 else
 {
  gotoxy(34,13);
  printf("Invalid Option");
  delay(3000);
  clrscr();
  goto op;
 }
}
void Pin(int n)
{
 char type[5],option;
 int i;
 again:
 gotoxy(24,11);
 printf("Please enter your four digit PIN:");
 gotoxy(39,14);
 for(i=0;i<4;i++)
 {
  type[i]=getch();
  printf("*");
 }
 type[4]='\0';
 getch();
 clrscr();
 if(!n)
 {
  if(strcmp(type,pin1)==0)
   menu();
  else
  {
   incorrect:
   gotoxy(29,12);
   printf("PIN entered is incorrect");
   op:
   gotoxy(27,13);
   printf("Do you want to continue(Y/N)");
   gotoxy(40,14);
   fflush(stdin);
   scanf("%c",&option);
   clrscr();
   if(option=='Y')
    goto again;
   else if(option=='N')
    termination();
   else
   {
    gotoxy(32,13);
    printf("Invalid Option");
    delay(2000);
    clrscr();
    goto op;
   }
  }
 }
 else
  if(strcmp(type,exepin)==0)
   executivedata();
  else
   goto incorrect;
}
void menu()
{
 char option;
 begin:
 clrscr();
 gotoxy(11,10);
 printf("1.Savings Account");
 gotoxy(53,10);
 printf("2.Current Account");
 gotoxy(40,11);
 fflush(stdin);
 scanf("%c",&option);
 if(option!='1'&&option!='2')
 {
  again:
  clrscr();
  gotoxy(34,13);
  printf("Invalid option");
  delay(2000);
  clrscr();
  gotoxy(29,10);
  printf("Do you want to continue(Y/N)");
  gotoxy(40,11);
  fflush(stdin);
  scanf("%c",&option);
  clrscr();
  if(option=='Y')
   goto begin;
  else if(option=='N')
   termination();
  else
   goto again;
 }
 begin2:
  clrscr();
 gotoxy(11,9);
 printf("1.Cash Withdrawal");
 gotoxy(53,9);
 printf("2.Balance Enquiry");
 gotoxy(11,12);
 printf("3.PIN change");
 gotoxy(53,12);
 printf("4.Cash Deposit");
 gotoxy(11,15);
 printf("5.Money Transfer");
 gotoxy(53,15);
 printf("6.Ministatement");
 gotoxy(40,17);
 fflush(stdin);
 scanf("%c",&option);

 clrscr();
  if(option=='1'||option=='2'||option=='3'||option=='4'||option=='5'||option=='6')
  switch(option)
  {
   case '1': cashwithdrawal();
			 break;
   case '2': balanceenquiry();
			 break;
   case '3': pinchange();
		    break;
   case '4': cashdeposit();
		      break;
   case '5': moneytransfer();
			break;
   case '6': ministatement();
			break;
  }
 else
 {
  again2:
    clrscr();
  gotoxy(34,13);
  printf("Invalid option");
  delay(2000);
   clrscr();
  gotoxy(29,10);
  printf("Do you want to continue(Y/N)");
  gotoxy(40,11);
  fflush(stdin);
  scanf("%c",&option);
  clrscr();
  if(option=='Y')
   goto begin2;
  else if(option=='N')
   termination();
  else
   goto again2;
 }
}
void balanceenquiry()
{
 char option;
 int i;
 gotoxy(22,10);
 printf("Available Balance: %f",balance1);
 xy:
 gotoxy(26,13);
 printf("As a part of Green Revolution");
 gotoxy(26,15);
 printf("We suggest not to take reciept");
 gotoxy(19,17);
 printf("Even if you need a reciept then press (Y/N)");
 gotoxy(40,19);
 fflush(stdin);
 scanf("%c",&option);
   clrscr();
 if(option=='Y')
 {
  gotoxy(5,3);
  for(i=0;i<70;i++)
   printf("_");
  gotoxy(4,4);
  for(i=0;i<13;i++)
  {
   printf("|");
   gotoxy(4,5+i);
  }
  gotoxy(75,4);
  for(i=0;i<13;i++)
  {
   printf("|");
   gotoxy(75,5+i);
  }
  gotoxy(34,5);
  printf("VNRVJIET Bank");
  time(&t);
  gotoxy(7,7);
  printf("DAY MON DT   TIME   YEAR");
  gotoxy(7,8);
  printf("%s",ctime(&t));
  gotoxy(29,10);
  printf("Account NO : XXXXXXXX%c%c%c%c",acc1[8],acc1[9],acc1[10],acc1[11]);
  gotoxy(33,12);
  printf("Balance Enquiry");
  gotoxy(7,14);
  printf("Available balance :");
  gotoxy(65,14);
  printf("%8.2f",balance1);
  gotoxy(5,16);
  for(i=0;i<70;i++)
  printf("_");
  gotoxy(29,18);
  printf("Please take your reciept");
  getch();
  clrscr();
 }
 else if(option=='N');
 else
 {
  gotoxy(34,13);
  printf("Invalid input");
  delay(3000);
    clrscr();
  goto xy;
 }
 termination();
}
void cashwithdrawal()
{
 FILE *fp,*fp1;
 float cash;
 char option;
 int i;
 begin:
 gotoxy(29,13);
 printf("Enter the amount: ");
 scanf("%f",&cash);
 if(cash>balance1)
 {
  clrscr();
  gotoxy(31,13);
  printf("Insufficient balance");
  delay(3000);
  clrscr();
  op:
  gotoxy(29,11);
  printf("Press Y to continue");
  gotoxy(29,12);
  printf("OR");
  gotoxy(29,13);
  printf("Press N to terminate");
  gotoxy(40,14);
  fflush(stdin);
  scanf("%c",&option);
  clrscr();
  if(option=='Y')
   goto begin;
  else if(option=='N')
   termination();
  else
  {
   gotoxy(34,13);
   printf("Invalid input");
   delay(2000);
   clrscr();
   goto op;
  }
 }
 else
 {
  if(cash>maximumw1)
  {
   clrscr();
   gotoxy(31,13);
   printf("Daily limit exceeded");
   delay(3000);
   clrscr();
   goto op;
  }
  else
  {
   clrscr();
  maximumw1-=cash;
  balance1-=cash;
  withdraw1++;
  fp=fopen("bank.txt","r");
 fp1=fopen("bank1.txt","w");
 for(i=0;i<x;i++)
 {
  fscanf(fp,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x,acc2,name2,&balance2,pin2,branch2,id2,mobile2,&maximumw2,&maximumd2,&withdraw2,&deposit2,&transfer2);
  if(strcmp(ID,id2)==0)
  {
   balance2=balance1;
   maximumw2=maximumw1;
   withdraw2=withdraw1;
  }
  fprintf(fp1,"%d %s %s %f %s %s %s %s %ld %ld %d %d %d\n",x,acc2,name2,balance2,pin2,branch2,id2,mobile2,maximumw2,maximumd2,withdraw2,deposit2,transfer2);
 }
 fcloseall();
 fp=fopen("bank.txt","w");
 fp1=fopen("bank1.txt","r");
 for(i=0;i<x;i++)
 {
  fscanf(fp1,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x,acc2,name2,&balance2,pin2,branch2,id2,mobile2,&maximumw2,&maximumd2,&withdraw2,&deposit2,&transfer2);
  fprintf(fp,"%d %s %s %f %s %s %s %s %ld %ld %d %d %d\n",x,acc2,name2,balance2,pin2,branch2,id2,mobile2,maximumw2,maximumd2,withdraw2,deposit2,transfer2);
 }
 fcloseall();
  time(&t);
  for(i=4;i>0;i--)
   s[r].amount[i]=s[r].amount[i-1];
  s[r].amount[0]=cash;
  for(i=4;i>0;i--)
   strcpy(s[r].transaction[i],s[r].transaction[i-1]);
  strcpy(s[r].transaction[0],"Withdraw");
  for(i=4;i>0;i--)
   strcpy(s[r].time[i],s[r].time[i-1]);
  strcpy(s[r].time[0],ctime(&t));
  gotoxy(30,13);
  printf("Please take your cash");
  delay(2000);
  clrscr();
  gotoxy(22,10);
  printf("Available Balance : %f",balance1);
  bc:
  gotoxy(26,13);
  printf("As a part of Green Revolution");
  gotoxy(26,15);
  printf("We suggest not to take reciept");
  gotoxy(19,17);
  printf("Even if you need a reciept then press (Y/N)");
  gotoxy(40,19);
  fflush(stdin);
  scanf("%c",&option);
  clrscr();
  if(option=='Y')
  {
   gotoxy(5,3);
   for(i=0;i<70;i++)
    printf("_");
   gotoxy(4,4);
   for(i=0;i<15;i++)
   {
    printf("|");
    gotoxy(4,5+i);
   }
   gotoxy(75,4);
   for(i=0;i<15;i++)
   {
    printf("|");
    gotoxy(75,5+i);
   }
   gotoxy(34,5);
   printf("VNRVJIET Bank");
   time(&t);
   gotoxy(7,7);
   printf("DAY MON DT   TIME   YEAR");
   gotoxy(7,8);
   printf("%s",ctime(&t));
   gotoxy(29,10);
   printf("Account NO : XXXXXXXX%c%c%c%c",acc1[8],acc1[9],acc1[10],acc1[11]);
   gotoxy(33,12);
   printf("Cash Withdrawal");
   gotoxy(7,14);
   printf("Withdrawn Amount  :");
   gotoxy(65,14);
   printf("%8.2f",cash);
   gotoxy(7,16);
   printf("Available balance :");
   gotoxy(65,16);
   printf("%8.2f",balance1);
   gotoxy(5,18);
   for(i=0;i<70;i++)
    printf("_");
   gotoxy(29,20);
   printf("Please take your reciept");
   getch();
   clrscr();
   termination();
  }
  else if(option=='N')
  termination();
  else
  {
   gotoxy(34,13);
   printf("Invalid input");
   delay(3000);
   clrscr();
   goto bc;
  }
 }
}
}
void pinchange()
{
 int i;
 char pina[5],pinb[5];
 FILE *fp,*fp1;
 begin:
 gotoxy(32,12);
 printf("Enter your new PIN");
 gotoxy(39,13);
 for(i=0;i<4;i++)
 {
  fflush(stdin);
  pina[i]=getch();
  printf("*");
 }
 pina[4]='\0';
 getch();
 clrscr();
 gotoxy(29,12);
 printf("Please re-enter your PIN");
 gotoxy(39,13);
 for(i=0;i<4;i++)
 {
  fflush(stdin);
  pinb[i]=getch();
  printf("*");
 }
 pinb[4]='\0';
 getch();
 clrscr();
 if(strcmp(pina,pinb)==0)
 {
   fp=fopen("bank.txt","r");
 fp1=fopen("bank1.txt","w");
 for(i=0;i<x;i++)
 {
  fscanf(fp,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x1,acc2,name2,&balance2,pin2,branch2,id2,mobile2,&maximumw2,&maximumd2,&withdraw2,&deposit2,&transfer2);
  if(strcmp(ID,id2)==0)
  {
   strcpy(pin2,pina);
  }
  fprintf(fp1,"%d %s %s %f %s %s %s %s %ld %ld %d %d %d\n",x1,acc2,name2,balance2,pin2,branch2,id2,mobile2,maximumw2,maximumd2,withdraw2,deposit2,transfer2);
 }
 fcloseall();
 fp=fopen("bank.txt","w");
 fp1=fopen("bank1.txt","r");
 for(i=0;i<x;i++)
 {
  fscanf(fp1,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x,acc2,name2,&balance2,pin2,branch2,id2,mobile2,&maximumw2,&maximumd2,&withdraw2,&deposit2,&transfer2);
  fprintf(fp,"%d %s %s %f %s %s %s %s %ld %ld %d %d %d\n",x,acc2,name2,balance2,pin2,branch2,id2,mobile2,maximumw2,maximumd2,withdraw2,deposit2,transfer2);
 }
 fcloseall();
  gotoxy(29,13);
  printf("PIN change is successful");
  delay(3000);
  clrscr();
  termination();
 }
 else
 {
  gotoxy(34,13);
  printf("PIN mis-match");
  delay(2000);
  clrscr();
  goto begin;
 }
}
void cashdeposit()
{
 FILE *fp,*fp1;
 float cash;
 int i;
 char option;
 begin:
 gotoxy(29,13);
 printf("Enter the amount: ");
 scanf("%f",&cash);
 clrscr();
 if(cash<=maximumd1)
 {
  maximumd1-=cash;
  balance1+=cash;
  deposit1++;
  fp=fopen("bank.txt","r");
 fp1=fopen("bank1.txt","w");
 for(i=0;i<x;i++)
 {
  fscanf(fp,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x1,acc2,name2,&balance2,pin2,branch2,id2,mobile2,&maximumw2,&maximumd2,&withdraw2,&deposit2,&transfer2);
  if(strcmp(ID,id2)==0)
  {
   balance2=balance1;
   maximumd2=maximumd1;
   deposit2=deposit1;
  }
  fprintf(fp1,"%d %s %s %f %s %s %s %s %ld %ld %d %d %d\n",x1,acc2,name2,balance2,pin2,branch2,id2,mobile2,maximumw2,maximumd2,withdraw2,deposit2,transfer2);
 }
 fcloseall();
 fp=fopen("bank.txt","w");
 fp1=fopen("bank1.txt","r");
 for(i=0;i<x;i++)
 {
  fscanf(fp1,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x,acc2,name2,&balance2,pin2,branch2,id2,mobile2,&maximumw2,&maximumd2,&withdraw2,&deposit2,&transfer2);
  fprintf(fp,"%d %s %s %f %s %s %s %s %ld %ld %d %d %d\n",x,acc2,name2,balance2,pin2,branch2,id2,mobile2,maximumw2,maximumd2,withdraw2,deposit2,transfer2);
 }
 fcloseall();
  time(&t);
  for(i=4;i>0;i--)
   s[r].amount[i]=s[r].amount[i-1];
  s[r].amount[0]=cash;
  for(i=4;i>0;i--)
   strcpy(s[r].transaction[i],s[r].transaction[i-1]);
  strcpy(s[r].transaction[0],"Deposit");
  for(i=4;i>0;i--)
   strcpy(s[r].time[i],s[r].time[i-1]);
  strcpy(s[r].time[0],ctime(&t));
  bc:
  gotoxy(22,10);
  printf("Available Balance: %lf",balance1);
  gotoxy(26,13);
  printf("As a part of Green Revolution");
  gotoxy(26,15);
  printf("We suggest not to take reciept");
  gotoxy(19,17);
  printf("Even if you need a reciept then press (Y/N)");
  gotoxy(40,19);
  fflush(stdin);
  scanf("%c",&option);
  clrscr();
  if(option=='Y')
  {
   gotoxy(5,3);
   for(i=0;i<70;i++)
    printf("_");
   gotoxy(4,4);
   for(i=0;i<15;i++)
   {
    printf("|");
    gotoxy(4,5+i);
   }
   gotoxy(75,4);
   for(i=0;i<15;i++)
   {
    printf("|");
    gotoxy(75,5+i);
   }
   gotoxy(34,5);
   printf("VNRVJIET Bank");
   time(&t);
   gotoxy(7,7);
   printf("DAY MON DT   TIME   YEAR");
   gotoxy(7,8);
   printf("%s",ctime(&t));
   gotoxy(29,10);
   printf("Account NO : XXXXXXXX%c%c%c%c",acc1[8],acc1[9],acc1[10],acc1[11]);
   gotoxy(33,12);
   printf("Cash Deposition");
   gotoxy(7,14);
   printf("Deposited Amount  :");
   gotoxy(65,14);
   printf("%8.2f",cash);
   gotoxy(7,16);
   printf("Available balance :");
   gotoxy(65,16);
   printf("%8.2f",balance1);
   gotoxy(5,18);
   for(i=0;i<70;i++)
    printf("_");
   gotoxy(29,20);
   printf("Please take your reciept");
   getch();
   clrscr();
   termination();
  }
  else if(option=='N')
  termination();
  else
  {
   gotoxy(34,13);
   printf("Invalid input");
   goto bc;
  }
 }
 else
 {
  clrscr();
  gotoxy(31,13);
  printf("Daily limit exceeded");
  delay(3000);
  clrscr();
  xy:
  gotoxy(29,11);
  printf("Press Y to continue");
  gotoxy(29,12);
  printf("OR");
  gotoxy(29,13);
  printf("Press N to terminate");
  gotoxy(40,14);
  fflush(stdin);
  scanf("%c",&option);
  clrscr();
  if(option=='Y')
   goto begin;
  else if(option=='N')
   termination();
  else
  {
   gotoxy(34,11);
   printf("Invalid input");
   delay(3000);
   clrscr();
   goto xy;
  }
 }
}
void moneytransfer()
{
 FILE *fp,*fp1;
 char account[13];
 int flag=0,i,j;
 char option;
 float cash;
 again:
 gotoxy(30,12);
 printf("Enter payee account NO");
 gotoxy(40,13);
 scanf("%s",account);
 clrscr();
 fp=fopen("bank.txt","r");
 for(i=0;i<x;i++)
 {
  fscanf(fp,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x1,acc2,name2,&balance2,pin2,branch2,id2,mobile2,&maximumw2,&maximumd2,&withdraw2,&deposit2,&transfer2);
  if(strcmp(account,acc2)==0)
  {
   op:
   gotoxy(29,8);
   printf("Name       : %s",name2);
   gotoxy(29,10);
   printf("Account NO : XXXXXXXX%c%c%c%c",acc2[8],acc2[9],acc2[10],acc2[11]);
   gotoxy(29,12);
   printf("Branch     : %s",branch2);
   delay(2000);
   gotoxy(29,14);
   printf("Press Y to continue");
   gotoxy(29,15);
   printf("OR");
   gotoxy(29,16);
   printf("Press N to terminate");
   gotoxy(40,17);
   fflush(stdin);
   scanf("%c",&option);
   clrscr();
   flag=1;
   break;
  }
 }
 if(flag)
 {
  if(option=='Y')
  {
   ab:
   gotoxy(29,13);
   printf("Enter the amount: ");
   scanf("%f",&cash);
   clrscr();
   if(cash<=maximumw1)
   {
    maximumw1-=cash;
    balance1-=cash;
    fp=fopen("bank.txt","r");
    fp1=fopen("bank1.txt","w");
    for(i=0;i<x;i++)
    {
     fscanf(fp,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x,acc2,name2,&balance2,pin2,branch2,id2,mobile2,&maximumw2,&maximumd2,&withdraw2,&deposit2,&transfer2);
     if(strcmp(ID,id2)==0)
     {
      balance2=balance1;
      maximumw2=maximumw1;
      withdraw2=withdraw1;
     }
     if(strcmp(account,acc2)==0)
     {
      balance2+=cash;
      deposit2+=1;
     }
     fprintf(fp1,"%d %s %s %f %s %s %s %s %ld %ld %d %d %d\n",x,acc2,name2,balance2,pin2,branch2,id2,mobile2,maximumw2,maximumd2,withdraw2,deposit2,transfer2);
    }
    fcloseall();
    fp=fopen("bank.txt","w");
    fp1=fopen("bank1.txt","r");
    for(i=0;i<x;i++)
    {
     fscanf(fp1,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x,acc2,name2,&balance2,pin2,branch2,id2,mobile2,&maximumw2,&maximumd2,&withdraw2,&deposit2,&transfer2);
     fprintf(fp,"%d %s %s %f %s %s %s %s %ld %ld %d %d %d\n",x,acc2,name2,balance2,pin2,branch2,id2,mobile2,maximumw2,maximumd2,withdraw2,deposit2,transfer2);
    }
    fcloseall();
    time(&t);
    for(j=4;j>0;j--)
     s[r].amount[j]=s[r].amount[j-1];
    s[r].amount[0]=cash;
    for(j=4;j>0;j--)
     strcpy(s[r].transaction[j],s[r].transaction[j-1]);
    strcpy(s[r].transaction[0],"Transfered to ");
    strcat(s[r].transaction[0],acc2);
    for(j=4;j>0;j--)
     strcpy(s[r].time[j],s[r].time[j-1]);
    strcpy(s[r].time[0],ctime(&t));
    for(j=4;j>0;j--)
     s[i].amount[j]=s[i].amount[j-1];
    s[i].amount[0]=cash;
    for(j=4;j>0;j--)
     strcpy(s[i].transaction[j],s[i].transaction[j-1]);
    strcpy(s[i].transaction[0],"Debited from ");
    strcat(s[i].transaction[0],acc2);
    for(j=4;j>0;j--)
     strcpy(s[i].time[j],s[i].time[j-1]);
    strcpy(s[i].time[0],ctime(&t));
    transfer1++;
    deposit2++;
    gotoxy(28,13);
    printf("Transaction is successful");
    fclose(fp);
    delay(2000);
    clrscr();
    gotoxy(26,12);
    printf("As a part of Green Revolution");
    gotoxy(26,14);
    printf("We suggest not to take reciept");
    gotoxy(19,16);
    printf("Even if you need a reciept then press (Y/N)");
    gotoxy(40,18);
    fflush(stdin);
    scanf("%c",&option);
    clrscr();
    if(option=='Y')
    {
     gotoxy(5,3);
     for(j=0;j<70;j++)
      printf("_");
     gotoxy(4,4);
     for(i=0;i<17;i++)
     {
      printf("|");
      gotoxy(4,5+i);
     }
     gotoxy(75,4);
     for(i=0;i<17;i++)
     {
      printf("|");
      gotoxy(75,5+i);
     }
     gotoxy(34,5);
     printf("VNRVJIET Bank");
     time(&t);
     gotoxy(7,7);
     printf("DAY MON DT   TIME   YEAR");
     gotoxy(7,8);
     printf("%s",ctime(&t));
     gotoxy(29,10);
     printf("Account NO : XXXXXXXX%c%c%c%c",acc1[8],acc1[9],acc1[10],acc1[11]);
     gotoxy(34,12);
     printf("Money Transfer");
     gotoxy(7,14);
     printf("Payee Acc.NO :");
     gotoxy(62,14);
     printf("XXXXXXXX%c%c%c%c",acc2[8],acc2[9],acc2[10],acc2[11]);
     gotoxy(7,16);
     printf("Transfered Amount  :");
     gotoxy(65,16);
     printf("%8.2f",cash);
     gotoxy(7,18);
     printf("Available balance :");
     gotoxy(65,18);
     printf("%8.2f",balance1);
     gotoxy(5,20);
     for(j=0;j<70;j++)
      printf("_");
     gotoxy(29,22);
     printf("Please take your reciept");
     getch();
     clrscr();
    }
    else if(option=='N')
     termination();
    else
    {
     gotoxy(34,13);
     printf("Invalid option");
     delay(2000);
     clrscr();
     goto xy;
    }
   }
   else
   {
    clrscr();
    gotoxy(31,13);
    printf("Daily limit exceeded");
    delay(3000);
    clrscr();
    xy:
    gotoxy(29,12);
    printf("Press Y to continue");
    gotoxy(29,13);
    printf("OR");
    gotoxy(29,14);
    printf("Press N to terminate");
    gotoxy(40,15);
    fflush(stdin);
    scanf("%c",&option);
    clrscr();
    if(option=='Y')
     goto ab;
    else if(option=='N')
     termination();
    else
    {
     cd:
     gotoxy(34,13);
     printf("Invalid option");
     delay(2000);
     clrscr();
     goto xy;
    }
   }
   termination();
  }
  else if(option=='N')
   termination();
  else
  {
   gotoxy(34,13);
   printf("Invalid input");
   delay(3000);
   clrscr();
   goto op;
  }
 }
 else
 {
  gotoxy(33,13);
  printf("Payee not found");
  delay(3000);
  clrscr();
  gotoxy(29,11);
  printf("Press Y to continue");
  gotoxy(29,12);
  printf("OR");
  gotoxy(29,13);
  printf("Press N to terminate");
  fflush(stdin);
  gotoxy(40,14);
  scanf("%c",&option);
  clrscr();
  if(option=='Y')
   goto again;
  else if(option=='N')
   termination();
  else
   goto cd;
 }
 fclose(fp);
}
void termination()
{
   char o;
 gotoxy(27,13);
 printf("Thank YOU for using our ATM");
 gotoxy(33,14);
 printf("Have A Nice day");
 fflush(stdin);
 o=getch();
   clrscr();
 if(o=='y')
 {
  gotoxy(30,13);
  printf("Thank YOU \"BABY ma'am\"");
  getch();
 }
else
 main();
}
void executivedata()
{
 FILE *fp;
   int i;
 gotoxy(26,13);
 printf("Total customers   : %d",x);
 getch();
   clrscr();
 fp=fopen("bank.txt","r");

 for(i=0;i<x;i++)
 {
  fscanf(fp,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x1,acc1,name1,&balance1,pin1,branch1,id1,mobile1,&maximumw1,&maximumd2,&withdraw1,&deposit1,&transfer1);
  gotoxy(26,8);
  printf("Name             : %s",name1);
  gotoxy(26,10);
  printf("Account NO       : %s",acc1);
  gotoxy(26,12);
  printf("Branch           : %s",branch1);
  gotoxy(26,14);
  printf("Cash Withdrawals : %d",withdraw1);
  gotoxy(26,15);
  printf("Cash Deposits    : %d",deposit1);
  gotoxy(26,16);
  printf("Money Transfers  : %d",transfer1);
  getch();
    clrscr();
 }
 termination();
}
void ministatement()
{
 int i,j;
 char option;
 gotoxy(6,8);
 printf("DAY MON DT   TIME   YEAR   TRANSACTION                         AMOUNT");
 for(i=0;i<5;i++)
 {
  gotoxy(6,8+(2*(i+1)));
  printf("%s",s[r].time[i]);
  gotoxy(33,8+(2*(i+1)));
  printf("%s",s[r].transaction[i]);
  gotoxy(68,8+(2*(i+1)));
  printf("%8.2f",s[r].amount[i]);
 }
 gotoxy(22,20);
 printf("Available Balance: %8.2f",balance1);
 getch();
 xy:
 clrscr();
 gotoxy(26,12);
 printf("As a part of Green Revolution");
 gotoxy(26,13);
 printf("We suggest not to take reciept");
 gotoxy(19,14);
 printf("Even if you need a reciept then press (Y/N)");
 gotoxy(40,15);
 fflush(stdin);
 scanf("%c",&option);
 clrscr();
 if(option=='Y')
 {
  gotoxy(5,1);
  for(j=0;j<70;j++)
   printf("_");
  gotoxy(4,2);
  for(i=0;i<22;i++)
  {
   printf("|");
   gotoxy(4,3+i);
  }
  gotoxy(75,2);
  for(i=0;i<22;i++)
  {
   printf("|");
   gotoxy(75,3+i);
  }
  gotoxy(34,3);
  printf("VNRVJIET Bank");
  time(&t);
  gotoxy(7,5);
  printf("DAY MON DT   TIME   YEAR");
  gotoxy(7,6);
  printf("%s",ctime(&t));
  gotoxy(29,8);
  printf("Account NO : XXXXXXXX%c%c%c%c",acc1[8],acc1[9],acc1[10],acc1[11]);
  gotoxy(34,9);
  printf("Mini Statement");
  gotoxy(7,11);
  printf("DAY MON DT   TIME   YEAR   TRANSACTION                     AMOUNT");
  for(i=0;i<5;i++)
  {
   gotoxy(7,11+(2*(i+1)));
   printf("%s",s[r].time[i]);
   gotoxy(34,11+(2*(i+1)));
   printf("%s",s[r].transaction[i]);
   gotoxy(64,11+(2*(i+1)));
   printf("%8.2f",s[r].amount[i]);
  }
  gotoxy(7,22);
  printf("Available Balance :");
  gotoxy(63,22);
  printf("%8.2f",balance1);
  gotoxy(5,23);
  for(j=0;j<70;j++)
   printf("_");
  gotoxy(29,24);
  printf("Please take your reciept");
  getch();
  clrscr();
 }
 else if(option=='N')
 termination();
 else
 {
  gotoxy(34,13);
  printf("Invalid option");
  delay(2000);
  clrscr();
  goto xy;
 }
 termination();
}
void BANK()
{
 char option;
 FILE *fp;
 fp=fopen("bank.txt","r");
 fscanf(fp,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x,acc1,name1,&balance1,pin1,branch1,id1,mobile1,&maximumw1,&maximumd1,&withdraw1,&deposit1,&transfer1);
 fclose(fp);
 clrscr();
 gotoxy(28,13);
 printf("Welcome to VNR VJIET Bank");
 getch();
 clrscr();
 begin:
 gotoxy(11,9);
 printf("1.Account Creation");
 gotoxy(53,9);
 printf("2.Apply for Debit Card");
 gotoxy(11,12);
 printf("3.Cash Deposit");
 gotoxy(53,12);
 printf("4.Cash Withdrawal");
 gotoxy(40,15);
 fflush(stdin);
 scanf("%c",&option);
 clrscr();
 if(option=='1'||option=='2'||option=='3'||option=='4'||option=='5')
  switch(option)
  {
   case '1': accountcreation();
			 break;
   case '2': applyfordebitcard();
			   break;
   case '3': deposit();
		 break;
   case '4': withdrawal();
		    break;
   case '5':
		    break;
  }
 else
 {
  again:
  clrscr();
  gotoxy(34,13);
  printf("Invalid option");
  delay(2000);
  clrscr();
  gotoxy(29,10);
  printf("Do you want to continue(Y/N)");
  gotoxy(40,11);
  fflush(stdin);
  scanf("%c",&option);
  clrscr();
  if(option=='Y')
   goto begin;
  else if(option=='N')
   terminationb();
  else
   goto again;
 }
}
void accountcreation()
{
 FILE *fp,*fp1;
 int i,y;
 char option;
 clrscr();
 gotoxy(30,12);
 printf("Name      : ");
 gotoxy(30,14);
 printf("Mobile NO : ");
 gotoxy(42,12);
 scanf("%s",name);
 gotoxy(42,14);
 scanf("%s",mobile);
 clrscr();
 again3:
 gotoxy(12,12);
 printf("Minimum balance options");
 gotoxy(45,12);
 printf("1. 1000");
 gotoxy(45,13);
 printf("2. 5000");
 gotoxy(45,14);
 printf("3. 10000");
 gotoxy(40,15);
 fflush(stdin);
 scanf("%c",&option);
 clrscr();
 if(option=='1')
 {
  maximumw=30000;
  maximumd=30000;
  minimum=1000;
 }
 else if(option=='2')
 {
  maximumw=50000;
  maximumd=50000;
  minimum=5000;
 }
 else if(option=='3')
 {
  maximumw=70000;
  maximumd=70000;
  minimum=10000;
 }
 else
 {
  ef:
  gotoxy(32,13);
  printf("Invalid Option");
  delay(2000);
  clrscr() ;
  printf("Do you want to continue(Y/N)");
  gotoxy(40,14);
  fflush(stdin);
  scanf("%c",&option);
  clrscr();
  if(option=='Y')
   goto again3;
  else if(option=='N')
   terminationb();
  else
   goto ef;
 }
 begin:
 gotoxy(23,13);
 printf("Balance deposited: ");
 gotoxy(41,13);
 scanf("%f",&balance);
 clrscr();
 if(balance<(float)minimum)
 {
  gotoxy(34,13);
  printf("Deposit is insufficient");
  delay(2000);
  clrscr();
  gh:
  gotoxy(29,10);
  printf("Do you want to continue(Y/N)");
  gotoxy(40,11);
  fflush(stdin);
  scanf("%c",&option);
  clrscr();
  if(option=='Y')
   goto begin;
  else if(option=='N')
   terminationb();
  else
  {
   gotoxy(32,13);
   printf("Invalid Option");
   delay(2000);
   clrscr();
   goto gh;
  }
 }
 x++;
 clrscr();
 gotoxy(26,6);
 printf("Account creation is successful");
 gotoxy(31,8);
 printf("Account details are:");
 gotoxy(29,10);
 printf("Name       : %s",name);
 gotoxy(29,12);
 printf("Account NO : %s",acc[(x-4)]);
 gotoxy(29,14);
 printf("Branch     : %s",branch[((x-3)%3)-1]);
 gotoxy(29,16);
 printf("Mobile     : %s",mobile);
 getch();
 clrscr();
 i=0;
 y=x;
 while(y)
 {
  id[i]=(char)(y%10);
  y/=10;
  i++;
 }
 id[i]='\0';
 fp=fopen("bank.txt","a");
 fprintf(fp,"%d %s %s %f %s %s %s %s %ld %ld %d %d %d\n",x,acc[(x-4)],name,balance,pin[((x-3)%3)-1],branch[((x-3)%3)-1],id,mobile,maximumw,maximumd,0,0,0);
 fclose(fp);
 fp=fopen("bank.txt","r");
 fp1=fopen("bank1.txt","w");
 for(i=0;i<x;i++)
 {
  fscanf(fp,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x1,acc2,name2,&balance2,pin2,branch2,id2,mobile2,&maximumw2,&maximumd2,&withdraw2,&deposit2,&transfer2);
  fprintf(fp1,"%d %s %s %f %s %s %s %s %ld %ld %d %d %d\n",x,acc2,name2,balance2,pin2,branch2,id2,mobile2,maximumw2,maximumd2,withdraw2,deposit2,transfer2);
 }
 fcloseall();
 fp=fopen("bank.txt","w");
 fp1=fopen("bank1.txt","r");
 for(i=0;i<x;i++)
 {
  fscanf(fp1,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x,acc2,name2,&balance2,pin2,branch2,id2,mobile2,&maximumw2,&maximumd2,&withdraw2,&deposit2,&transfer2);
  fprintf(fp,"%d %s %s %f %s %s %s %s %ld %ld %d %d %d\n",x,acc2,name2,balance2,pin2,branch2,id2,mobile2,maximumw2,maximumd2,withdraw2,deposit2,transfer2);
 }
 fcloseall();
 terminationb();
}
void applyfordebitcard()
{
 int i,flag=0;
 char option;
 FILE *fp,*fp1;
 xy:
 clrscr();
 gotoxy(35,12);
 printf("ACC NO:");
 gotoxy(35,13);
 printf("PIN   :");
 gotoxy(43,12);
 scanf("%s",A);
 gotoxy(43,13);
 for(i=0;i<4;i++)
 {
  P[i]=getch();
  printf("*");
 }
 P[4]='\0';
 getch();
 clrscr();
 fp=fopen("bank.txt","r");
 fp1=fopen("bank1.txt","r");
 for(i=0;i<x;i++)
 {
  fscanf(fp,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x,acc1,name1,&balance1,pin1,branch1,id1,mobile1,&maximumw1,&maximumd1,&withdraw1,&deposit1,&transfer1);
  if(strcmp(A,acc1)==0)
  {
   if(strcmp(P,pin1)==0)
   flag=1;
   break;
  }
 }
 if(flag)
 {
  if(isalpha(id1[0]))
  {
   gotoxy(21,13);
   printf("You have already applied for DEBIT Card");
   delay(3000);
   clrscr();
   terminationb();
  }
  else
  {
   gotoxy(22,11);
   printf("Through the application of debit card");
   gotoxy(11,12);
   printf("We are issuing a UNIQUE ID to proceed through transactions");
   gotoxy(13,13);
   printf("So kindly enter your UNIQUE ID using alpha and numerics");
   dh:
   gotoxy(31,15);
   printf("UNIQUE ID:");
   scanf("%s",id);
   clrscr();
   for(i=0;i<x;i++)
   {
    fscanf(fp1,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x,acc2,name2,&balance2,pin2,branch2,id2,mobile2,&maximumw2,&maximumd2,&withdraw2,&deposit2,&transfer2);
    if(strcmp(id,id2)==0)
    {
     ox:
     gotoxy(30,11);
     printf("UNIQUE ID already exists");
     gotoxy(27,13);
     printf("Do you want to continue(Y/N)");
     gotoxy(40,15);
     fflush(stdin);
     scanf("%c",&option);
     clrscr();
     if(option=='Y')
      goto dh;
     else if(option=='N')
      terminationb();
     else
     {
      ef:
      gotoxy(32,13);
      printf("Invalid Option");
      delay(2000);
      clrscr() ;
      goto ox;
     }
    }
   }
   fcloseall();
   fp=fopen("bank.txt","r");
   fp1=fopen("bank1.txt","w");
   for(i=0;i<x;i++)
   {
    fscanf(fp,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x,acc1,name1,&balance1,pin1,branch1,id1,mobile1,&maximumw1,&maximumd1,&withdraw1,&deposit1,&transfer1);
    if(strcmp(A,acc1)==0)
     strcpy(id1,id);
    fprintf(fp1,"%d %s %s %f %s %s %s %s %ld %ld %d %d %d\n",x,acc1,name1,balance1,pin1,branch1,id1,mobile1,maximumw1,maximumd1,withdraw1,deposit1,transfer1);
   }
   fcloseall();
   fp=fopen("bank.txt","w");
   fp1=fopen("bank1.txt","r");
   for(i=0;i<x;i++)
   {
    fscanf(fp1,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x,acc1,name1,&balance1,pin1,branch1,id1,mobile1,&maximumw1,&maximumd1,&withdraw1,&deposit1,&transfer1);
    fprintf(fp,"%d %s %s %f %s %s %s %s %ld %ld %d %d %d\n",x,acc1,name1,balance1,pin1,branch1,id1,mobile1,maximumw1,maximumd1,withdraw1,deposit1,transfer1);
   }
   fcloseall();
  }
  gotoxy(25,12);
  printf("UNIQUE ID creation is successful");
  gotoxy(16,14);
  printf("You may proceed through your furthur transactions");
  gotoxy(30,15);
  printf("through your UNIQUE ID");
  getch();
  clrscr();
 }
 if(!flag)
 {
  gotoxy(26,13);
  printf("Details entered are incorrect");
  delay(2000);
  clrscr();
  xo:
  gotoxy(27,12);
  printf("Do you want to continue(Y/N)");
  gotoxy(40,14);
  fflush(stdin);
  scanf("%c",&option);
  clrscr();
  if(option=='Y')
   goto xy;
  else if(option=='N')
  terminationb();
  else
  {
   gotoxy(32,13);
   printf("Invalid Option");
   delay(2000);
   clrscr() ;
   goto xo;
  }
 }
 terminationb();
}
void withdrawal()
{
 int flag=0,i,j;
 float cash;
 char option;
 FILE *fp,*fp1;
 clrscr();
 fp=fopen("bank.txt","r");
 dh:
 gotoxy(35,12);
 printf("ACC NO:");
 gotoxy(35,13);
 printf("PIN   :");
 gotoxy(43,12);
 scanf("%s",A);
 gotoxy(43,13);
 for(i=0;i<4;i++)
 {
  P[i]=getch();
  printf("*");
 }
 P[4]='\0';
 getch();
 clrscr();
 for(j=0;j<x;j++)
 {
  fscanf(fp,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x,acc1,name1,&balance1,pin1,branch1,id1,mobile1,&maximumw1,&maximumd1,&withdraw1,&deposit1,&transfer1);
  if(strcmp(A,acc1)==0)
  {
   if(strcmp(P,pin1)==0)
    flag=1;
   break;
  }
 }
 if(flag)
 {
  begin:
  gotoxy(29,13);
  printf("Enter the amount: ");
  scanf("%f",&cash);
  if(cash>balance1)
  {
   clrscr();
   gotoxy(31,13);
   printf("Insufficient balance");
   delay(3000);
   clrscr();
   op:
   gotoxy(29,11);
   printf("Press Y to continue");
   gotoxy(29,12);
   printf("OR");
   gotoxy(29,13);
   printf("Press N to terminate");
   gotoxy(40,14);
   fflush(stdin);
   scanf("%c",&option);
   clrscr();
   if(option=='Y')
    goto begin;
   else if(option=='N');
   else
   {
    gotoxy(34,13);
    printf("Invalid input");
    delay(2000);
    clrscr();
    goto op;
   }
  }
  else
  {
   clrscr();
   balance1-=cash;
   withdraw1++;
   time(&t);
   for(i=4;i>0;i--)
    s[j].amount[i]=s[j].amount[i-1];
   s[j].amount[0]=cash;
   for(i=4;i>0;i--)
    strcpy(s[j].transaction[i],s[j].transaction[i-1]);
   strcpy(s[j].transaction[0],"Withdraw");
   for(i=4;i>0;i--)
    strcpy(s[j].time[i],s[j].time[i-1]);
   strcpy(s[j].time[0],ctime(&t));
   gotoxy(30,13);
   printf("Please take your cash");
   delay(2000);
   clrscr();
   gotoxy(22,10);
   printf("Available Balance : %f",balance1);
   bc:
   gotoxy(26,13);
   printf("As a part of Green Revolution");
   gotoxy(26,15);
   printf("We suggest not to take reciept");
   gotoxy(19,17);
   printf("Even if you need a reciept then press (Y/N)");
   gotoxy(40,19);
   fflush(stdin);
   scanf("%c",&option);
   clrscr();
   if(option=='Y')
   {
    gotoxy(5,3);
    for(i=0;i<70;i++)
     printf("_");
    gotoxy(4,4);
    for(i=0;i<15;i++)
    {
     printf("|");
     gotoxy(4,5+i);
    }
    gotoxy(75,4);
    for(i=0;i<15;i++)
    {
     printf("|");
     gotoxy(75,5+i);
    }
    gotoxy(34,5);
    printf("VNRVJIET Bank");
    time(&t);
    gotoxy(7,7);
    printf("DAY MON DT   TIME   YEAR");
    gotoxy(7,8);
    printf("%s",ctime(&t));
    gotoxy(29,10);
    printf("Account NO : XXXXXXXX%c%c%c%c",acc1[8],acc1[9],acc1[10],acc1[11]);
    gotoxy(33,12);
    printf("Cash Withdrawal");
    gotoxy(7,14);
    printf("Withdrawn Amount  :");
    gotoxy(65,14);
    printf("%8.2f",cash);
    gotoxy(7,16);
    printf("Available balance :");
    gotoxy(65,16);
    printf("%8.2f",balance1);
    gotoxy(5,18);
    for(i=0;i<70;i++)
     printf("_");
    gotoxy(29,20);
    printf("Please take your reciept");
    getch();
    clrscr();
   }
   else if(option=='N')
    terminationb();
   else
   {
    gotoxy(34,13);
    printf("Invalid input");
    delay(3000);
    clrscr();
    goto bc;
   }
  }
 }
 else
 {
  gotoxy(26,13);
  printf("Details entered are incorrect");
  delay(2000);
  clrscr();
  ox:
  gotoxy(27,12);
  printf("Do you want to continue(Y/N)");
  gotoxy(40,14);
  fflush(stdin);
  scanf("%c",&option);
  clrscr();
  if(option=='Y')
   goto dh;
  else if(option=='N');
  else
  {
   gotoxy(32,13);
   printf("Invalid Option");
   delay(2000);
   clrscr() ;
   goto ox;
  }
 }
 fcloseall();
 fp=fopen("bank.txt","r");
 fp1=fopen("bank1.txt","w");
 for(i=0;i<x;i++)
 {
  fscanf(fp,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x,acc2,name2,&balance2,pin2,branch2,id2,mobile2,&maximumw2,&maximumd2,&withdraw2,&deposit2,&transfer2);
  if(strcmp(A,acc2)==0)
  {
   balance2=balance1;
   withdraw2=withdraw1;
  }
  fprintf(fp1,"%d %s %s %f %s %s %s %s %ld %ld %d %d %d\n",x,acc2,name2,balance2,pin2,branch2,id2,mobile2,maximumw2,maximumd2,withdraw2,deposit2,transfer2);
 }
 fcloseall();
 fp=fopen("bank.txt","w");
 fp1=fopen("bank1.txt","r");
 for(i=0;i<x;i++)
 {
  fscanf(fp1,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x,acc2,name2,&balance2,pin2,branch2,id2,mobile2,&maximumw2,&maximumd2,&withdraw2,&deposit2,&transfer2);
  fprintf(fp,"%d %s %s %f %s %s %s %s %ld %ld %d %d %d\n",x,acc2,name2,balance2,pin2,branch2,id2,mobile2,maximumw2,maximumd2,withdraw2,deposit2,transfer2);
 }
 fcloseall();
 terminationb();
}
void deposit()
{
 FILE *fp,*fp1;
 float cash;
 int i,flag=0,j;
 char option;
 fp=fopen("bank.txt","r");
 dh:
 gotoxy(35,12);
 printf("ACC NO:");
 gotoxy(35,13);
 printf("PIN   :");
 gotoxy(43,12);
 scanf("%s",A);
 gotoxy(43,13);
 for(i=0;i<4;i++)
 {
  P[i]=getch();
  printf("*");
 }
 P[4]='\0';
 getch();
 clrscr();
 for(j=0;j<x;j++)
 {
  fscanf(fp,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x,acc1,name1,&balance1,pin1,branch1,id1,mobile1,&maximumw1,&maximumd1,&withdraw1,&deposit1,&transfer1);
  if(strcmp(A,acc1)==0)
  {
   if(strcmp(P,pin1)==0)
    flag=1;
   break;
  }
 }
 if(flag)
 {
  begin:
  gotoxy(29,13);
  printf("Enter the amount: ");
  scanf("%f",&cash);
  clrscr();
  balance1+=cash;
  deposit1++;
  time(&t);
  for(i=4;i>0;i--)
   s[j].amount[i]=s[j].amount[i-1];
  s[j].amount[0]=cash;
  for(i=4;i>0;i--)
   strcpy(s[j].transaction[i],s[j].transaction[i-1]);
  strcpy(s[j].transaction[0],"Deposit");
  for(i=4;i>0;i--)
   strcpy(s[j].time[i],s[j].time[i-1]);
  strcpy(s[j].time[0],ctime(&t));
  bc:
  gotoxy(22,10);
  printf("Available Balance: %lf",balance1);
  gotoxy(26,13);
  printf("As a part of Green Revolution");
  gotoxy(26,15);
  printf("We suggest not to take reciept");
  gotoxy(19,17);
  printf("Even if you need a reciept then press (Y/N)");
  gotoxy(40,19);
  fflush(stdin);
  scanf("%c",&option);
  clrscr();
  if(option=='Y')
  {
   gotoxy(5,3);
   for(i=0;i<70;i++)
    printf("_");
   gotoxy(4,4);
   for(i=0;i<15;i++)
   {
    printf("|");
    gotoxy(4,5+i);
   }
   gotoxy(75,4);
   for(i=0;i<15;i++)
   {
    printf("|");
    gotoxy(75,5+i);
   }
   gotoxy(34,5);
   printf("VNRVJIET Bank");
   time(&t);
   gotoxy(7,7);
   printf("DAY MON DT   TIME   YEAR");
   gotoxy(7,8);
   printf("%s",ctime(&t));
   gotoxy(29,10);
   printf("Account NO : XXXXXXXX%c%c%c%c",acc1[8],acc1[9],acc1[10],acc1[11]);
   gotoxy(33,12);
   printf("Cash Deposition");
   gotoxy(7,14);
   printf("Deposited Amount  :");
   gotoxy(65,14);
   printf("%8.2f",cash);
   gotoxy(7,16);
   printf("Available balance :");
   gotoxy(65,16);
   printf("%8.2f",balance1);
   gotoxy(5,18);
   for(i=0;i<70;i++)
    printf("_");
   gotoxy(29,20);
   printf("Please take your reciept");
   getch();
   clrscr();
  }
  else if(option=='N');
  else
  {
   gotoxy(34,13);
   printf("Invalid input");
   goto bc;
  }
 }
 else
 {
  gotoxy(26,13);
  printf("Details entered are incorrect");
  delay(2000);
  clrscr();
  ox:
  gotoxy(27,12);
  printf("Do you want to continue(Y/N)");
  gotoxy(40,14);
  fflush(stdin);
  scanf("%c",&option);
  clrscr();
  if(option=='Y')
   goto dh;
  else if(option=='N')
   terminationb();
  else
  {
   gotoxy(32,13);
   printf("Invalid Option");
   delay(2000);
   clrscr() ;
   goto ox;
  }
 }
 fcloseall();
 fp=fopen("bank.txt","r");
 fp1=fopen("bank1.txt","w");
 for(i=0;i<x;i++)
 {
  fscanf(fp,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x1,acc2,name2,&balance2,pin2,branch2,id2,mobile2,&maximumw2,&maximumd2,&withdraw2,&deposit2,&transfer2);
  if(strcmp(A,acc2)==0)
  {
   balance2=balance1;
   deposit2=deposit1;
  }
  fprintf(fp1,"%d %s %s %f %s %s %s %s %ld %ld %d %d %d\n",x1,acc2,name2,balance2,pin2,branch2,id2,mobile2,maximumw2,maximumd2,withdraw2,deposit2,transfer2);
 }
 fcloseall();
 fp=fopen("bank.txt","w");
 fp1=fopen("bank1.txt","r");
 for(i=0;i<x;i++)
 {
  fscanf(fp1,"%d%s%s%f%s%s%s%s%ld%ld%d%d%d",&x,acc2,name2,&balance2,pin2,branch2,id2,mobile2,&maximumw2,&maximumd2,&withdraw2,&deposit2,&transfer2);
  fprintf(fp,"%d %s %s %f %s %s %s %s %ld %ld %d %d %d\n",x,acc2,name2,balance2,pin2,branch2,id2,mobile2,maximumw2,maximumd2,withdraw2,deposit2,transfer2);
 }
 fcloseall();
 terminationb();
}
void terminationb()
{
 char option;
 clrscr();
 gotoxy(25,12);
 printf("Thank you for choosing our Bank");
 gotoxy(32,14);
 printf("Please visit again");
 fflush(stdin);
 option=getch();
 clrscr();
 if(option=='y')
 {
  gotoxy(30,13);
  printf("Thank YOU \"BABY ma'am\"");
  getch();
 }
 else
  main();
}