#include<iostream>
using namespace std; 
double Pow(double x, int n);

int main()
{
    double x=2.0, n = 10; 
    cout<<"\nPower :"<<Pow(x,n)<<endl; 
    return 0; 
}
double Pow(double x, int n)
{
    double result=1; 
    for(int i=0;i<n;i++)
    {
        result = result*x; 
    }
    return result; 
}




