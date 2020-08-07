#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    map <char,string> s;
    s['>']="1000";
    s['<']="1001";
    s['+']="1010";
    s['-']="1011";
    s['.']="1100";
    s[',']="1101";
    s['[']="1110";
    s[']']="1111";
    string a,b="";
    cin>>a;
    int len_a=a.size();
    for(ll i=0;i<len_a;i++)
    {
        b=b+s[a[i]];
    } 
    ll len_b=b.size();
    ll x=1,ans=0;
    for(ll i=len_b-1;i>=0;i--)
    {
        if(b[i]=='1')
            ans=(x+ans)%1000003;
        x=(x*2)%1000003;
    }
    cout<<ans<<endl;
}