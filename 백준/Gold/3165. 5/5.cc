#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int each_num[17];
long long N,K;
long long num;
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>K;
    N++;
    int temp=N;
    int num_size=0;
    int five_count=0;
    while(N>0){
        if(N%10==5){
            five_count++;
        }
        each_num[num_size]=N%10;
        num_size++;
        N/=10;
    }
    N=temp;
    long long ans=0;
    if(five_count>=K){
        cout<<N;
        return 0;
    }
    if(num_size<K){
        for(int i=0;i<K;i++)
            cout<<5;
        return 0;
    }
    else if(num_size==K){
        int k=0;
        for(int i=0;i<K;i++){
            k+=5;
            k*=10;
        }
        k/=10;
        if(N>K){
            cout<<1<<k;
        }
        else
            cout<<k;
        return 0;
    }
    else{
        bool no=false;
        for(int i=0;i<num_size;i++){
            if(each_num[i]!=5&&each_num[i]<5){
                each_num[i]=5;
                five_count++;
                for(int j=i-1;j>=0;j--){
                    if(each_num[j]==5){
                        five_count--;
                    }
                }
                for(int j=0;j<=i-1;j++){
                    if(five_count<K){
                        each_num[j]=5;
                        five_count++;
                    }
                    else
                        each_num[j]=0;
                }
                if(five_count==K){
                    no=true;
                    break;
                }
            }
        }
        if(!no){
            five_count=0;
            each_num[num_size-1]++;
            if(each_num[num_size-1]==10){
                each_num[num_size-1]=0;
                each_num[num_size]=1;
                num_size++;
            }
            else if(each_num[num_size-1]==5)
                five_count++;
            for(int i=0;i<num_size-1;i++)
                each_num[i]=0;
            for(int i=0;i<17;i++){
                if(each_num[i]!=5&&each_num[i]<5){
                    each_num[i]=5;
                    five_count++;
                    if(five_count==K){
                        no=true;
                        break;
                    }
                }
            }
        }
        for(int i=num_size-1;i>=0;i--)
            cout<<each_num[i];
    }

}
