#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
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
//cout << fixed << setprecision(9);
ll n, m;
bool check(pair <ll,ll> ptr, ve <ve <ll>> &in)
{
    if(ptr.fi<0)
    {
        return false;
    }
    if(ptr.se<0)
        return false;
    if(ptr.fi>n-1)
        return false;
    if(ptr.se>m-1)
        return false;
    if(in[ptr.fi][ptr.se])
        return false;
    return true;
}
int main()
{
    fastio
    
    cin>>n>>m;
    ve <ve <ll>> in(n, ve <ll>(m));
    fr(i, 0, n-1)
    {
        string _t;
        cin>>_t;
        fr(j, 0, m-1)
        {
            in[i][j]=_t[j]-'0';
        }
    }
    ve <ve <bool>> isvalid1(n, ve <bool>(m, true));
    ve <ve <bool>> isvalid2(n, ve <bool>(m, true));
    ve <ve <ll>> left(n, ve <ll> (m, -1));
    ve <ve <ll>> right(n, ve <ll> (m, m));
    ve <ve <ll>> top(n, ve <ll> (m, -1));
    ve <ve <ll>> bottom(n, ve <ll> (m, n));
    ve <ve <ll>> topright(n, ve <ll> (m, -1));
    ve <ve <ll>> topleft(n, ve <ll> (m, -1));
    ve <ve <ll>> bottomright(n, ve <ll> (m, -1));
    ve <ve <ll>> bottomleft(n, ve <ll> (m, -1));
    fr(i, 0, n-1)
    {
        fr(j, 0, m-1)
        {
            left[i][j]=(j>0?left[i][j-1]:-1);
            top[i][j]=(i>0?top[i-1][j]:-1);
            right[i][m-1-j]=(j>0?right[i][m-j]:m);
            bottom[n-1-i][j]=(i>0?bottom[n-i][j]:n);
            if(in[i][j])
            {
                left[i][j]=j;
                top[i][j]=i;
            }
            if(in[i][m-1-j])
            {
                right[i][m-1-j]=m-1-j;
            }
            if(in[n-1-i][j])
            {
                bottom[n-1-i][j]=n-1-i;
            }
        }
    }
    fr(s, 0, n-1)
    {
        ll i=s;
        ll j=0;
        while((i<n)&&(j<m))
        {
            if((i)&&(j))
            {
                topleft[i][j]=topleft[i-1][j-1];
            }
            if(in[i][j])
                topleft[i][j]=i;
            i++;
            j++;
        }
    }
    fr(s, 0, m-1)
    {
        ll i=0;
        ll j=s;
        while((i<n)&&(j<m))
        {
            if((i)&&(j))
            {
                topleft[i][j]=topleft[i-1][j-1];
            }
            if(in[i][j])
                topleft[i][j]=i;
            i++;
            j++;
        }
    }
    fr(s, 0, m-1)
    {
        ll i=n-1;
        ll j=s;
        while((i>=0)&&(j>=0))
        {
            if((i<n-1)&&(j<m-1))
            {
                bottomright[i][j]=bottomright[i+1][j+1];
            }
            if(in[i][j])
                bottomright[i][j]=i;
            i--;
            j--;
        }
    }
    fr(s, 0, n-1)
    {
        ll i=s;
        ll j=m-1;
        while((j>=0)&&(i>=0))
        {
            if((j<m-1)&&(i<m-1))
            {
                bottomright[i][j]=bottomright[i+1][j+1];
            }
            if(in[i][j])
                bottomright[i][j]=i;
            i--;
            j--;
        }
    }
    
    fr(s, 0, n-1)
    {
        ll i=s;
        ll j=m-1;
        while((j>=0)&&(i<n))
        {
            if((j<m-1)&&(i))
            {
                topright[i][j]=topright[i-1][j+1];
            }
            if(in[i][j])
                topright[i][j]=i;
            i++;
            j--;
        }
    }
    fr(s, 0, m-1)
    {
        ll j=s;
        ll i=0;
        while((j>=0)&&(i<n))
        {
            if((j<m-1)&&(i))
            {
                topright[i][j]=topright[i-1][j+1];
            }
            if(in[i][j])
                topright[i][j]=i;
            i++;
            j--;
        }
    }
    fr(s, 0, n-1)
    {
        ll i=s;
        ll j=0;
        while((j<m)&&(i>=0))
        {
            if((j)&&(i<n-1))
            {
                bottomleft[i][j]=bottomleft[i+1][j-1];
            }
            if(in[i][j])
                bottomleft[i][j]=i;
            i--;
            j++;
        }
    }
    fr(s, 0, m-1)
    {
        ll j=s;
        ll i=n-1;
        while((j<m)&&(i>=0))
        {
            if((j)&&(i<n-1))
            {
                bottomleft[i][j]=bottomleft[i+1][j-1];
            }
            if(in[i][j])
                bottomleft[i][j]=i;
            i--;
            j++;
        }
    }
    /*
    fr(i, 0, n-1)
    {
        outarr(j, topleft[i], m);
        cout<<endl;
    }
    cout<<endl;
    fr(i, 0, n-1)
    {
        outarr(j, bottomleft[i], m);
        cout<<endl;
    }
    cout<<endl;
    fr(i, 0, n-1)
    {
        outarr(j, bottomright[i], m);
        cout<<endl;
    }
    cout<<endl;
    fr(i, 0, n-1)
    {
        outarr(j, topright[i], m);
        cout<<endl;
    }
    cout<<endl;
    //*/
    ll ans=0;
    fr(i, 0, n-1)
    {
        fr(j, 0, m-1)
        {
            pair <ll,ll> ptr1(i, j), ptr2(i, j), ptr3(i, j);
            while((check(ptr1, in))&&(check(ptr2, in)))
            {
                ptr1.fi--;
                ptr1.se--;
                ptr2.fi++;
                ptr2.se--;
                if(!((check(ptr1, in))&&(check(ptr2, in))))
                    break;
                if(bottom[ptr1.fi][ptr1.se]>ptr2.fi)
                    ans++;
            }
            ptr1=mk(i, j), ptr2=mk(i, j), ptr3=mk(i, j);
            while((check(ptr1, in))&&(check(ptr2, in)))
            {
                ptr1.fi--;
                ptr1.se--;
                ptr2.fi--;
                ptr2.se++;
                if(!((check(ptr1, in))&&(check(ptr2, in))))
                    break;
                if(right[ptr1.fi][ptr1.se]>ptr2.se)
                    ans++;
            }
            ptr1=mk(i, j), ptr2=mk(i, j), ptr3=mk(i, j);
            while((check(ptr1, in))&&(check(ptr2, in)))
            {
                ptr1.fi--;
                ptr1.se++;
                ptr2.fi++;
                ptr2.se++;
                if(!((check(ptr1, in))&&(check(ptr2, in))))
                    break;
                if(bottom[ptr1.fi][ptr1.se]>ptr2.fi)
                    ans++;
           }
            ptr1=mk(i, j), ptr2=mk(i, j), ptr3=mk(i, j);
            while((check(ptr1, in))&&(check(ptr2, in)))
            {
                ptr1.fi++;
                ptr1.se--;
                ptr2.fi++;
                ptr2.se++;
                if(!((check(ptr1, in))&&(check(ptr2, in))))
                    break;
                if(right[ptr1.fi][ptr1.se]>ptr2.se)
                    ans++;
           }
            ptr1=mk(i, j), ptr2=mk(i, j), ptr3=mk(i, j);
            while((check(ptr1, in))&&(check(ptr2, in)))
            {
                ptr1.fi--;
                ptr2.se++;
                if(!((check(ptr1, in))&&(check(ptr2, in))))
                    break;
                if((topleft[ptr2.fi][ptr2.se]==-1)||(topleft[ptr2.fi][ptr2.se]<ptr1.fi))
                    ans++;
            }
            ptr1=mk(i, j), ptr2=mk(i, j), ptr3=mk(i, j);
            while((check(ptr1, in))&&(check(ptr2, in)))
            {
                ptr1.fi++;
                ptr2.se--;
                if(!((check(ptr1, in))&&(check(ptr2, in))))
                    break;
                 if((topleft[ptr1.fi][ptr1.se]==-1)||(topleft[ptr1.fi][ptr1.se]<ptr2.fi))
                    ans++;
           }
            ptr1=mk(i, j), ptr2=mk(i, j), ptr3=mk(i, j);
            while((check(ptr1, in))&&(check(ptr2, in)))
            {
                ptr1.fi--;
                ptr2.se--;
                if(!((check(ptr1, in))&&(check(ptr2, in))))
                    break;
                if((topright[ptr2.fi][ptr2.se]==-1)||(topright[ptr2.fi][ptr2.se]<ptr1.fi))
                    ans++;
                
           }
            ptr1=mk(i, j), ptr2=mk(i, j), ptr3=mk(i, j);
            while((check(ptr1, in))&&(check(ptr2, in)))
            {
                ptr1.fi++;
                ptr2.se++;
                if(!((check(ptr1, in))&&(check(ptr2, in))))
                    break;
                 if((topright[ptr1.fi][ptr1.se]==-1)||(topright[ptr1.fi][ptr1.se]<ptr2.fi))
                    ans++;
           }
        }
    } 
    cout<<ans<<endl;
    //*/
}