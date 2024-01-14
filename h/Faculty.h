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
    static void Post_notice(Course& , char[]);//����֪ͨ
    static void Show_notice(const Course&);//��ʾ�ѷ�֪ͨ
    static void Grade_assignment(Course&,int);//�鿴��ҵ������
    static void Show_score(const Course& c,int t);//��ʦ�����̿��Ծ���鿴ĳ����ҵȫ������ͬѧ�ķ���
    int id{};//��Ա���
    char name[20]{};//�û���
};
#endif //SYSTEM_FACULTY_H
