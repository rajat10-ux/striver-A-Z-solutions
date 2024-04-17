vector<int> diagonal(Node *root)
{
   // your code here
   vector<int>ans;
   if(root==NULL){
       return {};
   }
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
       Node*frontdata=q.front();q.pop();
       while(frontdata!=NULL){
           ans.push_back(frontdata->data);
           if(frontdata->left){
               q.push(frontdata->left);
           }
           frontdata=frontdata->right;
       }
   }
   return ans;
}
