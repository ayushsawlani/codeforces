#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    cin>>n>>t;
    char arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int p=0;p<t;p++)
    {
        int i=0,j=0;
        while(i<n)
        {
            if(arr[i]=='G')
            {
                j=i;
                while(arr[j]=='G')
                {
                    j++;
                }
                if(i>0)
                {
                    int temp=arr[i];
                    arr[i]=arr[i-1];
                    arr[i-1]=temp;
                }
                i=j;   
            }
            else
            {
                i++;
            }
            
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i];
}