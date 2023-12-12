#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
int main()
{
	char name[30];
	cout<<"Enter the name of file to create ";
	cin>>name;
	
	ofstream fout;
	fout.open(name);
	if(!fout)
	{
		cout<<"Error opening the file";
		exit(1);
	}
	cout<<"Writing to the file"<<endl;
	cout<<"Enter contents for file end it with ^D";
	string data;
	while(getline(cin, data))
	{
		if(data=="^D")
		break;
		fout<<data<<endl;
	}
	fout.close();
	
	ifstream fin;
	fin.open(name);
	if(!fin)
	{
		cout<<"Error opening the file";
		exit(1);
	}
		cout<<"Reading from the file\n";
		while(fin)
		{
			getline(fin,data);
			cout<<data;
		}
		fin.close();

return 0;
}
