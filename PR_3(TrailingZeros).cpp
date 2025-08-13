#include<iostream>
using namespace std;

int TrailingZeros(int No)
{
	int count = 0;
	while(No>=5)
	{
		count = count+ No/5;
		No = No/5;
	}
	return count;
}

int Trailing(int n)
{
	int sum = -1;
	
	if(n<5)
	{
		sum = n*5;
	}
	else
	{
		int low = 0,high = n * n;
		
		while(low <= high)
		{
			int mid = (low + high)/2;
			
			if(TrailingZeros(mid) >= n)
			{
				sum = mid;
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
	}
	return sum;
}                         

int main()
{
	int n;
	
	cout<<"\nEnter a number:";
	cin>>n;
	
	cout<<"\nThe smallest number whose factorial contains at least "<<n<<" trailing zeroes is "<<Trailing(n)<<endl;	
	return 0;
}
