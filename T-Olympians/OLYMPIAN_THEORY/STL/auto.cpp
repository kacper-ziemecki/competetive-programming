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


int main()
{
  //mowimy c++, ze zmienna liczba jest typem int
  int liczba = 5;

  //czasami typy sa bardzo dlugie
  map<int, vector<pair<string,string>>> konwerter = {...};

  //zamiast takiego dlugiego napisu deklaracji typu
  auto konwerter = {...};

  //nie mozna tego ustawiac bez podpowiedzi
  auto konwerter; //zle
  
  // auto -> automatycznie
}