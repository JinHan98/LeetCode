#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,K;
bool isvisit[100001];
void BFS(int n);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>K;
    if(N==K){
        cout<<0;
        return 0;
    }
    if(N*2==K){
        cout<<0;
        return 0;
    }
    BFS(N);
}
void BFS(int n){
    queue<pair<int,int> > k;
    isvisit[n]=true;
    pair<int,int> temp;
    k.push({n,0});
    while (!k.empty())
    {
        temp=k.front();
        if(temp.first-1>=0&&!isvisit[temp.first-1]){
            isvisit[temp.first-1]=true;
            if(temp.first-1==K){
                cout<<temp.second+1;
                return ;
            }
            k.push({temp.first-1,temp.second+1});
        }
        if(temp.first+1<=100000&&!isvisit[temp.first+1]){
            isvisit[temp.first+1]=true;
            if(temp.first+1==K){
                cout<<temp.second+1;
                return ;
            }
            k.push({temp.first+1,temp.second+1});
        }
        k.pop();
        pair<int,int> tmp=temp;
        tmp.first*=2;
        while (tmp.first<=100000)
        {
            if(!isvisit[tmp.first]){
                isvisit[tmp.first]=true;
                if(tmp.first==K){
                    cout<<tmp.second;
                    return ;
                }
                if(tmp.first-1>=0&&!isvisit[tmp.first-1]){
                    if(tmp.first-1==K){
                        cout<<tmp.second+1;
                        return ;
                    }
                    k.push({tmp.first-1,tmp.second+1});
                }
                if(tmp.first+1<=100000&&!isvisit[tmp.first+1]){
                    if(tmp.first+1==K){
                        cout<<tmp.second+1;
                        return ;
                    }
                    k.push({tmp.first+1,tmp.second+1});
                }
            }
            if(tmp.first==0)
                break;
            tmp.first*=2;
        }
        
    }
    

}