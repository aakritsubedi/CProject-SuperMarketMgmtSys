#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void banner();
void login();
void signup();
void menu();
void bio();
void billp();
void contact();
void add();
void modify();
void dpl();
void search();
void emp();
void trye();

struct bio
{
	char username[30];
	char biography[100];

};
struct signup
{
	char fname[30];
	char lname[30];
	char usename[30];
	char password[30];
	char address[30];
	char proffession[30];
	long int landline;
	int code;
	char account_type[10];
};
struct bal
{
	int amt;
	int pin;
};
	struct adpr
{
	char pname[30];
	char pcompany[30];
	float pwt;
	float pprice;
	int pcode;
	char pedate[20];
	char pmdate[20];
	int pmyear;
	int peyear;
	int pmday;
	int peday;
};
char fname[30];
char lname[30];
char username[30];
int ctr;
int main()
{
int a;
banner();
printf("\n \n \n ");
printf ("\t \t \t\t1.Login \n \n");
printf ("\t \t \t\t2.Create account\n\n ");
printf ("\t \t \t\t3.Exit \n\n  ");
printf("------------------------------------------------------------------------------");
sleep(1);
printf("\n\n \t \t  What do you want to do? ");
scanf("%d",&a);
if (a>3)
{
	printf ("\t \t \t\tWrong Input \n \n");
	printf ("\t \t \t\tTry again!!\n \n");
	sleep(2);
	main();
}
switch(a)
{
case 1:
login();
break;
case 2:
signup();
break;
case 3:
exit(1);
break;
} 
return 0;
}

void banner()/*to display banner*/
{
system("cls");
printf("\n\n\n");
printf("\t \t \t \t   AakritSubedi SUPER MARKET\n");
printf("\t \t \t \t    KATHAMANDU,NEPAL \n");
printf("\t \t \t \t      VAT No.000000\n");
printf("\t \t \t \t  www.aakritsubedi.com.np \n");
printf("--------------------------------------------------------------------------------");
time_t t;
time(&t);
printf("\t\t\t\t      DATE & TIME : %s \n" ,ctime(&t));
printf("--------------------------------------------------------------------------------");
	printf("\n \n \t\t\t\t\t\t\tWelcome %s %s\n ",fname,lname);




}/*end of banner()*/

void login()
{
	char uname[30],pass[30];
	int code,flag=1;
	char ch;
    char o[35];
	banner();
	
	struct signup b;
	FILE *ft;
	ft=fopen("user.txt","rb");
	
	if (ft==NULL)
	{
		puts("Cannot open the file-user.txt");
		exit(1);
	}
a:
printf("\n \n \t \t \t \t \t   Login Menu\n");
printf("\t \t \t \t \t  ------------");
printf("\n\n\n\t\t\t\t\t Enter username ");
scanf("%s",uname);
printf("\n\n\t\t\t\t\t Enter password ");
scanf("%s",pass);
printf("\n\n\t\t\t\t\t Enter Login Code ");
scanf("%d",&code);

while(fread(&b,sizeof(b),1,ft)==1)
{
	
if (strcmp(b.usename,uname)==0 && strcmp(b.password,pass)==0)
{
	
	/*if (code==123)
	{*/
		strcpy(fname,b.fname);
		strcpy(lname,b.lname);
		strcpy(username,b.usename);
		flag=0;
	/*}*/
	if(strcmp(b.account_type,"Admin")==0)
	{
		printf("\n\n\t\t>>You are trying to signup via Admin account.\n ");
		 	printf("\n\n\t\t\t>>>Please enter developer password.");
		 	fflush(stdin);
		 	gets(o);
		 	fflush(stdin);
		 	if (strcmp(o,"change the world")==0)
		 	{
		 	printf("\n\n\t\tDeveloper password correct.\n ");
		 	sleep(1);
			
			 }
			 else
			 {
			 	printf("\n\n\t\tDeveloper password incorrect.\n ");
			 	sleep(1);
			 	main();
			 	break;
			 }
	}
	

}/*end of if*/	
}/*end of while for signup()*/	


if (flag==1)
		{
			printf("\n \n \t Username: %s and password: %s & Code: %d invalid",uname,pass,code);
			printf("\n \n \t \t Do you want to try again? (Y||N)");
			scanf("%s",&ch);
				if (ch=='Y' || ch =='y')
					{
						printf("\n \n \t \t \t Try again");
						goto a;
					}
				else
					{
						main();
					}		
		}/*end of if*/
else
{

			printf("\t\t\t\t\t \tlogging in .");
			sleep(1);
			printf(".");
			sleep(1);
			printf(".\n");
			sleep(1);
			menu();
			exit(1);	
		}		
		fclose(ft);
}

void signup()
{
char str[100];
	char repass[30],usename[30];
	char p[30],ch;
	int ab=1;
	char o[35];
	struct signup c;
	struct signup b;
	struct bio z;
	FILE *ft;
	FILE *fp;
	FILE *fz;
	ft=fopen("user.txt","ab");
	fz=fopen("user.txt","rb");
	fp=fopen("bio.txt","ab");
	if (ft==NULL)
	{
		puts("Cannot open the file-user.txt");
		exit(1);
	}
	banner();
printf("\n\n\n\n\t\t\t\tSIGN-UP Menu\n");
printf("\t\t\t\t-------------");		
printf("\n\n\t\t\t >>Enter company password ");
scanf("%s",p);
	if(strcmp(p,"letusc")==0 ||strcmp(p,"LETUSC")==0)
	{
		printf("\n\t\t\t\tEnter First Name: ");
		scanf("%s",b.fname);
		printf("\n\n\t\t\t\tEnter Last Name: ");
		scanf("%s",b.lname);
		printf("\n\n\t\t\t\tEnter Username: ");
		scanf("%s",usename);
		printf("\n\n\t\t\t\tEnter Password: ");
		scanf("%s",b.password);
		printf("\n\n\t\t\t\tRe-Enter Password: ");
		scanf("%s",repass);
		printf("\n\n\t\t\t\tEnter Address: ");
		scanf("%s",&b.address);
		printf("\n\n\t\t\t\tEnter Login Code: ");
		scanf("%d",&b.code);
		printf("\n\n\t\t\t\tProffession: ");
		fflush(stdin);
		gets(b.proffession);
		fflush(stdin);
		printf("\n\n\t\t\t\tEnter Mobile no: ");
		scanf("%ld",&b.landline);
		printf("\n\n\t\t\t\tAccount type:(Admin/User)");
		scanf("%s",b.account_type);
		if(strcmp(b.account_type,"Admin")==0 || strcmp(b.account_type,"admin")==0)
		{
			printf("\n\n\t\t>>You are trying to signup via Admin account.\n ");
		 	printf("\n\n\t\t>>>Please enter developer password.");
		 	fflush(stdin);
		 	gets(o);
		 	fflush(stdin);
		 	if (strcmp(o,"change the world")==0)
		 	{
		 	strcpy(b.account_type,"Admin");
		 	printf("\n\n\t\t\t\t>>Account type:(Admin/User) %s",b.account_type);
		 	printf("\n\n\t\t--Developer password correct.\n ");
		 	sleep(1);
			}
			 else
			 {
			 	
			 	strcpy(b.account_type,"User");
			 	printf("\n\n\t\t\t\tAccount type:(Admin/User) %s",b.account_type);
			 	printf("\n\n\t\t--Developer password incorrect.\n ");
			 	
			 	sleep(1);
			 	
			 
			 }
		}
		
		printf("\n\n\t\t\t\tEnter somethings about you: ");
		fflush(stdin);
		gets(z.biography);
		fflush(stdin); 
		
		strcpy(z.username,b.fname);
				
		fwrite(&z,sizeof(z),1,fp);
		//printf("\n\n\t\t\t\tEnter DOB(Day/Months/Year)");
		//scanf("%d %s %d",&b.day,b.month,&b.year);
		while(fread(&c,sizeof(c),1,fz)==1)
		{
			if(strcmp(usename,c.usename)==0)
			{
				ab=0;
			}
		}
}
	else
		{
		printf("\n \t Company password didn't match");
		printf("\n\n\t You have no rights to create account");
		sleep(2);
		main();
		}
		if(ab!=0 && strcmp(repass,b.password)==0)
			{
			strcpy(b.usename,usename);
			fwrite(&b,sizeof(b),1,ft);
			printf("\n\t\t\t Creating account .");
			sleep(1);
			printf(".");
			sleep(1);
			printf(".\n");
			sleep(1);
			printf("\n\n \t \t Account created successfully.");
			printf("\n\n \t \t Welcome %s %s ji ",b.fname,b.lname);
			sleep(1);
			system("cls");
			strcpy(fname,b.fname);
			strcpy(lname,b.lname);
			strcpy(username,b.usename);
			menu();
			
			}
			if(ab==0 || strcmp(repass,b.password)!=0)
			{
				if (ab==0)
				{
					printf("\n \n \t \t Username: %s already exits.",b.usename);
					sleep(1);
					printf("\n \n \t \t Re-Enter username again.\n");
					printf("\t \t-----------------------");
					printf("\n\t\t\t\tFirst Name: %s ",b.fname);
		printf("\n\n\t\t\t\tLast Name: %s ",b.lname);
		printf("\n\n\t\t\t\tRe-Enter Username: ");
		scanf("%s",b.usename);
		printf("\n\n\t\t\t\t Password: %s",b.password);
		printf("\n\n\t\t\t\t Address: %s ",b.address);
		printf("\n\n\t\t\t\t Login Code: %d ",b.code);
		printf("\n\n\t\t\t\t Work place: %s ",b.proffession);
		printf("\n\n\t\t\t\t Mobile no: %ld ",b.landline);
		printf("\n\n\t\t\t\t About you: %s ",z.biography);
		//printf("\n\n\t\t\t\tEnter DOB: ",b.day,b.month,b.year);
		fwrite(&b,sizeof(b),1,ft);
		printf("\n\t\t\t Creating account .");
			sleep(1);
			printf(".");
			sleep(1);
			printf(".\n");
			sleep(1);
			printf("\n\n \t \t Account created successfully.");
			printf("\n\n \t \t Welcome %s %s ji !! ",b.fname,b.lname);
			sleep(1);
			system("cls");
			strcpy(fname,b.fname);
			strcpy(lname,b.lname);
			strcpy(username,b.usename);
			menu();
			
				}
				else
				{
					printf("\n \n \t \t Password didn't match.");
					sleep(1);
		printf("\n\t\t\t\t First Name: %s ",b.fname);
		printf("\n\n\t\t\t\t Last Name: %s ",b.lname);
		printf("\n\n\t\t\t\t Username: %s ",b.usename);
		printf("\n\n\t\t\t\tEnter Password: ");
		scanf("%s",b.password);
		printf("\n\n\t\t\t\t Address: %s ",b.address);
		printf("\n\n\t\t\t\t Login Code: %d ",b.code);
		printf("\n\n\t\t\t\t Work place: %s ",b.proffession);
		printf("\n\n\t\t\t\t Mobile no: %ld ",b.landline);
		printf("\n\n\t\t\t\t About you: %s ",z.biography);
		//printf("\n\n\t\t\t\tEnter DOB: ",b.day,b.month,b.year);
		fwrite(&b,sizeof(b),1,ft);
		printf("\n\t\t\t Creating account .");
			sleep(1);
			printf(".");
			sleep(1);
			printf(".\n");
			sleep(1);
			printf("\n\n \t \t Account created successfully.");
			printf("\n\n \t \t Welcome %s %s ji ",b.fname,b.lname);
			sleep(1);
			system("cls");
			strcpy(fname,b.fname);
			strcpy(lname,b.lname);
			strcpy(username,b.usename);
				}
			
			}
			else
			{
			main();
			}
			
		

fclose(ft);		
}
void menu()
{
	system("cls");
	int a;
	
	banner();
printf("\n");
printf ("\t \t \t \t 1.BILL PROCESS\n \n ");
printf ("\t \t \t \t 2.ADD PRODUCTS \n \n  ");
printf ("\t \t \t \t 3.CHECK STOCKS  \n \n  ");
printf ("\t \t \t \t 4.SEARCH PRODUCTS  \n\n   ");
printf ("\t \t \t \t 5.Delete PRODUCTS\n \n  ");
printf ("\t \t \t \t 6.EMPLOYEE RECORDS  \n\n   ");
printf ("\t \t \t \t 7.CONTACT US\n\n   ");
printf ("\t \t \t \t -->Settings\n\n   ");
printf("\t \t \t \t \t 8.Profile\n\n ");
printf("\t \t \t \t \t 9.Change Password\n\n ");
printf ("\t \t \t \t 10.Log out  \n \n  ");
sleep(1);
printf("--------------------------------------------------------------------------------");
printf("\n\n \t \t  What do you want to do ? ");
scanf("%d",&a);
switch (a)	
{
	case 1:
		billp();
		break;
	case 2:
	   add();
	   break;
	case 3:
	   dpl();
	   break; 
	case 4:
		search();
		break; 
	case 5:
	   modify();
	   break;
	case 6:
	 emp();
	 break;   	    	
	case 7:
	    contact();
	    break;
	case 8:
		bio();
		break; 
	case 9:
	    break;	
	case 10:
		
		printf("\n\t\t\t log out processing .");
			sleep(1);
			printf(".");
			sleep(1);
			printf(".\n");
			sleep(1);
		system("cls");
		strcpy(fname," ");
		strcpy(lname," ");
		strcpy(username," ");
	    main();
		break;	   
	
}/*end of switch cases*/

}/*end of menu*/
void billp()
{
	FILE *fp;
	fp=fopen("prodlist.txt","rb");
	system("cls");
	banner();
	int i=0,n,d,ct;
	float subt=0.0;
	float tender=0,dis=0.0,gt=0.0;
	
	struct bill
{
	char pname[30];
	float pprice;
	int code;
	int pqty;
	float ptotal;

};
struct adpr a;
struct bill p[100];
printf("\n \n \t How many product (approx)? ");
scanf("%d",&n);
ct=1;

		for (i=1; i<=n; i++)
	{
a:       

        ct++;
		printf("\n\n \t Serial no. %d ",i);
		printf(" \n\n Product name ");
		scanf("%s",&p[i].pname);
		printf(" \n\n Product qty  ");
		scanf("%d",&p[i].pqty);
		while (fread(&a,sizeof(a),1,fp)==1)
		{
			if (strcmp(a.pname,p[i].pname)==0)
			{
		printf(" \n\n Product code %d ",a.pcode);
		
		printf(" \n\n Product rate %f",a.pprice);
		//p[i].ptotal=0;
		p[i].ptotal = ((p[i].pqty) * (p[i].pprice));
				printf("\nProduct no %d Total = %f",i,p[i].ptotal);
			break;
			}
			
		}
		
		
		}
		printf("\n\n\nDo you want to add more products?");
	char ch;
	scanf("%s",&ch);
	if (ch=='Y'|| ch=='y')
	{
		goto a;
	}
	else 
	{
printf("\n\n\n");
printf("\t \t \t   BHAT-BHATENI SUPER MARKET\n");
printf("\t \t \t     KATHAMANDU,NEPAL \n");
printf("\t \t \t       VAT No.000000\n");
printf("\t \t \t   www.bhatbhateni.com \n");
	printf("\n      ------------------------------------------------------------");
	printf("\n \n       Pcode \t Name \t Rate \t        QTY \t     Total ");
	printf("\n      ------------------------------------------------------------\n");
			for (i=1;i<ct;i++)
		{
	printf("\n\n        %d\b\b\b\t%s\t%f\t%d\t%f",&p[i].pname,p[i].pname,p[i].pprice,p[i].pqty,p[i].ptotal);
		printf("\n     ------------------------------------------------------------\n");
		subt=subt+p[i].ptotal;
		}
		
}
	int x=0;
		 if  (subt>=100000)  
		{
		   	
		   	x=25;
		   	
		}
	     else if (subt>=25000.0)
	       {
		    x=15;
	       }
	    else if (subt>=12500.0 && subt<=24999)
		{
			x=12;
				
			
		}
		else if ( subt>=7500 && subt<=12499)
		{
			x=10;
		}
		
		else if (subt>=5001 && subt<=7499)
		{
			x=5;
			
		}
		else if (subt>=2500 && subt<=5000)
		{
			x=3;
			
		}
		else if  (subt>=1250 && subt<=2499)	
		{
			x=2;
		
			
		}
		else if  (subt>=600 && subt<=1249)  
		{
		   	
		   	dis=25;
		   	goto p;
		}
		
		else
		{
			
			dis=0;
			goto p;
		}
		dis=subt*x/100;			
p:
printf("\n                                 -----------------------------\n");
	printf("\n\n \t \t\t \t Net amount:%f",subt);
	gt=subt-dis;
	printf("\n\n\t\t\t\t Discount(%dper):%f",x,dis);
	printf("\n\n \t\t\t \t Total:%f",gt);
	printf("\n                                 -----------------------------\n");
	printf("\n\t\t\t \tTender:");
	scanf("%f",&tender);
	printf("\n\t\t\t \tChange:%f",tender-gt);
	printf("\n      ------------------------------------------------------------\n");
	printf("\n             WELCOME TO GREATE SHOPPING EXPERIENCE\n");
	printf("\n              EXCHANGE IN 10 DAYS WITH INVOICE\n");
	printf("\n               BHAT-BHATENI (Tel.01-4016130)\n");
	printf("\n      ------------------------------------------------------------\n");
	printf("\n       Cashier: %s.\n ",username);
	time_t t;
time(&t);
printf("\t\t\t DATE & TIME:%s" ,ctime(&t));
	printf("\n      ------------------------------------------------------------");
	sleep(3);
	printf("\n \t \t Press any key to continue \n");
getch();
menu();
	
}
void contact()
{
	system("cls");
	printf("\n\n\n");
printf("\t \t \t    AK SOFTWARE Pvt Ltd.\n");
printf("\t \t \t    _changing  the world\n");
printf("\t \t \t     KATHAMANDU,NEPAL \n");
printf("\t \t \t    Ph no. 01-2070021 \n");
printf("\t \t \t      VAT No.000000\n");
printf("\t \t \t    www.aksoftware.com \n");
printf("\n      ------------------------------------------------------------\n");
	printf("\n \n");
printf("\t \t \t       1.Er.Aakrit Subedi\n");
printf("\t \t \t   Chief Executive Officer. \n");
printf("\t \t \t    Ph no.  +9779808858237\n");
printf("\t \t \t              +97712070021  \n");
printf("\t \t \t    www.aakritsubedi.com\n");
printf("\t \t \t    email:aakritsub@aksoft.com\n");
printf("\n      		    ----------------------------------------                     \n");
printf("\t \t \t       2.Er.Aakrit Subedi\n");
printf("\t \t \t          Software engneer. \n");
printf("\t \t \t   	 Ph no.+9779808858237\n");
printf("\t \t \t    email:aakritsub@aksoft.com\n");
printf("\n      		    ----------------------------------------                     \n");
printf("\t \t \t       3.Er.Piyush Subedi\n");
printf("\t \t \t          Software Engneer. \n");
printf("\t \t \t    Ph no.+9779843936126\n");
printf("\t \t \t    email:pyushsub@aksoft.com\n");
printf("\n      	   	    ----------------------------------------                     \n");
printf("\t \t \t       4.Mr.Aakrit Subedi\n");
printf("\t \t \t          Sr. Finance officer \n");
printf("\t \t \t    Ph no.+9779841243887\n");
printf("\t \t \t    email:aakritsub@aksoft.com\n");
printf("\n      	   	    ----------------------------------------                     \n");
printf("\t \t \t       4.Er.Aakrit Subedi\n");
printf("\t \t \t          Software Assitance \n");
printf("\t \t \t    Ph no.+9779841243887\n");
printf("\t \t \t    email:aakritsub@aksoft.com\n");
printf("\n      	   	    ----------------------------------------                     \n");
printf("\n \n \n");
printf("------------------------------------------------------------------------------\n");	 
printf("\n \t \t \t \t \t \t \t     AK SOFTWARE");
printf("\n \t \t \t \t \t \t  \t  changing the world");
printf("\n------------------------------------------------------------------------------\n");
printf("\n \t \t Press any key to continue \n");
getch();
menu();
}

void add()
{
	struct adpr m;
	int n;
	char chr;
	banner();
FILE *fp;
fp=fopen("prodlist.txt","a+b");

printf ("\n \n \t how many product do you want to add ?");
scanf ("%d",&n);
int i;
printf(" \n \t \t Enter details of Products: ");
	for (i=0; i<n; i++)
	{
a:
        ctr=ctr+1;
		printf("\n \t Product no. %d ", i + 1);
		printf(" \n Product name ");
		scanf("%s",&m.pname);
		printf(" \n Product manufacturing company ");
		scanf("%s", &m.pcompany);
		printf(" \n Product weight(kg)  ");
		scanf("%f", &m.pwt);
		printf(" \n Product price(Rs) ");
		scanf("%f", &m.pprice);
		printf(" \n Product code ");
		scanf("%d",&m.pcode);
		printf(" \n Product Date of manufacture(Day,Month,Year) ");
		scanf(" %d %s %d",&m.pmday,&m.pmdate,&m.pmyear);
		printf(" \n Product Date of expiry(Day,Month,Year) ");
		scanf("%d %s  %d",&m.peday, &m.pedate,&m.peyear);
		fwrite(&m,sizeof(m),1,fp);
	
		
      }
      
    
		
		
printf(" \n Do you want to add a products?(Y/N)");

scanf("%s",&chr);
if (chr=='y' || chr =='Y')
{
goto a;
}
else 
{
	printf("Adding data to database. . ");
		sleep(1);
		printf(" .");
		sleep(1);
		printf ("  .");
		sleep(1);
		printf("\n \t Data Added completely ");
		fclose(fp);
	menu();
}
	
}/*end of add*/	
void cpro()
{
	
}/*end of cpro*/
void dpl()
{
	char a;
	banner();
int k=0;
FILE *fp;
	fp= fopen("prodlist.txt","r");
		if (fp==NULL)
	{
		puts("Cannot open the file");
		exit(1);
	}
struct adpr m;

printf("\n \t \t \t 		PRODUCT LISTS");
printf("\n \t \t \t 		-------------\n");


while(fread(&m,sizeof(m),1,fp)==1)
{	
k=k+1; 
printf("\n\t \t \t   %d.Name: %s\n",k,m.pname);
printf("\t \t \t       %s Manufacturing company: %s \n",m.pname,m.pcompany);
printf("\t \t \t       %s Weight(kg): %f \n",m.pname,m.pwt);
printf("\t \t \t       %s Price(Rs) %f  \n",m.pname,m.pprice);
printf("\t \t \t       %s Code  %d  \n",m.pname,m.pcode);
printf("\t \t \t       -->Remarks\n");
printf("\t \t \t        *Date of Manufacture:%d %s %d\n",m.pmday,m.pmdate,m.pmyear);
printf("\t \t \t        *Date of Expiry:%d %s %d\n",m.peday,m.pedate,m.peyear);
printf("\n      		    --------------------------------------------------");

}
if (k==0)
{
	printf("\n \t \tNo product to display \n");
	printf("\n \t \tDo you want to add product\n");
	a=getche();
	if(a=='y'|| a=='Y')
	{
		printf("\t \t \t \t Loading to add menu. . ");
		sleep(1);
		add();
	}
	
}
printf("\n \t \tTotal number of product displyed %d\n",k);
printf("\n \n \t PRESS ANY KEY TO CONTINUE");
getch();
fclose(fp);
menu();	
}
void search()
{

char name[30],ch;
int code,b=0;
struct adpr m;
banner();

	FILE *fp;
	fp= fopen("prodlist.txt","r");
		if (fp==NULL)
	{
		puts("Cannot open the file");
		exit(1);
	}
	
	top:
		fflush(stdin);
printf("\n \n \t Enter Name of Product that you want to search ");
scanf("%s",&name);
//printf("\n \n \t Enter Code of Product that you want to search");
//scanf("%d",&code);
rewind(fp);
	while(fread(&m,sizeof(m),1,fp)==1)
	{
	
	if (strcmp(m.pname,name)==0)	
	{
	
b=1;
printf("\n\t \t \t   	 Name: %s\n",m.pname);
printf("\t \t \t       %s Code  %d  \n",m.pname,m.pcode);
printf("\t \t \t       %s Manufacturing company: %s \n",m.pname,m.pcompany);
printf("\t \t \t       %s Weight(kg): %f \n",m.pname,m.pwt);
printf("\t \t \t       %s Price(Rs) %f  \n",m.pname,m.pprice);
printf("\t \t \t       -->Remarks\n");
printf("\t \t \t        *Date of Manufacture:%d %s %d\n",m.pmday,m.pmdate,m.pmyear);
printf("\t \t \t        *Date of Expiry:%d %s %d\n",m.peday,m.pedate,m.peyear);
printf("\n      		    --------------------------------------------------");
}
}
if (b!=1)
{
	printf("\n \t \t \t No product is named %s",name);
	printf("\n \t \t \t \t  TRY AGAIN!!");
	sleep(1);
}
printf("\n\n \n \t \tDo you want to search another product ");
scanf("%s",&ch);
if (ch=='Y'||ch=='y')
{
	goto top;
}
else
{
printf("\n \n \t PRESS ANY KEY TO CONTINUE");
getch();
menu();	
}
fclose(fp);
}
void emp()
{
		int a;
		char ch;
		struct emp 
		{
			char fname[30];
			char lname[30];
			char pos[30];
			long int  idno;
			char add[30];
			long int cno;
			char dob1[10];
			int year;
		}data;
		FILE *ft,*fp;
		ft=fopen("emp.txt","rb");
		fp=fopen("emp.txt","ab");
	banner();
   		
printf("\n \n \n ");

printf ("\t \t \t\t1.Attendance \n \n");
printf ("\t \t \t\t2.Empolyee Record\n\n ");
printf ("\t \t \t\t3.Search Employee\n\n  ");
printf ("\t \t \t\t4.Add Empolyee\n\n  ");

printf("------------------------------------------------------------------------------");
sleep(1);
printf("\n\n \t \t  What do you want to do ? ");
scanf("%d",&a);
switch(a)/*allow user for different cases*/
{

	case 1:
		printf("\n Welcome to office.. Have a good day :P");
		printf("\n \n \t \t PRESS ANY KEY TO CONTINUE.");
		sleep(1);
		emp();
		break;
	case 2:
		banner();
		printf ("\t \t \t\tEmployee Record \n \n");
		while(fread(&data,sizeof(data),1,ft)==1)
		{
printf("\n \n");
printf("\t \t \t       Name: %s %s\n",data.fname,data.lname);
printf("\t \t \t          %s \n",data.pos);
printf("\t \t \t    Ph no.: %ld \n",data.cno);
printf("\t \t \t    Address: %s \n",data.add);
printf("\t \t \t    Id no.: %ld \n",data.idno);
printf("\t \t \t    Company joined in %d %s:\n",data.dob1,data.year);
printf("\t \t \t    email:%s@aksoft.com\n",data.fname);
printf("\n      		    ----------------------------------------                     \n");
		}
			printf("\n \n \t \t PRESS ANY KEY TO CONTINUE.");
		sleep(1);
		emp();
		break;
		case 4:
			banner();
printf(" \n \t \t Enter details of Employee: ");
	do
	{
		
		printf("\n \t First name ");
      	scanf("%s",&data.fname);
		printf("\n \t Last name ");
		scanf("%s",&data.lname);
		printf("\n \tId no. ");
		scanf("%ld", &data.idno);
		printf("\n \t Contact No.  ");
		scanf("%ld", &data.cno);
		printf("\n \t Company joined in(Months Year) ");
		scanf("%d",&data.dob1);
		printf("\n \t Email: %s@aksoft.com ",data.fname);
		printf("\n \t Address: ");
		scanf("%s",&data.add);
		printf("\n \t Position: ");
		scanf("%s",&data.pos);
		fwrite(&data,sizeof(data),1,fp);
	printf("\n Do you want to add another record?(Y/N) ");
	scanf("%s",&ch);
	}while(ch=='Y' || ch =='y');
      		
		printf("\n Adding data to database. . ");
		sleep(1);
		printf(" .");
		sleep(1);
		printf ("  .");
		sleep(1);
		printf("\n \t Data Added completely ");
			printf("\n \n \t \t PRESS ANY KEY TO CONTINUE.");
		sleep(1);
		
		emp();
		
	}
	fclose(ft);
	fclose(fp);
	//break;

 }
void modify()
{
	
	char name[30],ch,a;
	long int recsize;
	struct adpr m;
	banner();
	
	FILE *fp;
	FILE *ft;
	top:
	ft=fopen("temp.txt","wb");
	fp= fopen("prodlist.txt","r+b");
		if (fp==NULL)
	{
		puts("Cannot open the file");
		exit(1);
	}

	
	rewind(fp);
printf("\n \n \t Enter Name of Product that you want to Delete ");
scanf("%s",&name);

rewind(fp);
while(fread(&m,sizeof(m),1,fp)==1)
{
	
if (strcmp(name,m.pname)!=0)
{
	
	
		fwrite(&m,sizeof(m),1,ft);
		
	}
}
if (strcmp(name,m.pname)!=0)
{
	printf("\n\n \t No product is named %s ",name);
	printf("\n \t Do you want to  Try again!!");
	a=getch();
	if(a=='y' || a=='Y')
	{
	
	goto top;
}

}

fclose(fp);
fclose(ft);
remove("prodlist.txt");
rename("temp.txt","prodlist.txt");
printf("\n\t\t\t Deleting data .");
			sleep(1);
			printf(".");
			sleep(1);
			printf(".\n");
			sleep(1);
printf("\n\t\t\t Data deleted succussfully.");			
printf("\n\n \n \t \tDo you want to Delete another product ");
scanf("%s",&ch);
if (ch=='Y'||ch=='y')
{
	goto top;
}
else
{
printf("\n \n \t PRESS ANY KEY TO CONTINUE");
getch();
menu();	
}

}
		void bio()
{
	int s=1;
	int i=1;
	FILE *fp;
	fp=fopen("user.txt","rb");
	FILE *fz;
	fz=fopen("bio.txt","rb");
	struct signup b;
	struct bio z;
			banner();
			fflush(stdin);
		while (fread(&b,sizeof(b),1,fp)==1)
		{

			if (strcmp(b.fname,fname)==0 && strcmp(b.lname,lname)==0)
			{
				if (strcmp(b.usename,username)==0)
					{
						i=0;
					
						break;
					}
			}
		}
if(i==0)
{
		printf("\n\t\t\t\t   Name: %s %s",b.fname,b.lname);
		printf("\n\n\t\t\t\t Username: %s ",b.usename);
		printf("\n\n\t\t\t\t Password: ********(hidden)");
		printf("\n\n\t\t\t\t Address: %s ",b.address);
		printf("\n\n\t\t\t\t Login Code: %d ",b.code);
		printf("\n\n\t\t\t\t Work place: %s ",b.proffession);
		printf("\n\n\t\t\t\t Mobile no: %ld ",b.landline);
		while(fread(&z,sizeof(z),1,fz)==1)
		{
			if(strcmp(z.username,b.fname)==0)
			{
				s=0;
				break;
			}
	}
		if (s==0)
		{
		printf("\n \n \t \t \t\tAbout me:");
		printf("\n \t\t \t \t \t %s",z.biography);
		printf("\n\n--------------------------------------------------------------------------------\n");
		getch();
		menu();
		}


}
}
