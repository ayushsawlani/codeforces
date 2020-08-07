#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,d;
    cin>>n>>d;
    int sum=(-1)*d;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        sum+=temp;
    }
    sum+=((n-1)*10);
    if(sum>0)
        cout<<-1;
    else
    {
        cout<<((-1)*sum)/5+(n-1)*2;
    }
    

}