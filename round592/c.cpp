#include <bits/stdc++.h>
using namespace std;
#define ll long long
pair <ll,ll> bs(pair <ll,ll> match,ll p,ll w,ll d,ll n)
{
    if(((match.first==0)&&(p%d>0))||((p%d==0)&&(d*n<p)))
        return pair <ll,ll>(-1,-1);
    if((p==w*match.first+d*match.second)&&(match.first+match.second<=n))
        return match;
    else if(p<w*match.first+d*match.second)
    {
        match.first--;   
    }
    else
    {
        ll x=p-w*match.first+d*match.second;
        ll z=x/d;
        if(x%d>0)
            z++;
        match.second+=z;
        if(match.first+match.second>n)
            return (pair <ll,ll>(-1,-1));
    }
}
int main()
{
    ll n,p,w,d;
    cin>>n>>p>>w>>d;
    ll win,draw;
    win=p/w;
//    cout<<p<<w<<p%w<<endl;
    draw=(p%w)/d;
    if((p<d)&&(p>0))
    {
        cout<<-1<<endl;
        return 0;
    }
    ll prev1=-1;
    ll prev2=-1;
    while(1)
    {
        prev2=prev1;
        prev1=win*w+draw*d;
        if(p==win*w+draw*d)
            break;
        else if(p<win*w+draw*d)
        {
            if(win>0)
                win--;
            else if(draw>0)
            {
                draw--;
            }
            else
            {
                cout<<-1<<endl;
                return 0;
            }
        }
        else
        {
            ll x=p-(win*w+draw*d);
            ll z=x/d;
            if(x%d>0)
                z++;
            draw+=z;
            if(win+draw>n)
            {
                cout<<-1<<endl;
                return 0;
            }
        }
        if(w*win+d*draw==prev2)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    if((p==win*w+draw*d)&&(win+draw<=n))
        cout<<win<<" "<<draw<<" "<<n-win-draw<<endl;
    else
    {
        cout<<-1<<endl;
    }
}