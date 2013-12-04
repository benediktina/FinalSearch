#include <iostream>
#include <stdlib.h>
template <class T> void exch(T &, T &);
template <class T> void compexch(T &, T &);
template <class T> void selection(T *, int, int);
template <class T> void insertion(T *, int, int);
template <class T> void bubble(T *, int, int);
using namespace std;
int main(int argc, char *argv[])
{cout<<"N - masyvo dydis."<<endl<<""<<endl<<"KaDaryt - kokia masyvo sugeneravimo tvarka:"<<endl<<
      "  1 - sutvarkytas masyvas nou maziausio iki didziausio,"<<endl<<
      "  2 - atsitiktinai sugeneruotas masyvass" <<endl<<
      "  3 - sutvarkytas masyvas nou didziausio iki maziausio." <<endl<<""
      <<endl<<
      "Kuris - Kuris algoritmas bus naudojamas:"<<endl<<
      "  1 - isrinkomo algoritmas,"<<endl<<
      "  2 - iterpomo algoritmas,"<<endl<<
      "  3 - Burbulo algoritmas,"<<endl<<
      "  4 - suliejimo (marge) algoritmas"
      <<endl;
      
    int i, N , KaDaryt;
   int kuris;
   cout<<endl<<"N, KaDaryt, kuris"<<endl;
   cin>>N; cin>>KaDaryt; cin>>kuris;
   int *a = new int[N];
    if (KaDaryt==2) // Atsitiktinai sugeneruoja N skaičių intervale: 1,...,1000.
      for (i = 0; i < N; i++)
        a[i] = 1000*(1.0*rand()/RAND_MAX);
      else if (KaDaryt==1) // Atsitiktinai sugeneruoja N skaičių intervale: 1,...,1000.
      for (i = 0; i < N; i++)
        a[i] = i;
      else if (KaDaryt==3) // Atsitiktinai sugeneruoja N skaičių intervale: 1,...,1000.
      for (i = 0; i < N; i++)
        a[i] = N - i;
    else // Savo nuožiūra įvedame skaičius. Norėdami baigti įvedimą, įvedame bet kokį simbolį - ne skaičių.
      { N = 0; while (cin >> a[N]) N++; }
    cout << "Įvestas skaičių masyvas yra:" << endl;
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
    selection(a, 0, N-1);
    cout << "Surūšiuotas skaičių masyvas yra:" << endl;
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
   system("PAUSE");
    return EXIT_SUCCESS;
}
// Sukeičia elementus vietomis
template <class T>
  void exch(T &A, T &B)
    { T t = A ; A = B; B = t; }
// Sukeičia elementus vietomis tik jei patenkinta sąlyga
template <class T>
  void compexch(T &A, T &B)
    { if (B < A) exch(A, B); }
// Išrinkimo algoritmo realizacija
template <class T>
void selection(T a[], int l, int r)
  { for (int i = l; i < r; i++)
      { int min = i;
        for (int j = i+1; j <= r; j++)
            if (a[j] < a[min]) min = j;
        exch(a[i], a[min]);
      }
  }
// Įterpimo algoritmo realizacija
template <class T>
void insertion(T a[], int l, int r)
  { int i;
    for (i = r; i > l; i--) compexch(a[i-1], a[i]);
    for (i = l+2; i <= r; i++)
      { int j = i; T v = a[i];
        while (v < a[j-1])
          { a[j] = a[j-1]; j--; }
        a[j] = v;
      }
  }
// Burbulo algoritmas
template <class T>
void bubble(T a[], int l, int r)
  { for (int i = l; i < r; i++)
      for (int j = r; j > i; j--)
        compexch(a[j-1], a[j]);
  }
