#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;
int gcd(int a,int b);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    int down=B*D;
    int up=A*D+B*C;
    int a=gcd(down,up);
    cout<<up/a<<' '<<down/a<<'\n';

}
int gcd(int a,int b){
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}