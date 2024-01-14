#ifndef SYSTEM_STUDENT_H
#define SYSTEM_STUDENT_H
#include <iostream>
#include <fstream>
#include "Course.h"

using namespace std;
class Student {
private:
    int id;//ѧ�����
    char name[20]{};//�����û���
    int course_num=0;//�������γ̵�����
    int course_id[20]{};//����Ŀγ̱��
    bool is_read[20][50]{};//֪ͨ�Ƿ��Ѷ������������Ϣ���һһ��Ӧ��

public:
    static int ID;//�������±��
    explicit Student(char[]);//��ʼ��
    static void Show_help();//��ʾ����
    void Show_unread_notice();//��ʾδ��֪ͨ
    void Show_read_notice(Course &) const;//��ʾ�Ѷ�֪ͨ
    void Show_unsubmitted_assignment() const;//��ʾδ�ύ��ҵ
    void Show_submitted_assignment(Course &) const;//��ʾ���ύ��ҵ
    void Join_course(int);//����γ�
    void Exit_course(int);//�˳��γ�
    void Show_score(int, const Course&) const;//��ʾ��ҵ�ɼ�
    void Submit_assignment(char[], int, Course &) const;
    void Teaching_evaluation(int, char[], Course &) const;//����
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
