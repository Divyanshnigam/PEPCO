#include<iostream>
using namespace std;
void merge(long long int* a,long long int s,long long int e)
{

	long long int mid=(s+e)/2;
	long long int i,j,k;
	i=s;
	j=mid+1;
	k=s;
	long long int temp[100000]; 
	cout<<"Merging these two arrays "<<endl;
	cout<<"left array -> ";
	
	for(long long int m=s;m<=mid;m++)
	{
		cout<<a[m]<<" ";
	}
	cout<<endl;
	
	cout<<"right array -> ";
	for(long long int n=mid+1;n<=e;n++)
	{
		cout<<a[n]<<" ";
	}
	cout<<endl;
	
	while(i<=mid && j<=e)
	{
		if(a[i]>=a[j])
		{             
		  temp[k++]=a[j++];
		}
		if(a[i]<a[j])
		{
		  temp[k++]=a[i++];
		}
	}
	while(i<=mid)
	{
		temp[k++]=a[i++];
	} 
	while(j<=e)
	{
		temp[k++]=a[j++]; 
	} 
	for(long long int m=s;m<=e;m++)
	{
	    a[m]=temp[m];
	}
}
void mergeSort(long long int *a,long long int s,long long int e)
{
   if(s>=e)
   {
		return ;
   }
   long long int mid=(s+e)/2;

   mergeSort(a,s,mid);
   mergeSort(a,mid+1,e);

   merge(a,s,e);
}
int main()
{

  long long int n;
  cin>>n;
  long long int a[n];
  for(long long int i=0;i<n;i++){
    cin>>a[i] ;
  }
  mergeSort(a,0,n-1);
  cout<<"Sorted Array -> ";
  for(long long int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}
/*
#include<iostream>
using namespace std;
void merge(long long int *a,long long int s,long long int e)
{
	long long int mid=(s+e)/2;
	long long int i=s;
	long long int j=mid+1;
	long long int k=0;
	long long int temp[e-s+1];
	while(i<=mid and j<=e)
	{
		if(a[i]<a[j])
		{
			temp[k++]=a[i++];
		}
		else{
			temp[k++]=a[j++];
		}
	}
	while(i<=mid)
	{
		temp[k++]=a[i++];
	}
	while(j<=e)
	{
		temp[k++]=a[j++];
	}
	for(long long int i=s;i<=e;i++)
	{
		a[i]=temp[i-s];
	}
}
void mergesort(long long int *a,long long int s,long long int e)
{
	if(s>=e)
	{
		return ;
	}
	long long int mid=(s+e)/2;
	//divide in 2 by 2 calls
	mergesort(a,s,mid);
	mergesort(a,mid+1,e);
	//merge
	merge(a,s,e);
}
int main() 
{
	long long int n;
	cin>>n;
	long long int a[n];
	for(long long int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	mergesort(a,0,n-1);
	for(long long int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}

*/
