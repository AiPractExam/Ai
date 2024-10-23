#include<iostream>
using namespace std;
int calcost(int arr[10],int n)
{
	int c=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if (arr[j]<arr[i])
			{
				c++;
			}
		}
	}
	return c;
}

void swap(int arr[10],int i, int j)
{
	int temp;
	temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
int main()
{
	int a[100],n,bestcost,newcost;
	cout<<"Enter size of array: ";
	cin>>n;
	cout<<"Enter array elements: ";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	bestcost=calcost(a,n);
	while(bestcost>0)
	{
		for(int i=0;i<n-1;i++)
		{
			swap(a,i,i+1);
			newcost=calcost(a,n);
			if(bestcost>newcost)
			{
				cout<<"after swap:"<<endl;
				for(i=0;i<n;i++)
				{
					cout<<a[i]<<" ";
					cout<<"\n";
					bestcost=newcost;
				}
			}
			else
			swap(a,i,i+1);
		}
	}
	cout<<"Final ans: ";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
		cout<<"\n";
	}
	return 0;
		
}
