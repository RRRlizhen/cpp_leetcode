#ifndef STRINGDOUBLECHAR_H_INCLUDED
#define STRINGDOUBLECHAR_H_INCLUDED
#include <typeinfo>
#include <exception>
#include <stdexcept>
#include<string.h>
#include<sstream>
#include<stdio.h>

class Offer{
public:
//double -->string
string doubleConverToString(double d){
    ostringstream os;
    if(os << d) return os.str();
    return "invalid conversion";
}

//string-->double
double stringConverTodouble(string str){
    istringstream iss(str);

    double  x;
    if(iss >> x) return x;
    return 0.0;
}

/*
//string-->char*
    string str("string");
    char *p = const_cast<char *>(str.c_str());
    cout<<"string->char*"<<p<<endl;
*/
char* strTochar(string str){
    char *p = const_cast<char *>(str.c_str());
    return p;
}

/*
//double&float --->string
    double dd = 3.14;
    string ddstr = doubleConverToString(dd);
    cout<<ddstr<<endl;
*/
string charTostring(char *p){
    string str(p);
    return str;
}

//c-function double-->string
string cfunctionDtoS(double d){
    char str[100];
    sprintf(str,"%.3lf",d);
    return str;
}
//c-function string->double
double cfunctionStoD(string str){
    double dd;
    sscanf(str.c_str(),"%lf",&dd);
    return dd;
}
};


#endif // STRINGDOUBLECHAR_H_INCLUDED
