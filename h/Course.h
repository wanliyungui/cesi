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
    char name[20]{};//课程名
    int id;//课程编号

    int teacher_id;//任课老师的编号
    int number_assistant=0;//加入课程的助教数
    int assistant_id[5]={0};//加入课程的助教编号
    int number_student=0;//加入课程的学生数
    int student_id[30]={0};//加入课程的学生编号
    char comment[30][50]{};//学生评语（与学生的用户名一一对应）
    bool is_commented[30]={false};
    int evaluation_score[30]={0};//学生评分
    char submitted_assignment[10][30][50]={0};//学生提交的作业（与学生的编号一一对应）
    bool is_submitted[10][30]={false};//作业是否已提交（与学生的编号一一对应）
    int score[10][30]={0};//作业分数（与学生的编号一一对应）
    int Assignment_ID=0;//保存最新作业编号
    char content[10][50]={0};//课程作业内容
    double averagescore=0;//课程平均分
    int notice_ID=0;//通知数量
    char comment_notice[20][50]{};//通知内容
public:
    static int ID;//保存最新编号
    Course(int,char[]);//构造函数
    void addstudent(int);//添加学生至课程
    void addassistant(int);//添加助教至课程
    void calaverage();//计算课程平均分
    void exitstudent(int);
    void exitassistant(int);
    void get_name();//输出课程名称
    char* _name(){return name;}
    int _id() const{return id;}
    int _teacher_id() const{return teacher_id;}
    int _student_id(int i){return student_id[i];}
    int _assistant_id(int i){return assistant_id[i];}
    int _number_student() const{return number_student;}
    int _number_assistant() const{return number_assistant;}
    int _number_assignment() const{return Assignment_ID;}
    ~Course();//析构函数
};
#endif //SYSTEM_COURSE_H

