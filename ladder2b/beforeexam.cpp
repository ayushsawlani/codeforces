#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll d,sumtime,_sumtime;
    cin>>d>>sumtime;
    _sumtime=sumtime;
    ll arr[d][2];
    for(ll i=0;i<d;i++)
    {
        cin>>arr[i][0];
        cin>>arr[i][1];
        sumtime=sumtime-arr[i][0];
        _sumtime=_sumtime-arr[i][1];
    }
    if((sumtime<0)||(_sumtime>0))
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for(ll i=0;i<d;i++)
        {
            sumtime=sumtime-(arr[i][1]-arr[i][0]);
            if(sumtime>=0)
                cout<<arr[i][1]<<" ";
            else
            {
                cout<<arr[i][0]+sumtime+(arr[i][1]-arr[i][0])<<" ";
                sumtime=0;
            }
        }
        cout<<endl;
    }
}