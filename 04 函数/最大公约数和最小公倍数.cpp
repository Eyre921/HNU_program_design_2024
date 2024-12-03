#include <iostream>
using namespace std;
int gcd (int u,int v);
int lcm(int u,int v);
int main()
{
    int x,y;
    cin>>x>>y;
    cout<<gcd(x, y)<<" "<<lcm(x,y)<<endl;
    return 0;
}

int gcd(int u, int v)            
{
	for(int i = min(u,v); i > 0; i--)
	{
		if (i == 1 || ((u % i == 0) && (v % i == 0)))
		{
			return i;
		}
	}
	return 1;
}

int lcm(int u,int v)                                                
{
    return u*v/gcd(u,v);
}


