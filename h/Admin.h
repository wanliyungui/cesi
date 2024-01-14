#ifndef SYSTEM_ADMIN_H
#define SYSTEM_ADMIN_H
#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;
class Admin{
public:
    int notice_ID=0;//����֪ͨ��
    char comment_notice[50][50]={};
    static void Show_help();//��ʾ����
    static void Show_all_courses();//��ʾ���пγ�
    static void Show_all_teachers();//��ʾ���н�ʦ
    static void Show_all_students();//��ʾ����ѧ��
    static void Show_all_assistants();//��ʾ��������
    static void Query_course();//�����û�������ݲ�ѯ�γ�
    static void Dismiss_course();//��ɢ�γ�
    static void Join_course(Student&, int);//��ѧ������γ�
    static void Exit_course(Student&, int);//��ѧ���Ƴ��γ�
    void Post_notice(char[]);//���ʦ����֪ͨ
    ~Admin();
};


#endif //SYSTEM_ADMIN_H
