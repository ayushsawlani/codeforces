#include <bits/stdc++.h>
using namespace std;
int dp[2001][21][21];
int main()
{
   string s;
    cin>>s;
    int m;
    cin>>m;
    for(int i=0;i<1001;i++)
        for(int j=0;j<=10;j++)
            for(int k=0;k<=10;k++)
                dp[i][j][k]=0;
    for(int i=0;i<10;i++)
    {
        if(s[i]=='1')
            dp[1][i+1][i+1]=1;
    }    
    for(int i=1;i<1000;i++)
    {
        for(int j=1;j<11;j++)
        {
            for(int k=1;k<11;k++)
            {
                if(dp[i][j][k])
                {
                    for(int l=1;l<=10;l++)
                    {
                        if((l>j)&&(s[l-1]=='1')&&(l!=k))
                        {
                            dp[i+1][l-j][l]=1;
                        }
                    }
                }
            }
        }
    }
    int m_=m,diff,last,flag=0;
    for(int i=1;i<11;i++)
    {
        for(int j=1;j<11;j++)
        {
            if(dp[m][i][j])
            {
                flag=1;
                diff=i;
                last=j;
                break;
            }
        }
    }
    if(flag==0)
        cout<<"NO"<<endl;
    else
    {
        int x[m];
        cout<<"YES"<<endl;
        while(m>0)
        {
            x[m-1]=last;
            diff=last-diff;
            m=m-1;
            for(int i=1;i<11;i++)
            {
                if((dp[m][diff][i])&&(i!=last))
                {
                    last=i;
                    break;
                }
            }
        }
        for(int i=0;i<m_;i++)
            cout<<x[i]<<" ";
        cout<<endl;
    }
    
    
}