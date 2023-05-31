#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
string S;
string ans;
int S_size;
int get_title(int i);
int get_ptag(int i);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    getline(cin,S);
    S_size=S.size();
    for(int i=0;i<S_size;i++){
        if(S[i]=='<'){
            if(S[i+1]=='m'){//main
                i+=5;
            }
            else if(S[i+1]=='d'){
                i=get_title(i+1);
            }
            else if(S[i+1]=='p'){
                i=get_ptag(i+1);
            }
            else{// /
                continue;
            }
        }
    }
    cout<<ans;
}
int get_title(int i){
    int re=i;
    string temp="title : ";
    string title;
    for(int j=i+11;j<S_size;j++){
        re=j;
        if(S[j]=='"')
            break;
        title.push_back(S[j]);

    }
    title.push_back('\n');
    temp+=title;
    ans+=temp;
    return re;
}
int get_ptag(int i){
    int re=i;
    string p;
    for(int j=i+2;j<S_size;j++){
        if(j==i+2&&S[j]==' ')
            continue;
        if(p.back()==' '&&S[j]==' ')
            continue;
        re=j;
        if(S[j]=='<'){
            string temp;
            for(int k=j+1;k<S_size;k++){
                j=k;
                if(S[k]=='/')
                    continue;
                if(S[k]=='>')
                    break;
                temp.push_back(S[k]);
            }
            if(temp=="p"){
                break;
            }
            continue;
        }
        p.push_back(S[j]);
    }
    if(p.back()==' ')
        p.pop_back();
    p.push_back('\n');
    ans+=p;
    return re;
}