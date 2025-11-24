//-----------------KACPER ZIEMECKI TEMPLATE (uzywane na kazde zadanie)-----------------//
#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define endl "\n"
#define vi vector<int>
#define pb push_back
#define str string
#define PI 3.1415926535897932384626433832795l
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)


//-------------USUNĄĆ KIEDY WYSYŁA SIĘ PLIK-----------------
// #define TESTING
//----------------------------------------------------------

void solve(){
  int a,b;
  cin >> a >> b;
  cout << b / a << endl;
}

int main(){
  
#ifdef TESTING
freopen("../input.txt", "r", stdin);
freopen("../output.txt", "w", stdout);
#endif
  
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    solve();
  }

#ifdef TESTING
cerr << "\n\nTIME: " << (float(clock())/CLOCKS_PER_SEC) << " seconds.\n" << endl;
#endif
}