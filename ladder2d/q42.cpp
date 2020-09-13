#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define pb push_back
#define mod 1000000007
#define inarr(i,arr,n); for(ll i=0;i<n;i++) cin >> arr[i];
#define outarr(i,arr,n); for(ll i=0;i<n;i++) cout<<arr[i]<<' ';
#define swap(a,b,t) {t=a;a=b;b=t;}
#define ve vector
#define sz(a) (int)((a).size())
#define fi first
#define se second
#define pa pair
#define fastio  {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define ll long long int
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
int main()
{
    //fastio
    ld a,b,m,vx,vy,vz;
    cin>>a>>b>>m>>vx>>vy>>vz;
    vy=(abs(vy));
    ld t=(m/abs(vy));
    ld phase1=0;
    if(vz>0)
        phase1=t-((2*b)/vz)*floor(t/((2*b)/vz));
    ld ansz;
    ld ansx;
    if(phase1/((b)/vz)<1)
        ansz=phase1*vz;
    else
    {
        ansz=b-(phase1-(b/vz))*vz ;
    }
    if((a/2+t*vx>=0)&&(a/2+t*vx<=a))
        ansx=a/2+t*vx;
    else
    {
        ll sign=vx/abs(vx);
        vx=abs(vx);
        t=t-a/(2*vx);
        ld phase1=t-((2*a)/vx)*floor(t/((2*a)/vx));
        if(phase1/((a)/vx)<1)
           ansx=phase1*vx;
        else
        {
           ansx=a-(phase1-(a/vx))*vx ;
        }
        if(sign>0)
            ansx=a-ansx;
    }
    cout << fixed << setprecision(9) << ansx <<" "<<ansz<<endl;

}