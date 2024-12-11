//Problem Link : https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/
#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
    fast;
    int n,k;
    cin>>n>>k;
    int arr[n+5],mx=INT_MIN,ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mx=max(mx,arr[i]);
    }
    vector<int>range(mx+k+5,0);
    for(int i=0;i<n;i++)
    {
        int l = arr[i]-k;
        int r = arr[i]+k+1;
        if(l<0)range[0]++;
        else range[l]++;
        range[r]--;
    }
    for(int i=1;i<=mx+k;i++)
    {
        range[i]+=range[i-1];
        ans=max(range[i],ans);
    }
    cout<<ans<<endl;
    return 0;
}
