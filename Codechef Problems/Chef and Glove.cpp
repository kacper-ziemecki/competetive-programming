#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
	int n;
  cin >> n;
  vector<int> a(n, 0), b(n, 0);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  bool front=true, back=true;
  for(int i = 0; i < n; i++){
    if(a[i] > b[i]){
      front = false;
    }
    if(a[i] > b[n-i-1]){
      back = false;
    }
  }
  if(front&&back){
    cout << "both\n";
  }
  else if(front){
    cout << "front\n";
  }
  else if(back){
    cout << "back\n";
  }
  else{
    cout << "none\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("input.txt", "r", stdin);
  ll t;
  cin >> t;
  while(t--) solve();
}