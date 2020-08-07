#include <bits/stdc++.h>
using namespace std;
int main()
{
    int p,q,l,r;
    int ans=0;
    cin>>p>>q>>l>>r;
    set <pair<int, int>> pvec;
    set <pair<int, int>> qvec;
    set <pair<int, int>> neg_pvec;
    set <pair<int, int>> neg_qvec;
    for(int i=0;i<p;i++)
    {
        pair <int, int> temp;
        cin>>temp.first>>temp.second;
        pvec.insert(temp);
        temp.first=(-1)*temp.first;
        temp.second=(-1)*temp.second;
        neg_pvec.insert(temp);
    }
    for(int i=0;i<q;i++)
    {
        pair <int, int> temp;
        cin>>temp.first>>temp.second;
        qvec.insert(temp);
        temp.first=(-1)*temp.first;
        temp.second=(-1)*temp.second;
        neg_qvec.insert(temp);
    }
    for(int i=l;i<=r;i++)
    {
        int flag=0;
        for(auto j=qvec.begin();j!=qvec.end();j++)
        {
            pair <int, int> temp;
            temp.first=(*j).first+i;
            temp.second=(*j).second+i;
            auto it=pvec.upper_bound(temp);
            if(it!=pvec.end())
            {


                if(temp.second>=(*it).first)
                {
/*                cout<<temp.first<<" "<<temp.second<<endl;
                cout<<(*it).first<<" "<<(*it).second<<endl;
                cout<<1<<endl;
*/

                    flag=1;
                }
            }
            else
            {
                it--;
                if(temp.first<=(*it).second)
                {
/*                cout<<temp.first<<" "<<temp.second<<endl;
                cout<<(*it).first<<" "<<(*it).second<<endl;
                        
                    cout<<2<<endl;
                    */
                    flag=1;
                }
            }
            if(flag)
                break;
        }
        for(auto j=neg_qvec.begin();j!=neg_qvec.end();j++)
        {
            pair <int, int> temp;
            temp.first=((*j).first)-i;
            temp.second=((*j).second)-i;
            auto it=neg_pvec.lower_bound(temp);
            temp.first=(-1)*((*j).first)+i;
            temp.second=(-1)*((*j).second)+i;
            pair <int ,int > j_;
            j_.first=(-1)*((*it).first);
            j_.second=(-1)*((*it).second);
            if(it!=neg_pvec.end())
            {

                if(temp.first<=j_.second)
                {
/*                cout<<temp.first<<" "<<temp.second<<endl;
                cout<<(j_).first<<" "<<(j_).second<<endl;
                cout<<3<<endl;
*/

                    flag=1;
                }    
            }
            else
            {
                it--;
                j_.first=(-1)*((*it).first);
                j_.second=(-1)*((*it).second);
                if(temp.second>=j_.first)
                {
                    /*cout<<temp.first<<" "<<temp.second<<endl;
                    cout<<(j_).first<<" "<<(j_).second<<endl;
                    cout<<4<<endl;
                    */
                    flag=1;
                }
            }
            if(flag)
                break;
        }
            
        if(flag)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}