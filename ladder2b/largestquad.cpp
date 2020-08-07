#include <bits/stdc++.h>
using namespace std;
#define ll long long
double slope(pair <double,double> p1,pair <double,double> p2)
{
    if((p1.first)==(p2.first))
        return DBL_MAX;
    else
    {
        return (p2.second-p1.second)/(p2.first-p1.first);
    }
    
}
double dist(double m, double c, pair <double,double> p)
{
    if(m==DBL_MAX)
        return c-p.first;
    else
    {
        return ((p.second-m*p.first-c)/(sqrt(1+m*m)));
    }
}
int main()
{
    ll n;
    cin>>n;
    vector <pair <double ,double >> v;
    for(ll i=0;i<n;i++)
    {
        pair <double,double> temp;
        cin>>temp.first>>temp.second;
        v.push_back(temp);
    }
    double x=0;
    for(ll i=0;i<n-1;i++)
    {
        for(ll j=i+1;j<n;j++)
        {
            double m1=-DBL_MAX;
            double m2=DBL_MAX;
            double m;
            double c;
            if(v[i].first!=v[j].first)
            {
                m=slope(v[i],v[j]);
                c=v[i].second-m*v[i].first;
            }
            else
            {
                c=v[i].first;
                m=DBL_MAX;
            }
            
            double dist_btw_points=sqrt((v[i].first-v[j].first)*(v[i].first-v[j].first)+(v[i].second-v[j].second)*(v[i].second-v[j].second));
            for(ll k=0;k<n;k++)
            {
                if((k!=i)&&(k!=j))
                {
                    double dist_from_line=dist(m,c,v[k]);
                    if(dist_from_line>m1)
                        m1=dist_from_line;
                    if(dist_from_line<m2)
                        m2=dist_from_line;
                }
            }
            double area=(m1-m2)*dist_btw_points*(0.5);
            if(area>x)
            x=area;
        }
    }
    printf("%f\n",x);
}