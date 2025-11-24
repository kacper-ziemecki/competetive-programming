#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve(){
  int n;
  cin >> n;
  if(n < 100){
    cout << "Easy\n";
  }
  else if(n < 200){
    cout << "Medium\n";
  }
  else{
    cout << "Hard\n";
  }
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