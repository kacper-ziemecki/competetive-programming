#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

bool check(char a, char b, char c, char d){
  vector<char> lista = {a,b,c,d};
  sort(lista.begin(), lista.end());
  vector<char> wzor = {'a', 'c', 'e', 'f'};
  for(ll i = 0; i < 4; i++){
    if(lista[i] != wzor[i]) return false;
  }
  return true;
}

void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<string> list(n, "");
  for(auto &el : list) cin >> el;
  ll res = 0;
  for(ll i = 0; i+1 < n; i++){
    for(ll j = 0; j+1 < m; j++){
      res += check(list[i][j], list[i+1][j], list[i][j+1], list[i+1][j+1]);
    }
  }
  cout << res << endl;
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

  solve();
}