//I have assumed that elements aren't distinct, they repeat and hence we don't need to search for all elements in left and
//right half.

//ISSUE:
//ye tab bokhla jaara jab saare elements index ke barabar ho.

#include<iostream>
#include<algorithm>  //to use sort()
#include<cstdlib>   //to use malloc()

//isse baar baar std:: nhi likhna padta
using namespace std; 

//returns minimum of the two
int min(int a, int b)
{
	if(a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

//returns maximum of the two
int max(int a, int b)
{
	if(a<b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

int MagicIndex(int a[],int start,int end,int n)
{
	//Base case (a case where recursion ends)
	if(end<start)
	{
		return -1;
	}
	
	int midindex=(start+end)/2;
	int midvalue=a[midindex];
	
	if(midindex==midvalue)
	{
		return midindex;
	}
	
	//If not, search left now. We don't need to search every element in the left half.
	int leftindex=min(midindex-1,midvalue);
	
	//call itself to the left
	int left=MagicIndex(a,start,leftindex,n);
	
	//base case
	if(left>=0)
	{
		return left;
	}
	
	//if not there, search right half
	int rightindex=max(midindex+1,midvalue);
	
	//call itself to the right
	int right=MagicIndex(a,rightindex,end,n);
	
	//base case
	if(right<n)
	{
		return right;
	}
	
}

int main()
{
	int n,i; 
	 
	cout<<"\nWhat should be your array's size => ";
	cin>>n;
	
	//input array being dynamically allocated
	cout<<"\nStart filling the string => ";
	int *a=(int*)malloc(sizeof(int)*(n));
	
	for(i=0;i<n;i++)
	{
		cout<<"\nElement at index "<<i<<" ";
		cin>>a[i];
	}
	
	//array must be by default sorted but in case its not sorted, sort it. Don't include this time in final TC
	sort(a,a+n);
	
	int ans=MagicIndex(a,0,n-1,n);
	
	if(ans==-1)
	{
		cout<<"\nNo magic index in the input array!";
	}
	else
	{
		cout<<"\nThe magic index is => "<<ans;
	}

return 0;
}
