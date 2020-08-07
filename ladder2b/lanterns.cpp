#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    double l;
    cin>>n>>l;
    if(n>1)
    {
        double arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        double max=(arr[1]-arr[0])/2.0;
        for(int i=1;i<n-1;i++)
            if(max<(arr[i+1]-arr[i])/2.0)
                max=(arr[i+1]-arr[i])/2.0;
        if(arr[0]!=0)
            if(max<arr[0])
                max=arr[0];
        if(arr[n-1]!=l)
            if(max<l-arr[n-1])
                max=l-arr[n-1];
        printf("%f\n",max);
    }
    else
    {
        double temp;
        cin>>temp;
        printf("%f\n",max(temp,l-temp));
    }
    
}