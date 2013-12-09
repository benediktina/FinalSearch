#include <iostream>
#include <stdlib.h>
#include <assert.h>
template <class T> void exch(T &, T &);
template <class T> void compexch(T &, T &);
template <class T> void selection(T *, int, int);
template <class T> void insertion(T *, int, int);
template <class T> void bubble(T *, int, int);
template <class T> void heapsort(T *, int);
using namespace std;
int main(int argc, char *argv[])
{
    int i, N = atoi(argv[1]), KaDaryt = atoi(argv[2]);
    int *a = new int[N];
    if (KaDaryt) // Atsitiktinai sugeneruoja N skaičių intervale: 1,...,1000.
      for (i = 0; i < N; i++)
        a[i] = 1000*(1.0*rand()/RAND_MAX);
    else // Savo nuožiūra įvedame skaičius. Norėdami baigti įvedimą, įvedame bet kokį simbolį - ne skaičių.
      { N = 0; while (cin >> a[N]) N++; }
    cout << "Įvestas skaičių masyvas yra:" << endl;
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
    heapsort(a, N-1);
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

//Heapsort algoritmas
void shiftRight(int* arr, int low, int high)
{
    int root = low;
    while ((root*2)+1 <= high)
    {
        int leftChild = (root * 2) + 1;
        int rightChild = leftChild + 1;
        int swapIdx = root;
        /*Check if root is less than left child*/
        if (arr[swapIdx] < arr[leftChild])
        {
            swapIdx = leftChild;
        }
        /*If right child exists check if it is less than current root*/
        if ((rightChild <= high) && (arr[swapIdx] < arr[rightChild]))
        {
            swapIdx = rightChild;
        }
        /*Make the biggest element of root, left and right child the root*/
        if (swapIdx != root)
        {
            int tmp = arr[root];
            arr[root] = arr[swapIdx];
            arr[swapIdx] = tmp;
            /*Keep shifting right and ensure that swapIdx satisfies
            heap property aka left and right child of it is smaller than
            itself*/
            root = swapIdx;
        }
        else
        {
            break;
        }
    }
    return;
}

void heapify(int* arr, int low, int high)
{
    /*Start with middle element. Middle element is chosen in
    such a way that the last element of array is either its
    left child or right child*/
    int midIdx = (high - low -1)/2;
    while (midIdx >= 0)
    {
        shiftRight(arr, midIdx, high);
        --midIdx;
    }
    return;
}

template <class T>
void heapsort(T a[], int l)
{
    assert(a);
    assert(l > 0);
    heapify(a, 0, l-1);
    int high = l - 1;
    while (high > 0)
    {
        int tmp = a[high];
        a[high] = a[0];
        a[0] = tmp;
        --high;
        /*Ensure heap property on remaining elements*/
        shiftRight(a, 0, high);
    }
    return;
}
