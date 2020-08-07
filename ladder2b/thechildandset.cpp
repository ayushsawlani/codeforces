#include <bits/stdc++.h>
using namespace std;
#define ll long long int
string itoa(ll n)
{
    if(n==0)
        return "0";
    string s="";
    while(n>0)
    {
        if(n%2)
            s.push_back('1');
        else
        {
            s.push_back('0');
        }
        n=n/2;
    }
    for(ll i=0;i<=(s.size()-1)/2;i++)
    {
        char temp=s[i];
        s[i]=s[s.size()-i-1];
        s[s.size()-i-1]=temp;
    }
    return s;
}
ll atoi(string a)
{
    ll x=1;
    ll ans=0;
    for(ll i=a.size()-1;i>=0;i--,x=2*x)
        if(a[i]=='1')
            ans+=x;
    return ans;
}
int main()
{
    ll sum,limit;
    cin>>sum>>limit;
    ll a[54],b[54];
    for(ll i=0;i<54;i++)
    {
        b[i]=0;
        a[i]=0;
    }
    for(ll i=1;i<=limit;i++)
    {
        ll x=i&(-i);
        ll c=0;
        while(x>0)
        {
            x=x/2;
            c++;
        }
        a[c-1]++;
    }

    ll p=53;
    while((sum>0)&&(p>=0))
    {
        ll num=pow(2,p);
        if(sum/num>a[p])
        {
            b[p]=a[p];
            sum=sum-a[p]*num;
        }
        else
        {
            b[p]=sum/num;
            sum=sum%num;
        }
        p--;
    }
    if(sum!=0)
        cout<<-1<<endl;
    else
    {
        ll ans=0;
        for(ll i=0;i<54;i++)
            ans+=b[i];
        cout<<ans<<endl;
        for(ll i=0;i<54;i++)
        {
            string s1=itoa(pow(2,i));
            for(ll j=0;j<b[i];j++)
            {
                string s2=itoa(j);
                for(ll k=0;k<s1.size();k++)
                    s2.push_back(s1[k]);
                cout<<atoi(s2)<<" ";
            }
        }
        cout<<endl;
    }
    
}