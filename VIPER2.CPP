#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>

#define clrbuf cin.get(buffer)    //to clear the input buffer

char buffer;  //this variable clears the buffer

//prototypes of functions
void acceptpass(char *);

//defining some constants like size of password,username,account


#define pwsize 30
#define acsize 30
#define unsize 30
#define sizerec 90

void enter();
void see();
void seeun();
void seeac();
void recmodify();
void delaccount();
void seeusernames();
void seeaccountnames();
void change();
void seenumberofacc();

//end of prototypes

class user
{
  private:
	   char pw[pwsize];
	   char username[unsize];
	   char account[acsize];
	   void genrandompassword();
	   void storepassword();

  public:
	   user()
	   {
		strcpy(pw,"NULL");
		strcpy(username,"NULL");
		strcpy(account,"NULL");
	   }

	   user(char * p)
	   {
		strcpy(pw,p);
		strcpy(username,"NULL");
		strcpy(account,"NULL");
	   }

	   user(char *password, char * uname, char * aname)
	   {
		strcpy(pw,password);
		strcpy(username,uname);
		strcpy(account,aname);

	//	this -> putdata();
	//	delay(1000);
	//	clrscr();

	   }

	   void getdata()
	   {
		clrbuf;
		cout<<"\nEnter the name of the account:";
		cin.getline(account,acsize);
		clrbuf;
		cout<<"\nEnter the username of account:";
		cin.getline(username,unsize);
		cout<<"\n";
		cout<<"\nEnter the password:";
		storepassword();

		cout<<"\nRecord stored";

		return;
	   }

	   void putdata()
	   {
		cout<<"\n\n\nAccount:"<<account;
		cout<<"\nUsername:"<<username;
		cout<<"\nPassword:"<<pw;
		return;
	   }

	   char * getusername()
	   {
		return username;
	   }

	   char * getpassword()
	   {
		return pw;
	   }

	   char * getaccount()
	   {
		return account;
	   }

	   void modify()
	   {
		cout<<"\n\nYou can modify the username,account and password";

		char temp[acsize],temp1[unsize];
		char ch;
		cout<<"\nOld account name:"<<account;
		cout<<"\nPress y to retain and n to change:";
		cin>>ch;

		if(ch=='n')
		{
			clrbuf;
			cout<<"\nEnter the new account name:";
			cin.getline(temp,acsize);

			strcpy(account,temp);

			cout<<"\nAccount name changed\n";
		}

		cout<<"\nOld user name:"<<username;
		cout<<"\nPress y to retain and n to change:";
		cin>>ch;

		if(ch=='n')
		{
			clrbuf;
			cout<<"\nEnter the new username:";
			cin.getline(temp1,unsize);

			strcpy(username,temp);

			cout<<"\nUsername changed\n";
		}


		cout<<"\nOld password:"<<pw;
		cout<<"\nPress y to retain and n to change:";
		cin>>ch;

		if(ch=='n')
		{
			storepassword();
		}

		cout<<"\nRecord modified";
		return;
	}

}p;

/*the following function of the class generates random passwords of
10 charachters length. these passwords have lower and upper case charachters*/

void user::genrandompassword()
{
	randomize();

	for(int j=0;j<10;j++)
	{

		int rand=random(2)+1;

		/*if rand is 1 then a uppercase charachter
		is generated, else a lowercase charachter is
		generated*/

		if(rand==1)

			pw[j]=(char)(random(26)+65);

		if(rand==2)

			pw[j]=(char)(random(26)+97);
	}
	pw[j]='\0';

	return;   //the random password has been generated

}

/*this function asks the user if she wants to enter a password of her own
or she would like VIPER to select a password for her

if he/she asks VIPER to select a password, generate a password randomly
and store it in the variable that has been
passed as parameter */


void user::storepassword()
{
	cout<<"\nYou need to select a password\n";
	delay(1000);
	char ch;

	cout<<"\nPress y to enter your own password \nOr press n so VIPER can";
	cout<<" select a password for you(recommended):";
	cin>>ch;

	if(ch=='y')
	{
		clrbuf;
		cout<<"\nEnter your password:";
		acceptpass(pw);
		return;
	}

	if(ch=='n')
	{
		cout<<"\nGenerating a password for you";
		delay(2000);

		genrandompassword();
		clrscr();

		cout<<"\nFor security reasons,we will display your password";
		cout<<" 5 seconds only \nIt will be safely stored";
		cout<<" by VIPER";
		cout<<"\nPassword:"<<pw;

		delay(5000);
		clrscr();

		cout<<"\nPassword selected and stored";
		cout<<"\nPress a key";
		getch();
		clrscr();

		return;

	}
}


//end of class

//the main() function

char pass[pwsize];
char masterkey[pwsize];

int main()
{
	clrscr();
	char ch;

	/*the screen*/

	cout<<"\n\n\n\nVisual Interface for Password Entry and Retrieval";

	cout<<"\n\nVIPER 2.0";

	cout<<"\n\nWith more space for your usernames, accounts and passwords";

	cout<<"\n\nProgrammed by Siddharth Kannan";

	cout<<"\n\nThis is a free software which runs on any DOS shell";

	cout<<"\n\n\nLoading... Please wait...";

	delay(8000);


	/*the following lines take the master key from the p.dat file
	and store it in a variable for further use in the program*/

	ifstream f;
	f.open("p.dat");
	f.read((char*)&p,sizeof(user));
	strcpy(masterkey,p.getpassword());
	f.close();

	/*master key has been stored in the variable 'masterkey'*/

	clrscr();
	cout<<"\nEnter the master key:";

	acceptpass(pass);

	if(strcmp(pass,masterkey)!=0)
	{
		cout<<"\nBAD PASSWORD!";
		cout<<"\nVIPER has detected unathorized access";
		cout<<"\nGOOD BYE";
		getch();
		return 0;
	}

	cout<<"\nACCESS GRANTED";
	getch();
	clrscr();

	cout<<"\nI am VIPER,your password manager";

	cout<<"\nTaking you to the main interface";
	cout<<"\nPress a key, please";
	getch();
	clrscr();
	int opt;

	while(1)
	{
		clrscr();
		cout<<"\n\t\t\tMENU";
		cout<<"\n\nPress 1 to enter a new account's details";
		cout<<"\n\nPress 2 to see the password of an account";
		cout<<"\n\nPress 3 to see all the usernames stored";
		cout<<"\n\nPress 4 to see all the accounts stored";
		cout<<"\n\nPress 5 to change the password of an account";
		cout<<"\n\nPress 6 to delete an account";
		cout<<"\n\nPress 7 to change the master key";
		cout<<"\n\nPress 8 to see the number of accounts stored";
		cout<<"\n\nPress 9 to exit";
		cout<<"\n\nEnter your choice:";
		cin>>opt;

		clrscr();

		switch(opt)
		{
		  case 1: enter();
			  break;

		  case 2: see();
			  break;

		  case 3: seeusernames();
			  break;

		  case 4: seeaccountnames();
			  break;

		  case 5: recmodify();
			  break;

		  case 6: delaccount();
			  break;

		  case 7: change();
			  break;

		  case 8: seenumberofacc();
			  break;

		  case 9: cout<<"\nThank you for using this program";
			  getch();
			  clrscr();
			  cout<<"\nTrust me, I am VIPER";
			  getch();
			  return 0;

		  default:
			  cout<<"\nWrong input";
			  cout<<"\nTaking you back to the menu";
			  getch();
			  continue;
		}

	}
 /*
	cout<<"\nThank you for using this program";
	getch();
	clrscr();
	cout<<"\nTrust me, I am VIPER";
	getch();
	return 0; */

}

//end of main()


/*the following function serves to keep the password hidden so that the
user alone knows what he/she is entering*/

void acceptpass(char * pw)
{

		char ch;

		for(int i=0;i<pwsize;i++)
		{
			 ch=getch();

			 if(ch==13)  //13 is the ascii code of return key
			 break;

			 pw[i]=ch;

			 cout<<"*";
		}

		pw[i]='\0';

		/*the last line is required as without the '\0'
		charachter other functions (such as cout) will not know till
		where they need to print the string   */

		return;
}


//functions used in main()

void enter()
{
	cout<<"\nEnter the master key to proceed:";
	acceptpass(pass);

	if(strcmp(pass,masterkey)!=0)
	{
		clrscr();
		cout<<"\nSorry, We are unable to proceed with your request";
		delay(1000);
		cout<<"\nVIPER has detected unauthorized access";
		delay(1000);
		cout<<"\nTerminating and returning to Windows";
		cout<<"\nPress a key";
		getch();
		exit(0);
	}

	cout<<"\nPassword accepted, Continuing with processing\n";

	p.getdata();

	ofstream f;
	f.open("pw.dat",ios::app);
	f.write((char*)&p,sizeof(user));
	long pos=f.tellp();
	f.close();


	cout<<"\nThe new record was written to the file by VIPER";
	cout<<"\n"<<pos/sizerec<<" records are there in the file";
	cout<<"\nNow we will take you back to the main interface";
	cout<<"\nPress a key";
	getch();
	clrscr();
	return;
}

void see()
{
	char ch;
	clrbuf;

	cout<<"\nEnter the master key to proceed:";
	acceptpass(pass);

	if(strcmp(pass,masterkey)!=0)
	{
		clrscr();
		cout<<"\nSorry, We are unable to proceed with your request";
		cout<<"\nVIPER has detected unauthorized access";
		cout<<"\nTerminating and returning to Windows";
		cout<<"\nPress a key";
		getch();
		exit(0);
	}

	cout<<"\nPassword accepted, Continuing with processing\n";

	cout<<"\nTo enter the username of an account, press u";
	cout<<"\nTo enter the name of an account, press a\n";
	cin>>ch;

	if(ch=='u') seeun();

	if(ch=='a') seeac();

	return;
}

//functions used inside see()

void seeun()
{
	clrbuf;
	char un[unsize];
	cout<<"\nEnter the username of the account:";
	cin.getline(un,unsize);

	ifstream f;

	f.open("pw.dat");

	f.seekg(0,ios::beg);
	int flag=0;

	while(f.read((char*)&p,sizeof(user)))
	{
		if(strcmp(p.getusername(),un)==0)
		{
			p.putdata();
			flag=1;
		}
	}

	f.close();

	if(flag==0)

	cout<<"\nNo match found";
	getch();

	return;
}

void seeac()
{
	clrbuf;
	char ac[acsize];
	cout<<"\nEnter the name of the account:";
	cin.getline(ac,acsize);

	ifstream f;

	f.open("pw.dat");

	f.seekg(0,ios::beg);
	int flag=0;

	while(f.read((char*)&p,sizeof(user)))
	{
		if(strcmp(p.getaccount(),ac)==0)
		{
			p.putdata();
			flag=1;
		}
	}

	f.close();

	if(flag==0)

	cout<<"\nNo match found";
	getch();

	return;
}

//end of functions used inside see()

void seeusernames()
{
	clrscr();
	cout<<"\nVIPER will now show you all the usernames stored";
	delay(3000);
	clrscr();

	ifstream f;
	f.open("pw.dat");

	if(!f)
	{
		cout<<"\nFile could not be opened";
		getch();
		return;
	}

	f.seekg(0,ios::beg);
	int i=1;

	while(f.read((char*) &p,sizeof(user)))
	{
		cout<<"\n\n"<<i<<". "<<p.getusername();
		i++;

		if(i%9==0)
		{
		    cout<<"\n\nPlease press a key";
			getch();
			clrscr();
			i;
		}
	}

	cout<<"\n\nEnd of file";
	getch();

	return;
}

void seeaccountnames()
{
	clrscr();
	cout<<"\nVIPER will now show you all the account names stored";
	delay(3000);
	clrscr();

	ifstream f;
	f.open("pw.dat");

	if(!f)
	{
		cout<<"\nFile could not be opened";
		getch();
		return;
	}

	f.seekg(0,ios::beg);
	int i=1;

	while(f.read((char*) &p,sizeof(user)))
	{
		cout<<"\n\n"<<i<<". "<<p.getaccount();
		i++;

		if(i%9==0)
		{
		//the screen will be cleared for better viewing of data
	    cout<<"\n\nPlease press a key";
			getch();
			clrscr();
		}
	}

	cout<<"\n\nEnd of file";
	getch();

	return;
}


void recmodify()
{
	cout<<"\nYou have chosen to modify the details of an account\n";

	char un[20];
	clrbuf;

	cout<<"\nEnter the username of the account:";
	cin.getline(un,20);

	cout<<"\nEnter the master key to proceed:";
	acceptpass(pass);

	if(strcmp(pass,masterkey)!=0)
	{
		clrscr();
		cout<<"\nSorry, We are unable to proceed with your request";
		cout<<"\nVIPER has detected unauthorized access";
		cout<<"\nTerminating and returning to Windows";
		cout<<"\nPress a key";
		getch();
		exit(0);
	}

	cout<<"\nPassword accepted, Continuing with processing\n";

	ifstream f;
	ofstream g;
	user o; // to store the record to be modified

	f.open("pw.dat");
	g.open("temp.dat");

	f.seekg(0,ios::beg);
	g.seekp(0,ios::beg);
	int flag=0;

	while(f.read((char*)&p,sizeof(user)))
	{
		if(strcmp(un,p.getusername())==0 && flag==0)
		{

		/*here we are checking for flag as 0 and for the username
		because we will entertain the modification of one record
		at a time*/

			flag=1;
			o=p;
			continue;
		}

		g.write((char*)&p,sizeof(user));
	}

	if(flag==0)
	{
		cout<<"\nUsername not found";
		getch();
		return;
	}

	else
	{

	o.modify();

	g.write((char*)&o,sizeof(user));

	}

	f.close();
	g.close();

	remove("pw.dat");
	rename("temp.dat","pw.dat");

	return;


}

void delaccount()
{
	clrscr();
	cout<<"\nYou have chosen to delete an account\n";

	char un[20];
	clrbuf;

	cout<<"\nEnter the username of the account:";
	cin.getline(un,20);

	cout<<"\nEnter the master key to proceed:";
	acceptpass(pass);

	if(strcmp(pass,masterkey)!=0)
	{
		clrscr();
		cout<<"\nSorry, We are unable to proceed with your request";
		cout<<"\nVIPER has detected unauthorized access";
		cout<<"\nTerminating and returning to Windows";
		cout<<"\nPress a key";
		getch();
		exit(0);
	}

	cout<<"\nPassword accepted, Continuing with processing\n";

	ifstream f;
	ofstream g;
	user o; // to store the record to be deleted

	f.open("pw.dat");
	g.open("temp.dat");

	f.seekg(0,ios::beg);
	g.seekp(0,ios::beg);
	int flag=0;

	while(f.read((char*)&p,sizeof(user)))
	{
		if(strcmp(un,p.getusername())==0 && flag==0)
		{
		/*here we are checking for flag as 0 and for the username
		because we will entertain the deletion of one record
		at a time*/

			flag=1;
			o=p;
			continue;
		}

		g.write((char*)&p,sizeof(user));
	}


	if(flag==0)
	{
		cout<<"\nUsername not found";
		getch();
		return;
	}

	else
	{

	o.putdata();

	f.close();
	g.close();

	remove("pw.dat");
	rename("temp.dat","pw.dat");

	cout<<"\n\nAccount has been deleted";
	getch();

	return;
	}

}

void change()
{
	clrscr();

	cout<<"\nEnter the master key to proceed:";
	acceptpass(pass);

	if(strcmp(pass,masterkey)!=0)
	{
		clrscr();
		cout<<"\nSorry, We are unable to proceed with your request";
		cout<<"\nVIPER has detected unauthorized access";
		cout<<"\nTerminating and returning to Windows";
		cout<<"\nPress a key";
		getch();
		exit(0);
	}

	cout<<"\nPassword accepted, Continuing with processing\n";

	cout<<"Enter the new password:";
	acceptpass(pass);

	user temp(pass);

	remove("p.dat");

	ofstream f;
	f.open("p.dat");

	f.write((char*)&temp,sizeof(user));

	f.close();

	cout<<"\nPassword changed";
	cout<<"\nPress a key";
	getch();
	clrscr();

	//thought the file has been modifed, the password is unchanged
	//in the varibale here. so we must change that too.

	ifstream g;
	g.open("p.dat");
	g.read((char*)&p,sizeof(user));
	strcpy(masterkey,p.getpassword());
	g.close();

	return;
}

void seenumberofacc()
{
	ifstream f;

	f.open("pw.dat");

	f.seekg(0,ios::end);

	long pos=f.tellg();

	int x=pos/sizeof(user);

	cout<<"\n"<<x<<" accounts are presently stored";

	getch();
	return;
}
