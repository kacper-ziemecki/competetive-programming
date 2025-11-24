#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

bool test(unordered_map<ll, bool> mapa, ll x){
  for(auto jeden : mapa){
    for(auto dwa : mapa){
      if((jeden.first | x) != (dwa.first | x)){
        return true;
      }
    }
  }
  return false;
}

void solve(){
  ll n,x,a;
  cin >> n >> x;
  unordered_map<ll, bool> mapa;
  for(ll i = 0; i < n; i++){
    cin >> a;
    mapa[a] = true;
  }
  int res = 0;
  for(auto jeden : mapa){
    for(auto dwa : mapa){
      if(jeden.first!=dwa.first){
        int temp1 = jeden.first ^ dwa.first;
        int temp2 = 0;
        int cnt = -1;
        for(int i = 0; i <= 30; i++){
          if((temp1 >> i)&1){
            cnt++;
          }
        }
        for(int i = 30; i >= 0; i--){
          if(temp2 + (1 << i) <= x){
            if(((temp1 >> i)&1) && cnt > 0){
              cnt--;
              temp2 += (1 << i);
            }
            if(!((temp1 >> i)&1)){
              temp2 += (1 << i);
            }
          }
        }
        res = max(res, temp2);
      }
    }
  }
  cout << res << endl;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}