#include <iostream>
#include <cstring>
#include <fstream>
#include <unistd.h>
#include <conio.h>
#include <iomanip>
using namespace std;
string s,auth,type;
int len;

void Display(int a)
{
	if(auth=="Invalid" || auth=="Bad Input")
		type="";
	cout<<setw(21-len)<<"-"<<setw(10)<<auth<<" |"<<type<<endl;
}


void Display()
{
	if(auth=="Invalid" || auth=="Bad Input")
		cout<<" - "<<auth<<"!"<<endl;
	else
		cout<<" - "<<auth<<" |"<<type<<endl;
}


void validator(int a)
{
	int i,sum=0,num;
	len=s.length();
	--len;
	for(i=len;i>=0;i--)
	{
		num=s[i]-48;
		if(num<0 || num>9)
		{
			usleep(300000);
			auth="Bad Input";
			if(a==1)
				Display(a);
			else
				Display();
			return ;
		}
		if(i%2==len%2)
			sum+=num;
		else
		{
			if(num*2>9)
				sum+=(num*2)-9;
			else
				sum+=num*2;
		}	
	}
	num=s[0]-48;
	switch(num)
	{
		case 3:
			num=s[1]-48;
			if(num==7)
				type="American Express";
			else if(num==8 || num==6)
				type="Diners Club";
			else
				type="Not Identified";
		break;
		case 4:
			type="Visa";
		break;
		case 5:
			type="MasterCard";
		break;
		case 6:
			type="Discover";
		break;
		default:
			type="Not Identified";
	}
	usleep(600000);
	auth=((sum%10==0 && len>=12 && len<=18) ? "Valid" : "Invalid");
	if(a==1)
		Display(a);
	else
		Display();
}


void bulktxt()
{
	char file[20];
	ifstream f;
	cout<<"Enter ";
Retake:
	cout<<"file name in txt format or type \"exit\" to head back to main menu: ";
	cin>>file;
	f.open(file);
	if(file[0]=='e' && file[1]=='x' && file[2]=='i' && file[3]=='t')
	{
		sleep(1);
		return ;
	}
	else if(!f)
	{
		cout<<"File not available. Try again.\n"<<endl;
		cout<<"Enter another ";
		goto Retake;
	}
	else
	{
		cout<<"\n";
		while(!f.eof())
		{
			getline(f,s);
			cout<<s;
			validator(1);
		}
		cout<<"\nFile Read Successfully.\n\n";
		f.close();
		cout<<"Enter another ";
		goto Retake;
	}
}


void bulkmanual()
{
	ofstream fout;
	fout.open("File1.txt",ios_base::app);
	cout<<"You can anytime type \"exit\" to head back to main menu.\n"<<endl;
	while(true)
	{
		cout<<"Enter Credit Card Number: ";
		cin>>s;
		if(s=="exit")
		{
			sleep(1);
			return ;
		}
		else
		{
			fout<<"\n"<<s;
			cout<<"\n"<<s;
			validator(0);
		}
		cout<<endl;
	}
}


void singlemanual()
{
	ofstream fout;
	fout.open("File1.txt",ios_base::app);
	cout<<"Enter Credit Card Number: ";
	cin>>s;
	fout<<"\n"<<s;
	cout<<"\n"<<s;
	validator(0);
	cout<<"Press any key to head back to main menu.";
	getch();
}


int main()
{
	int ch;
Choice:
	cout<<"**This program uses the Luhn Algorithm to validate a Credit Card Number and identify the card network**"<<endl;
	cout<<"\nPress enter to continue.";
	getchar();
	system("cls");
	cout<<"Choose your option:-"<<endl;
	usleep(100000);
	cout<<"1. Bulk Validator using txt file."<<endl;
	usleep(100000);
	cout<<"2. Bulk validator using manual input."<<endl;
	usleep(100000);
	cout<<"3. Single validator using manual input."<<endl;
	usleep(100000);
	cout<<"4. Exit program."<<endl;
	usleep(100000);
	cout<<"Type respective serial no.: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			sleep(1);
			system("cls");
			bulktxt();
			goto Choice;
			break;
		case 2:
			sleep(1);
			system("cls");
			bulkmanual();
			goto Choice;
			break;
		case 3:
			sleep(1);
			system("cls");
			singlemanual();
			goto Choice;
			break;
		case 4:
			break;
		default:
			cout<<"\nWrong input!! Try again."<<endl;
			sleep(2);
			system("cls");
			goto Choice;
	}
	sleep(1);
	system("cls");
	cout<<"Program exited successfully!";
	sleep(2);
	return 0;
}
