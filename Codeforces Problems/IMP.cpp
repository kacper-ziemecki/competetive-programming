#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve(){
  int n,a;
  cin >> n;
  vector<int> lista(n, 0);
  vector<bool> certain(n, true);
  for(int i = 0; i < n; i++){
    cin >> a;
    if(i == 0){
      lista[1] = a;
    }
    else if(i == n-1){
      lista[n-2] = a; 
    }
    else{
      if(lista[i-1] == a){
        certain[i-1] = true;
        if(lista[i-3] == a){
          lista[i-3] = 0;
          certain[i-3] = true;
        }
      }
      if(lista[i-1] != a){
        lista[i+1] = a;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("input.txt", "r", stdin);
  solve();
}