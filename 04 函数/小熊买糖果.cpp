#include <iostream>
using namespace std;
int getCandy(int k, int r);

int main()
{
    int k, r;
    cin>>k>>r;
    int result = getCandy(k, r);
    cout<<result;
    return 0;
}

int getCandy(int k, int r) {
    int n = 1;
    while (true) {
        int totalCost = n * k;
        if (totalCost % 10 == 0 || totalCost % 10 == r)
        {
            return n;
        }
        n++;
    }
}