#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==key){
            cout<<"found at "<<mid;
            return 0;
        }else if(arr[mid]<key){
            start=mid+1;//checking right

        }else{//arr[mid]>key
             end=mid-1;//checking left
        }
    }
    cout<<"not found";
    return 0;
}