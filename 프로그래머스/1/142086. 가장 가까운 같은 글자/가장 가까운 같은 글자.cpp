#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char,int> alpha;
    for(int i=0;i<s.size();i++){
        auto iter=alpha.find(s[i]);
        if(iter==alpha.end()){
            answer.push_back(-1);
            alpha[s[i]]=i;
        }
        else{
            answer.push_back(i-alpha[s[i]]);
            alpha[s[i]]=i;
        }
    }
    
    return answer;
}