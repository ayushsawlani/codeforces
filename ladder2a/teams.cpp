#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[]={0,0,0,0,0,0};
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        arr[temp]++;
    }
    int m=5-k;
    int sum=0;
    for(int i=0;i<=m;i++)
    {
        sum+=arr[i];
    }
    cout<<sum/3;
}