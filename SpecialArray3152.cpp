#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
    fast;
    int n,q;
    cin>>n>>q;
    int a[n+5];
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> prefix(n + 1, 0);
    prefix[0] = 1;
    for(int i=1;i<n;i++)
    {
        if(a[i]%2==0 && a[i-1]%2!=0)prefix[i]=1+prefix[i-1];
        else if(a[i]%2!=0 && a[i-1]%2==0)prefix[i]=1+prefix[i-1];
        else prefix[i]=prefix[i-1];
    }
//    for(int i=0;i<n;i++)
//        cout<<prefix[i]<<" ";
//    cout<<endl;
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        if((r-l)==(prefix[r]-prefix[l]))cout<<"true"<<endl;
        else cout<<"False"<<endl;
    }
    return 0;
}
//4
//2
//4 3 1 6
//0 2
//2 3
