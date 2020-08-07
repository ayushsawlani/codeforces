#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1000001]={0};
int main()
{
    ll n;
    cin>>n;
    ll sevencount=n/7;
    ll fourcount=(n-7*sevencount)/4;
    while(7*sevencount+4*fourcount!=n)
    {
        if(sevencount==0)
        {
            cout<<-1<<endl;
            return 0;
        }
        sevencount--;
        fourcount=(n-7*sevencount)/4;
    }
    for(ll i=0;i<fourcount;i++)
    {
        cout<<4;
    }
    for(ll i=0;i<sevencount;i++)
    {
        cout<<7;
    }
    cout<<endl;
}