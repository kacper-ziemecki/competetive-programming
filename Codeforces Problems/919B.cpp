#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double

bool test(ull k){
  ll suma = 0;
  while(k){
    suma += k%10;
    k /= 10;
  }
  if(suma != 10) return false;
  return true;
}

void solve()
{
  ll n;
  cin >> n;
  ull temp = 19;
  for(ll i = 0; i < n-1; i++){
    temp += 9;
    while(!test(temp)){
      temp+=9;
    }
  }
  cout << temp << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  solve();
}