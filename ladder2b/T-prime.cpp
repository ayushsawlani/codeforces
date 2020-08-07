#include <bits/stdc++.h>
using namespace std;
int c_arr[1000001];
int main()
{
    int n;
    cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<1000001;i++)
        c_arr[i]=0;
    for(long long int i=2;i<1000001;i++)
    {
        if(c_arr[i]==0)
        {
            for(long long int j=i*i;j<1000001;j=j+i)
                c_arr[j]=1;
        }
    }
    for(int i=0;i<n;i++)
    {
        double x= arr[i];
        x=sqrt(x);
        long long int y=x;
        if(x-y>0.00)
            cout<<"NO"<<endl;
        else if(arr[i]==1)
            cout<<"NO"<<endl;
        else if(c_arr[y]!=1)
            cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
    }
}