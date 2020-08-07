#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll strtoi(string s)
{
    ll len_s=s.size();
    ll ans=0;
    for(ll i=len_s-1,x=1;i>=0;i--,x=x*10)
    {
        ans+=(((ll)(s[i])-48)*x);
    }
    return ans;
}
string itos(ll i)
{
    string s="";
    if(i<10)
        s.push_back('0');
    if(i==0)
        s.push_back('0');
    while(i>0)
    {
        s.push_back((char)((i%10)+48));
        i=i/10;
    }
    ll len_s=s.size();
    for(ll i=0;i<(len_s+1)/2;i++)
    {
        ll temp=s[i];
        s[i]=s[len_s-i-1];
        s[len_s-i-1]=temp;
    }
    return s;
}
ll isvalid(string s)
{
    ll month[12];
    month[0]=31;
    month[2]=31;
    month[4]=31;
    month[6]=31;
    month[7]=31;
    month[9]=31;
    month[11]=31;
    month[1]=28;
    month[3]=30;
    month[5]=30;
    month[8]=30;
    month[10]=30;
 
    if(s[2]!='-')
        return 0;
    if(s[5]!='-')
        return 0;
    ll len_s=s.size();
    for(ll i=0;i<len_s;i++)
    {
        if((i!=2)&&(i!=5))
        {
            if((s[i]<48)||(s[i]>58))
                return 0;
        }
    }
    string dd="",mm="",yy="";
    ll i=0;
    while(dd.size()<2)
    {
        dd.push_back(s[i]);    
        i++;
    }
    i++;
    while(mm.size()<2)
    {
        mm.push_back(s[i]);
        i++;
    }
    i++;
    while(yy.size()<4)
    {
        yy.push_back(s[i]);
        i++;
    }
    ll y=strtoi(yy);
    ll m=strtoi(mm);
    ll d=strtoi(dd);
    m--;
    if((d<1)||(d>month[m]))
        return 0;
    if((y<2013)||(y>2015))
        return 0;
    if((m<0)||(m>11))
    {
        return 0;
    }
    return 1;
}
int main()
{
    ll month[12];
    string s;
    cin>>s;
    month[0]=31;
    month[2]=31;
    month[4]=31;
    month[6]=31;
    month[7]=31;
    month[9]=31;
    month[11]=31;
    month[1]=28;
    month[3]=30;
    month[5]=30;
    month[8]=30;
    month[10]=30;
    ll len_s=s.size();
    map <string,ll> table;
    for(ll i=2013;i<=2015;i++)
    {
        string s1=itos(i);
        for(ll j=0;j<12;j++)
        {   
            string s2=itos(j);
            for(ll k=1;k<=month[j];k++)
            {
                string s3=itos(k);
                s3.push_back('-');
                for(ll l=0;l<s2.size();l++)
                    s3.push_back(s2[l]);
                s3.push_back('-');
                for(ll l=0;l<s1.size();l++)
                    s3.push_back(s1[l]);
                table[s3]=0;
            }
        }
    }
    for(ll i=0;i<=len_s-10;i++)
    {
        string s1="";
        ll x=0;
        while(x<10)
        {
            s1.push_back(s[i+x]);
            x++;
        }
        if(isvalid(s1))
        {
            table[s1]++;
        }
    }
    auto x=table.begin();
    for(auto i=table.begin();i!=table.end();i++)
        if(x->second<i->second)
            x=i;
    cout<<x->first<<endl;
    
}