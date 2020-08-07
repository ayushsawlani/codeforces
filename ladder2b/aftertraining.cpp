#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    cin>>n>>m;
    ll c=0;
    while(c<n)
    {
        for(ll i=(m+1)/2;i>=1;i--)
        {
            if(c==n)
                break;
            cout<<i<<endl;
            c++;
            if(c==n)
                break;
            if((m-i+1)!=i)
            {
                cout<<m-i+1<<endl;
                c++;
            }
            
        }
    }
}