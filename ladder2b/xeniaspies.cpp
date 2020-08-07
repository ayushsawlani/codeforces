#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m,s,f;
    cin>>n>>m>>s>>f;
    ll t[m],l[m],r[m],ans=1;
    for(ll i=0;i<m;i++)
    {
        cin>>t[i]>>l[i]>>r[i];   
    }
    ll i=0;
    ll current=1;
    while(s!=f)
    {
        if(current!=t[i])
        {
            if(s<f)
            {
                s++;
                cout<<"R";
            }
            else
            {
                s--;
                cout<<"L";
            }
        }
        else
        {
            if(s<f)
            {
                if((s<l[i]-1)||(s>r[i]))
                {
                    s++;
                    cout<<"R";
                }
                else
                {
                    cout<<"X";
                }
                
            }
            else
            {
                if((s<l[i])||(s>r[i]+1))
                {
                    s--;
                    cout<<"L";
                }
                else
                {
                    cout<<"X";
                }
            }
        }
        if(current==t[i])
            i++;
        current++;
    }
    cout<<endl;
}