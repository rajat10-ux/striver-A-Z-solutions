#include<bits/stdc++.h>
using namespace std;
void interleafe(queue<int>&q){
        queue<int>second;
        int n=q.size();
        for (int  i = 0; i < n/2; i++)
        {
                int temp=q.front();
                second.push(temp);
                q.pop();
        }
        for (int  i = 0; i < n/2; i++)
        {
                int a=second.front();
                second.pop();
                q.push(a);
                a=q.front();
                q.push(a);
                q.pop();
        }
        
}
int main(){
queue<int>q;
q.push(10);
q.push(20);
q.push(30);
q.push(40);
q.push(50);
interleafe(q);
while (!q.empty())
{
        cout<<q.front()<<" ";
        q.pop();
}

return 0;
}