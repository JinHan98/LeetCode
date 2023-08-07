#include <iostream>
#include <map>
using namespace std;
int N;
map<string,string> change;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    change["@"]="a";
    change["["]="c";
    change["!"]="i";
    change[";"]="j";
    change["^"]="n";
    change["0"]="o";
    change["7"]="t";
    change["\'"]="v";
    change["\\'"]="w";
    cin>>N;
    string sentence;
    for(int i=0;i<N;i++){
        string ans="";
        cin>>sentence;
        int count=0;
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]!='\\'){
                auto iter=change.find(sentence.substr(i,1));
                if(iter!=change.end()){
                    ans.push_back(change[sentence.substr(i,1)][0]);
                    count++;
                }
                else
                    ans.push_back(sentence[i]);
            }
            else{
                if(sentence[i+1]=='\\'){
                    ans.push_back('w');
                    i+=2;
                }
                else{
                    ans.push_back('v');
                    i++;
                }
                count++;
            }
        }
        if(count<(ans.size()+1)/2){
            cout<<ans<<'\n';
        }
        else
            cout<<"I don't understand\n";
    }

}