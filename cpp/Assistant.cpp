#include <cstring>
#include "../h/Assistant.h"
#include "../h/Function.h"
using namespace std;
int Assistant::ID = 0;
Assistant::Assistant(char name_assistant[])
{
    id=++ID;
    strcpy(name,name_assistant);
}
void Assistant::show_help()
{
    cout<<"1:加入课程"<<endl;
    cout<<"2:退出课程"<<endl;
    cout<<"3:发布课程通知"<<endl;
    cout<<"4:查看已发通知"<<endl;
    cout<<"5:作业评分"<<endl;
    cout<<"6:显示作业成绩"<<endl;
    cout<<"7:注销"<<endl;
    cout<<"0:退出"<<endl;
}
void Assistant::join_course(int id_course)
{
    course_id[course_num++] = id_course;
    Course &c = read_course(id_course);
    c.addassistant(id);
    cout<<"加入成功！";
}
void Assistant::exit_course(int id_course)
{
    bool flag = false;
    for(int i = 0; i < course_num; ++i)
    {
        if(course_id[i] == id_course)
            flag = true;
        if(flag)
            course_id[i] = course_id[i + 1];
    }
    if(flag)
    {
        course_num--;
        Course &c=read_course(id_course);
        c.exitassistant(id);
        cout<<"退出成功！\n";
    }
    else
        cout << "课程不存在！" << endl;
}
void Assistant::get_name()
{
    cout<<"助教用户名："<<name<<endl;
}
void Assistant::get_courses()
{
    cout<<"该助教加入的课程如下：\n";
    for(int i=0;i<course_num;++i)
    {
        Course &c=read_course(course_id[i]);
        c.get_name();
    }
}
int Assistant::GetCourseID(char CourseName[]) const
{
    for(int i = 0; i < course_num; ++i){
        Course &c = read_course(course_id[i]);
        if(strcmp(c.name,CourseName)==0)
            return course_id[i];
    }
    return 0;
}
Assistant::~Assistant() {}

