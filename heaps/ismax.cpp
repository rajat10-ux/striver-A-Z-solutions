#include<bits/stdc++.h>
using namespace std;
pair<int,bool>checkmaxheap(Node*root){
        if(root==NULL){
                pair<int,bool>temp=make_pair(INT_MIN,true);
                return temp;
        }
        if(root->left==NULL && root->right==NULL){
                pair<int,bool>temp=make_pair(root->data,true);
                return temp;
        }
        pair<int,bool>leftans=checkmaxheap(root->left);
        pair<int,bool>rightans=checkmaxheap(root->right);
        if(root->data >leftans.first && root->data >rightans.first 
         && leftans.second && rightans.second){
                pair<int,bool>temp=make_pair(root->data,true);
                return temp;
         }
         else{
                pair<int,bool>temp;
                temp.first=max(root->data,max(leftans.first,rightans.first));
                temp.second=false;
                retrun temp;
         }
}
int main(){
return 0;
}