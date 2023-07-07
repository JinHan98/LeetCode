#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int white=0;
int blue=0;

void qudtree(int a[][128],int start_x,int start_y,int size);


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N;
    int K[128][128];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>K[i][j];
        }
    }
    qudtree(K,0,0,N);
    cout<<white<<'\n'<<blue;
}
void qudtree(int a[][128],int start_x,int start_y,int size){
    int temp=a[start_x][start_y];
    bool JJo=false;
    for(int i=0;i<size;i++){
        if(JJo==true)
            break;
        for(int j=0;j<size;j++){
            if(temp!=a[start_x+i][start_y+j]){
                JJo=true;
                break;
            }
        }
    }
    if(JJo==true){
        qudtree(a,start_x,start_y,size/2);
        qudtree(a,start_x+size/2,start_y,size/2);
        qudtree(a,start_x,start_y+size/2,size/2);
        qudtree(a,start_x+size/2,start_y+size/2,size/2);
    }
    else{
        if(temp==1)
            blue++;
        else
            white++;
    }
}