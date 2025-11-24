#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  string text;
  cin >> text;
  vector<bool> list(text.size(), false);
  for(int i = 0; i < text.size(); i++){
    if(text[i] == 'f' || text[i] == 'r' || text[i] == 'i' || text[i] == 'e' || text[i] == 'z' || text[i] == 'a'){
      list[i] = true;
    }
  }
  int cnt = 1;
  for(int i = 1; i < list.size(); i++){
    if(list[i] == list[i-1]){
      cnt++;
    }
    else{
      cout << cnt;
      cnt = 1;
    }
  }
  cout << cnt;
  cout << endl;
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