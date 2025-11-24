#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve()
{
  ll n,a,b;
  cin >> n >> a >> b;
  map<char, ll> mapa;
  string text(n, 'a');
  for(ll i = 0; i < b-1; i++){
    text[i] = 'a'+i+1;
  }
  ll sizeMap = 0;
  for(ll i = 0; i < a; i++){
    mapa[text[i]]++;
    if(mapa[text[i]] == 1) sizeMap++;
  }
  for(ll i = a; i < n; i++){
    mapa[text[i-a]]--;
    if(mapa[text[i-a]] == 0) sizeMap--;
    if(sizeMap < b){
      for(ll j = 0; j < 26; j++){
        if(mapa['a'+j] == 0){
          mapa['a'+j]++;
          text[i] = 'a'+j;
          sizeMap++;
          break;
        }
      }
    }
  }
  cout << text << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
#endif

  ll t;
  cin >> t;
  while(t--)
  solve();
  
}