#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;



int main(){
    vector<pair<int,int> > container_yet;
    stack<pair<int,int> > container_already;
    stack<pair<int,int> > temp;
    int N;
    int M;
    int answer=0;
    cin>>N>>M;
    vector<int> many(M+1,0);
    pair<int, int> a;
        for(int i=0;i<N;i++){
            cin>>a.first>>a.second;
            many[a.first-1]++;
            container_yet.push_back(a);
        }
    while(!container_yet.empty()){
        if(many[container_yet[0].first]==0){//넣어라
            while(1){
                if(container_already.empty()){
                    answer+=container_yet[0].second;
                    container_already.push(container_yet[0]);
                    container_yet.erase(container_yet.begin());
                    many[container_already.top().first-1]--;
                    while(!temp.empty()){
                        answer+=temp.top().second;
                        container_already.push(temp.top());
                        temp.pop();
                    }
                    break;
                }
                if(container_already.top().second<container_yet[0].second&&container_already.top().first==container_yet[0].first){//못넣으면(앞의 무게 때문에)
                    temp.push(container_already.top());
                    answer+=container_already.top().second;
                    container_already.pop();
                }
                else{//넣을 수 있으면
                    answer+=container_yet[0].second;
                    container_already.push(container_yet[0]);
                    many[container_yet[0].first-1]--;
                    container_yet.erase(container_yet.begin());
                    while(!temp.empty()){
                        answer+=temp.top().second;
                        container_already.push(temp.top());
                        temp.pop();
                    }
                    break;
                }
            }
        }
        else{//뒤로 빼라
            container_yet.push_back(container_yet[0]);
            answer+=container_yet[0].second;
            container_yet.erase(container_yet.begin());
        }
    }
    cout<<answer;
}