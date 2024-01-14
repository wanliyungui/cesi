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
    cout << "0:退出\n";
    cout << "1:查看所有课程\n";
    cout << "2:查看所有学生\n";
    cout << "3:查看所有教师\n";
    cout << "4:查看所有助教\n";
    cout << "5:按照用户名和身份查询课程\n";
    cout << "6:解散课程\n";
    cout << "7:向教师发送通知\n";
    cout << "8:将学生移入课程\n";
    cout << "9:将学生移出课程\n";
    cout << "请输入指令以执行操作:\n";
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
    cout<<"0:教师\n1:助教\n2:学生\n";
    cout<<"请输入用户名：\n";
    cin >> op;
    cout<<"请输入身份：\n";
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
    else cout<<"身份错误！\n";
}

void Admin::Dismiss_course(){
    cout<<"请输入课程名：\n";
    char course_name[20];
    cin>>course_name;
    cout<<"请输入任课老师名：\n";
    char teacher_name[20];
    cin>>teacher_name;
    int id= find_out_course(course_name, find_out_teacher(teacher_name));
    if(id==0)
        cout<<"课程不存在！\n";
    else
    {
        delete_course(read_course(id));
        cout<<"课程解散成功！\n";
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
    cout<<"通知已成功发布。\n";
}

Admin::~Admin() {}
