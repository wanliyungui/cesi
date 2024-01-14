#ifndef SYSTEM_STUDENT_H
#define SYSTEM_STUDENT_H
#include <iostream>
#include <fstream>
#include "Course.h"

using namespace std;
class Student {
private:
    int id;//学生编号
    char name[20]{};//保存用户名
    int course_num=0;//保存加入课程的数量
    int course_id[20]{};//加入的课程编号
    bool is_read[20][50]{};//通知是否已读（与上面的消息编号一一对应）

public:
    static int ID;//保存最新编号
    explicit Student(char[]);//初始化
    static void Show_help();//显示帮助
    void Show_unread_notice();//显示未读通知
    void Show_read_notice(Course &) const;//显示已读通知
    void Show_unsubmitted_assignment() const;//显示未提交作业
    void Show_submitted_assignment(Course &) const;//显示已提交作业
    void Join_course(int);//加入课程
    void Exit_course(int);//退出课程
    void Show_score(int, const Course&) const;//显示作业成绩
    void Submit_assignment(char[], int, Course &) const;
    void Teaching_evaluation(int, char[], Course &) const;//评教
    int GetCourseID(char[]) const;
    void get_name();
    void get_courses();
    char* _name(){return name;}
    int _id() const{return id;}
    int _course_num() const{return course_num;}
    int _course_id(int i){return course_id[i];}
    ~Student();
};
#endif //SYSTEM_STUDENT_H
