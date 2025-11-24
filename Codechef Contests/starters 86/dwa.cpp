#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve(){
  int n;
  cin >> n;
  string napis;
  cin >> napis;
  int jeden=0, dwa=0;
  for(auto el : napis){
    if(el == '1') jeden++;
    if(el == '0') dwa++;
  }
  if(min(jeden,dwa)&1){
    cout << "Zlatan\n";
  }
  else{
    cout << "Ramos\n";
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