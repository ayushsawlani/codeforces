#include <bits/stdc++.h>
using namespace std;
long long int nc2(long long int a)
{
    if(a>=2)
        return (a*(a-1))/2;
    else
    {
        return 0;
    }
    
}
int main()
{
    long long int n,m;
    cin>>n>>m;
    long long int max=nc2(n-m+1);
    long long int min=(m-n%m)*nc2(n/m)+n%m*nc2(n/m+1);
    cout<<min<<" "<<max<<endl;
}