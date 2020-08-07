#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr1[n],arr2[n];
    int c1=0,c2=0;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        if(temp%2==0)
            arr1[c1++]=i+1;
        else
        {
            arr2[c2++]=i+1;
        }
    }
    if(c1==1)
        cout<<arr1[0];
    else
    {
        cout<<arr2[0];
    }
    
}