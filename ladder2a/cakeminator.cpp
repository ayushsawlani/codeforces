#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r,c,ans=0;
    cin>>r>>c;
    char arr[r][c];
    int row[r],col[c];
    for(int i=0;i<r;i++)
        row[i]=0;
    for(int i=0;i<c;i++)
        col[i]=0;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='S')
            {
                row[i]=1;
                col[j]=1;
            }
        }
    }
    
    for(int i=0;i<c;i++)
    {
        if(col[i]==0)
        {
            for(int j=0;j<r;j++)
            {
                if(arr[j][i]=='.')
                {
                    ans++;
                    arr[j][i]='E';
                }
            }
        }
    }
    for(int i=0;i<r;i++)
    {
        if(row[i]==0)
        {
            for(int j=0;j<c;j++)
            {
                if(arr[i][j]=='.')
                {
                    ans++;
                    arr[i][j]='E';
                }
            }
        }
    }
    cout<<ans;
}