#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int N,M;
int map[101][101];
int dx[9]={0,0,-1,-1,-1,0,1,1,1};
int dy[9]={0,-1,-1,0,1,1,1,0,-1};
using namespace std;
void DFS(int x,int y);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>map[i][j];
        }
    }
    int d,s;
    int cl_size;
    vector<pair<int,int> > cloud;
    cloud.push_back(make_pair(N,1));
    cloud.push_back(make_pair(N,2));
    cloud.push_back(make_pair(N-1,1));
    cloud.push_back(make_pair(N-1,2));
    for(int i=0;i<M;i++){
        cin>>d>>s;
        cl_size=cloud.size();
        for(int j=0;j<cl_size;j++){
            cloud[j].first+=(dx[d]*s);
            cloud[j].second+=(dy[d]*s);
            if(cloud[j].first<1){
                while(cloud[j].first<1)
                    cloud[j].first+=N;
            }
            if(cloud[j].first>N){
                while(cloud[j].first>N)
                    cloud[j].first-=N;
            }
            if(cloud[j].second<1){
                cloud[j].second+=N;
                while(cloud[j].second<1)
                    cloud[j].second+=N;
            }
            if(cloud[j].second>N){
                while(cloud[j].second>N)
                    cloud[j].second-=N;
            }
            map[cloud[j].first][cloud[j].second]++;
        }
        for(int j=0;j<cl_size;j++){
            int adit=0;
            for(int k=2;k<=8;k+=2){
                int x=cloud[j].first+dx[k];
                int y=cloud[j].second+dy[k];
                if(x<1||x>N||y<1||y>N)
                    continue;
                if(map[x][y]>0)
                    adit++;
            }
            map[cloud[j].first][cloud[j].second]+=adit;
        }
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N;k++){
                bool pos=true;
                for(int a=0;a<cl_size;a++){
                    if(j==cloud[a].first&&k==cloud[a].second){
                        pos=false;
                        break;
                    }
                }
                if(pos){
                    if(map[j][k]>=2){
                        map[j][k]-=2;
                        cloud.push_back(make_pair(j,k));
                    }
                }
            }
        }
        cloud.erase(cloud.begin(),cloud.begin()+cl_size);
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)
            ans+=map[i][j];
    }
    cout<<ans;
}