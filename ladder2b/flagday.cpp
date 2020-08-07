#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,m;
    cin>>n>>m;
    ll arr[m][3];
    ll color[n];
    for(ll i=0;i<n;i++)
        color[i]=0;
    for(ll i=0;i<m;i++)
    {
        for(ll j=0;j<3;j++)
        {
            cin>>arr[i][j];
            arr[i][j]--;
        }
    }
    for(ll i=0;i<m;i++)
    {
        ll p;
        ll flag=0;
        for(ll j=0;j<3;j++)
            if(color[arr[i][j]])
            {
                p=j;
                flag=1;
                break;
            }
        if(flag)
        {
            color[arr[i][(p+1)%3]]=1+(color[arr[i][p]])%3;
            color[arr[i][(p+2)%3]]=1+(color[arr[i][p]]+1)%3;
        }
        else
        {
            color[arr[i][0]]=1;
            color[arr[i][1]]=2;
            color[arr[i][2]]=3;
        }
        
    }
    for(ll i=0;i<n;i++)
        cout<<color[i]<<" ";
    cout<<endl;
}