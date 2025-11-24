#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
  ll n,m;
  cin >> n >> m;
  string text;
  cin >> text;
  unordered_map<char, ll> mapa;
  for(auto el : text){
    mapa[el]++;
  }
  string res(m, ' ');
  for(auto el : res){
    char temp;
    bool flag = true;
    for(char a = 'a'; a <= 'z'; a++){
      if(mapa[a] < 1 && flag){
        temp = a;
        flag = false;
      }
    }
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}