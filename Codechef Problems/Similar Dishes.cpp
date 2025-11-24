#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  string a,b,c,d,e,f,g,h;
  cin >> a >> b >> c >> d >> e >> f >> g >> h;
  int cnt = 0;
  vector<string> one = {a,b,c,d}, two = {e,f,g,h};
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(one[i] == two[j]) cnt++;
    }
  }
  if(cnt >= 2){
    cout << "similar\n";
  }
  else{
    cout << "dissimilar\n";
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