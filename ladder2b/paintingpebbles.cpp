#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int min=1;
    int arr[n],arr2[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        arr2[i]=arr[i];
    }
    sort(arr, arr+n);
    if(arr[n-1]-arr[0]>k)
        cout<<"NO"<<endl;
    else 
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            int x=1;
            for(int j=0;j<=arr[0];j++)
            {
                if(j>=arr2[i])
                    break;
                cout<<1<<" ";
            }
            for(int j=0;j<arr2[i]-arr[0]-1;j++)
            {
                cout<<j+2<<" ";
            }
            cout<<endl;//hello
        }
    }
}