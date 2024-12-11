//Problem Link: https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/?envType=daily-question&envId=2024-12-10
#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
bool checkFrq(string s)
{
    int letter[27]={0};
    int check =0 ;
    for(int i=0;i<s.size();i++)
    {
        int x=s[i]-'a';
        if(letter[x]==0)
        {
            letter[x]++;
            check++;
        }
    }
    if(check==1)return true;
    else return false;
}
int main()
{
    fast;
    string s;
    cin>>s;
    map<string,int>mp;
    for(int i=0;i<s.size();i++)
    {
        for(int j=i;j<s.size();j++)
        {
            string temp = s.substr(i,j-i+1);
            //cout<<temp<<endl;
            mp[temp]++;
        }
    }
    int len=-1;
    for(auto it:mp)
    {
        //cout<<it.first<<" "<<it.second<<endl;
        int xx = it.first.size();
        if(xx>len && it.second>=3 && checkFrq(it.first))
            len=xx;
    }
    cout<<len<<endl;
    return 0;
}
