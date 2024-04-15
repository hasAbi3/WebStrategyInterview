#include <bits/stdc++.h>

using namespace std;

int F (int num)
{
    int a = 1;
    int b = 1;
    int sum = 1;

    for (int i = 0 ; i < num - 1; i ++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }
    return sum;
}


int main()
{
    int n; 

    cout << "Enter the number: " ;
    cin >> n;

    cout << "The fibonnaci number: " << F(n) << endl;

}