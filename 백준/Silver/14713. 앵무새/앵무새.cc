#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
queue<string> word[100];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    map<string,int> sentense;
    cin>>N;
    cin.ignore();
    string temp;
    for(int i=0;i<N;i++){
        getline(cin,temp);
        int start=0;
        for(int j=0;j<temp.size();j++){
            if(j==temp.size()-1){
                word[i].push(temp.substr(start));
            }
            if(temp[j]==' '){
                word[i].push(temp.substr(start,j-start));
                start=j+1;
            }
        }
    }
    for(int i=0;i<N;i++){
        sentense[word[i].front()]=i;
        word[i].pop();
    }
    getline(cin,temp);
    int start=0;
    for(int j=0;j<temp.size();j++){
        if(temp[j]==' '||j==temp.size()-1){
            map<string, int>::iterator iter;
            if(temp[j]==' ')
                iter=sentense.find(temp.substr(start,j-start));
            else
                iter=sentense.find(temp.substr(start));
            if(iter==sentense.end()){
                cout<<"Impossible";
                return 0;
            }
            else{
                int next_num=iter->second;
                sentense.erase(iter);
                if(!word[next_num].empty()){
                    sentense[word[next_num].front()]=next_num;
                    word[next_num].pop();
                }
            }
            start=j+1;
        }
    }
    for(int i=0;i<N;i++){
        if(!word[i].empty()){
            cout<<"Impossible";
            return 0;
        }
    }
    if(!sentense.empty()){
        cout<<"Impossible";
        return 0;
    }
    cout<<"Possible";
    return 0;
}