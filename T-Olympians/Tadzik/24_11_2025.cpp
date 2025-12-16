#include<bits/stdc++.h>
using namespace std;

int main(){
  // string napis = "sdfajsdlhfdsj;lsdfjsd;lfjsdlk;fjsdl;jsdlkfjsjfjklsadhfkljsdhfljkshfasdjklfhaskldjfhlsakdfhlsakdjhfklsdjhfkljadshfkljasdhflkjahsdfkljsdhflkashflkjsadhfkljsdhfjklsdhfkljsdahflkjsdhflkjsadhfkljsdhfjklsdhfsdlhfsdjfhlsdkjfhsdjklnfsdjfhsd";
  vector<int> lista; // tworzy pusty wektor
  // [32,5,324,23,45,223,34]
  vector<int> lista2(100); // tworzy wektor o 100 elementach, ktore wszystkie sa 0
  // [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
  vector<int> lista3(100, 1);
  // [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
  vector<string> lista_napisow;
  // ["asdfas", "asdfasdf", "hgfdgdfg", "fsdfsd"]
  vector<bool> lista_true_false;
  // [false, false, true, false, true, true]
  vector<vector<int>> lista_list;
  // [[12,4,52,234], [432,234,23452,35,3], [443,4325,23,235,4]]

  lista.push_back(4);
  lista.push_back(6);
  lista.push_back(-1);

  // wczytywanie wektora z input
  for(int i = 0; i < lista.size(); i++){
    cin >> lista[i];
  }

  // wyswietlanie na ekranie
  for(int i = 0; i < lista.size(); i++){
    cout << lista[i] << ' ';
  }
  cout << endl;
  // po co jest indeksowanie?
  string napis = "sdfajsdlhfdsjlsdfjsdlfjsdlkfjsdljssdfkljhadlskfjhsalkfhasdfkjadshflkahdsflkjahsdfkljhsadfklahsfkasjhflkasdhflasdhfdlkfjsjfjklsadhfkljsdhfljkshfasdjklfhaskldjfhlsakdfhlsakdjhfklsdjhfkljadshfkljasdhflkjahsdfkljsdhflkashflkjsadhfkljsdhfjklsdhfkljsdahflkjsdhflkjsadhfkljsdhfjklsdhfsdlhfsdjfhlsdkjfhsdjklnfsdjfhsd";
  // zadanie co jest na 0 pozycji?
  cout << napis[0] << endl;
  // zadanie co jest na 51 pozycji w napisie?
  cout << napis[51] << endl;
  // zadanie jaka ma dlugosc ten napis?
  cout << napis.size() << endl;
  // zadanie sprawdzic czy napis jest pusty?
  cout << napis.empty() << endl;
  // zadanie usunac element z napisu
  napis.erase(napis.begin()+2);
  // zadanie odwrocic napis
  reverse(napis.begin(), napis.end());
  // zadanie posortowac liste
  sort(lista.begin(), lista.end());
  // sort(napis.begin(), napis.end());
  for(int i = 0; i < lista.size(); i++){
    cout << lista[i] << ' ';
  }
  cout << endl;
  cout << napis << endl;
  // zadanie wyswietlic napis jednym cout
  cout << napis << endl;
  // zadanie wyswietlic napis for loopem
  cout << "wyswietlanie napisu za pomoca for loopa:" << endl; 
  for(int i = 0; i < napis.size(); i++){
    cout << napis[i];
  }
  cout << endl;
}