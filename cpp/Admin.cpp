#include <vector>
#include <cstring>
#include "../h/Admin.h"
#include "../h/Function.h"
extern vector<Student> STUDENT;
extern vector<Teacher> TEACHER;
extern vector<Assistant> ASSISTANT;
extern vector<Course> COURSE;
void Admin::Show_help()
{
    cout << "0:�˳�\n";
    cout << "1:�鿴���пγ�\n";
    cout << "2:�鿴����ѧ��\n";
    cout << "3:�鿴���н�ʦ\n";
    cout << "4:�鿴��������\n";
    cout << "5:�����û�������ݲ�ѯ�γ�\n";
    cout << "6:��ɢ�γ�\n";
    cout << "7:���ʦ����֪ͨ\n";
    cout << "8:��ѧ������γ�\n";
    cout << "9:��ѧ���Ƴ��γ�\n";
    cout << "������ָ����ִ�в���:\n";
}

void Admin::Show_all_courses(){
    for(auto & i : COURSE)
        i.get_name();
}

void Admin::Show_all_teachers(){
    for(auto & i : TEACHER)
        i.get_name();
}

void Admin::Show_all_students(){
    for(auto & i : STUDENT)
        i.get_name();
}

void Admin::Show_all_assistants(){
    for(auto & i : ASSISTANT)
        i.get_name();
}

void Admin::Query_course(){
    char name[20];
    int op;
    cout<<"0:��ʦ\n1:����\n2:ѧ��\n";
    cout<<"�������û�����\n";
    cin >> op;
    cout<<"��������ݣ�\n";
    cin>>name;
    if(op==0)
    {
        int id= find_out_teacher(name);
        Teacher &t= read_teacher(id);
        t.get_courses();
    }
    else if(op==1)
    {
        int id= find_out_assistant(name);
        Assistant &t= read_assistant(id);
        t.get_courses();
    }
    else if(op==2)
    {
        int id= find_out_student(name);
        Student &t= read_student(id);
        t.get_courses();
    }
    else cout<<"��ݴ���\n";
}

void Admin::Dismiss_course(){
    cout<<"������γ�����\n";
    char course_name[20];
    cin>>course_name;
    cout<<"�������ο���ʦ����\n";
    char teacher_name[20];
    cin>>teacher_name;
    int id= find_out_course(course_name, find_out_teacher(teacher_name));
    if(id==0)
        cout<<"�γ̲����ڣ�\n";
    else
    {
        delete_course(read_course(id));
        cout<<"�γ̽�ɢ�ɹ���\n";
    }
}

void Admin::Join_course(Student& s, int course_id){
    s.Join_course(course_id);
}

void Admin::Exit_course(Student& s, int course_id){
    s.Exit_course(course_id);
}

void Admin::Post_notice(char content[]) {
    strcpy(comment_notice[++notice_ID],content);
    cout<<"֪ͨ�ѳɹ�������\n";
}

Admin::~Admin() {}
