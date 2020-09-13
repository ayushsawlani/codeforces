#include <bits/stdc++.h>
using namespace std;
#define M (ll)(1e9+7)
#define ll long long
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string x;
        cin>>x;
        string x1,x2;
        x1.push_back('1');
        x2.push_back('1');
        ll i;
        for(i=1;i<n;i++)
        {
            if(x[i]=='0')
            {
                x1.push_back('0');
                x2.push_back('0');
            }
            else if(x[i]=='2')
            {
                x1.push_back('1');
                x2.push_back('1');
            }
            else
            {
                break;
            }
            

        }
        if(i!=n)
        {
            x1.push_back('1');
            x2.push_back('0');
            i++;
            for(;i<n;i++)
            {
                x1.push_back('0');
                x2.push_back(x[i]);
            }
        }
        cout<<x1<<endl<<x2<<endl;
    }
}