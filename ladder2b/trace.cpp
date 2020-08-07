#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.1415926536
int main()
{
    ll n;
    cin>>n;
    double a[n+1];
    a[0]=0;
    double sum=0.00;
    for(ll i=1;i<n+1;i++)
        cin>>a[i];
    n++;
    sort(a,a+n);
    for(int i=n-1;i>0;i=i-2)
    {
        sum+=pi*(a[i]*a[i]-a[i-1]*a[i-1]);
    }
    printf("%f\n",sum);
}
