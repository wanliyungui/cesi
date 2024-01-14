#include <vector>
#include <cstring>
#include "../h/Function.h"
extern vector<Student> STUDENT;
extern vector<Teacher> TEACHER;
extern vector<Assistant> ASSISTANT;
extern vector<Course> COURSE;
int find_out_student(char name[])//通过用户名查找学生id
{
    for(auto & i : STUDENT)
        if(strcmp(i._name(),name)==0)
            return i._id();
    return 0;
}
int find_out_teacher(char name[])//通过用户名查找教师id
{
    for(auto & i : TEACHER)
        if(strcmp(i._name(),name)==0)
            return i._id();
    return 0;
}
int find_out_assistant(char name[])//通过用户名查找助教id
{
    for(auto & i : ASSISTANT)
        if(strcmp(i._name(),name)==0)
            return i._id();
    return 0;
}
int find_out_course(char name[],int teacher_id)//通过名称和任课老师id查找课程id
{
    for(auto & i : COURSE)
        if(!strcmp(i._name(),name)&&i._teacher_id()==teacher_id)
            return i._id();
    return 0;
}
Student &read_student(int id)//通过id查找学生
{
    for(auto & i : STUDENT)
        if(i._id()==id)
            return i;
}
Teacher &read_teacher(int id)//通过id查找教师
{
    for(auto & i : TEACHER)
        if(i._id()==id)
            return i;
}
Assistant &read_assistant(int id)//通过id查找助教
{
    for(auto & i : ASSISTANT)
        if(i._id()==id)
            return i;
}
Course &read_course(int id)//通过id查找课程
{
    for(auto & i : COURSE)
        if(i._id()==id)
            return i;
}
void delete_student(Student& a)//删除学生
{
    for(int i=0;i<a._course_num();++i)
        a.Exit_course(a._course_id(i));
    for(int i=0;i<STUDENT.size();++i)
        if(STUDENT[i]._id()==a._id())
            STUDENT.erase(STUDENT.begin()+i);
}
void delete_assistant(Assistant& a)//删除助教
{
    for(int i=0;i<a._course_num();++i)
        a.exit_course(a._course_id(i));
    for(int i=0;i<ASSISTANT.size();++i)
        if(ASSISTANT[i]._id()==a._id())
            ASSISTANT.erase(ASSISTANT.begin()+i);
}
void delete_course(Course& a)
{
    read_teacher(a._teacher_id()).exit_course(a._id());
    for(int i=0;i<a._number_student();++i)
        read_student(a._student_id(i)).Exit_course(a._id());
    for(int i=0;i<a._number_assistant();++i)
        read_assistant(a._assistant_id(i)).exit_course(a._id());
    for(int i=0;i<COURSE.size();++i)
        if(COURSE[i]._id()==a._id())
            COURSE.erase(COURSE.begin()+i);
}
void delete_teacher(Teacher& a)
{
    for(int i=0;i<a._course_num();++i)
        delete_course(read_course(a._course_id(i)));
    for(int i=0;i<TEACHER.size();++i)
        if(TEACHER[i]._id()==a._id())
            TEACHER.erase(TEACHER.begin()+i);
}
void add_course(const Course& c)
{
    COURSE.push_back(c);
}
void add_student(const Student& c)
{
    STUDENT.push_back(c);
}
void add_teacher(const Teacher& c)
{
    TEACHER.push_back(c);
}
void add_assistant(const Assistant& c)
{
    ASSISTANT.push_back(c);
}