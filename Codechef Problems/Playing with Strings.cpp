#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
	int n;
  cin >> n;
  string text1,text2;
  cin >> text1 >> text2;
  sort(text1.begin(), text1.end());
  sort(text2.begin(), text2.end());
  if(text1 != text2){
    cout << "NO\n";
  }
  else{
    cout << "YES\n";
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