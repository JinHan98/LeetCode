#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int K,N;
string answer;
struct compare
{
    bool operator()(string a, string b){
        for(int i=0;i<min(a.size(),b.size());i++){
            if(a[i]!=b[i])
                return a[i]<b[i];
        }
        if(a.size()>b.size()){
            int a_temp=0;
            int b_temp=b.size();
            for(int i=b.size();i<a.size()*b.size();i++){
                if(a[i-a_temp]!=b[i-b_temp]){
                    return a[i-a_temp]<b[i-b_temp];
                }
                if((i+1)%b.size()==0){
                    b_temp+=b.size();
                }
                if((i+1)%a.size()==0){
                    a_temp+=a.size();
                }
            }
        }
        else if(a.size()<b.size()){
            int a_temp=a.size();
            int b_temp=0;
            for(int i=a.size();i<b.size()*a.size();i++){
                if(a[i-a_temp]!=b[i-b_temp]){
                    return a[i-a_temp]<b[i-b_temp];
                }
                if((i+1)%a.size()==0){
                    a_temp+=a.size();
                }
                if((i+1)%b.size()==0){
                    b_temp+=b.size();
                }
            }
        }
        return a.size()<b.size();
    }
};

priority_queue<string,vector<string>,compare> number;
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string temp;
    string big="";
    cin>>K>>N;
    for(int i=0;i<K;i++){
        cin>>temp;
        number.push(temp);
        if(temp.size()>=big.size()){
            if(temp.size()==big.size()&&temp>big)
                big=temp;
            else if(temp.size()>big.size())
                big=temp;
        }
    }
    bool same=false;
    while(!number.empty()){
        if(number.top()==big&&!same){
            for(int i=0;i<N-K+1;i++)
                answer+=big;
            same=true;
        }
        else
            answer+=number.top();
        number.pop();
    }
    cout<<answer<<'\n';
    
}



/*
10

101010101010
*/