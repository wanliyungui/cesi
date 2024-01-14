#ifndef SYSTEM_ASSISTANT_H
#define SYSTEM_ASSISTANT_H
#include <iostream>
#include "Faculty.h"
using namespace std;
class Assistant:public Faculty{
private:
    int course_num{};//�������γ̵�����
    int course_id[10]={0};//�γ̱��
public:
    static int ID;//�������±��
    explicit Assistant(char[]);//��ʼ��
    void show_help() override;//��ʾ����
    void join_course(int);//����γ�
    void exit_course(int);//�˳��γ�
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

