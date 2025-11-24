#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
	int n,a;
  cin >> n;
  unordered_map<int, int> list;
  for(int i = 0; i < n; i++){
    cin >> a;
    list[a]++;
  }
  pair<int,int> maks = {0,0};
  for(auto el : list){
    if(el.second > maks.second){
      maks = el;
    }
  }
  int cnt = 0;
  for(auto el : list){
    if(el.second == maks.second) cnt++;
  }
  if(cnt > 1){
    cout << "CONFUSED\n";
  }
  else{
    cout << maks.first << endl;
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