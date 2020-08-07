#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll s,k;
    cin>>s>>k;
    queue <ll> q;
    vector <ll> v;
    ll sum=0;
    ll current =0;
    q.push(1);
    while(current<s)
    {
        if(q.size()<k+1)
        {
            current+=(q.back());
            q.push(current);
        }
        else
        {
            current-=q.front();
            current+=(q.back());
            q.pop();
            q.push(current);
        }
        
        v.push_back(current);
        sum+=current;
    }
    sum=0;
    sort(v.begin(),v.end());
   // for(auto i=v.begin();i!=v.end();i++)
     //   cout<<(*i)<<" ";
    //cout<<endl;
    vector <ll> ans;
    for(auto i=v.end()-1;i>=v.begin();i--)
    {
        if(sum+(*i)<=s)
        {
            sum+=(*i);
            ans.push_back((*i));
        }
        if(sum==s)
            break;
    }
    cout<<ans.size()+1<<endl;
    for(auto i=ans.begin();i!=ans.end();i++)
    {
        cout<<(*i)<<" ";
    }
    cout<<0<<endl;
}