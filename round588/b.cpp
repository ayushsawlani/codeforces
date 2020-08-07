#include <bits/stdc++.h> 
using namespace std;
#define ll long long
int main()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(k>0)
    {
        if(s[0]!='1')
        {
            s[0]='1';
            k--;
        }
        if(n==1)
            s[0]='0';
    }
    ll i=1;
    while((i<n))
    {
        if(k==0)
            break;
        if(s[i]!='0')
        {
            s[i]='0';
            k--;
        }
        i++;
    }
    cout<<s<<endl;
}