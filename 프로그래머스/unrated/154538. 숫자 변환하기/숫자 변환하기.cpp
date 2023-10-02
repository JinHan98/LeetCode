#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    vector<bool> isvisit(y+1);
    queue<pair<int,int> >k;
    k.push({x,0});
    isvisit[x]=true;
    if(x==y)
        return 0;
    while(!k.empty()){
        pair<int,int> temp=k.front();
        k.pop();
        temp.second++;
        if(temp.first+n<=y&&!isvisit[temp.first+n]){
            if(temp.first+n==y)
                return temp.second;
            isvisit[temp.first+n]=true;
            k.push({temp.first+n,temp.second});
        }
        if(temp.first*2<=y&&!isvisit[temp.first*2]){
            if(temp.first*2==y)
                return temp.second;
            isvisit[temp.first*2]=true;
            k.push({temp.first*2,temp.second});
        }
        if(temp.first*3<=y&&!isvisit[temp.first*3]){
            if(temp.first*3==y)
                return temp.second;
            isvisit[temp.first*3]=true;
            k.push({temp.first*3,temp.second});
        }
    }
    return -1;
}