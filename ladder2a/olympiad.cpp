#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,c[3];
    c[0]=0;
    c[1]=0;
    c[2]=0;
    cin>>n;
    int arr[3][n];
    for(int i=0;i<3;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=-1;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        arr[temp-1][c[temp-1]++]=i+1;
    }
    int min=n;
    for(int i=0;i<3;i++)
        if(min>c[i])
            min=c[i];
    cout<<min<<endl;
    for(int i=0;i<min;i++)
        cout<<arr[0][i]<<" "<<arr[1][i]<<" "<<arr[2][i]<<endl;
}