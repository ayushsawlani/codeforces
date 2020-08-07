#include <bits/stdc++.h>
using namespace std;
//#define int long long
pair <int,int> imp[1000010];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;  
    cin>>s;
    for(int i=1;i<1000010;i++)
    {
        imp[i].first=(-1)*INT32_MAX;
        imp[i].second=INT32_MAX;
    }
    for(int i=0;i<s.size()-1;i++)
    {
        int t=i+2;
        pair <int,int> node1;
        pair <int,int> node2;
        pair <int,int> node3;
        if(s[i]=='l')
        {
            node1.second=t-1;
            node1.first=imp[t-1].first;
            node2.first=t;
            node2.second=imp[t-1].second;
            node3.second=t;
            if(imp[t-1].first!=(-1)*INT32_MAX)
                node3.first=imp[imp[t-1].first].first;
            else
                node3.first=(-1)*INT32_MAX;
 /*           imp[t].first=node1.first;
            imp[t].second=node1.second;
            imp[t-1].first=node2.first;
            imp[t-1].second=node2.second;
 */         imp[t]=node1;
            imp[t-1]=node2;


            if(node1.first!=(-1)*INT32_MAX)
            {
/*                imp[node1.first].first=node3.first;
                imp[node1.first].second=node3.second;
*/                imp[node1.first]=node3;
            }
        }
        else
        {
            node1.second=imp[t-1].second;
            node1.first=t-1;
            node2.second=t;
            node2.first=imp[t-1].first;
            node3.first=t;
             if(imp[t-1].second!=INT32_MAX)
                node3.second=imp[imp[t-1].second].second;
            else
                node3.second=INT32_MAX;
            
            /*imp[t].first=node1.first;
            imp[t].second=node1.second;
            imp[t-1].first=node2.first;
            imp[t-1].second=node2.second;*/
            imp[t]=node1;
            imp[t-1]=node2;

            if(node1.second!=INT32_MAX)
            {
                /*
                imp[node1.second].first=node3.first;
                imp[node1.second].second=node3.second;*/
                imp[node1.second]=node3;
            }
        }
        
    }
    int x=1;
    for(int i=1;i<=s.size();i++)
    {
        if(imp[i].first==(-1)*INT32_MAX)
            x=i;

    }
    while(imp[x].second!=INT32_MAX)
    {
        cout<<x<<endl;
        x=imp[x].second;
    }
    cout<<x;
    cout<<endl;
    
    
}