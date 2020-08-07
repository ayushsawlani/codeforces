#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld double
#define ceil (ll)ceil
#define ll int
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
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
//uncomment for accurate decimal precision.
//not getting AC because setter madarchod hai
ld fast_expo(ld a, ll n)
{
	ld ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=(ans*a);
		a=(a*a);
		n=n/2;
	}
	return ans;
}
ld dp[5001][5001]={0};
ld p[5001]={0};
ll t[5001]={0};
ll n, T;
int main()
{
    fastio
    cout << fixed << setprecision(9);
    cin>>n>>T;
    //n=5000;
    //T=5000;
    fr(i, 0, n-1)
    {
        cin>>p[i]>>t[i];
    //    p[i]=90;
    //    t[i]=5000;
        p[i]=p[i]*0.01;
    
    }
    dp[0][0]=1;
    ld ans=0;
    fr(i, 1, n)
    {
        ld pi=p[i-1];
        ll ti=t[i-1];
        ld val2=fast_expo(1-pi, ti-1);
        ld yess=0;
        fr(j, 0, T)
        {
            if(j>0)
            {
                dp[i][j]=dp[i][j-1]*(1-pi)+dp[i-1][j-1]*pi;
            }
            if(j>=ti)
            {
                ld val=dp[i-1][j-ti]*val2;
                dp[i][j]-=(val*pi);
                dp[i][j]+=(val);
                if(j>ti)
                {
                    dp[i][j]-=(dp[i-1][j-ti-1]*val2*(1-pi));
                }
            }
            if((j>=T-ti)&&(j<T))
            {
                yess=yess*(1-pi)+dp[i-1][j+1];
            }
            //cout<<dp[i][j]<<endl;
        }
        //cout<<ans<<endl;
        ans+=((yess)*(i-1));
    }
    /*
    fr(i, 0, n)
    {
        fr(j, 0, T)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    //*/
    /*
    fr(i, 1, n-1)
    {
        ll ti=t[i];
        ld val=1;
        frn(j, T, T-ti+1)
        {
            ans+=(i*dp[i][j]*val);
            val*=(1-p[i]);
        }
    }
    //*/
    fr(i, n, T)
    {
        ans+=(dp[n][i]*n);
    }
    cout<<ans<<endl;
}