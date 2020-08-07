#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2000][2000];
int main()
{
    //x
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    ll pos_slope_down[n],pos_slope_up[n];
    ll sum=0;
    int i,j;
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<=i;j++)
        {
            sum+=a[n-1-j][n-1-i+j];
        }
        pos_slope_down[i]=sum;
    }
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<=i;j++)
        {
            sum+=a[0+j][0+i-j];
        }
        pos_slope_up[i]=sum;
    }
    ll neg_slope_up[n],neg_slope_down[n];
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<=i;j++)
        {
            sum+=a[0+j][n-1-i+j];
        }
        neg_slope_up[i]=sum;
    }
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<=i;j++)
        {
            sum+=a[n-1-j][0+i-j];
        }
        neg_slope_down[i]=sum;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=((-1)*a[i][j]);
            if(i>=j)
            {
                a[i][j]+=(neg_slope_down[n-1-(i-j)]);
            }
            else
            {
                a[i][j]+=(neg_slope_up[n-1-(j-i)]);
            }
            if(i+j>=n-1)
            {
                a[i][j]+=(pos_slope_down[2*(n-1)-(i+j)]);
            }
            else
            {
                a[i][j]+=(pos_slope_up[(i+j)]);
            }
        }
    }
    pair <int,int>p1(0,0),p2(0,0);
    ll evenmax=-1,oddmax=-1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((i+j)%2)
            {
                if(a[i][j]>oddmax)
                {
                    p1.first=i+1;
                    p1.second=j+1;
                    oddmax=a[i][j];
                }
            }
            else
            {
                if(a[i][j]>evenmax)
                {
                    p2.first=i+1;
                    p2.second=j+1;
                    evenmax=a[i][j];
                }
           }
        }
    }

    cout<<evenmax+oddmax<<endl;
    cout<<p1.first<<" "<<p1.second<<" "<<p2.first<<" "<<p2.second<<endl;
}