#ifndef SYSTEM_TEACHER_H
#define SYSTEM_TEACHER_H
#include <iostream>
#include <utility>
#include "Faculty.h"
#include "Course.h"
#include "Admin.h"
using namespace std;
class Teacher :public Faculty{
private:

    int course_num=0;//分别保存创建课程的数量
    int course_id[50]={};//创建的课程编号
    bool is_read[50]{};//通知（来自教务）是否已读（与上面的消息编号一一对应）
public:
    static int ID;//保存最新编号
    explicit Teacher(char[]);//初始化
    void show_help() override;//显示帮助
    void Show_unread_notice(Admin&);//显示未读通知（来自教务）
    void get_name();
    void get_courses();

    static void Assign_assignment(Course &  ,char[]);//布置作业
    static void Show_assignment(const Course &);//显示已布置作业

    void Create_course(char []);//创建课程
    void exit_course(int);//退出课程,方便解散
    static void Show_evaluation(Course & );//显示评教的均分和所有评语
    char* _name(){return Teacher::name;}
    int _id(){return Teacher::id;}
    int _course_num() const{return course_num;}
    int _course_id(int i){return course_id[i];}

    ~Teacher();
};


#endif //SYSTEM_TEACHER_H
