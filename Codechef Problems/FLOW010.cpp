#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve(){
  char a;
  cin >> a;
  if(a == 'B' || a == 'b'){
    cout << "BattleShip\n";
  }
  if(a == 'C' || a == 'c'){
    cout << "Cruiser\n";
  }
  if(a == 'D' || a == 'd'){
    cout << "Destroyer\n";
  }
  if(a == 'F' || a == 'f'){
    cout << "Frigate\n";
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