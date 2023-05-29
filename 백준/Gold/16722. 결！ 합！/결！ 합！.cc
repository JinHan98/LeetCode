#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
char all[10][3];
bool isvisit[10][10][10];
int N;
bool H(int x,int y,int z);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string a;
    string b;
    string c;
    bool check=false;
    for(int i=1;i<=9;i++){
        cin>>a>>b>>c;
        all[i][0]=a[0];
        all[i][1]=b[0];
        all[i][2]=c[0];
    }
    int score=0;
    char choose;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>choose;
        if(choose=='H'){
            int num[3];
            cin>>num[0]>>num[1]>>num[2];
            sort(num,num+3);
            if(isvisit[num[0]][num[1]][num[2]]){
                score--;
                continue;
            }
            if(H(num[0],num[1],num[2])){
                score++;
                isvisit[num[0]][num[1]][num[2]]=true;
            }
            else
                score-=1;
        }
        else{
            if(check){
                score--;
                continue;
            }
            bool op=true;
            for(int x=1;x<=9;x++){
                for(int y=x+1;y<=9;y++){
                    for(int z=y+1;z<=9;z++){
                        if(isvisit[x][y][z])
                            continue;
                        if(H(x,y,z)){
                            op=false;
                            break;
                        }
                    }
                }
            }
            if(op){
                score+=3;
                check=true;
            }
            else
                score-=1;
        }
    }
    cout<<score;
}
bool H(int x,int y,int z){
    bool op=true;
    for(int i=0;i<3;i++){
        if(all[x][i]==all[y][i]&&all[y][i]==all[z][i]){
            continue;
        }
        else if(all[x][i]!=all[y][i]&&all[y][i]!=all[z][i]&&all[x][i]!=all[z][i]){
            continue;
        }
        else{
            op=false;
            break;
        }
    }
    return op;
}