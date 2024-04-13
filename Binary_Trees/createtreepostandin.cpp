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
Node*createTree(){
        cout<<"enter data"<<endl;
        int data;
        cin>>data;
        if(data==-1){
                return NULL;
        }
        Node*newnode=new Node(data);
        cout<<"left"<<newnode->data<<endl;
        newnode->left=createTree();
        cout<<"right"<<newnode->data<<endl;
        newnode->right=createTree();
        return newnode;
}
void preordertraversal(Node*root){
        if(root==NULL) return;
        cout<<root->data<<" ";
        preordertraversal(root->left);
        preordertraversal(root->right);
}
void postordertraversal(Node*root){
                if(root==NULL) return;
        preordertraversal(root->left);
        preordertraversal(root->right);
        cout<<root->data<<" ";
}
void inorderroottraversal(Node*root){
            if(root==NULL) return;
        preordertraversal(root->left);
           cout<<root->data<<" ";
        preordertraversal(root->right);
}
// void levelordertraverals(Node*root){
//         queue<Node*>q;
//         q.push(root);
//         q.push(NULL);
//         while (q.size()>1)
//         {
//                 Node*frontdata=q.front();
//                 q.pop();
//                 if(frontdata==NULL){
//                         cout<<endl;
//                         q.push(NULL);
//                 }
//                 else{
//                      cout<<frontdata->data<<" "; 
//                 if(frontdata->left!=NULL){
//                         q.push(root->left);
//                 }
//                 if(frontdata->right!=NULL){
//                         q.push(root->right);
//                 }
//           }
//       } 
// }
  int helpersearch(int*arr,int n,int element){
        for (int  i = 0; i < n; i++)
        {
                if(arr[i]==element){
                        return  i;
                }
        }
        return -1;
  }
  void createmapping(int*inorder,int n,map<int,int>&mp){
        for (int  i = 0; i < n; i++)
        {
                mp[inorder[i]]=i;
        }
  }
// Node*createtreepreandin(map<int,int>&mp,int*pre,int*in,int &preindex,int instart,int inend,int n){
//         // base case
//         if(preindex>=n || instart>inend){
//                 return NULL;
//         }
//         int element=pre[preindex];
//         preindex++;
//         Node*root=new Node(element);
//         //int pos=helpersearch(in,n,element);
//        // this map pos tak o(1)
//         int pos=mp[element];
//         root->left=createtreepreandin(mp,pre,in,preindex,instart,pos-1,n);
//         root->right=createtreepreandin(mp,pre,in,preindex,pos+1,inend,n);
//         return root;
// }
Node*createtreepostandin(map<int,int>&mp,int*post,int *in,int &postindex,int instart,int inend,int n){
        if(instart>inend || postindex<0){
                return NULL;
        }
        int element=post[postindex];
        postindex--;
        Node*root=new Node(element);
        int pos=mp[element];
        root->right=createtreepostandin(mp,post,in,postindex,pos+1,inend,n);
        root->left=createtreepostandin(mp,post,in,postindex,instart,pos-1,n);
        return root;
}
int main(){
// Node*root=createTree();
// inorderroottraversal(root);
// int pre[]={2,8,10,6,4,12};
// int in[]={10,8,6,2,4,12};
// int preindex=0;
// int instart=0;
// int inend=5;
// int n=6;
// map<int,int>mp;
// createmapping(in,n,mp);
// Node*ans=createtreepreandin(mp,pre,in,preindex,instart,inend,n);
// preordertraversal(ans);

int in[]={8,14,6,2,10,4};
int post[]={8,6,14,4,10,2};
int instart=0;
int inend=5;
int n=6;
int postindex=5;
map<int,int>mp;
createmapping(in,n,mp);
Node*ans=createtreepostandin(mp,post,in,postindex,instart,inend,n);
preordertraversal(ans);
return 0;
}
