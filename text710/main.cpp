//
//  main.cpp
//  text710
//
//  Created by 唐伟强 on 2018/7/10.
//  Copyright © 2018年 唐伟强. All rights reserved.
//

#include <iostream>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
struct student
{
    string numbers;
    string name;
    string sex;
    string birthofdate;
    string cla;
    string phoneNO;
    double average;
};
int main() {
    int i=0,l;
    double max,min;
    string line;
    struct student s[100];
    ifstream fin("/Users/s20171105131/Desktop/text710/studentdata.csv");
    while(getline(fin,line)){
        istringstream sin(line);
        vector<string> fields;
        string field;
        while (getline(sin,field,','))
        {
            fields.push_back(field);
        }
        s[i].numbers=fields[0];
        s[i].name=fields[1];
        s[i].sex=fields[2];
        s[i].birthofdate=fields[3];
        s[i].cla=fields[4];
        s[i].phoneNO=fields[5];
        for(max=0,min=101,l=0;l<5;++l){
            if(max<atof(fields[6+l].c_str()))
                max=atof(fields[6+l].c_str());
            if(min>atof(fields[6+l].c_str()))
                min=atof(fields[6+l].c_str());
            s[i].average+=atof(fields[6+l].c_str());
        }
        s[i].average=(s[i].average-max-min)/3;
        ++i;
    }
    ofstream  out("/Users/s20171105131/Desktop/text710/studentdataout.csv");
    if(out.is_open()){
        out<<"numbers,name,sex,dateofbirth,class,phoneNO,score\n";
        for(l=1;l<i;++l){
            out<<s[l].numbers<<","<<s[l].name<<","<<s[l].sex<<","<<s[l].birthofdate<<","<<s[l].cla<<","<<s[l].phoneNO<<","<<s[l].average<<endl;
        }
        out.close();
    }
    return 0;
}
