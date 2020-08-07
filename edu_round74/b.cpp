#include <bits/stdc++.h>
using namespace std;
int c[1000000];
vector <pair <int,int>> compress_array(int *a, int n)
{
    vector <pair <int,int>> ans;
    int i=0;
    int c=1;
    while(i<n-1)
    {
        if(a[i]!=a[i+1])
        {
            pair <int,int> temp;
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
    pair <int,int> temp;
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
    int q;
    cin>>q;
    for(int t=0;t<q;t++)
    {
        int n,r;
        cin>>n>>r;
        int a[n];
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>a[i];
        }
        sort(a,a+n);
        vector <pair <int,int>> v=compress_array(a,n);
        int ans=0;
        int x=0;
        int len_v=v.size();
        for(int i=0;i<len_v;i++)
        {
            if(v[len_v-i-1].first-x>0)
            {
                ans+=1;
                x+=r;
            }
        }
        cout<<ans<<endl;
    }
}