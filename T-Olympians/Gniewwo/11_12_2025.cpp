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
  string s;
  cin >> s;
  int n = s.size();
  map<char, vector<int>> mapa;
  vector<bool> res(n, true);
  for(int i = 0; i < n; i++){
    if(s[i] == 'd'){
      res[i] = false;
      for(char litera = 'z'; litera >= 'a'; litera--){
        if(mapa.count(litera)){
          int indeks = mapa[litera].back();
          mapa[litera].erase(mapa[litera].begin()+mapa[litera].size()-1);
          if(mapa[litera].empty()){
            mapa.erase(litera);
          }
          res[indeks] = false;
          break;
        }
      }
    } else{ 
      mapa[s[i]].pb(i); 
    }
  }
  for(int i = 0; i < n; i++){
    if(res[i]) cout << s[i];
  }
  cout << endl;
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