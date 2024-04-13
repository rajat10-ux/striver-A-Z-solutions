#include <iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
  public:
	int data;
	Node* left;
	Node* right;


	Node(int val) {
	  this->data = val;
	  this->left = NULL;
	  this->right = NULL;
	}
};

Node* createTree() {
  cout << "Enter the value for Node : " ;
  int value;
  cin >> value;

  if(value == -1) {
	return NULL;
  }

  //create Node;
  Node* root = new Node(value);
  cout << "Entering in left of: "<< value << endl;
  root->left = createTree() ;
  cout << "Entering in right of: "<< value << endl;
  root->right = createTree();
  return root;
}

void preOrder(Node* root) {
  if(root == NULL) 
	return;

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right); 
}

void inOrder(Node* root) {
  if(root == NULL) 
	return;   
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right); 
}

void postOrder(Node* root) {
  if(root == NULL) 
	return;
	postOrder(root->left);
	postOrder(root->right); 
	cout << root->data << " ";
}

void levelOrderTraversal(Node* root) {
  queue<Node*> q;
  q.push(root);
  q.push(NULL);
  cout << endl;
  while(!q.empty()) {
	Node* temp = q.front();
	q.pop();

	if(temp == NULL) {
	  cout << endl;
	  if(!q.empty()) {
		q.push(NULL);
	  }
	}
	else {
	  cout << temp->data << " ";
	  if(temp->left != NULL) {
		q.push(temp->left);
	  }
	  if(temp->right != NULL) {
		q.push(temp->right);
	  }
	}


  }
}

void printLeftView(Node* root, int level, vector<int>& leftView) {
  if(root == NULL) 
	return;

  if(level == leftView.size()) {
	//iska matlab left view ki node milgyi h , store karlo
	leftView.push_back(root->data);
  }
  printLeftView(root->left, level+1, leftView);
  printLeftView(root->right, level+1, leftView);
}
void printrightview(Node*root,int level,vector<int>&rightview){
  if(root == NULL) 
	return;

  if(level == rightview.size()) {
	//iska matlab left view ki node milgyi h , store karlo
	rightview.push_back(root->data);
  }
    printrightview(root->right, level+1, rightview);
  printrightview(root->left, level+1, rightview);
}
void printTopView(Node* root) {
	map<int,int> hdToNodemap;
	queue< pair<Node* , int> > q;
	q.push(make_pair(root, 0));
	while(!q.empty()) {
		pair<Node* ,int> temp = q.front();
		q.pop();
		Node* frontNode = temp.first;
		int hd = temp.second;
		//if there is no entry for hd in map, then create a new entry
		if(hdToNodemap.find(hd) == hdToNodemap.end()) {
			hdToNodemap[hd] = frontNode->data;
		}
		//child ko dekhna h 
		if(frontNode->left != NULL) {
			q.push(make_pair(frontNode->left, hd-1));
		}
		if(frontNode->right != NULL) {
			q.push(make_pair(frontNode->right, hd+1));
		}
	}
	cout << "printing top view: " << endl;
	for(auto i: hdToNodemap) {
		cout << i.second << " ";
	}
}
void prinBottomView(Node* root) {
	map<int,int> hdToNodemap;
	queue< pair<Node* , int> > q;
	q.push(make_pair(root, 0));
	while(!q.empty()) {
		pair<Node* ,int> temp = q.front();
		q.pop();
		Node* frontNode = temp.first;
		int hd = temp.second;
		//if there is no entry for hd in map, then create a new entry
			hdToNodemap[hd] = frontNode->data;
		//child ko dekhna h 
		if(frontNode->left != NULL) {
			q.push(make_pair(frontNode->left, hd-1));
		}
		if(frontNode->right != NULL) {
			q.push(make_pair(frontNode->right, hd+1));
		}
	}
	cout << "printing bottom view: " << endl;
	for(auto i: hdToNodemap) {
		cout << i.second << " ";
	}
}
void printleftboundary(Node*root){
        if(root==NULL){
                return;
        }
        if(root->left==NULL && root->right==NULL){
                return;
        }
        cout<<root->data<<" ";
        if(root->left!=NULL){
                printleftboundary(root->left);
        }
        else{
                printleftboundary(root->right);
        }
}
void printleafboundary(Node*root){
if(root==NULL){
        return;
}
if(root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
}
printleafboundary(root->left);
printleafboundary(root->right);
}
void printrightboundary(Node*root){
        if(root==NULL){
                return;
        }
        if(root->left==NULL && root->right==NULL){
                return;
        }
        if(root->right!=NULL){
          printrightboundary(root->right);
        }
        else{
                printrightboundary(root->left);
        }
                cout<<root->data<<" ";
}
void boundarytraversal(Node*root){
        if(root==NULL) return;
        cout<<root->data<< " ";
        printleftboundary(root->left);
        printleafboundary(root->left);
        printleafboundary(root->right);
       printrightboundary(root->right);
}
int main(){
        Node*ans=createTree();
        levelOrderTraversal(ans);
        // vector<int>res;
        // cout<<endl<<"left view"<<endl;
        // printLeftView(ans,0,res);
        // for (int  i = 0; i < res.size(); i++)
        // {
        //         cout<<res[i]<<" ";
        // }
        // cout<<endl<<"right view"<<endl;
        // vector<int>right;
        // printrightview(ans,0,right);
        // for (int  i = 0; i < right.size(); i++)
        // {
        //         cout<<right[i]<<" ";
        // }
        // cout<<endl;
        // printTopView(ans);
        // cout<<endl;
        // prinBottomView(ans);
        boundarytraversal(ans);
return 0;
}






