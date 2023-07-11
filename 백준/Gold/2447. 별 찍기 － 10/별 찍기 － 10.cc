#include <iostream>
using namespace std;

void makestar(int x,int y,int zegob);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            makestar(i,j,N);
        cout<<'\n';
    }
}
void makestar(int x,int y,int zegob){
    if((x / zegob)%3 == 1 && (y / zegob)%3 == 1) {
        cout << ' ';
    }
    else
    {
        if(zegob / 3 == 0)
            cout <<'*';
        else
            makestar(x,y,zegob/3);
    }
}
