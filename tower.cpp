#include<iostream>
#include<conio.h>
using namespace std;
void tower(int a,char from,char aux,char to)
{
	if(a==1)
	{
		cout<<"\t\tMove disc 1 from "<<from<<" to "<<to<<"\n";
		return;
		}
	else
	{
		tower(a-1,from,to,aux);
		cout<<"\t\tMove disc "<<a<<" from "<<from<<" to "<<to<<"\n";
		tower(a-1,aux,from,to);
		
		
	}
}
	int main()
	{
		int n;
		cout<<"**********\tTower of Hanoi\t**********\n";
		cout<<"Enter the no. of disc: ";
		cin>>n;
		tower(n,'A','B','C');
	
		getch();
		return 0;
	}
