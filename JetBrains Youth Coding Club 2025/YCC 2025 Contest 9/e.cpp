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
  int a,b,c,d,n;
  int idx=0;
  cin >> a >> b >> c >> d >> n;
  vector<int> lista(n);
  for(auto &el : lista) cin >> el;
  vector<string> res(max(b,d), string(a+c, '.'));
  if(!(a&1)){
    //zaczynamy od gory
    for(int i = 0; i < a+c; i++){
      if(!(i&1)){
        for(int j = 0; j < (i < a ? b : d); j++){
          if(lista[idx] == 0) idx++;
          lista[idx]--;
          res[j][i] = 'a'+idx;
        }
      } 
      else{
        for(int j = (i < a ? b : d)-1; j >= 0; j--){
          if(lista[idx] == 0) idx++;
          lista[idx]--;
          res[j][i] = 'a'+idx;
        }
      }
    }
  } else{
    //zaczynamy od dolu
    for(int i = 0; i < a+c; i++){
      if(i&1){
        for(int j = 0; j < (i < a ? b : d); j++){
          if(lista[idx] == 0) idx++;
          lista[idx]--;
          res[j][i] = 'a'+idx;
        }
      } else{
        for(int j = (i < a ? b : d)-1; j >= 0; j--){
          if(lista[idx] == 0) idx++;
          lista[idx]--;
          res[j][i] = 'a'+idx;
        }
      }
    }
  }
  cout << "YES\n";
  for(auto el : res) cout << el << endl;

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