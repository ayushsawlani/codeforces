#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    if(n==1)
        cout<<1<<endl;
    else
    {
    cout<<n<<" ";

    int flag=0;
    for(ll i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            n=n/i;
            if(n==1)
                break;
            cout<<n<<" ";
            i--;
        }
    }
    cout<<1<<" ";
    }
}