#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll atoi(string s)
{
    ll sum=0,x=1;
    ll len_s=s.size();
    for(ll i=len_s-1;i>=0;i--,x=x*10)
    {
        sum=sum+(((ll)(s[i])-48)*x);
    }
    return sum;
}
ll trailing_nines(ll x)
{
    ll ans=0;
    while(x>0)
    {
        if(x%10!=9)
            break;
        x=x/10;
        ans++;
    }
    return ans;
}
int main()
{
    ll p,d;
    cin>>p>>d;
    d=p-d;
    string s="";
    for(ll i=pow(10,18);i>=1;i=i/10)
    {
        if((p/i)!=(d/i))
        {
            if(i!=1)
                s.push_back((char)((p/i)%10+48-1));
            else
            {
                s.push_back((char)((p/i)%10+48));
            }
            break;
        }
        s.push_back((char)((p/i)%10+48));
    }
    ll len_s=s.size();
    while(len_s<19)
    {
        s.push_back('9');
        len_s++; 
    }
    if(trailing_nines(atoi(s))>trailing_nines(p))
        cout<<atoi(s)<<endl;
    else
    {
        cout<<p<<endl;
    }
    
}