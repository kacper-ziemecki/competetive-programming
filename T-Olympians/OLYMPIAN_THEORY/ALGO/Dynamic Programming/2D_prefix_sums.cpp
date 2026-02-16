#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(){
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  solve();
}


Zadanie: Magiczna tablica

Masz daną prostokątną tablicę liczb całkowitych o rozmiarze N × M.
Następnie dostajesz Q zapytań. W każdym zapytaniu musisz obliczyć sumę elementów w podprostokącie.


📥 Wejście

W pierwszym wierszu:

N M Q

W kolejnych N wierszach:

M liczb – zawartość tablicy


W kolejnych Q wierszach:

x1 y1 x2 y2


co oznacza zapytanie o sumę w prostokącie
od wiersza x1 do x2 i kolumny y1 do y2 (1-indexowane, włącznie).

📤 Wyjście

Dla każdego zapytania wypisz w osobnej linii sumę elementów w podanym prostokącie.

📊 Ograniczenia
1 ≤ N, M ≤ 1000  
1 ≤ Q ≤ 200000  
|A[i][j]| ≤ 1000

      kolumny →
        1   2   3   4
      ┌───┬───┬───┬───┐
 w 1  │ 1 │ 2 │ 3 │ 4 │
 i    ├───┼───┼───┼───┤
 e 2  │ 5 │ 6 │ 7 │ 8 │
 r    ├───┼───┼───┼───┤
 s 3  │ 9 │10 │11 │12 │
      └───┴───┴───┴───┘



x1=1, y1=1, x2=2, y2=2

      1   2   3   4
      ┌───┬───┬───┬───┐
  1   │███│███│ 3 │ 4 │
      ├───┼───┼───┼───┤
  2   │███│███│ 7 │ 8 │
      ├───┼───┼───┼───┤
  3   │ 9 │10 │11 │12 │
      └───┴───┴───┴───┘

x1=2, y1=2, x2=3, y2=4
      1   2   3   4
      ┌───┬───┬───┬───┐
  1   │ 1 │ 2 │ 3 │ 4 │
      ├───┼───┼───┼───┤
  2   │ 5 │███│███│███│
      ├───┼───┼───┼───┤
  3   │ 9 │███│███│███│
      └───┴───┴───┴───┘
vector<vector<int>> lista(n, vector<int>(m, 0));
suma_pref[j-1][x2-1] - (x1-2 < 0 ? 0 : suma_pref[j-1][x1-2]);