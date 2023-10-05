#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int,int> me;
    map<int,int> bro;
    for(int i=0;i<topping.size();i++){
        auto iter=me.find(topping[i]);
        if(iter!=me.end()){
            me[topping[i]]++;
        }
        else
            me[topping[i]]=1;
    }
    for(int i=0;i<topping.size();i++){
        me[topping[i]]--;
        if(me[topping[i]]==0)
            me.erase(topping[i]);
        auto iter=bro.find(topping[i]);
        if(iter!=bro.end()){
            bro[topping[i]]++;
        }
        else
            bro[topping[i]]=1;
        int temp=me.size()-bro.size();
        if(temp==0)
            answer++;
    }
    return answer;
}