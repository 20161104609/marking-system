//
//  main.cpp
//  marking system
//
//  Created by 20161104609 on 18/6/25.
//  Copyright ? 2018年 20161104609. All rights reserved.
//

//
//  main.cpp
//  marking
//
//  Created by 20161104609 on 18/7/5.
//  Copyright ? 2018年 20161104609. All rights reserved.
//
#include <cstring>
#include <iostream>
using namespace std;
struct referee
{//裁判
    string name;
    string sex;
    string tel;
};
void  put(referee *r)//裁判信息
{   int i;
    cout<<"输入裁判信息:"<<endl;
    for(i=0;i<5;i++)
    {
        cout<<"name:";
        cin>>r[i].name;
        cout<<"sec:";
        cin>>r[i].sex;
        cout<<"tel:";
        cin>>r[i].tel;
        cout<<"once  change succeed!!"<<endl;
        
    }
}

void  output (referee *r)//输出裁判人员信息
{  int i;
    for(i=0;i<5;i++)
    {
        cout<<"名字："<<r[i].name<<"性别："<<r[i].sex<<"电话号码："<<r[i].tel<<endl;
    }
}

class student       // student 类为管理系统的一个节点
{
    friend class studentMessage;//声明一个有类
    student      *next;//定义类的节点
    char         name[30];
    char         num[30];
    char         Class[10];
    char         form[10];
    char         tel[10];
    char         sex[10];
    double       score[6];
    double       averageScore;//平均成绩
public:
    student()
    {
        strcpy(name, "null");
        strcpy(num, "null");
        strcpy(Class, "null");
        strcpy(form, "null");
        strcpy(tel, "null");
        strcpy(sex, "null");
        averageScore=0;
        for (int i = 0; i < 6; ++i) score[i] = 0;//初始化
    }
    student(const student &a)//设置成为常量
    {
        strcpy(name, a.name);
        strcpy(num, a.num);
        strcpy(Class, a.Class);
        strcpy(form, a.form);
        strcpy(tel, a.tel);
        averageScore=a.averageScore;
        for (int i = 0; i < 6; ++i)
            score[i] = a.score[i];
    }
    student &input()
    {
        cout << "姓名：";  cin >> name;
        cout << "性别：";  cin >> sex;
        cout << "学号：";  cin >> num;
        cout << "班级：";  cin >> Class;
        cout << "组成：";  cin >> form;
        cout << "电话：";  cin >> tel;
        for (int i = 0; i < 5; ++i)
        {
            cout << "输入第" << (i + 1) << "门成绩:";
            cin >> score[i];
            score[5] += score[i];
            
        }//求平均函数
        double max = score[0];
        double min = score[0];
        int k;
        for( k = 0; k < 5; k++) {
            if( max < score[k]) {
                max = score[k];
                
            }
            if( min > score[k]) {
                min = score[k];
                
            }
            averageScore += score[k];
        }
        averageScore=averageScore-max-min;
        cout<<"最大值"<<max<<endl;
        cout<<"最小值:"<<min<<endl;
        averageScore /= 3;
        return *this;
    }
    student* get_next()
    {
        return next;
    }
    
    
    void print()
    {
        printf("%8s %8s %8s %7s %8s %12s ", name, sex,num,Class,form,tel);
        for (int i = 0; i < 6; ++i) printf(" %8.2f ", score[i]);
        printf("%8.2f",averageScore);
        printf("\n");
    }
    
    
    void Swap() // 交换当前结点和下一个
    {
        char temp[300];
        strcpy(temp, name);
        strcpy(name, next->name);
        strcpy(next->name, temp);
        
        strcpy(temp, sex);
        strcpy(sex, next->sex);
        strcpy(next->sex, temp);
        
        strcpy(temp, num);
        strcpy(num, next->num);
        strcpy(next->num, temp);
        
        strcpy(temp, Class);
        strcpy(Class, next->Class);
        strcpy(next->Class, temp);
        
        strcpy(temp, form);
        strcpy(form, next->form);
        strcpy(next->form, temp);
        
        strcpy(temp, tel);
        strcpy(tel, next->tel);
        strcpy(next->tel, temp);
        
        for (int i = 0; i < 6; i++)
        {
            int tmp = score[i];
            score[i] = next->score[i];
            next->score[i] = tmp;
        }
        for (int i=0;i<6; i++) {
            int tmp=averageScore;
            averageScore = next->averageScore;
            next->averageScore = tmp;
            
        }
        
        
    }
    
};

class studentMessage
{
protected:
    student *first;
    student *last;
public:
    studentMessage()
    {
        first = last = new student;
    }
    ~studentMessage()
    {
        Clear();
        delete first;
    }
    studentMessage &Append();           // 在链表尾部插入节点
    student *Find(const char *x);       // 查找
    void Query();                       // 查询
    studentMessage &Delete();           // 删除查找结点
    studentMessage &Clear();            // 删除所有结点
    studentMessage &Sort();             // 按第i门课排序
    studentMessage &save();              //保存函数
    void print();                       // 显示所有节点
    void menu();                         // 显示菜单
    
};

studentMessage &studentMessage::Append()//设置好头结点是链表能连续
{
    student x;
    x.input();
    student *ptr = last;
    *ptr = x;
    last = new student;
    ptr->next = last;
    return *this;
}

studentMessage &studentMessage::Delete()
{
    char x[30];
    cout << "输入要删除的信息（学号或姓名）\n";
    cin >> x;
    student *ptr = Find(x);
    
    if (ptr == last)
    {
        cout << "未找到相关信息\n";
        return *this;
    }
    ptr->print();
    cout << "是否删除此信息？（是输入1，否输入0）";
    cin >> x;
    if (*x == '1')
    {
        if (ptr == first)
        {
            first = first->next;
            delete first;
        }
        else
        {
            student *temp = first;
            while (temp->next != ptr) temp = temp->next;
            temp->next = ptr->next;
            delete ptr;
        }
        cout << "已删除\n";
    }
    else
    {
        cout << "已取消\n";
    }
    return *this;
}

studentMessage &studentMessage::Clear()
{
    char m [300];
    cout << "将删除所有信息。确认请按Y";
    cin >> m;
    if (*m != 'Y' && *m  != 'y')
    {
        cout << "已取消\n";
        return *this;
    }
    student *ptr = first;
    while (ptr != last)
    {
        student *next = ptr->next;
        delete ptr;
        ptr = next;
    }
    first = last;
    return *this;
}

void studentMessage::print()
{
    if (first == last)
    {
        cout << "暂无信息\n";
        return ;
    }
    cout << "---------------------------------成绩列表--------------------------------------------------------------" << endl;
    cout << "序号      姓名     性别     学号       班级      类别       电话号     成绩1     成绩2     成绩3     成绩4     成绩5       总成绩   平均成绩" << endl;
    int no = 1;
    student *ptr = first;
    while (ptr != last)
    {
        printf("%3d:", no++);
        ptr->print();
        ptr = ptr->next;
    }
}

student *studentMessage::Find(const char *x)
{
    student *ptr = first;
    while (ptr != last)
    {
        if (strcmp(ptr->name, x) == 0 || strcmp(ptr->num, x) == 0)
            break;
        ptr = ptr->next;
    }
    return ptr;
}

void studentMessage::Query()
{
    char x[30];
    cout << "输入你要查询的信息(学号或姓名)";
    cin >> x;
    student *ptr = Find(x);
    if (ptr == last)
    {
        cout << "没有查询到相关信息\n";
    }
    else
    {
        ptr->print();
    }
}

// 冒泡排序
studentMessage &studentMessage::Sort()
{
    int x;
    cout << "输入你想按照哪门课的成绩来排序?((1-5)总成绩输入6):";
    cin >> x;
    x--;
    student *ptr, *cnt = last;
    while (cnt != first)
    {
        ptr = first;
        while (ptr->next != cnt)
        {
            if (ptr->next->score[x] > ptr->score[x])
            {
                ptr->Swap();
            }
            ptr = ptr->next;
        }
        cnt = ptr;
    }
    return *this;
}
studentMessage &studentMessage::save()
{
    student *ptr, *hou = last;
    ptr = first;
    int i;
   	FILE *fp = NULL;
    if((fp = fopen("/Users/a20161104609/Desktop/markingsystem/markingstystem.csv","w")) != NULL )
    {
        fprintf(fp,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n","姓名:","性别：","班级：","项目名称：","联系方式:","成绩1：","成绩2：","成绩3：","成绩4：","成绩5：","总成绩：");
        while (ptr != hou)
  				  {
                      fprintf(fp,"%s ,%s, %s ,%s, %s,",ptr->name,ptr->sex,ptr->Class,ptr->form,ptr->tel);
                      for ( i= 0; i <6; )
                      {
                          fprintf(fp,"%f,",ptr->score[i]);
                          i++;
                      }
                      fprintf(fp,"\n");
                      ptr = ptr->next;
                  }
        
        
        
    }
    fclose(fp);
    
    return *this;
}






void studentMessage::menu()
{
    cout << "===============================\n";
    cout << "      裁判及其参赛人员成绩管理系统\n\n";
    cout << "      1.参赛人员显示排序后的成绩\n";
    cout << "      2.添加参赛人员信息\n";
    cout << "      3.查询参赛人员信息\n";
    cout << "      4.删除参赛人员信息\n";
    cout << "      5.运行参赛人员成绩排序程序\n";
    cout << "      6.删除参赛人员所有信息\n";
    cout << "      7.输入裁判信息\n";
    cout << "      8.输出裁判信息\n";
    cout << "      0.退出\n";
    cout << "===============================\n";
    
    
}

int main()
{
    studentMessage L;//声明有类的对象
    struct referee r[10];
    int a ;
    L.menu();//运行主菜单
    
    while (cin>>a)
    {
        switch(a)
        {
            case 1: L.print(); break;
            case 2: L.Append(); break;
            case 3: L.Query(); break;
            case 4: L.Delete(); break;
            case 5: L.Sort(); break;
            case 6: L.Clear(); break;
            case 7: put(r); break;
            case 8: output(r); break;
            case 0: L.save();break; 
                
        }
    }
    
    
    return 0;
}

