#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

int n = 10;
string napis = "programowanie";
string wejscie;
char literka = 'k';

int main(){
  napis = "t-olympians";
  cout << napis;
  cout << endl;
  cout << napis[0] << endl;
  cout << literka;
  cout << endl;
  cout << ' ';
  cin >> wejscie;
  int dlugosc = wejscie.size();
  for(int i = 0; i < dlugosc; i++){
    cout << wejscie.at(i);
    // cout << wejscie[i];
  }
  cout << endl;
  char tymczasowa_zmienna = wejscie[dlugosc];
  cout << tymczasowa_zmienna << endl;
  // i == dlugosc
  // wejscie[dlugosc]
  // cout << wejscie;
  string a;
  cin >> a;
  // 0 1 2 3 4 5 6 7 ... a.size()-1
  for(int i = 0; i < a.size();i++){
    // cout << a[];
  }
  // programowanie
  // pormwne
}
