#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        ll str,in,exp;
        cin>>str>>in>>exp;
        ll ans=0;
        if(str<=in)
        {
            str+=exp;
            if(str>in)
            {
                cout<<(str-in+1)/2<<endl;
            }
            else
            {
                cout<<0<<endl;
            }
        }
        else if(str>in)
        {
            if(str>in+exp)
            {
                cout<<exp+1<<endl;
            }
            else
            {
            cout<<exp+1-((in+exp-str+2)/2)<<endl;
                
            }
            
        }
    }
        

    
}