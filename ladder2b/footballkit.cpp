#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n][2];
    int c_arr[100001];
    for(int i=0;i<100001;i++)
        c_arr[i]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)//helloworld
            cin>>arr[i][j];
        c_arr[arr[i][0]]++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<n-1+c_arr[arr[i][1]]<<" "<<n-1-c_arr[arr[i][1]]<<endl;
    }


    
}