#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    int temp=storey;
    while(temp>0){
        int num=temp%10;
        int t=temp%100;
        if(num>5){
            answer+=(10-num);
            temp/=10;
            temp++;
        }
        else if(num==5){
            if(t/10>=5){
                answer+=(10-num);
                temp/=10;
                temp++;
            }
            else{
                answer+=num;
                temp/=10;
            }
        }
        else{
            answer+=num;
            temp/=10;
        }
    }
    
    return answer;
}