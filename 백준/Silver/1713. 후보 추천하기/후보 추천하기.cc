#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int N;
int reco[101];
using namespace std;
void DFS(int x,int y);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    vector<int> pic;
    cin>>N;
    bool op=false;
    int k,temp,out;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>temp;
        if(pic.size()<N){
            op=false;
            for(int a=0;a<pic.size();a++){
                if(pic[a]==temp){
                    op=true;
                    reco[temp]++;
                    break;
                }
            }
            if(!op){
                pic.push_back(temp);
                reco[temp]++;
            }
        }
        else{
            op=false;
            for(int a=0;a<N;a++){
                if(pic[a]==temp){
                    reco[temp]++;
                    op=true;
                    break;
                }
            }
            if(!op){
                int min=10000;
                for(int i=0;i<N;i++){
                    if(reco[pic[i]]<min){
                        min=reco[pic[i]];
                        out=i;
                    }
                }
                reco[pic[out]]=0;
                pic.erase(pic.begin()+out);
                pic.push_back(temp);
                reco[temp]++;
            }
        }
    }
    sort(pic.begin(),pic.end());
    for(int i=0;i<N&&i<k&&i<pic.size();i++)
        cout<<pic[i]<<' ';
}