#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int w[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>w[i][j];
    float a[n][n],b[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            a[i][j]=((float)(w[i][j])+(float)(w[j][i]))/2.0;
            b[i][j]=((float)(w[i][j])-(float)(w[j][i]))/2.0;
        }
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                printf("%f ",a[i][j]);
            printf("\n");
        }
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                printf("%f ",b[i][j]);
            printf("\n");
        }

}