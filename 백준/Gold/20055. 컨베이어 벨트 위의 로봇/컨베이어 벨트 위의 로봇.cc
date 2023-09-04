#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N,K;
vector<int> robot;
int isrobot[200];
int container[200];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int round=0;
    int out=0;
    int zero=0;
    int ans=1;
    cin>>N>>K;
    int total=2*N;
    for(int i=0;i<2*N;i++){
        cin>>container[i];
    }
    while(1){
        round--;
        if(round==-1)
            round=total-1;
        out=round+N-1;
        out%=total;
        for(int i=0;i<robot.size();i++){
            if(robot[i]==out){
                isrobot[robot[i]]--;
                robot.erase(robot.begin()+i);
                i--;
            }
        }
        for(int i=0;i<robot.size();i++){
            if(!isrobot[(robot[i]+1)%total]&&container[(robot[i]+1)%total]>0){
                container[(robot[i]+1)%total]--;
                if(container[(robot[i]+1)%total]==0)
                    zero++;
                isrobot[(robot[i]+1)%total]++;
                isrobot[robot[i]%total]--;
                robot[i]++;
                robot[i]%=total;
                if(robot[i]==out){
                    isrobot[robot[i]]--;
                    robot.erase(robot.begin()+i);
                    i--;
                }

            }
        }
        if(container[round]>0){
            isrobot[round]++;
            robot.push_back(round);
            container[round]--;
            if(container[round]==0)
                zero++;
        }
        if(zero>=K){
            cout<<ans;
            return 0;
        }
        ans++;
    }
}