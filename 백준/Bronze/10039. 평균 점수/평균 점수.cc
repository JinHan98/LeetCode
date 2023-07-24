#include <iostream>
using namespace std;


int main(){
    int score[5];
    for(int i=0;i<5;i++){
        cin>>score[i];
        if(score[i]<40)
            score[i]=40;
    }
    cout<<(score[0]+score[1]+score[2]+score[3]+score[4])/5;
}
