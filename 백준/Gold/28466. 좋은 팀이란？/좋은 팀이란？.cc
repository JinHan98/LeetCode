#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int chengan[10][10];
int zizi[12][12];
int get_relation(int a,int b,int c);
int N;
map<string,int> trans;
map<int,string> r_trans;
map<int,vector<int> > people;
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    string twelve="0A";
    for(int i=0;i<60;i++){
        trans[twelve]=i;
        r_trans[i]=twelve;
        twelve[0]++;
        twelve[1]++;
        if(twelve[0]>'9')
            twelve[0]='0';
        if(twelve[1]>'L')
            twelve[1]='A';
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)
            cin>>chengan[i][j];
    }
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++)
            cin>>zizi[i][j];
    }
    int s;
    string p;
    for(int i=0;i<N;i++){
        cin>>s>>p;
        people[trans[p]].push_back(s);
    }
    for(auto iter=people.begin();iter!=people.end();iter++){
        sort(iter->second.begin(),iter->second.end(),greater<int>());
    }
    int ans=0;
    for(auto iter1=people.begin();iter1!=people.end();iter1++){
        for(auto iter2=people.begin();iter2!=people.end();iter2++){
            for(auto iter3=people.begin();iter3!=people.end();iter3++){
                if(iter1==iter2&&iter2==iter3){
                    if(iter1->second.size()>2)
                        ans=max(ans,get_relation(iter1->first,iter2->first,iter3->first)+iter1->second[0]+iter1->second[1]+iter1->second[2]);
                }
                else if(iter1==iter2){
                    if(iter1->second.size()>1)
                        ans=max(ans,get_relation(iter1->first,iter2->first,iter3->first)+iter1->second[0]+iter1->second[1]+iter3->second[0]);
                    else
                        break;
                }
                else if(iter2==iter3){
                    if(iter2->second.size()>1)
                        ans=max(ans,get_relation(iter1->first,iter2->first,iter3->first)+iter1->second[0]+iter2->second[0]+iter2->second[1]);
                }
                else if(iter1==iter3){
                    if(iter1->second.size()>1)
                        ans=max(ans,get_relation(iter1->first,iter2->first,iter3->first)+iter1->second[0]+iter2->second[0]+iter3->second[1]);
                }
                else{
                    ans=max(ans,get_relation(iter1->first,iter2->first,iter3->first)+iter1->second[0]+iter2->second[0]+iter3->second[0]);
                }
            }
        }
    }
    cout<<ans;
}
int get_relation(int a,int b,int c){
    string A=r_trans[a];
    string B=r_trans[b];
    string C=r_trans[c];
    int ans=chengan[A[0]-'0'][B[0]-'0']+chengan[A[0]-'0'][C[0]-'0']+chengan[B[0]-'0'][C[0]-'0'];
    ans+=(zizi[A[1]-'A'][B[1]-'A']+zizi[B[1]-'A'][C[1]-'A']+zizi[A[1]-'A'][C[1]-'A']);
    return ans;
}