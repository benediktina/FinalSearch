#include <iostream>
#include <stdlib.h>
template <class T> void exch(T &, T &);
template <class T> void compexch(T &, T &);
template <class T> void selection(T *, int, int);
template <class T> void insertion(T *, int, int);
template <class T> void bubble(T *, int, int);
template <class T> void marge(T *, int, int);
using namespace std;
int main(int argc, char *argv[])
{
    //int i, N = atoi(argv[1]), KaDaryt = atoi(argv[2]);
	int i, N , KaDaryt=1;
    int kuris;
    cin>>N; cin>>kuris;
    int *a = new int[N];
	cout<<endl<<"N, kuris"<<endl;

    if (KaDaryt==1) // Atsitiktinai sugeneruoja N skaičių intervale: 1,...,1000.
      for (i = 0; i < N; i++)
        a[i] = 1000*(1.0*rand()/RAND_MAX);
    else // Savo nuožiūra įvedame skaičius. Norėdami baigti įvedimą, įvedame bet kokį simbolį - ne skaičių.
      { N = 0; while (cin >> a[N]) N++; }

    cout << "Įvestas skaičių masyvas yra:" << endl;
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;

	if(kuris == 1)selection(a, 0, N-1);
    else if (kuris == 2) insertion (a, 0, N-1);
    else if (kuris == 3) bubble (a, 0, N-1);
    else marge(a, 0, N-1);

    selection(a, 0, N-1);
    cout << "Surūšiuotas skaičių masyvas yra:" << endl;
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
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
  template <class T>
void marge(T a[], int l, int r)
{
 int i = 0;
 int length = r - l + 1;
 int pivot  = 0;
 int merge1 = 0;
 int merge2 = 0;
 //int temp[100];
 int *temp = new int[r];

 if(l == r)
 return;

 pivot  = (l + r) / 2;

 marge(a, l, pivot);
 marge(a, pivot + 1, r);

 for(i = 0; i < length; i++)
 {
  temp[i] = a[l + i];
 }

 merge1 = 0;
 merge2 = pivot - l + 1;

 for(i = 0; i < length; i++)
 {
  if(merge2 <= r - l)
  {
   if(merge1 <= pivot - l)
   {
    if(temp[merge1] > temp[merge2])
    {
     a[i + l] = temp[merge2++];
    }

    else
    {
     a[i + l] = temp[merge1++];
    }
   }

   else
   {
    a[i + l] = temp[merge2++];
   }
  }

  else
  {
   a[i + l] = temp[merge1++];
  }
 }
}

