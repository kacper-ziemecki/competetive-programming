#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long



int main()
{

  pair<int,int> zmianna; // {first, second}
  //wczytywanie pary
  cin >> zmienna.first >> zmienna.second;


  vector<pair<int,int>> lista(5);
  //wczytywanie wektora par
  for(int i = 0; i < 5; i++){
    cin >> lista[i].first >> lista[i].second;
  }

  //ZADANKO: https://szkopul.edu.pl/c/mistrz-programowania-2026/p/r1b/
  int n;
  cin >> n;
  vector<pair<int,int>> pary(n);
  int punkty = 0;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    cin >> pary[i].first >> pary[i].second;
    punkty = max(punkty, pary[i].first);
  }
  for(int i = 0; i < n; i++){
    if(pary[i].first == punkty) cnt++;
  }
  if(cnt == 1) cout << "MAKSIMUM\n";
  else cout << "MINIMUM\n";
}