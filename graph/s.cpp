#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
public:
unordered_map<T,list<pair<T,T>>>adjlist;
void addedge(T u,T v,T wt,bool direction){
        if(direction==1){
                adjlist[u].push_back(make_pair(v,wt));
        }
        else{
          adjlist[u].push_back(make_pair(v,wt));
           adjlist[v].push_back(make_pair(u,wt));       
        }
}
void printgraph(){
        for(auto i:adjlist){
                cout<<i.first<<"->";
                for(auto j:i.second){
                        cout<<" neigh="<<j.first<<" wt="<<j.second;
                }
                cout<<endl;
        }
}
void bfstraversal(T src,unordered_map<char,bool>&vis){
        queue<T>q;
        q.push(src);
        vis[src]=true;
        while (!q.empty())
        {
          T frontnode=q.front();
          cout<<char(frontnode)<<" ";
          q.pop();
        for(auto nbr:adjlist[frontnode]){
                T nbrdata=nbr.first; 
                if(!vis[nbrdata]){
                        q.push(nbrdata);
                        vis[nbrdata]=true;
                }
        }
     }
}
void dfs(T src,unordered_map<char,bool>&vis){
        vis[src]=true;
        cout<<char(src)<<" ";
        for(auto nbr:adjlist[src]){
                T nbrdata=nbr.first;
                if(!vis[nbrdata]){
                        dfs(nbrdata,vis);
                }
        }
}
};
int main(){
Graph<int> g;
g.addedge('a','b',5,0);
// g.addedge('a','c',5,0);

g.addedge('c','d',5,0);

g.addedge('c','e',50,0);
g.addedge('d','e',50,0);
g.addedge('e','f',50,0);
unordered_map<char ,bool>vis;
for(char node='a';node<='f';node++){
        if(!vis[node]){
               g.dfs(node,vis);
        }
}
return 0;
}