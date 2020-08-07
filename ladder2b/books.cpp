#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    cin>>n>>t;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int i=0,j=0,max=0,sum=0;
    while(j<n)
    {
        sum=sum+arr[j];
        j++;
        if(sum>t)
        {
            while(sum>t)
            {
                sum=sum-arr[i];
                i++;
            }
        }
        if(max<j-i)
            max=j-i;
    }
    cout<<max<<endl;
}