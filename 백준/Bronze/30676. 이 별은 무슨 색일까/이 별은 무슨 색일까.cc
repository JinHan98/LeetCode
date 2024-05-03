#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N;
    if(N>=620){
        cout<<"Red";
        return 0;
    }
    if(N>=590){
        cout<<"Orange";
        return 0;
    }
    if(N>=570){
        cout<<"Yellow";
        return 0;
    }
    if(N>=495){
        cout<<"Green";
        return 0;
    }
    if(N>=450){
        cout<<"Blue";
        return 0;
    }
    if(N>=425){
        cout<<"Indigo";
    }
    else{
        cout<<"Violet";
    }
}