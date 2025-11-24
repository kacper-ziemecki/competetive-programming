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
  int one = INT_MAX, two = INT_MAX, three = INT_MAX;
  for(int i = 0; i < n; i++){
    if(b[i] == 1){
      one = min(one, a[i]);
    }
    else if(b[i] == 2){
      two = min(two, a[i]);
    }
    else{
      three = min(three, a[i]);
    }
  }
  cout << min(one + two, three) << endl;
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