#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
ll arr_max(ll *arr,ll n)
{
    ll m1=0;
    for(ll i=0;i<n;i++)
    {
        if(arr[m1]<arr[i])
            m1=i;
    }
    return m1;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio;
    string s;
    cin>>s;
    ll count[26];
    memset(count,0,26*sizeof(ll));
    for(ll i=0;i<s.size();i++)
    {
        count[s[i]-'a']++;
        s[i]='.';
    }
    ll sei[1008];
    memset(sei,0,1008*sizeof(ll));
    for(ll i=2;i<1008;i++)
    {
        if(!(sei[i]))
        {
            for(ll j=i*i;j<1008;j=j+i)
                sei[j]=1;
        }
    }
    sei[1]=1;
    ll m1=arr_max(count,26);
    for(ll i=1;i<s.size();i+=2)
    {
        s[i]=(char)(m1+'a');
    }
    count[m1]-=(s.size()/2);
    if(count[m1]<0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(ll i=3;i<=s.size()/2;i++)
    {
        if(sei[i]==0)
        {
            for(ll j=i-1;j<s.size();j+=i)
            {
                if(s[j]=='.')
                {
                    s[j]=(char)(m1+'a');
                    if(count[m1]>0)
                        count[m1]--;
                    else
                    {
                        cout<<"NO"<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    for(ll i=s.size()/2+1;i<=s.size();i++)
    {
        if((sei[i]==0)&&(i!=2))
        {
            m1=arr_max(count,26);
            s[i-1]=(char)(m1+'a');
            if(count[m1]>0)
                count[m1]--;
            else
            {
                cout<<"NO"<<endl;
                return 0;
            }
            
        }
    }
    m1=arr_max(count,26);
    if(count[m1]>0)
        s[0]=(char)(m1+'a');
    else
    {
        cout<<"NO"<<endl;
        return 0;
    }
    
    cout<<"YES"<<endl;
    cout<<s<<endl;
}