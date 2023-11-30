#include <iostream>
#include <vector>

using namespace std;

int max_num[3];
int min_num[3];
int last_max_num[3];
int temp[3];
int last_min_num[3];


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N,op;
    cin>>N;
    for(int i=0;i<3;i++){
        cin>>max_num[i];
        min_num[i]=max_num[i];
        last_max_num[i]=min_num[i];
        last_min_num[i]=min_num[i];
    }
    for(int i=0;i<N-1;i++){
        cin>>temp[0]>>temp[1]>>temp[2];
        op=last_min_num[0]<last_min_num[1]?last_min_num[0]:last_min_num[1];
        min_num[0]=temp[0]+op;
        op=last_max_num[0]>last_max_num[1]?last_max_num[0]:last_max_num[1];
        max_num[0]=temp[0]+op;

        op=last_min_num[1]<last_min_num[2]?last_min_num[1]:last_min_num[2];
        op=op<last_min_num[0]?op:last_min_num[0];
        min_num[1]=temp[1]+op;
        op=last_max_num[1]>last_max_num[2]?last_max_num[1]:last_max_num[2];
        op=op>last_max_num[0]?op:last_max_num[0];
        max_num[1]=temp[1]+op;

        op=last_min_num[1]<last_min_num[2]?last_min_num[1]:last_min_num[2];
        min_num[2]=temp[2]+op;
        op=last_max_num[1]>last_max_num[2]?last_max_num[1]:last_max_num[2];
        max_num[2]=temp[2]+op;
        for(int i=0;i<3;i++){
            last_max_num[i]=max_num[i];
            last_min_num[i]=min_num[i];
        }
    }
    op=last_max_num[1]>last_max_num[2]?last_max_num[1]:last_max_num[2];
    op=op>last_max_num[0]?op:last_max_num[0];
    cout<<op<<' ';    
    op=last_min_num[1]<last_min_num[2]?last_min_num[1]:last_min_num[2];
    op=op<last_min_num[0]?op:last_min_num[0];
    cout<<op;
}