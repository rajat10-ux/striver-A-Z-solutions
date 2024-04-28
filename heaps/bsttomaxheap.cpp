#include<bits/stdc++.h>
using namespace std;
class Node{
        public:
        int data;
        Node*left;
        Node*right;
        Node(int data){
                this->data=data;
                this->left=NULL;
                this->right=NULL;
        }
};
void inorder(Node*root,vector<int>&ans){
        if(root==NULL)return;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
}
void replaceusinginorder(Node*root,vector<int>&ans,int &index){
        if(root==NULL)return;
        replaceusinginorder(root->left,ans,index);
        replaceusinginorder(root->right,ans,index);
        root->data=ans[index];
}
Node*convertbsttoheap(Node*root){
vector<int>ans;
inorder(root,ans);
int index=0;
replaceusinginorder(root,ans,index);
index++;
return root;
}
int main(){
return 0;
}