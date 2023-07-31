#include <iostream>
#include <vector>

using namespace std;


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    vector<int> fx(3);
    pair<int,int> gx;
    cin>>fx[0]>>fx[1]>>fx[2];
    cin>>gx.first>>gx.second;
    vector<int> px(3);
    vector<int> qx(3);
    px[0]=fx[0]*gx.first;
    px[1]=fx[1]*gx.first;
    px[2]=fx[2]*gx.first+gx.second;
    qx[0]=gx.first*gx.first*fx[0];
    qx[1]=(2*gx.first*gx.second*fx[0])+(fx[1]*gx.first);
    qx[2]=fx[0]*gx.second*gx.second+fx[1]*gx.second+fx[2];
    if(px[0]==0&&qx[0]==0){
        if(px[1]==qx[1]){
            if(px[2]!=qx[2]){
                cout<<"Head on";
            }
            else{
                cout<<"Nice";
            }
            return 0;
        }
        else{
            cout<<"Remember my character";
            return 0;
        }
    }
    for(int i=0;i<3;i++){
        px[i]-=qx[i];
    }
    if(px[0]==0&&px[1]==0&&px[2]==0){
        cout<<"Nice";
        return 0;
    }
    if(px[0]==0&&px[1]!=0){
        cout<<"Remember my character";
        return 0;
    }
    if(px[0]==0&&px[1]==0&&px[2]!=0){
        cout<<"Head on";
        return 0;
    }
    if((px[1]*px[1])-(4*px[0]*px[2])==0){
        cout<<"Remember my character";
    }
    else if((px[1]*px[1])-(4*px[0]*px[2])>0){
        cout<<"Go ahead";
    }
    else{
        cout<<"Head on";
    }
    return 0;
}