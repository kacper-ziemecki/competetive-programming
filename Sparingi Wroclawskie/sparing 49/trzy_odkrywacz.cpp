#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n,k;

bool helper(ll x, ll gracz, ll ruchy_przed, vector<ll> &res){
  // dbg(x,gracz);
  if(x <= 0) return true;
  if(gracz == 0){
    for(ll i = x-1; i >= max(x-k,x-ruchy_przed); i--){
      if(!helper(i,1,x-i,res)){
        res[x] = 1;
        return true;
      }
    }
  } else{
    for(ll i = x-1; i >= x-ruchy_przed; i--){
      if(!helper(i,0,x-i,res)){
        res[x] = 1;
        return true;
      }
    }
  }
  res[x] = 0;
  return false;
}

void solve(){
  for(int i = 2; i < 100; i++){
    for(int j = 1; j < 20; j++){
      k = j;
      vector<ll> res(i+1,-1);
      res[0] = 1; // 1 - wygrywa
      helper(i,0,INT_MAX,res);
      // dbg(i,j);
      // for(auto el : res) cout << el << ' ';
      // cout << endl;
      if(res[i] != 1){
        dbg(i,j);
      }
      // cout << (res[i] == 1 ? "TAK\n" : "NIE\n");
    }
  }
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

  
  solve();
}