#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int partition(int *a , int begin , int end)
{
	int x=a[end],i=begin-1,j;
	for(j=begin;j<end;j++)
		if(a[j]<x)
		{
			i++;
			swap(a[i],a[j]);
		}
	swap(a[++i],a[end]);
	return i;
}

void qsort(int *a , int begin , int end)
{
	if(begin<end-1)
	{
		int k=partition(a,begin,end-1);
		qsort(a,begin,k);
		qsort(a,k+1,end);
	}
}

int main()
{
	int a[1000];
	srand(int(time(0)));
	for(int i=0; i<1000; i++)
		a[i]=rand()%10000;
	qsort(a,0,1000);
	for(int i=0; i<1000; i++)
		cout<<a[i]<<" ";
}
