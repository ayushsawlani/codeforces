#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll checker(pair <ld,ld> p1,pair <ld,ld> p2,pair <ld,ld> p3,pair <ld,ld> p4)
{
    ld m12,c12;
    if((p1==p2)&&(p2==p3)&&(p3==p4))
        return 0;
    if(p1.first==p2.first)
    {
        if((p3.first-p1.first)*(p4.first-p1.first)>=0)
        {
            pair <ld,ld> temp=p2;
            p2=p3;
            p3=temp;
        }
    }
    else
    {
        m12=((p1.second)-(p2.second))/((p1.first)-(p2.first));
        c12=p1.second-m12*p1.first;
        if((p3.second-m12*p3.first-c12)*(p4.second-m12*p4.first-c12)>=0)
        {
            pair <ld,ld> temp=p2;
            p2=p3;
            p3=temp;
        }
    }
    if(p1.first==p2.first)
    {
        if((p3.first-p1.first)*(p4.first-p1.first)>=0)
        {
            pair <ld,ld> temp=p2;
            p2=p4;
            p4=temp;
        }
    }
    else
    {
        m12=((p1.second)-(p2.second))/((p1.first)-(p2.first));
        c12=p1.second-m12*p1.first;
        if((p3.second-m12*p3.first-c12)*(p4.second-m12*p4.first-c12)>=0)
        {
            pair <ld,ld> temp=p2;
            p2=p4;
            p4=temp;
        }
    }
    ll flag1=0,flag2=0,flag3=0;
    if(((p1.first+p2.first)==(p3.first+p4.first))&&((p1.second+p2.second)==(p3.second+p4.second)))
    {
        flag1=1;
    }
    if(((p1.first==p2.first)&&(p3.second==p4.second))||((p3.first==p4.first)&&(p1.second==p2.second)))
    {
        flag2=1;
    }
    m12=((p1.second)-(p2.second))/((p1.first)-(p2.first));
    ld m34=((p3.second)-(p4.second))/((p3.first)-(p4.first));
    if(m12*m34==-1)
        flag2=1;
    if(((p1.first)-(p2.first))*((p1.first)-(p2.first))+((p1.second)-(p2.second))*((p1.second)-(p2.second))==((p3.first)-(p4.first))*((p3.first)-(p4.first))+((p3.second)-(p4.second))*((p3.second)-(p4.second)))
        flag3=1;
    if((flag1)&&(flag2)&&(flag3))
        return 1;
    return 0;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll q;
    cin>>q;
    while(q--)
    {
        ll ans=INT64_MAX;
        pair <ld,ld> home[4],pos[4];
        for(ll i=0;i<4;i++)
        {
            cin>>pos[i].first>>pos[i].second>>home[i].first>>home[i].second;
        }
        ld x3,y3;
        ll flag=0;
        x3=home[3].first+home[3].second-pos[3].second;
        y3=pos[3].first-home[3].first+home[3].second;
        for(ll i=0;i<4;i++)
        {
            for(ll j=0;j<4;j++)
            {
                for(ll k=0;k<4;k++)
                {
                    for(ll l=0;l<4;l++)
                    {
                        if(checker(pos[0],pos[1],pos[2],pos[3]))
                        {
                            flag=1;
                            ans=min(ans,i+j+k+l);
                        }
                        x3=home[3].first+home[3].second-pos[3].second;
                        y3=pos[3].first-home[3].first+home[3].second;
                        pos[3].first=x3;
                        pos[3].second=y3;
                    }
                    x3=home[2].first+home[2].second-pos[2].second;
                    y3=pos[2].first-home[2].first+home[2].second;
                    pos[2].first=x3;
                    pos[2].second=y3;                    
                }
                x3=home[1].first+home[1].second-pos[1].second;
                y3=pos[1].first-home[1].first+home[1].second;
                pos[1].first=x3;
                pos[1].second=y3;                
            }
            x3=home[0].first+home[0].second-pos[0].second;
            y3=pos[0].first-home[0].first+home[0].second;
            pos[0].first=x3;
            pos[0].second=y3;
 
        }
        if(flag==1)
            cout<<ans<<endl;
        else
        {
            cout<<-1<<endl;
        }
        
    }
}