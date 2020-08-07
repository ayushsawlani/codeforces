#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    string arr[n];
    int ans=0;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int flag=0;
            if(arr[i][j]=='W')
            {
                if(i>0)
                {
                    if(arr[i-1][j]=='P')
                       flag=1; 
                }
                else if(i<n-1)
                {
                    if(arr[i+1][j]=='P')
                       flag=1; 
                }
                else if(j>0)
                {
                    if(arr[i][j-1]=='P')
                       flag=1; 
                }
                else if(j<m-1)
                {
                    if(arr[i][j+1]=='P')
                       flag=1; 
                }
            }
            if(flag)
                ans++;
        }
    }
    cout<<ans<<endl;
}