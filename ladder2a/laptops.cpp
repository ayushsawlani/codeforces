#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,flag=0;
    cin>>n;
    vector <pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        pair <int , int> p;
        cin>>p.first>>p.second;
        v.push_back(p);

    }
    sort(v.begin(),v.end());
    for(int i=0;i<n-1;i++)
    {
        if(v[i+1].second<v[i].second)
            flag=1;
    }
    if(flag==1)
        cout<<"Happy Alex"<<endl;
    else
    {
        cout<<"Poor Alex"<<endl;
    }
    
}