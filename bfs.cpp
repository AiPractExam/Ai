#include<iostream>
#include<conio.h>
using namespace std;
int cost[10][10],v,i,n,ver,ed,j,k,qu[10],front=0,rear=0;
int main()
{
	cout<<"Enter no.of vertices:";
	cin>>ver;
	cout<<"Enter no.of edges:";
	cin>>ed;
	for(k=1;k<=ed;k++)
	{
		cin>>i;
		cin>>j;
		cost[i][j]=1;
	}
	cout<<"Enter initial vertices:";
	cin>>v;
	cout<<"Visited vertices are:";
	cout<<v<<" ";
	k=1;
	while(k<ver)
	{
		for(j=1;j<=ver;j++)
		{
			if(cost[v][j]!=0)
			{
				qu[rear++]=j;
			}
		}
		v=qu[front++];
		cout<<v<<" ";
		k++;
	}
	return 0;
}
