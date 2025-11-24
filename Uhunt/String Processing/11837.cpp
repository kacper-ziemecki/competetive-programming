#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool compare(vector<ll>& one, vector<ll>& two, ll shift){
  ll n = one.size()+1+two.size();
  vector<ll> list(n), pi(n, 0);
  for(ll i = 0; i < two.size(); i++) list[i] = (two[i]+shift)%12;
  list[two.size()] = -1;
  for(ll i = 0; i < one.size(); i++) list[two.size()+i+1] = one[i];
  for(ll i = 1; i < n; i++){
    ll j = pi[i-1];
    while(j > 0 && list[i] != list[j]) j = pi[j-1];
    if(list[i] == list[j]) j++;
    pi[i] = j;
    if(pi[i] == two.size()) return true;
  }
  return false;
}

void solve(ll n, ll m)
{
  string cur;
  vector<string> s(n, " "),t(m, " ");
  vector<ll> one(n, 0), two(m, 0);
  for(auto &el : s) cin >> el;
  for(auto &el : t) cin >> el;
  vector<vector<string>> convert = {{"A"},{"A#","Bb"},{"B","Cb"},{"C","B#"},{"C#","Db"},{"D"},{"D#","Eb"},{"E","Fb"},{"F","E#"},{"F#","Gb"},{"G"},{"G#","Ab"}};
  map<string,ll> mp;
  for(ll i = 0; i < convert.size(); i++){
    for(auto el : convert[i]) mp[el] = i;
  }
  for(ll i = 0; i < n; i++) one[i] = mp[s[i]];
  for(ll i = 0; i < m; i++) two[i] = mp[t[i]];

  for(ll shift = 0; shift < 13; shift++){
    if(compare(one,two,shift)){
      cout << "S\n";
      return;
    }
  }
  cout << "N\n";
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  ll n,m;
  while(cin>>n>>m, n!=0||m!=0) solve(n,m);
}