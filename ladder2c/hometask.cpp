#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
vector <pair <ll,ll>> compress_array(string a, ll n)
{
    vector <pair <ll,ll>> ans;
    ll i=0;
    ll c=1;
    while(i<n-1)
    {
        if(a[i]!=a[i+1])
        {
            pair <ll,ll> temp;
            temp.first=a[i];
            temp.second=c;
            ans.push_back(temp);
            c=1;
        }
        else
        {
            c++;
        }
        i++;   
    }
    pair <ll,ll> temp;
    temp.first=a[i];
    temp.second=c;
    ans.push_back(temp);
    c=1;
    return ans;
}
int main()
{
 cin.tie(0);
ios::sync_with_stdio(0);
    string s;
    cin>>s;
    int k;
    cin>>k;
    map <char,char> m;
    for(ll i=0;i<k;i++)
    {
        string x;
        cin>>x;
        m[x[0]]=x[1];
        m[x[1]]=x[0];   
    }
    vector <pair <ll,ll>> v=compress_array(s,s.size());
    ll ans=0;
    for(int i=0;i<v.size()-1;i++)
    {
        if(m.find(v[i].first)!=m.end())
        {
            char c=v[i].first;
            ll ans1=0,ans2=0;
            ll flag=0;
            while((m[v[i].first]==v[i+1].first)&&(v[i].first==c)&&(i<v.size()-1))
            {
                ans1+=v[i].second;
                ans2+=v[i+1].second;
                i+=2;
                flag=1;
            }
            if((flag)&&(i<v.size()))
            {
                if(v[i].first==c)
                {
                    ans1+=v[i].second;
                    i++;
                }
            }
            if(flag)
                i--;
            //cout<<ans1<<" "<<ans2<<" "<<s.size()<<endl;
            ans+=min(ans1,ans2);
        }
    }
    cout<<ans<<endl;
}