#ifndef SYSTEM_ASSISTANT_H
#define SYSTEM_ASSISTANT_H
#include <iostream>
#include "Faculty.h"
using namespace std;
class Assistant:public Faculty{
private:
    int course_num{};//保存加入课程的数量
    int course_id[10]={0};//课程编号
public:
    static int ID;//保存最新编号
    explicit Assistant(char[]);//初始化
    void show_help() override;//显示帮助
    void join_course(int);//加入课程
    void exit_course(int);//退出课程
    void get_name();
    void get_courses();
    int GetCourseID(char[]) const;
    char* _name(){return Assistant::name;}
    int _id(){return Assistant::id;}
    int _course_num() const{return course_num;}
    int _course_id(int i){return course_id[i];}
    ~Assistant();
};
#endif //SYSTEM_ASSISTANT_H

