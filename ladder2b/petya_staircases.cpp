#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[m];
    for(int i=0;i<m;i++)
        cin>>arr[i];
    sort(arr,arr+m);
    int flag=0;
    if(arr[0]==1)
        flag=1;
    if(arr[m-1]==n)
        flag=1;
    for(int i=0;i<m-2;i++)
    {
        if((arr[i+1]-arr[i]==1)&&(arr[i+2]-arr[i+1]==1))
            flag=1;
        if(flag)
            break;
    }
    if(flag)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
    }
    
}