#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

int main(){
  // map<typ_klucza, typ_wartosci> nazwa_zmiennej;
  map<string,bool> mp;

  vector<int> mapa(100,0);
  mapa[3]=7;
  vector<vector<int>> mapa1(100,0);
  mapa1[1] = {1,6,3,0,5};
  mapa1[2] = {7,4,6,34,34};

  1 100 1 1 1 100 1000000
  100000->1 100->2 1->4
  vector<int> licznik(100000);
  licznik[1] = 4;
  licznik[100] = 2;
  licznik[1000000] = 1;
  map<int,int> licznik1;
  licznik1[1] = 4;
  licznik1[100] = 2;
  licznik1[1000000] = 1;
  // indeksowanie oraz ustawianie warosci
  // klucz      wartosc
  mp["harry"] = true;

  map<int, int> mapa;
  // klucz mapuje do wartosci
  // {{klucz1 -> wartosc1}, 
  // {klucz2 -> wartosc2}}

  // mapa[klucz1] == wartosc1
  // mapa[klucz2] == wartosc2

  // mapa[klucz1]++;
  // mapa[klucz2] = 1;



  // === TRZY METODY SPRAWDZANIA CZY JAKIŚ KLUCZ WYSTĘPUJE W MAPIE: ===

  //1. count - O(log n)
  if(mp.count("harry") == 1){
    cout << "wystepuje\n";
  } else{
    cout << "nie wystepuje\n";
  }

  //2. find - O(log n)
  if(mp.find("harry") != mp.end()){
    cout << "wystepuje\n";
  } else{
    cout << "nie wystepuje\n";
  }


  //3. indeksowanie - O(log n)
  // W C++ wyrażenie indeksowania mapy, np. mojaMapa[klucz],
  // gdy klucz nie istnieje, automatycznie tworzy nowy element w mapie, 
  // przypisując mu domyślną wartość dla typu wartości 
  // (np. 0 dla int, nullptr dla wskaźników, pusty string dla std::string), 
  // i zwraca referencję do tej właśnie utworzonej, domyślnej wartości, 
  // umożliwiając jej natychmiastową modyfikację.
  if(mp["harry"] == true){
    cout << "wystepuje\n";
  } else{
    cout << "nie wystepuje\n"; 
  }


  // ===================================================================


  // usuwanie erase - O(log n)
  // do metody erase możemy podać jako argument klucz jaki chcemy usunąć
  mp.erase("harry");
  mp["harry"] = true;
  // do metody erase możemy podać iterator wskazujący na klucz jaki chcemy usunąć
  mp.erase(mp.find("harry")); 

  // mapy mają unikatowe klucze
  vector<string> napisy = {"A", "A", "A", "B", "A"};
  map<string, int> mapa2;
  for(int i = 0; i < napisy.size(); i++){
    mapa2[napisy[i]]++;
  }
  for(pair<string, int> el : mapa2){
    cout << el.first << " -> " << el.second << endl;
  }
}
// ZADANIA: 
// 1.https://leetcode.com/problems/two-sum/description/?envType=problem-list-v2&envId=hash-table
// 2.https://leetcode.com/problems/longest-substring-without-repeating-characters/?envType=problem-list-v2&envId=hash-table
// 3.https://codeforces.com/contest/855/problem/A
// 4.https://leetcode.com/problems/isomorphic-strings/description/?envType=problem-list-v2&envId=hash-table


//ROZWIĄZANIA:
// 1) -
// 2)
// vector<string> lista = {"tom","lucius","ginny","harry","ginny","harry"};
// map<string,bool> odwiedzone;
// for(auto napis : lista){
//   if(odwiedzone.count(napis) == 0){
//     cout << "NO\n";
//   } else{
//     cout << "YES\n";
//   }
//   odwiedzone[napis] = true;
// }
