#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r,c;
    cin>>r>>c;
    int b[r][c],a[r][c];
    int row[r],col[c];
    for(int i=0;i<r;i++)
        row[i]=0;
    for(int i=0;i<c;i++)
        col[i]=0;
    int boom1=1,boom2=1;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {
            a[i][j]=1;
            cin>>b[i][j];
            if(b[i][j]==0)
            {
                col[j]=1;
                row[i]=1;
            }
        }
    for(int i=0;i<r;i++)
    {
        if(row[i])
        {
            for(int j=0;j<c;j++)
                a[i][j]=0;
            
        }
        else
            boom1=0;
    }
    for(int i=0;i<c;i++)
    {
        if(col[i])
        {
            for(int j=0;j<r;j++)
                a[j][i]=0;
        }
        else
        {
            boom2=0;
        }
        
    }
    int boom=boom1||boom2;
    int flag=0;
    for(int i=0;i<r;i++)
    {    for(int j=0;j<c;j++)
            if(((row[i])&&(col[j]))&&(b[i][j]))
            {
                flag=1;
                break;
            }
        if(flag)
            break;
    }
    if(boom)
    {
        int flag=0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(b[i][j]==1)
                    flag=1;
        if(flag==0)
            boom=0;
    }
    if((flag==0)&&(boom==0))
    {
        cout<<"YES"<<endl;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }
        
    
}