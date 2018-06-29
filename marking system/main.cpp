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

struct  marking
{//参赛人员信息
    string  name;
    string  sex;
    string  Class;
    string  form;
    string   tel;
    int number;
    double  score[10];
    double sum;
    double aver;
    
    
};
struct referee
{//裁判
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
        cin>>m[i].number;
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
        cout<<"max:"<<max<<endl;
        cout<<"min:"<<min<<endl;
        cout<<"Calculate complete!\n";
        cout<<m[i].aver;
    }
    //cout<<"Calculate complete!\n";
    //1cout<<m[i].aver;
    
    
}
void change(marking *m)//修改函数
{
    int i;
    int q;
    cout<<"请输出要修改的号码:"<<endl;
    cin>>q;
    struct  marking s;
    for (i=0; i<n; ) {
        if(m[i].number!=q)
        {
            i++;
        }
        else{
            break;
        }
    }
    cout<<i<<endl;
    cout<<"请输出入新的参赛人姓名："<<endl;
    cin>>s.name;
    m[i].name=s.name;
    cout<<"请输出入新的参赛人性别："<<endl;
    cin>>s.sex;
    m[i].sex=s.sex;
    cout<<"请输出入新的参赛人班级："<<endl;
    cin>>s.Class;
    m[i].Class=s.Class;
    cout<<"请输出入新的参赛人电话号码："<<endl;
    cin>>s.tel;
    m[i].tel=s.tel;
    cout<<"请输出入新的参赛人类别："<<endl;
    cin>>s.form;
    m[i].form=s.form;
    cout<<"请输出入新的参赛人成绩1："<<endl;
    cin>>s.score[1];
    m[i].score[1]=s.score[1];
    cin>>s.score[2];
    cout<<"请输出入新的参赛人成绩2："<<endl;
    m[i].score[2]=s.score[2];
    cin>>s.score[3];
    cout<<"请输出入新的参赛人成绩3："<<endl;
    m[i].score[3]=s.score[3];
    cout<<"请输出入新的参赛人成绩4："<<endl;
    cin>>s.score[4];
    m[i].score[4]=s.score[4];
    cout<<"请输出入新的参赛人成绩5："<<endl;
    cin>>s.score[5];
    m[i].score[5]=s.score[5];
    
    
    

}
void del(marking *m)//删除函数
{
    int i;
    //int h;
    int q;
    cout<<"请输出要删除的号码:"<<endl;
    cin>>q;
    struct  marking k;
    for (i=1; i<=n; )
    {
        if(m[i].number!=q)
        {
            i++;
        }
        else{
            n--;
        }
    }
    /*k=m[h];
    for (h=i;h<n; h++)
    {
        m[h]=m[h-1];
        n--;
    }*/
    cout<<"delete succeed!!!!";
}
void  output (marking *m )//输出参赛人员信息
{  int i;
    for(i=0;i<n;i++)
    {
        cout<<"名字："<<m[i].name<<"性别："<<m[i].sex<<"班级："<<m[i].Class<<"项目："<<m[i].form<<"电话："<<m[i].tel<<"成绩1："<<m[i].score[1]<<"成绩2："<<m[i].score[2]<<"成绩3："<<m[i].score[3]<<"成绩4："<<m[i].score[4]<<"成绩5："<<m[i].score[5]<<endl;
    }
}
void menu()
{
    
    
    
    
    cout<<"                    | -----------------------------\n";
    cout<<"                    |         评分系统              \n";
    cout<<"                    | -----------------------------\n";
    cout<<"                    |            菜单栏             \n";
    cout<<"                    | -----------------------------\n";
    cout<<"                    |       1---录入参赛人员信息       \n";
    cout<<"                    |       2---录入裁判信息          \n";
    cout<<"                    |       3---修改参赛人员信息       \n";
    cout<<"                    |       4---排名参赛人员信息       \n";
    cout<<"                    |       5---参赛人员的平均成绩     \n";
    cout<<"                    |       6---显示才赛人员的信息     \n";
    cout<<"                    |       7---删除参赛人员信息       \n";
    cout<<"                    |       0---退出系统             \n";
    cout<<"                    | ----------------------------- \n";
    
    
   
    
    
    
}

 struct  marking  m [100];
int main(int argc, const char * argv[]) {
    // insert code here...
    //struct  marking  m [100];
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
            case 3: change(m);break;
                //case 4: sort(L);break;
            case 5:ave(m,n); break;
            case 6:output(m);break;
            case 7:del(m);break;
            case 0:
                //save(L);
                exit(0);
                break;
        }
        menu();//循环一下菜单
    }
    return 0;
}
