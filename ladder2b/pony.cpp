#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[2*n];
    int c_arr[2*n];
    int c=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        arr[i+n]=arr[i];
    }
    for(int i=0;i<2*n-1;i++)
        if(arr[i]>arr[i+1])
            c_arr[c++]=i;
    if(c>2)
        cout<<-1<<endl;
    else if(c==2)
    {
        if(c_arr[1]-c_arr[0]==n)
            cout<<n-c_arr[0]-1<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    
}