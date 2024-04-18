#include <iostream>
using namespace std;
double score;
string s;
int main() {
    cin>>s;
    cout<<fixed;
    cout.precision(1);
    if(s[0]=='A'){
        score=4.0;
    }
    else if(s[0]=='B'){
        score=3.0;
    }
    else if(s[0]=='C'){
        score=2.0;
    }
    else if(s[0]=='D'){
        score=1.0;
    }
    else{
        cout<<0.0;
        return 0;
    }
    if(s[1]=='+'){
        score+=0.3;
    }
    else if(s[1]=='-'){
        score-=0.3;
    }
    cout<<score;
}