#include "utils.h"

#include <utility>

string ltrim(string toTrim){
    size_t found=toTrim.find_first_not_of(' ');
    if (found!=string::npos)
    {
        toTrim=toTrim.substr(found);
    }
    return toTrim;
}

string rtrim(string toTrim){
    size_t found=toTrim.find_last_not_of(' ');
    if (found!=string::npos)
    {
        toTrim=toTrim.substr(0,found+1);
    }
    return toTrim;
}

string trim(string toTrim){
    return rtrim(ltrim(move(toTrim)));
}

vector<string> trim(vector<string> toTrim){
    for(auto & i : toTrim){
        i=rtrim(ltrim(i));
    }
    return toTrim;
}

void trim(vector<string> *toTrim){
    for(auto & i : *toTrim){
        i=rtrim(ltrim(i));
    }
}

vector<string> split(const string& toSplit){
    vector<string> splitVec;
    string temp;
    string toremovechars = " .-_*^`'+&%$#:;,/|=(){}[]?!«»<>";
    for(char i : toSplit){
        if(toremovechars.find(i)!=string::npos){
            if(temp.empty())continue;
            splitVec.push_back(trim(temp));
            temp="";
        }else{
            temp+=i;
        }
    }
    if(!temp.empty())splitVec.push_back(trim(temp));
    return splitVec;
}

vector<string> split(const string& toSplit,const string& splitPoint){
    vector<string> splitVec;
    string temp;
    for(char i : toSplit){
        if(splitPoint.find(i)!=string::npos){
            if(temp.empty())continue;
            splitVec.push_back(trim(temp));
            temp="";
        }else{
            temp+=i;
        }
    }
    if(!temp.empty())splitVec.push_back(trim(temp));
    return splitVec;
}

bool isnum(string toConvert) {
    toConvert = trim(toConvert);
    stringstream str;
    str.str(toConvert);
    if (str.peek() == '-') str.ignore(1);
    bool point = false;
    bool anyDigit = false;
    while (str.peek() != str.eof())
        if (!point && str.peek() == '.') {
            point = true;
            str.ignore(1);
            continue;
        }
    if (!isdigit(str.peek())) return false;
    anyDigit = true;
    return true;
}


/*vector<string> trimSplit(string str, string splitPoint) {
    return split(trim(str), splitPoint);
}*/

string upper(const string & s) {
    string ns;
    for (char i : s)
        if (i >= 'a' && i <= 'z')
            ns.push_back(i - 32);
        else
            ns.push_back(i);
    return ns;
}
