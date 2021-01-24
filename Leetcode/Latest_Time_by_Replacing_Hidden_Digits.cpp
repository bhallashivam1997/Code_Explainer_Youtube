class Solution {
public:
    string maximumTime(string time) {
        if(time[0]=='?' && time[1]=='?') time[0]='2';
        else if(time[0]=='?' && time[1]>='0' && time[1]<='3') time[0]='2';
        else if(time[0]=='?') time[0]='1';
        if(time[0]=='2' && time[1]=='?') time[1]='3';
        else if(time[1]=='?') time[1]='9';
        if(time[3]=='?') time[3]='5';
        if(time[4]=='?') time[4]='9';
        return time;
    }
};
