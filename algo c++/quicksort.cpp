#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int partation(int arr[],int start,int end){
      int piv=arr[end];
      int j=start;
      int i=j-1;
      for( j=start;j<end;j++){
          if(arr[j]<piv){
              i++;
              int temp=arr[i];
              arr[i]=arr[j];
              arr[j]=temp;
          }
      }
      int temp1=arr[i+1];
      arr[i+1]=arr[end];
      arr[end]=temp1;
      return i+1;


}
void quickSort(int arr[],int start,int end){
     if(start>=end){
         return;
     }
     int p=partation(arr,start,end);
     quickSort(arr,start,p-1);
     quickSort(arr,p+1,end);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}