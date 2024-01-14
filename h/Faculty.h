#ifndef SYSTEM_FACULTY_H
#define SYSTEM_FACULTY_H
#include<iostream>
#include <fstream>
#include <utility>
#include "Course.h"
using namespace std;
class Faculty{
    friend class Course;
public:
    virtual void show_help()= 0;
    static void Post_notice(Course& , char[]);//发布通知
    static void Show_notice(const Course&);//显示已发通知
    static void Grade_assignment(Course&,int);//查看作业并评分
    static void Show_score(const Course& c,int t);//教师和助教可以具体查看某次作业全班所有同学的分数
    int id{};//教员编号
    char name[20]{};//用户名
};
#endif //SYSTEM_FACULTY_H
