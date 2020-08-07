#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    map <string, string> ans;
    for(int i=0;i<m;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        if(s1.size()<=s2.size())
            ans[s1]=s1;
        else
        {
            ans[s1]=s2;
        }
    }
    string p="";
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        p.append(ans[s]);
        p.append(" ");
    }
    cout<<p<<endl;
}