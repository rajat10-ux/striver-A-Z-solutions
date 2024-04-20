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
Node*insertintoBST(Node*root,int data){
if(root==NULL){
        root=new Node(data);
        return root;
        }
// not node
if(data>root->data){
        root->right=insertintoBST(root->right,data);
}
else{
        root->left=insertintoBST(root->left,data);
}
return root;
}
void createBST(Node*&root){
        cout<<"enter data"<<"\n";
        int data;
        cin>>data;
        while (data!=-1)
        {
                root=insertintoBST(root,data);
                 cout<<"enter data"<<"\n";
                cin>>data;
        }
}
void levelorder(Node*root){
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
                Node*frontnode=q.front();q.pop();
                if(frontnode==NULL){
                        cout<<endl;
                        if(!q.empty()){
                                q.push(NULL);
                        }
                }
                else{
                        cout<<frontnode->data<<" ";
                        if(frontnode->left){
                                q.push(frontnode->left);
                        }
                        if(frontnode->right){
                                q.push(frontnode->right);
                        }
                }
        }
        
}
void preorder(Node*root){
        if(root==NULL) return;
         cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
}
void postorder(Node*root){
        if(root==NULL) return;
        postorder(root->left);
        postorder(root->right);
         cout<<root->data<<" ";    
}
void inorder(Node*root){
                    if(root==NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
}
Node*minans(Node*root){
        if(root==NULL) return NULL;
        Node*temp=root;
        while (temp->left!=NULL)
        {
                temp=temp->left;
        }
        return temp;
}
Node*maxans(Node*root){
        if(root==NULL) return NULL;
              Node*temp=root;
        while (temp->right!=NULL)
        {
                temp=temp->right;
        }
        return temp;
}
bool searchelement(Node*root,int target){
        if(root==NULL) return false;
        if(root->data==target) return true;
        if(target>root->data){
                return searchelement(root->right,target);
        }
        else{
                return searchelement(root->left,target);
        }
        return false;
}
Node*deletebst(Node*root,int target){
        if(root==NULL) return NULL;
        if(target==root->data){
                //now delete karo
                if(root->left==NULL && root->right==NULL){
                        delete root;
                        return NULL;
                }
                //2 nd case
               else if(root->left!=NULL && root->right==NULL){
                        Node*child=root->left;
                        delete root;
                        return child;
                }
                // 3rd case
              else if(root->right!=NULL && root->left==NULL){
                        Node*child=root->right;
                        delete root;
                        return child;
                }
                //4 th case
                else{
                        Node*maximum=maxans(root->left);
                        root->data=maximum->data;
                        root->left=deletebst(root->left,maximum->data);
                        return root;
                }
        }
        else if(root->data>target){
                root->left=deletebst(root->left,target);
        }
        else{
                root->right=deletebst(root->right,target);
        }
        return root;
}
Node*createbstfrominorder(vector<int>&arr,int s,int e){
if(s>e) return NULL;
int mid=s+(e-s)/2;
Node*ans=new Node(arr[mid]);
ans->left=createbstfrominorder(arr,s,mid-1);
ans->right=createbstfrominorder(arr,mid+1,e);
return ans;
}
//conver bst to dll
void bstsll(Node*root,Node*&head){
    if(root==NULL) return;
    bstsll(root->right, head);
    if(head!=NULL)   root->right=head;
    head=root;
    bstsll(root->left, head);
}
void printll(Node*head){
        Node*temp=head;
        while (temp!=NULL)
        {
                cout<<temp->data<<" ";
                temp=temp->right;
        }
        cout<<endl;
}
Node*convertlltobst(Node*&head,int n){
        if(head==NULL) return NULL;
        Node*leftans=convertlltobst(head,n/2);
        Node*root=head;
        root->left=leftans;
        head=head->right;
        Node*rightans=convertlltobst(head,n-n/2-1);
        root->right=rightans;
        return root;
}
int fun(Node*root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 0;
        return 1+fun(root->left)+fun(root->right);
}
int main(){
// Node*root=NULL;
// createBST(root);
// cout<<endl;
// levelorder(root);
cout<<endl;
vector<int>ans={1,2,3,4,5,6,7,8,9};
Node*helper=createbstfrominorder(ans,0,ans.size()-1);
// levelorder(helper);
cout<<fun(helper);
// Node*head=NULL;
// bstsll(helper,head);
// printll(head);
// cout<<endl;
// Node*bst=convertlltobst(head,9);
// levelorder(bst);
// cout<<endl<<"preorder"<<endl;
// preorder(root);
// cout<<endl<<"postorder"<<endl;
// postorder(root);
// Node*minimum=minans(root);
// if(minimum==NULL){
//         cout<<"no minimum";
// }
// else{
//         cout<<endl<<"minimum value="<<minimum->data;
// }
// Node*maximum=maxans(root);
// if(maximum==NULL){
//         cout<<"no maxmum";
// }
// else{
//         cout<<endl<<"maximum value="<<maximum->data;
// }
// int data;
// cout<<endl<<"enter data"<<endl;
// cin>>data;
// if(searchelement(root,data)){
//         cout<<"is present"<<endl;
// }
// else{
// cout<<"not present";
// }
// int data;
// cout<<endl<<"enter data"<<endl;
// cin>>data;
// while (data!=-1)
// {
//         root=deletebst(root,data);
//         cout<<endl<<"printing levwel"<<endl;
//         levelorder(root);
//         cout<<endl<<"enter value"<<endl;
//         cin>>data;
// }
return 0;
}
