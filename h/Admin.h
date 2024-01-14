#ifndef SYSTEM_ADMIN_H
#define SYSTEM_ADMIN_H
#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;
class Admin{
public:
    int notice_ID=0;//发送通知数
    char comment_notice[50][50]={};
    static void Show_help();//显示帮助
    static void Show_all_courses();//显示所有课程
    static void Show_all_teachers();//显示所有教师
    static void Show_all_students();//显示所有学生
    static void Show_all_assistants();//显示所有助教
    static void Query_course();//按照用户名和身份查询课程
    static void Dismiss_course();//解散课程
    static void Join_course(Student&, int);//将学生加入课程
    static void Exit_course(Student&, int);//将学生移出课程
    void Post_notice(char[]);//向教师发布通知
    ~Admin();
};


#endif //SYSTEM_ADMIN_H
