#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
using namespace std;
int N;
vector<pair<char,char> > tree(26);
void preorder(int index,pair<char,char> node);
void inorder(int index,pair<char,char> node);
void postorder(int index,pair<char,char> node);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    char id,l,r;
    for(int i=0;i<N;i++){
        cin>>id>>l>>r;
        tree[id-'A'].first=l;
        tree[id-'A'].second=r;
    }
    preorder(0,tree[0]);
    cout<<'\n';
    inorder(0,tree[0]);
    cout<<'\n';
    postorder(0,tree[0]);
    cout<<'\n';
    return 0;
}
void preorder(int index,pair<char,char> node){
    char ans='A'+index;
    cout<<ans;
    if(node.first!='.'){
        preorder(node.first-'A',tree[node.first-'A']);
    }
    if(node.second!='.'){
        preorder(node.second-'A',tree[node.second-'A']);
    }
    return ;
}
void inorder(int index,pair<char,char> node){
    if(node.first!='.'){
        inorder(node.first-'A',tree[node.first-'A']);
    }
    char ans='A'+index;
    cout<<ans;
    if(node.second!='.'){
        inorder(node.second-'A',tree[node.second-'A']);
    }
    return ;
}
void postorder(int index,pair<char,char> node){
    if(node.first!='.'){
        postorder(node.first-'A',tree[node.first-'A']);
    }
    if(node.second!='.'){
        postorder(node.second-'A',tree[node.second-'A']);
    }
    char ans='A'+index;
    cout<<ans;
    return ;
}