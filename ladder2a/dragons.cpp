#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s,n;
    cin>>s>>n;
    int arr[n][2],won[n];
    for(int i=0;i<n;i++)
    {
        won[i]=0;
        cin>>arr[i][0]>>arr[i][1];
    }
    string ans="NO";
    while(1)
    {
        int flag=0;
        int s1=s;
        for(int i=0;i<n;i++)
        {
            if((s>arr[i][0])&&(won[i]==0))
            {
                won[i]=1;
                s1+=arr[i][1];
                flag=1;
            }
            s=s1;
        }
        if(flag==0)
            break;
    }
    int flag=0;
    for(int i=0;i<n;i++)
        if(won[i]==0)
            flag=1;
    if(flag==0)
        ans="YES";
    cout<<ans;
}