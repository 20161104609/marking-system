//
//  main.cpp
//  marking system
//
//  Created by 20161104609 on 18/6/25.
//  Copyright © 2018年 20161104609. All rights reserved.
//

#include <iostream>
#include <string>
#include <String>
int n ;
using namespace std;
struct  marking  {
    string  name;
    string  sex;
    string  Class;
    string  form;
    string   tel;
    int  score[10];
    int sum;
    
   
};
struct referee {
    string name;
    string sex;
    string tel;
};
void intput(marking *m)
{
    int i;
   cout<<"输入参赛人员的个数:"<<endl;
   cin>>n;
   for(i=0;i<n;i++)
    {
    cout<<"name:"<<endl;
    cin>>m[i].name;
    cout<<"sec:"<<endl;
    cin>>m[i].sex;
    cout<<"class:"<<endl;
    cin>>m[i].Class;
    cout<<"form:"<<endl;
    cin>>m[i].form;
    cout<<"tel:"<<endl;
    cin>>m[i].tel;
      
            cout<<"成绩1:"<<endl;
            cin>>m[i].score[1];
            cout<<"成绩2:"<<endl;
            cin>>m[i].score[2];
            cout<<"成绩3:"<<endl;
            cin>>m[i].score[3];
            cout<<"成绩4:"<<endl;
            cin>>m[i].score[4];
            cout<<"成绩5:"<<endl;
            cin>>m[i].score[5];
        m[i].sum=m[i].score[1]+m[i].score[2]+m[i].score[3]+m[i].score[4]+m[i].score[5];
            
            
        
    }
}
void  put(referee *r)
{   int i;
    for(i=0;i<5;i++)
    {
        cout<<"name:"<<endl;
        cin>>r[i].name;
        cout<<"sec:"<<endl;
        cin>>r[i].sex;
        cout<<"tel:"<<endl;
        cin>>r[i].tel;
    }
    
}
void  output (marking *m ,int n )
{  int i;
    for(i=0;i<n;i++)
    {
        cout<<"名字："<<m[i].name<<"性别："<<m[i].sex<<"班级："<<m[i].Class<<"项目："<<m[i].form<<"电话："<<m[i].tel<<"成绩1："<<m[i].score[1]<<"成绩2："<<m[i].score[2]<<"成绩3："<<m[i].score[3]<<"成绩4："<<m[i].score[4]<<"成绩5："<<m[i].score[5];
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    struct  marking  m [100];
    intput(m);
    output(m,n);
    
    return 0;
}
