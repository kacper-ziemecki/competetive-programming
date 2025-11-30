#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n;
string s;
bool isR=false,isL=false;

void solve(){
  cin >> n >> s;
  for(auto el : s){
    if(el == 'L') isL = true;
    if(el == 'R') isR = true;
  }
  if(!isL && !isR){
    cout << 1 << ' ' << 1 << endl;
  }
  if(isR){
    int poczotek=-1,koniec=-1;
    for(int i = 0; i < n; i++){
      if(s[i] == 'R' && poczotek == -1){
        poczotek = i;
      }
      if(s[i] == 'R') koniec = i;
    }
    if(!(s[koniec+1] == 'L')) koniec++;
    cout << poczotek+1 << ' ' << koniec+1 << endl;
  } else if(isL){
    int poczotek=-1,koniec=-1;
    for(int i = 0; i < n; i++){
      if(s[i] == 'L' && poczotek == -1){
        poczotek = i;
      }
      if(s[i] == 'L') koniec = i;
    }
    if(!(s[poczotek-1] == 'R')) poczotek--;
    cout << koniec+1 << ' ' << poczotek+1 << endl;
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