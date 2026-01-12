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
  // cin >> wejscie;
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
  // cin >> a;
  // 0 1 2 3 4 5 6 7 ... a.size()-1
  for(int i = 0; i < a.size();i++){
    // cout << a[];
  }
  // programowanie
  // pormwne

  int t;
  // cin >> t;
  for(int i = 0; i < t; i++){
    //rozwiozanie pojedynczego testu
    
  }

  // konwerowanie liczby na string

  string napis = "244666668888888";
  napis += 10; // nie mozna zrobic
  napis += "10";
  for(int i = 1; i < n; i++){
    for(int j = 0; j < i; i++){
      napis += to_string(i+1);
    }
  }

  // konwertowanie string na liczbe
  // stoi(...)
  // stoll(...)


  vector<int> lista;
  //tworzymy pustego wektor/pusta lista
  vector<int> lista1 = {1,2,3,4,5,6,7,564,234,623,34,46,234,53,...};
  //tworzy zmienna o typie wektor/liste z juz przypisanymi wartosciami
  vector<int> lista2(5, 1); // = {1,1,1,1,1};
  //tworzy zmiena o typie wektor/liste z piecioma jedynkami
  //pozycje w wektorze {0,1,2,3,4}
  cout << lista1[0] << endl; // wyswietlamy co znajduje sie na pozycji 0 w lista1
  cout << lista1[2] << endl; // wyswietlamy co znajduje sie na pozycji 2 w lista1

  // lista1.size() = rowna sie wielkosci wektora zmiennej lista1
  // 0,1,2,...,lista1.size()-1
  for(int i = 0; i < lista1.size(); i++){
    cout << lista1[i] << endl;
  }

  //zadko w trudnych zadaniach wczytujemy pojedyncze inty, przewaznie listy 
  n
  a1 a2 a3 a4 ... an

  int n;
  cin >> n;
  vector<int> lista(n,0);
  for(int i = 0; i < n; i++){
    cin >> lista[i];
  }

  5
  4 3 0 1 2
  // sortowanie
  0 1 2 3 4
  sort(lista.begin(), lista.end()); // sortuje rosnoco
  4 3 2 1 0
  sort(lista.begin(), lista.end()); // sortuje rosnoco
  reverse(lista.begin(), lista.end()); // odwracamy
  // teraz lista jest posortowana malejaco

  // https://www.codechef.com/problems/BALLOONS

  int n, suma = 0;
  cin >> n;
  vector<int> lista(n,0);
  for(int i = 0; i < n; i++){
    cin >> lista[i];
  }
  for(int i = 0; i < n; i++){
    suma += (i+1)*lista[i];
  }
  cout << suma << endl;
}
