#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
 

int binarne_na_dec(string liczba){
  int wynik = 0;
  int zapasowa = 1;
  for(int i = liczba.size()-1; i >= 0; i--){
    wynik += zapasowa * (liczba[i]-'0');
    zapasowa *= 2;
  }
  return wynik;
}

string dec_na_binarne(int liczba){
  string wynik;
  while(liczba){
    if(liczba%2==1) wynik += '1';
    else wynik += '0';
    liczba /=2;
  }
  reverse(wynik.begin(), wynik.end());
  return wynik;
}


string dec_na_szesnastkowe(int liczba){
  stringstream stream;
  stream << hex << liczba;
  string wynik;
  stream >> wynik;
  return wynik;
}

int szesnastkowe_na_dec(string liczba){
  stringstream stream;
  stream << liczba;
  int wynik;
  stream >> hex >> wynik;
  return wynik;
}

string dec_na_oct(int liczba){
  stringstream stream;
  stream << oct << liczba;
  string wynik;
  stream >> wynik;
  return wynik;
}

int oct_na_dec(string liczba){
  stringstream stream;
  stream << liczba;
  int wynik;
  stream >> oct >> wynik;
  return wynik;
}

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