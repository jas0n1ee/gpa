#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<fstream>
using namespace std;
int sum=0,sum_val=0,sum_point=0;
double GPA;
struct DATA
{
	char name[30];
	int val;
	int point;
};
DATA *data;	//will be use to store data
void swap(void *a,void *b,int size)
{
	char *temp=new char [size];
	memcpy(temp,a,size);
	memcpy(a,b,size);
	memcpy(b,temp,size);
}
int read()
{
	ifstream infile;
	infile.open ("data.dat",ios::in|ios::binary|ios:ate);
	if(infile)
	{
		sum=infile.tellp()/sizeof(DATA);
		data=new DATA[infile.tellp()/sizeof(DATA)];
		infile.seekp(ios::beg);
		for(int i=0;i<sum;i++)
		{
			infile.read((char*)&data[i],sizeof(DATA));
		}
		infile.close();
		return 1;
	}
	else return 0;
}
void write()
{
	ofstream outfile;
	outfile.open("data.dat",ios::trunc|ios::binary);
	for(int i=0;i<sum;i++)
	{
		outfile.write((char*)&data[i],sizeof(DATA));
	}
	outfile.close();
}
void writenewline()
{
	cin>>data[sum].name>>data[sum].val>>data[sum].point;
	sum_val+=data[sum].val;
	sum_point+=data[sum].val*data[sum].point;
	sum++;
}
void start()
{
	system("cls");
	cout<<"What do you want?"<<endl
		<<"0 Check current GPA"<<endl
		<<"1 Add new line"<<endl
		<<"2 Print all lines"<<endl
		<<"3 Erase one line"<<endl
		<<"4 Change one line"<<endl
		<<"5 Exit"<<endl;
	cin>>modle;
	switch(modle)
	{
	case 0:
		GPA=(double)sum_point/(double)sum_val;
		cout<<"SUM: "<<sum_val<<"      "<<"GPA: "<<GPA;
		system("pause");
		start();
		break;
	case 1:
		writenewline();
		start();
		break;
	case 2:
		for(int i=0;i<sum;i++)
			cout<<i<<"|	"<<data[i].name<<" "<<data[i].val<<" "<<data[i].point<<endl;
		system("pause");
		start();
		break;
	case 3:
		int temp;
		cout<<"Which line you want to erase?"<<endl;
		cin>>temp;
		for(int i=temp;i<sum-1;i++) swap(&data[temp],&data[temp+1],sizeof(DATA));
		sum--;
		start();
		break;
	case 4:
		cout<<"Which line you want to erase?"<<endl;
		cin>>temp;
		cout<<"New name:";
		cin>>data[temp].name;
		cout<<"New val:";
		cin>>data[temp].val;
		cout<<"New point:";
		cin>>data[temp].point;
		start();
		break;
	case 5:
		break;
	}

}
int main()
{	read();
	start();
	write();
	return 0;
}
