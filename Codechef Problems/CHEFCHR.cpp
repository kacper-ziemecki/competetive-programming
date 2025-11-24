#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  string text;
  cin >> text;
  ll res = 0;
  for(ll i = 0; i+3 < text.size(); i++){
    string temp = text.substr(i, 4);
    sort(temp.begin(), temp.end());
    // cout << temp << endl;
    if(temp == "cefh"){
      res++;
    }
  }
  if(res){
    cout << "lovely " << res << endl;
  }
  else{
    cout << "normal\n";
  }


}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  
  ll t;
  cin >> t;
  while(t--)
  solve();
}