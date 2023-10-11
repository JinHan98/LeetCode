#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<int > result(4);
    for(int i=0;i<survey.size();i++){
        if(survey[i]=="RT"){
            result[0]+=(choices[i]-4);
        }
        else if(survey[i]=="TR"){
            result[0]-=(choices[i]-4);
        }
        else if(survey[i]=="CF"){
            result[1]+=(choices[i]-4);
        }
        else if(survey[i]=="FC"){
            result[1]-=(choices[i]-4);
        }
        else if(survey[i]=="JM"){
            result[2]+=(choices[i]-4);
        }
        else if(survey[i]=="MJ"){
            result[2]-=(choices[i]-4);
        }
        else if(survey[i]=="AN"){
            result[3]+=(choices[i]-4);
        }
        else{
            result[3]-=(choices[i]-4);
        }
    }
    if(result[0]<=0)
        answer.push_back('R');
    else
        answer.push_back('T');
    if(result[1]<=0)
        answer.push_back('C');
    else
        answer.push_back('F');
    if(result[2]<=0)
        answer.push_back('J');
    else
        answer.push_back('M');
    if(result[3]<=0)
        answer.push_back('A');
    else
        answer.push_back('N');
    return answer;
}