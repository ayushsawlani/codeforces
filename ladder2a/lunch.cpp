#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int f[n],t[n];
    int j[n];
    for(int i=0;i<n;i++)
    {
        cin>>f[i]>>t[i];
        if(t[i]>k)
            j[i]=f[i]-t[i]+k;
        else
        {
            j[i]=f[i];
        }
    }
    int max=j[0];
    for(int i=1;i<n;i++)
        if(max<j[i])
            max=j[i];
    cout<<max;
        
    
}