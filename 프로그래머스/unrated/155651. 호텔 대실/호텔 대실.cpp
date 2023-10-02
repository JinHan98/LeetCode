#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
int time_to_int(string s);
int plus_ten(int time);
int solution(vector<vector<string>> book_time) {
    int answer = 1;
    sort(book_time.begin(),book_time.end());
    priority_queue<int,vector<int>,greater<int> > room;
    room.push(time_to_int(book_time[0][1]));
    for(int i=1;i<book_time.size();i++){
        int start_num=time_to_int(book_time[i][0]);
        int end_num=time_to_int(book_time[i][1]);
        if(plus_ten(room.top())>start_num){
            room.push(end_num);
            if(answer<room.size()){
                answer=room.size();
            }
        }
        else{
            room.pop();
            room.push(end_num);
        }
    }
    return answer;
}
int time_to_int(string s){
    int integer=0;
    for(int i=0;i<5;i++){
        if(s[i]==':')
            continue;
        integer+=(s[i]-'0');
        integer*=10;
    }
    return integer/10;
}
int plus_ten(int time){
    time+=10;
    if(time%100>=60){
        time+=100;
        time-=60;
    }
    return time;
}