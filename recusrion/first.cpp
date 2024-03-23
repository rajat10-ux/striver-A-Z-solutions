#include<bits/stdc++.h>
using namespace std;
void printn(int n){
  if(n==0) return;
    cout<<n<<" ";
  printn(n-1);
}
int main(){
printn(5);
return 0;
}