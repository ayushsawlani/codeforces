#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll *tol(string s)
{
    ll *ans=(ll *)(malloc(5*sizeof(ll)));
    ll len_s=s.size();
    ll i=0;
    while(i<5-len_s)
    {
        ans[i++]=0;
    }
    ll j=0;
    while(j<len_s)
    {
        if(s[j]<=58)
            ans[i++]=(ll)(s[j++])-48;
        else
        {
            ans[i++]=(ll)(s[j++])-55;
        }
        
    }
    return ans;
}
ll con(ll *a, ll b)
{
    ll ans=0;
    ll x=1;
    for(ll i=4;i>=0;i--,x=x*b)
        ans+=(a[i]*x);
    return ans;
}
int main()
{
    string s;
    cin>>s;
    ll i=0;
    ll len_s=s.size();
    string a,b;
    a="";
    b="";
    while(s[i]!=':')
    {
        a.push_back(s[i]);
        i++;
    }
    i++;
    while(i<len_s)
    {
        b.push_back(s[i]);
        i++;
    }
    ll *a1,*b1;
    a1=tol(a);
    b1=tol(b);
    ll m=0;
    for(ll i=0;i<5;i++)
    {
        if(m<a1[i])
            m=a1[i];
        if(m<b1[i])
            m=b1[i];

    }
    ll ans=60;
    for(ll i=59;i>m;i--)
    {
        ll x=con(a1,i);
        ll y=con(b1,i);
        if((x<24)&&(y<60))
        {
            ans=i;
            break;
        }
    }
    if(ans==60)
        cout<<0<<endl;
    else
    {
        ll flag1=0,flag2=0;
        for(ll i=0;i<4;i++)
        {
            if(a1[i]!=0)
                flag1=1;
            if(b1[i]!=0)
                flag2=1;
        }
        if((flag1==0)&&(flag2==0))
        {
            if((a1[4]<24)&&(b1[4]<60))
                cout<<-1<<endl;
            else
            {
                cout<<0<<endl;
            }
        }
        else
        {
            for(ll i=m+1;i<=ans;i++)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    
    
   }