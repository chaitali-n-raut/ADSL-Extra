#include <iostream>
using namespace std;

int main() 
{
    int c[] = {20,10,5,2,1};
    int V = 43;

    cout << "Coins: ";
    for (int i = 0; i < 5; i++) 
    {
        while (V >= c[i]) //23>20  3>2 1>=1
        {
            cout << c[i] << " "; // 20 20 2 1
            V -= c[i];  //23 //3 //1 //0
        }
    }
}
