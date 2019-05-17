#include <stdio.h>

void swap(int* a, int* b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

void BubbleSort(int arr[] , int size)
{
  int i = 0;
  int j = 0;
  int isSort;
  for(i = 0 ; i<size; i++)
  {
    isSort = 0;
    for(j = 0; j < size - 1 - i; j++)
    {

      if(arr[j] > arr[j+1])
      {
        swap(arr+j,arr+j+1);
        isSort = 1;
      }
    
    }
    if(isSort == 0)
      break;

  }
}

void Print(int arr[],int size)
{
  int i;
  for(i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  } 
  printf("\n");
}   
int  main()
{   
  int arr[] = {5,4,3,2,1,7,11,57,34,12};
  int size = sizeof(arr)/sizeof(int);
    
  BubbleSort(arr,size);

  Print(arr,size);
  return 0;
}
