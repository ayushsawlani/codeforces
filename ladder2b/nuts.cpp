#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sum=0;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sum+=arr[0]+1;
    for(int i=1;i<n;i++)
    {
        if(arr[i-1]>arr[i])
        {
            sum+=(arr[i-1]-arr[i]+2);
        }
        else
        {
            sum+=(arr[i]-arr[i-1]+2);
        }
    }
    cout<<sum<<endl;
}