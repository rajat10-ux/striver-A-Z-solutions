#include<bits/stdc++.h>
using namespace std;
int sume(int n){
        if(n==0) return 0;
        int sum=0;
        return n+sume(n-1);
}
int facte(int n){
        if(n<1) return 1;
        int ans=1;
        return n*facte(n-1);
}
int main(){
cout<<sume(10)<<endl;
cout<<facte(10);
return 0;
}