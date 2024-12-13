//Problem Link: https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/
#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
    fast;
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<pair<ll,ll>>v2(n);
    for(int i=0;i<n;i++)
    {
        v2[i]={v[i],i};
    }
    sort(v2.begin(),v2.end());
    ll score=0;
    for(int i=0;i<n;i++)
    {
        ll num = v2[i].first;
        ll idx = v2[i].second;
        if(v[idx]!=-1)
        {
            score+=v[idx];
            v[idx]=-1;
            if(idx-1>=0)v[idx-1]=-1;
            if(idx+1<n)v[idx+1]= -1;
        }
    }
    cout<<score<<endl;
    return 0;
}
