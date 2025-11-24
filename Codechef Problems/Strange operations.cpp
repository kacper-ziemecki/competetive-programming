#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int a,b;
  cin >> a >> b;
  int temp;
  bool sum = true;
  for(int i = 0; i < a; i++){
    cin >> temp;
    if(i == 0){
      sum = temp&1;
      continue;
    }
    sum ^= temp&1;
    sum = !sum;
  }
  if(sum){
    if(b&1){
      cout << "odd\n";
    }
    else{
      cout << "even\n";
    }
  }
  else{
    if(b&1){
      cout << "even\n";
    }
    else{
      cout << "odd\n";
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}