//Problem Link: https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/
#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

int main()
{
    fast;
    ll n, k;
    cin >> n >> k;

    multiset<ll> a;
    for(ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.insert(x);
    }

    while(k--) {
        auto it = --a.end();
        ll largest = *it;
        ll new_value = sqrt(largest);
        a.erase(it);
        a.insert(new_value);
    }
    ll total_gifts = 0;
    for(auto it = a.begin(); it != a.end(); it++) {
        total_gifts += *it;
    }

    cout << total_gifts << endl;
    return 0;
}
