#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  unsigned long long a,b;
  cin >> a >> b;
  unsigned long long one = 0, two = 0;
  unsigned long long temp;
  for(unsigned long long i = 0; i < a; i++){
    cin >> temp;
    if((long long)(temp * 2ll) >= b) one++;
    if((long long)(temp * 10ll) <= b) two++;
  }
  if(b < 10){
    cout << "no\n";
  }
  else if(one == 1 && two == 2){
    cout << "yes\n";
  }
  else{
    cout << "no\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}