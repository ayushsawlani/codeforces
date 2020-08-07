#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll q;
    cin>>q;
    vector <string> ans;
    vector <pair <ll,ll>> v;
    ll c=0;
    while(q--)
    {
        ll type;
        cin>>type;
        if(type>0)
        {
            v.push_back(pair <ll,ll>(type,c++));
        }
        else
        {
            vector <ll> great;
            c=0;
            sort(v.begin(),v.end());
            auto it=v.end();
            if(it!=v.begin())
            {      
                it--;
                great.push_back((*it).second);
            }
            if(it!=v.begin())
            {
                it--;
                great.push_back((*it).second);
            }
            if(it!=v.begin())
            {
                it--;
                great.push_back((*it).second);
            }
            sort(great.begin(),great.end());
            if(v.size()==0)
            {
                ans.push_back("0");
            }
            else if(v.size()==1)
            {
                ans.push_back("pushStack");
                ans.push_back("1 popStack");
            }
            else if(v.size()==2)
            {
                ans.push_back("pushStack");
                ans.push_back("pushQueue");
                ans.push_back("2 popStack popQueue");
            }
            else
            {
                for(ll i=0;i<v.size();i++)
                {
                    if((i<=great[2])&&(i!=great[1])&&(i!=great[0]))
                    {
                        ans.push_back("pushStack");
                    }
                    else if((i>great[2])&&(i!=great[1])&&(i!=great[0]))
                    {
                        ans.push_back("pushQueue");
                    }
                    else if(i==great[1])
                    {
                        ans.push_back("pushFront");
                    }
                    else
                    {
                        ans.push_back("pushQueue");
                    }
                }
                ans.push_back("3 popStack popQueue popFront");
            }
            v.clear();
        }
    }
    vector <ll> great;
    c=0;
    sort(v.begin(),v.end());
    auto it=v.end();
    if(it!=v.begin())
    {      
        it--;
        great.push_back((*it).second);
    }
    if(it!=v.begin())
    {
        it--;
        great.push_back((*it).second);
    }
    if(it!=v.begin())
    {
        it--;
        great.push_back((*it).second);
    }
    sort(great.begin(),great.end());
    if(v.size()==0)
    {
    }
    else if(v.size()==1)
    {
        ans.push_back("pushStack");
    }
    else if(v.size()==2)
    {
        ans.push_back("pushStack");
        ans.push_back("pushQueue");
    }
    else
    {
        for(ll i=0;i<v.size();i++)
        {
            if((i<=great[2])&&(i!=great[1])&&(i!=great[0]))
            {
                ans.push_back("pushStack");
            }
            else if((i>great[2])&&(i!=great[1])&&(i!=great[0]))
            {
                ans.push_back("pushQueue");
            }
            else if(i==great[1])
            {
                ans.push_back("pushFront");
            }
            else
            {
                ans.push_back("pushQueue");
            }
        }
    }
    v.clear();
    
    for(ll i=0;i<ans.size();i++)
    cout<<ans[i]<<endl;
 
}