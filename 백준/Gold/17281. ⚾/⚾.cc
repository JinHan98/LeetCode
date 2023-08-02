#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int ans=0;
int N;
int ining[51][10];
bool isvisit[10];
int order[10];
void DFS(int index,int depth);
int get_score();
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    order[4]=1;
    isvisit[1]=true;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=9;j++){
            cin>>ining[i][j];
        }
    }
    for(int i=1;i<=9;i++){
        if(i!=1){
            DFS(i,1);
            isvisit[i]=false;
        }
    }
    cout<<ans;
}
void DFS(int index, int depth){
    order[depth]=index;
    isvisit[index]=true;
    if(depth==9){
        int temp=get_score();
        if(ans<temp)
            ans=temp;
        // for(int i=1;i<=9;i++)
        //     cout<<order[i]<<' ';
        // cout<<'\n';
        return ;
    }
    for(int i=1;i<=9;i++){
        if(!isvisit[i]){
            if(depth==3){
                DFS(i,depth+2);
                isvisit[i]=false;
            }
            else{
                DFS(i,depth+1);
                isvisit[i]=false;
            }
        }
    }
}
int get_score(){
    int score=0;
    int ining_first_man=1;
    for(int i=1;i<=N;i++){
        bool roo[4]={0,0,0,0};
        int out=0;
        while(out<3){
            int this_result=ining[i][order[ining_first_man]];
            roo[0]=true;
            switch (this_result)
            {
            case 0:
                out++;
                break;
            case 1:
                if(roo[3]){
                    score++;
                    roo[3]=0;
                }
                for(int i=2;i>=0;i--){
                    if(roo[i]){
                        roo[i+1]=true;
                        roo[i]=false;
                    }
                }
                break;
            case 2:
                if(roo[3]){
                    score++;
                    roo[3]=0;
                }
                if(roo[2]){
                    score++;
                    roo[2]=0;
                }
                for(int i=1;i>=0;i--){
                    if(roo[i]){
                        roo[i+2]=true;
                        roo[i]=false;
                    }
                }
                break;
            case 3:
                for(int i=1;i<=3;i++){
                    if(roo[i]){
                        score++;
                        roo[i]=false;
                    }
                }
                roo[3]=true;
                break;
            default:
                for(int i=0;i<=3;i++){
                    if(roo[i]){
                        score++;
                        roo[i]=false;
                    }
                }
                break;
            }
            ining_first_man++;
            if(ining_first_man>9)
                ining_first_man=1;
        }
    }
    return score;
}
