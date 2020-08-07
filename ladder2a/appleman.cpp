#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int flag=0;
    char arr[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int c=0;
            if(i>=1)
                if(arr[i-1][j]=='o')
                    c++;
            if(j>=1)
                if(arr[i][j-1]=='o')
                    c++;
            if(i<n-1)
                if(arr[i+1][j]=='o')
                    c++;
            if(j<n-1)
                if(arr[i][j+1]=='o')
                    c++;
            if(c%2==1)
                flag=1;
        }
    }
    if(flag==1)
        cout<<"NO";
    else
    {
        cout<<"YES";
    }
    
    

}