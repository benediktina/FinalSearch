#include <stdio.h>
#include<conio.h>
void mergesort(int arr[], int l, int h);
int main()
{
 int array[100],n,i = 0;
 //clrscr();
 printf("iveskite elementu skaiciu: ");
 scanf("%d",&n);
 printf("\n  elementai: \n");
 for(i = 0 ; i < n ; i++ )
 {
  printf("\tArray[%d] = ",i);
  scanf("%d",&array[i]);
 }
 printf("\nPries Mergesort:");  //Array Before Mergesort
 for(i = 0; i < n; i++)
 {
  printf("%4d", array[i]);
 }
 printf("\n");

 mergesort(array, 0, n - 1);
 printf("\nPo Mergesort:");  //Array After Mergesort
 for(i = 0; i < n; i++)
 {
  printf("%4d", array[i]);
 }
 printf("\n");
 getch();
 //system("pause");
 return 0;
}

void mergesort(int arr[], int l, int h)
{
 int i = 0;
 int length = h - l + 1;
 int pivot  = 0;
 int merge1 = 0;
 int merge2 = 0;
 int temp[100];

 if(l == h)
 return;

 pivot  = (l + h) / 2;

 mergesort(arr, l, pivot);
 mergesort(arr, pivot + 1, h);

 for(i = 0; i < length; i++)
 {
  temp[i] = arr[l + i];
 }
 merge1 = 0;
 merge2 = pivot - l + 1;
 for(i = 0; i < length; i++)
 {
  if(merge2 <= h - l)
  {
   if(merge1 <= pivot - l)
   {
    if(temp[merge1] > temp[merge2])
    {
     arr[i + l] = temp[merge2++];
    }
    else
    {
     arr[i + l] = temp[merge1++];
    }
   }
   else
   {
    arr[i + l] = temp[merge2++];
   }
  }
  else
  {   arr[i + l] = temp[merge1++];
  }
 }
}
