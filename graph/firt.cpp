#include<bits/stdc++.h>
using namespace std;
class Graph{
public:
unordered_map<int,list<int>>adjlist;
void addedge(int u,int v,bool direction){
        //direction 0 undirected 
       // direction 1 directed
       if(direction==1){
        // u->v arraow ahai
        adjlist[u].push_back(v);
       }
       else{
         adjlist[u].push_back(v);
         adjlist[v].push_back(u);
       }
       cout<<endl;
}
void printll(){
        for(auto i:adjlist){
                cout<<i.first<<"->";
                for(auto j:i.second){
                        cout<<j<<",";
                }
                cout<<endl;
        }
}
};
int main(){
Graph g;
g.addedge(0,1,1);
g.addedge(1,2,1);
g.addedge(1,3,1);
g.addedge(2,3,1);
g.printll();
return 0;
}