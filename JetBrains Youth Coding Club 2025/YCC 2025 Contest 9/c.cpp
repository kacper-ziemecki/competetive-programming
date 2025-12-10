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



void solve(){
  int n,mx=0;
  cin >> n;
  vector<int> lista(n);
  map<int, pair<int,int>> begin_and_end;
  map<int, int> cnt;
  pair<int,int> res = {0, n-1};
  for(auto &el : lista) cin >> el;
  for(int i = 0; i < n; i++){
    if(cnt.count(lista[i]) == 0){
      begin_and_end[lista[i]] = {i,i};
    } else{
      begin_and_end[lista[i]].second = i;
    }
    cnt[lista[i]]++;
    mx = max(mx, cnt[lista[i]]);
  }
  for(auto el : cnt){
    if((el.second == mx) && (begin_and_end[el.first].second-begin_and_end[el.first].first < res.second-res.first)){
      res = {begin_and_end[el.first].first,begin_and_end[el.first].second};
    }
  }
  cout << res.first+1 << ' ' << res.second+1 << endl;
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