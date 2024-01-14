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

    int course_num=0;//�ֱ𱣴洴���γ̵�����
    int course_id[50]={};//�����Ŀγ̱��
    bool is_read[50]{};//֪ͨ�����Խ����Ƿ��Ѷ������������Ϣ���һһ��Ӧ��
public:
    static int ID;//�������±��
    explicit Teacher(char[]);//��ʼ��
    void show_help() override;//��ʾ����
    void Show_unread_notice(Admin&);//��ʾδ��֪ͨ�����Խ���
    void get_name();
    void get_courses();

    static void Assign_assignment(Course &  ,char[]);//������ҵ
    static void Show_assignment(const Course &);//��ʾ�Ѳ�����ҵ

    void Create_course(char []);//�����γ�
    void exit_course(int);//�˳��γ�,�����ɢ
    static void Show_evaluation(Course & );//��ʾ���̵ľ��ֺ���������
    char* _name(){return Teacher::name;}
    int _id(){return Teacher::id;}
    int _course_num() const{return course_num;}
    int _course_id(int i){return course_id[i];}

    ~Teacher();
};


#endif //SYSTEM_TEACHER_H
