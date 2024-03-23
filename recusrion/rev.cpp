#include<bits/stdc++.h>
using namespace std;
void reverseaa(int*arr,int i,int n){
        if(i>=n/2) return;
        swap(arr[i],arr[n-i-1]);
        reverseaa(arr,i+1,n);        
}
bool ispali(int i,string&st){
        if(i>=st.size()/2) return true;
        if(st[i]!=st[st.size()-i-1])return false;
        return ispali(i+1,st);
}
int fibonnaci(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        return fibonnaci(n-1)+fibonnaci(n-2);
}
int main(){
// int arr[5]={1,2,3,4,5};
// reverseaa(arr,0,5);
// for (int i = 0; i < 5; i++)
// {
//         cout<<arr[i]<<" ";
// }
cout<<fibonnaci(5);
return 0;
}