#ifndef SYSTEM_COURSE_H
#define SYSTEM_COURSE_H
#include<iostream>
#include<fstream>
using namespace std;
class Course {
    friend class Student;
    friend class Faculty;
    friend class Teacher;
    friend class Assistant;
private:
    char name[20]{};//�γ���
    int id;//�γ̱��

    int teacher_id;//�ο���ʦ�ı��
    int number_assistant=0;//����γ̵�������
    int assistant_id[5]={0};//����γ̵����̱��
    int number_student=0;//����γ̵�ѧ����
    int student_id[30]={0};//����γ̵�ѧ�����
    char comment[30][50]{};//ѧ�������ѧ�����û���һһ��Ӧ��
    bool is_commented[30]={false};
    int evaluation_score[30]={0};//ѧ������
    char submitted_assignment[10][30][50]={0};//ѧ���ύ����ҵ����ѧ���ı��һһ��Ӧ��
    bool is_submitted[10][30]={false};//��ҵ�Ƿ����ύ����ѧ���ı��һһ��Ӧ��
    int score[10][30]={0};//��ҵ��������ѧ���ı��һһ��Ӧ��
    int Assignment_ID=0;//����������ҵ���
    char content[10][50]={0};//�γ���ҵ����
    double averagescore=0;//�γ�ƽ����
    int notice_ID=0;//֪ͨ����
    char comment_notice[20][50]{};//֪ͨ����
public:
    static int ID;//�������±��
    Course(int,char[]);//���캯��
    void addstudent(int);//���ѧ�����γ�
    void addassistant(int);//����������γ�
    void calaverage();//����γ�ƽ����
    void exitstudent(int);
    void exitassistant(int);
    void get_name();//����γ�����
    char* _name(){return name;}
    int _id() const{return id;}
    int _teacher_id() const{return teacher_id;}
    int _student_id(int i){return student_id[i];}
    int _assistant_id(int i){return assistant_id[i];}
    int _number_student() const{return number_student;}
    int _number_assistant() const{return number_assistant;}
    int _number_assignment() const{return Assignment_ID;}
    ~Course();//��������
};
#endif //SYSTEM_COURSE_H

