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

const int maxn = 1e5+1;
int factors[maxn];
int maximum[maxn];
int lista[maxn];

void solve(){
  int n,res=1;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> lista[i];
  for(int i = 0; i < maxn; i++) factors[i] = i; 
  for(int i = 2; i*i < maxn; i++){
    if(factors[i] == i){
      factors[i] = i;
      for(int j = i*i; j < maxn; j+=i){
        if(factors[j] == j) factors[j] = i;
      }
    }
  } 
  for(int i = 0; i < n; i++){
    int el = lista[i];
    int mx = 0;
    int tmp = el;
    while(tmp != 1){
      mx = max(mx, maximum[factors[tmp]]);
      tmp /= factors[tmp];
    }
    mx++;
    res = max(res, mx);
    while(el != 1){
      maximum[factors[el]] = mx;
      el /= factors[el];
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
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  
  solve();
}