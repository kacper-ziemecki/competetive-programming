#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 


void solve(vector<int> prime){
  ll n,m,a;
  cin >> n >> m;
  ll jeden=0,dwa=0;
  ll poczotek;
  bool flag = true;
  vector<int> lista(n, 0);
  for(ll i = 0; i < n; i++){
    cin >> a;
    lista[i] = a;
    if(i == 0){
      poczotek = a;
    }
    else if(a != poczotek){
      flag =false;
    }
    if(a&1){
      dwa++;
    }
    else{
      jeden++;
    }
  }
  if(flag){
    cout << 0 << endl;
  }
  else if(dwa == 0 || jeden == 0){
    cout << 1 << endl << 2 << endl;
  }
  else{
    for(auto el : prime){
      if(el > m) break;
      bool flaga = true;
      for(int j = 0; j < n; j++){
        if(lista[j] % el == 0){
          flaga = false;
          break;
        }
      }
      if(flaga){
        cout << 1 << endl << el << endl;
        return;
      }
    }
    cout << 2 << endl << 2 << " " << 3 << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);

  vector<bool> arr(1e6+5, true);
  vector<int> prime;
  for(int i = 2; i <= 1e6; i++){
    if(arr[i]){
      prime.push_back(i);
      for(int j = i*2; j <= 1e6; j+=i){
        arr[j] = false;
      }
    }
  }

  ll t;
  cin >> t;
  while(t--) solve(prime);
}