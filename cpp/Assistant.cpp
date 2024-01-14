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
    cout<<"1:����γ�"<<endl;
    cout<<"2:�˳��γ�"<<endl;
    cout<<"3:�����γ�֪ͨ"<<endl;
    cout<<"4:�鿴�ѷ�֪ͨ"<<endl;
    cout<<"5:��ҵ����"<<endl;
    cout<<"6:��ʾ��ҵ�ɼ�"<<endl;
    cout<<"7:ע��"<<endl;
    cout<<"0:�˳�"<<endl;
}
void Assistant::join_course(int id_course)
{
    course_id[course_num++] = id_course;
    Course &c = read_course(id_course);
    c.addassistant(id);
    cout<<"����ɹ���";
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
        cout<<"�˳��ɹ���\n";
    }
    else
        cout << "�γ̲����ڣ�" << endl;
}
void Assistant::get_name()
{
    cout<<"�����û�����"<<name<<endl;
}
void Assistant::get_courses()
{
    cout<<"�����̼���Ŀγ����£�\n";
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

