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
struct  marking  {//参赛人员信息
    string  name;
    string  sex;
    string  Class;
    string  form;
    string   tel;
    int numeber;
    double  score[10];
    double sum;
    double aver;
    
    
};
struct referee {//裁判
    string name;
    string sex;
    string tel;
};

void intput(marking *m)//参赛人员信息
{
    int i;
    cout<<"输入参赛人员的个数:"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"name:"<<endl;
        cin>>m[i].name;
        cout<<"number:"<<endl;
        cin>>m[i].numeber;
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
void  put(referee *r)//裁判信息
{   int i;
    cout<<"输入裁判信息:"<<endl;
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
void  output (marking *m ,int n )//输出参赛人员信息
{  int i;
    for(i=0;i<n;i++)
    {
        cout<<"名字："<<m[i].name<<"性别："<<m[i].sex<<"班级："<<m[i].Class<<"项目："<<m[i].form<<"电话："<<m[i].tel<<"成绩1："<<m[i].score[1]<<"成绩2："<<m[i].score[2]<<"成绩3："<<m[i].score[3]<<"成绩4："<<m[i].score[4]<<"成绩5："<<m[i].score[5]<<endl;
    }
}
void ave(marking *m , int n)//求平均成绩
{
    int i;
    m[i].sum=0;
    m[1].aver=0;
    for ( i= 0; i < n; i ++)
    {
        double max = m[i].score[1];
        double min = m[i].score[1];
        for (int j = 1; j < 6; j ++)
        {
            if (m[i].score[j] > max)
            {
                max =m[i].score[j];
            }
            if (m[i].score[j] < min)
            {
                min = m[i].score[j];
            }
            m[i].sum+=m[i].score[j];
        }
        m[i].sum = m[i].sum - max - min;
        //aver=m[i].sum/=3;
        m[i].aver=m[i].sum/3;
        cout<<"max:"<<max;
        cout<<"min:"<<min;
        cout<<"Calculate complete!\n";
        cout<<m[i].aver;
    }
    //cout<<"Calculate complete!\n";
    //1cout<<m[i].aver;
    
    
}
void change(marking *m, int number)
{
    int i;
    int s,q;
    for (i=0; i<m[0].numeber; ) {
        if(m[i].numeber!=q)
        {
            i++;
        }
        else{
            break;
        }
    }
    while(q!=null)
    {cout<<"找到该参赛人员！"<<m[i].name<<endl;
        cin>>s;
        switch (s) {
            case 1:cout<<"name：";cin>>m[i].name;break;
            case 2:cin>>m[i].sex;break;
            case 3:cin>>m[i].Class;break;
            case 4:cin>>m[i].form;break;
            case 5:cin>>m[i].tel;break;
            case 6:cin>>m[i].score[1];break;
            case 7:cin>>m[i].score[2];break;
            case 8:cin>>m[i].score[3];break;
            case 9:cin>>m[i].score[4];break;
            case 10:cin>>m[i].score[5];break;
        }
    }
    
    
}
void menu()
{
    
    printf("                    | ----------------------------- |\n");
    printf("                    |         评分系统              |\n");
    printf("                    | ----------------------------- |\n");
    printf("                    |            菜单栏             |\n");
    printf("                    | ----------------------------- |\n");
    printf("                    |       1---录入参赛人员信息    |\n");
    printf("                    |       2---录入裁判信息        |\n");
    printf("                    |       3---修改参赛人员信息    |\n");
    printf("                    |       4---排名参赛人员信息    |\n");
    printf("                    |       5---参赛人员的平均成绩  |\n");
    printf("                    |       6---显示才赛人员的信息  |\n");
    printf("                    |       0---退出系统            |\n");
    printf("                    | ----------------------------- |\n");
    
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    struct  marking  m [100];
    struct referee r[10];
    menu();//运行主菜单
    //load(L);//读取学生存入的数据
    int s;
    cout<<"请输入要用的功能："<<endl;
    while(cin>>s)
    {
        switch(s)
        {
            case 1: intput(m);break;
            case 2: put(r);break;
            case 3: change(m,n);break;
                //case 4: sort(L);break;
            case 5:ave(m,n); break;
            case 6:output(m,n);break;
            case 0:
                //save(L);
                exit(0);
                break;
        }
        menu();//循环一下菜单
    }
    return 0;
}
