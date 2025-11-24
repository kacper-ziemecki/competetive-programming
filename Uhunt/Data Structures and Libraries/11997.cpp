#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve(ll k)
{
  vector<priority_queue<ll, vector<ll>, greater<ll>>> list(k, priority_queue<ll, vector<ll>, greater<ll>>());
  vector<ll> res(k, 0);
  ll tmp,wynik=0;
  for(ll i = 0; i < k; i++){
    for(ll j = 0; j < k; j++){
      cin >> tmp;
      list[i].push(tmp);
    }
  }
  for(ll i = 0; i < k; i++){
    res[i] = list[i].top();
    list[i].pop();
    wynik += res[i];
  }

  cout << wynik << " ";

  for(ll i = 0; i < k-1; i++){
    pair<ll, ll> tmp = {LONG_LONG_MAX, 0};
    for(ll j = 0; j < k; j++){
      if(tmp.first > list[j].top()-res[j]){
        tmp.first = list[j].top()-res[j];
        tmp.second = j;
      }
    }
    list[tmp.second].pop();
    cout << wynik + tmp.first;
    if(i != k-2) cout << ' ';
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
#endif

  ll k;
  ll t=0;
  while(cin >> k){
    t++;
    if(t > 1) cout << endl;
    solve(k);
  }
  
}