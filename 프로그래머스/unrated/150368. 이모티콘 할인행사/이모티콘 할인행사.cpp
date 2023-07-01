#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
bool make_discount();
vector<int> discount;
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    priority_queue<pair<int,int> > k;
    for(int i=0;i<emoticons.size();i++)
        discount.push_back(10);
    discount[emoticons.size()-1]=0;
    while(1){
        bool op=make_discount();
        if(op==false)
            break;
        pair<int,int> temp={0,0};
        for(int i=0;i<users.size();i++){
            int m_sum=0;
            for(int j=0;j<emoticons.size();j++){
                if(discount[j]>=users[i][0]){
                    m_sum+=((100-discount[j])*emoticons[j]/100);
                }
            }
            if(m_sum>=users[i][1]){
                temp.first++;
            }
            else
                temp.second+=m_sum;
        }
        k.push(temp);
    }
    answer.push_back(k.top().first);
    answer.push_back(k.top().second);
    return answer;
}
bool make_discount(){
    for(int i=discount.size()-1;i>=0;i--){
        if(discount[i]!=40){
            discount[i]+=10;
            break;
        }
        else{
            if(i==0)
                return false;
            discount[i]=10;
        }
    }
    return true;
}