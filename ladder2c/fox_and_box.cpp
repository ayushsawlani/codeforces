#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main()
{
 cin.tie(0);
ios::sync_with_stdio(0);
    ll n;
    cin>>n;
    ll ele[n];
    ll ele_size=0;
    ll ispre[n];
    for(ll i=0;i<n;i++)
    {
        cin>>ele[i];
        ispre[i]=1;
        ele_size++;
    }
    sort(ele,ele+n);
    ll ans=0;
    while(ele_size)
    {
        ll pile[n];
        ll pile_size=0;
        for(ll i=0;i<n;i++)
        {
            ll insert_here=-1;
            if(ispre[i])
            {
                for(ll j=0;j<pile_size+1;j++)
                {
                    if(pile_size-j<=ele[i])
                    {
                        ispre[i]=0;
                        insert_here=j;
                        ele_size--;
                        break;
                    }
                    else if(pile_size-1-(j+1)+1==pile[j])
                    {
                        break;
                    }
                }
            }
            //cout<<ele[i]<<" "<<insert_here<<endl;
            if(insert_here!=-1)
            {
                for(ll j=pile_size;j>insert_here;j--)
                {
                    pile[j]=pile[j-1];
                }
                pile_size++;
                pile[insert_here]=ele[i];
            }
        }
        ans++;
    }
    cout<<ans<<endl;
}