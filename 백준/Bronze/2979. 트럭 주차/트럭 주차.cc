#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool truck[3][101];
int A,B,C;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>A>>B>>C;
    int ans=0;
    int s,e;
    for(int i=0;i<3;i++){
        cin>>s>>e;
        for(int j=s;j<e;j++)
            truck[i][j]=true;
    }
    for(int i=1;i<=100;i++){
        int temp=0;
        for(int j=0;j<3;j++){
            if(truck[j][i])
                temp++;
        }
        switch (temp)
        {
        case 0:
            break;
        case 1:
            ans+=A;
            break;
        case 2:
            ans+=(B*2);
            break;
        default:
            ans+=(C*3);
            break;
        }
    }
    cout<<ans;
    
}
// 1 2
// 2 4
// 3 6
// 4 9
// 5 12
// 6 16