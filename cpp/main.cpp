#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include "../h/Function.h"
using namespace std;
vector<Student> STUDENT;
vector<Teacher> TEACHER;
vector<Assistant> ASSISTANT;
vector<Course> COURSE;
Admin ad;
void main_window();
void sign_up();
void READ();//从文件中读取数据
void WRITE();//从文件中写入数据

int main() {
    READ();//从文件中读取数据
    cout<<"欢迎使用在线教学管理系统！\n";
    main_window();
    WRITE();//从文件中写入数据
    return 0;
}
void READ()//从文件中读取数据
{
    char NAME[20]="NAME";
    ifstream file1("../data/student.dat", ios::in | ios::binary);
    Student data1(NAME);
    while (file1.read((char *)(&data1), sizeof(Student)))
        STUDENT.push_back(data1);
    file1.close();//读取学生数据
    if(!STUDENT.empty())Student::ID=STUDENT[STUDENT.size()-1]._id();

    ifstream file2("../data/teacher.dat", ios::in | ios::binary);
    Teacher data2(NAME);
    while (file2.read((char *)(&data2), sizeof(Teacher)))
        TEACHER.push_back(data2);
    file2.close();//读取教师数据
    if(!TEACHER.empty())Teacher::ID=TEACHER[TEACHER.size()-1]._id();

    ifstream file3("../data/assistant.dat", ios::in | ios::binary);
    Assistant data3(NAME);
    while (file3.read((char *)(&data3), sizeof(Assistant)))
        ASSISTANT.push_back(data3);
    file3.close();//读取助教数据
    if(!ASSISTANT.empty())Assistant::ID=ASSISTANT[ASSISTANT.size()-1]._id();

    ifstream file4("../data/course.dat", ios::in | ios::binary);
    Course data4(0,NAME);
    while (file4.read((char *)(&data4), sizeof(Course)))
        COURSE.push_back(data4);
    file4.close();//读取课程数据
    if(!COURSE.empty())Course::ID=COURSE[COURSE.size()-1]._id();

    ifstream file5("../data/admin.dat", ios::in | ios::binary);
    Admin data5;
    file5.read((char *)(&data5), sizeof(Admin));
    ad=data5;
    file5.close();//读取管理员数据

}
void WRITE()//从文件中写入数据
{
    ofstream o1("../data/student.dat",ios::out | ios::binary | ios::trunc);
    for (auto & i : STUDENT)
        o1.write((const char *)(&i), sizeof(Student));
    o1.close();//写入学生数据

    ofstream o2("../data/teacher.dat",ios::out | ios::binary | ios::trunc);
    for (auto & i : TEACHER)
        o2.write((const char *)(&i), sizeof(Teacher));
    o2.close();//写入教师数据

    ofstream o3("../data/assistant.dat",ios::out | ios::binary | ios::trunc);
    for (auto & i : ASSISTANT)
        o3.write((const char *)(&i), sizeof(Assistant));
    o3.close();//写入助教数据

    ofstream o4("../data/course.dat",ios::out | ios::binary | ios::trunc);
    for (auto & i : COURSE)
        o4.write((const char *)(&i), sizeof(Course));
    o4.close();//写入课程数据

    ofstream o5("../data/admin.dat",ios::out | ios::binary | ios::trunc);
    o5.write((const char *)(&ad), sizeof(Admin));
    o5.close();//写入管理员数据
}
void sign_up()
{
    char op;
    cout<<"0:教师\n1:助教\n2:学生\n";
    cout<<"请输入身份：\n";
    cin>>op;
    if(op!='0' && op!='1' && op!= '2')
    {
        cout<<"身份有误!\n";
        return;
    }
    char name[20];
    cout<<"请输入用户名：\n";
    cin>>name;
    if(strlen(name)==0)
    {
        cout<<"用户名不能为空!\n";
        return;
    }
    while(find_out_student(name)|find_out_teacher(name)|find_out_assistant(name))
    {
        cout<<"用户名已被使用，请重试！\n";
        return;
    }
    if(op=='0')
    {
        Teacher t(name);
        add_teacher(t);
        cout<<"注册成功！\n";
    }
    if(op=='1')
    {
        Assistant as(name);
        add_assistant(as);
        cout<<"注册成功！\n";
    }
    if(op=='2')
    {
        Student stu(name);
        add_student(stu);
        cout<<"注册成功！\n";
    }
}
void admin_window()
{
    char student_name[20],course_name[20],teacher_name[20],content[100],op;
    while(true)
    {
        Admin::Show_help();
        cin>>op;
        switch(op)
        {
            case '0'://退出
                return;
            case '1'://显示所有课程
                Admin::Show_all_courses();
                break;
            case '2'://显示所有学生
                Admin::Show_all_students();
                break;
            case '3'://显示所有教师
                Admin::Show_all_teachers();
                break;
            case '4'://显示所有助教
                Admin::Show_all_assistants();
                break;
            case '5'://按照用户名和身份查询课程
                Admin::Query_course();
                break;
            case '6'://解散课程
                Admin::Dismiss_course();
                break;
            case '7'://向教师发通知
                cout<<"请输入通知内容：\n";
                cin.get();
                cin.getline(content,50);
                ad.Post_notice(content);
                break;
            case '8'://将学生加入课程
            case '9'://将学生移出课程
                cout<<"请输入学生用户名：\n";
                cin>>student_name;
                cout<<"请输入课程名：\n";
                cin>>course_name;
                cout<<"请输入任课老师用户名：\n";
                cin>>teacher_name;
                if(op=='8')
                    Admin::Join_course(read_student(find_out_student(student_name)),
                                   find_out_course(course_name, find_out_teacher(teacher_name)));
                if(op=='9')
                    Admin::Exit_course(read_student(find_out_student(student_name)),
                                   find_out_course(course_name, find_out_teacher(teacher_name)));
                break;
            default:
                cout<<"指令错误，请重新输入!\n";
        }
    }
}
void student_window(char name[])
{
    Student &stu= read_student(find_out_student(name));
    char op;
    stu.Show_unread_notice();
    stu.Show_unsubmitted_assignment();
    while(true)
    {
        Student::Show_help();
        cin>>op;
        char course_name[20],teacher_name[20];
        int id;
        switch(op)
        {
            case '0':
                return;
            case '1':
            case '2':
                cout<<"请输入相应课程：\n";
                cin>>course_name;
                id=stu.GetCourseID(course_name);
                if(id==0)cout<<"课程不存在或尚未加入该课程！\n";
                else
                {
                    if(op=='1')stu.Show_read_notice(read_course(id));
                    if(op=='2')stu.Show_submitted_assignment(read_course(id));
                }
                break;
            case '3':
                cout<<"请输入相应课程：\n";
                cin>>course_name;
                id=stu.GetCourseID(course_name);
                if(id==0)cout<<"课程不存在或尚未加入该课程！\n";
                else
                {
                    cout<<"请输入要提交的作业编号：\n";
                    int asid;
                    cin>>asid;
                    if(asid >= 1 && asid <= read_course(id)._number_assignment()){
                        cout<<"请输入作业内容：\n";
                        char content[100];
                        cin.get();
                        cin.getline(content, 100); // cin>>content;
                        stu.Submit_assignment(content,asid,read_course(id));
                        cout<<"提交成功！\n";
                    }
                    else{
                        cout << "该作业不存在！ \n";
                    }
                }
                break;
            case '4':
                cout<<"请输入相应课程：\n";
                cin>>course_name;
                id=stu.GetCourseID(course_name);
                if(id==0)cout<<"课程不存在或尚未加入该课程！\n";
                else
                {
                    cout<<"请输入要查看的作业编号：\n";
                    int asid;
                    cin>>asid;
                    stu.Show_score(asid,read_course(id));
                }
                break;
            case '5':
                cout<<"请输入要加入的课程：\n";
                cin>>course_name;
                cout<<"请输入老师的用户名：\n";
                cin>>teacher_name;
                id=find_out_course(course_name, find_out_teacher(teacher_name));
                if(id==0)cout<<"课程不存在！\n";
                else stu.Join_course(id);
                break;
            case '6':
                cout<<"请输入要退出的课程：\n";
                cin>>course_name;
                id=stu.GetCourseID(course_name);
                if(id==0)cout<<"课程不存在或尚未加入该课程！\n";
                else stu.Exit_course(id);
                break;
            case '7':
                cout<<"请输入要评教的课程：\n";
                cin>>course_name;
                id=stu.GetCourseID(course_name);
                if(id==0)cout<<"课程不存在或尚未加入该课程！\n";
                else
                {
                    int score;
                    char comment[100];
                    cout<<"请输入评教分数：\n";
                    cin>>score;
                    cout<<"请输入评语:\n";
                    cin.get();
                    cin.getline(comment, 50); // cin>>comment;
                    stu.Teaching_evaluation(score,comment,read_course(id));
                    cout<<"评教成功！\n";
                }
                break;
            case '8':
                delete_student(stu);
                cout<<"注销成功！\n";
                return ;
            default:
                cout<<"指令错误，请重新输入!\n";
        }
    }
}
void teacher_window(char name[])
{
    Teacher &tea=read_teacher(find_out_teacher(name));
    char op;
    tea.Show_unread_notice(ad);//显示来自教务的未读通知
    while(true) {
        tea.show_help();
        cin >> op;
        char course_name[20], content[100];
        int Id, t;
        switch (op) {
            case '0':
                return;
            case '1':
                cout << "请输入课程名称：\n";
                cin>>course_name;
                Id = find_out_course(course_name, tea.id);
                if (Id != 0) {
                    cout << "您已创建同名课程！\n";
                } else {
                    tea.Create_course(course_name);
                    cout << "课程创建成功！\n";
                }
                break;
            case '2':
                cout << "请输入要解散的课程名称：\n";
                cin>>course_name;
                Id = find_out_course(course_name, tea.id);
                if (Id == 0) {
                    cout << "您尚未创建该课程！\n";
                } else {
                    delete_course(read_course(Id));
                    cout << "课程解散成功！\n";
                }
                break;
            case '3':
                cout << "请输入课程名称：\n";
                cin>>course_name;
                Id = find_out_course(course_name, tea.id);
                if (Id == 0) {
                    cout << "课程不存在！\n";
                } else {
                    cout << "请输入通知内容：\n";
                    cin.get();
                    cin.getline(content, 50); // cin>>content ;
                    Teacher::Post_notice(read_course(Id), content);
                }
                break;
            case '4':
                cout << "请输入课程名称：\n";
                cin>>course_name;
                Id = find_out_course(course_name, tea.id);
                if (Id == 0) {
                    cout << "课程不存在！\n";
                } else {
                    Teacher::Show_notice(read_course(Id));
                }
                break;
            case '5':
                cout << "请输入课程名称：\n";
                cin>>course_name;
                Id = find_out_course(course_name, tea.id);
                if (Id == 0) {
                    cout << "课程不存在！\n";
                } else {
                    cout << "请输入作业内容：\n";
                    cin.get();
                    cin.getline(content, 50); // cin>>content ;
                    Teacher::Assign_assignment(read_course(Id), content);
                    cout << "作业布置成功！\n";
                }
                break;
            case '6':
                cout << "请输入课程名称：\n";
                cin>>course_name;
                Id = find_out_course(course_name, tea.id);
                if (Id == 0) {
                    cout << "课程不存在！\n";
                } else {
                    Teacher::Show_assignment(read_course(Id));
                }
                break;
            case '7':
                cout << "请输入课程名称：\n";
                cin>>course_name;
                Id = find_out_course(course_name, tea.id);
                if (Id == 0) {
                    cout << "课程不存在！\n";
                } else {
                    cout << "请输入第几次作业：\n";
                    cin >> t;
                    if(t >= 1 && t <= read_course(Id)._number_assignment()){
                        Teacher::Grade_assignment(read_course(Id), t);
                    }
                    else{
                        cout << "该作业不存在！ \n";
                    }
                }
                break;
            case '8':
                cout << "请输入课程名称：\n";
                cin>>course_name;
                Id = find_out_course(course_name, tea.id);
                if (Id == 0)
                    cout << "课程不存在！\n";
                else
                    Teacher::Show_evaluation(read_course(Id));
                break;
            case '9':
                cout << "请输入课程名称：\n";
                cin>>course_name;
                Id = find_out_course(course_name, tea.id);
                if (Id == 0) {
                    cout << "课程不存在！\n";
                } else {
                    int tt;
                    cout << "请输入需要查看第几次作业：\n";
                    cin >> tt;
                    if(tt >= 1 && tt <= read_course(Id)._number_assignment()){
                        Teacher::Show_score(read_course(Id), tt);
                    }
                    else{
                        cout << "该作业不存在！ \n";
                    }
                }
                break;
            case 'A':
                delete_teacher(tea);
                cout << "注销成功！\n";
                return;
            default:
                cout << "指令错误，请重新输入!\n";
        }
    }

}
void assistant_window(char name[])
{
    Assistant &as=read_assistant(find_out_assistant(name));
    int t;
    char op;
    while(true)
    {
        as.show_help();
        cin>>op;
        char course_name[20],content[100],teacher_name[20];
        int Id;
        switch(op)
        {
            case '0':
                return;
            case '1':
                cout<<"请输入要加入的课程：\n";
                cin>>course_name;
                cout<<"请输入老师的用户名：\n";
                cin>>teacher_name;
                Id=find_out_course(course_name, find_out_teacher(teacher_name));
                if(Id==0)cout<<"课程不存在！\n";
                else as.join_course(Id);
                break;
            case '2':
                cout<<"请输入要退出的课程：\n";
                cin>>course_name;
                Id=as.GetCourseID(course_name);
                if(Id==0)cout<<"课程不存在或尚未加入该课程！\n";
                else as.exit_course(Id);
                break;
            case '3':
                cout<<"请输入课程名称：\n";
                cin>>course_name;
                Id=as.GetCourseID(course_name);
                if(Id==0)
                {
                    cout<<"课程不存在！\n";
                }
                else
                {
                    cout<<"请输入通知内容：\n";
                    cin.get();
                    cin.getline(content, 50); // cin>>content;
                    Assistant::Post_notice(read_course(Id),content);
                }
                break;
            case '4':
                cout<<"请输入课程名称：\n";
                cin>>course_name;
                Id=as.GetCourseID(course_name);
                if(Id==0)
                {
                    cout<<"课程不存在！\n";
                }
                else
                {
                    Assistant::Show_notice(read_course(Id));
                }
                break;
            case '5':
                cout<<"请输入课程名称：\n";
                cin>>course_name;
                Id=as.GetCourseID(course_name);
                if(Id==0)
                {
                    cout<<"课程不存在！\n";
                }
                else
                {
                    cout<<"请输入第几次作业：\n";
                    cin>>t;
                    if(t >= 1 && t <= read_course(Id)._number_assignment()){
                        Assistant::Grade_assignment(read_course(Id),t);
                    }
                    else{
                        cout << "该作业不存在！ \n";
                    }
                }
                break;
            case '6'://显示作业成绩
                cout<<"请输入课程名称：\n";
                cin>>course_name;
                cout<<"请输入任课老师用户名：\n";
                cin>>teacher_name;
                Id= find_out_course(course_name, find_out_teacher(teacher_name));
                if(Id==0)
                    cout<<"课程不存在！\n";
                else
                {
                    int tt;
                    cout<<"请输入需要查看第几次作业：\n";
                    cin>>tt;
                    if(tt >= 1 && tt <= read_course(Id)._number_assignment()){
                        Assistant::Show_score(read_course(Id),tt);
                    }
                    else{
                        cout << "该作业不存在！ \n";
                    }
                }
                break;
            case '7':
                delete_assistant(as);
                cout<<"注销成功！\n";
                return ;
            default:
                cout<<"指令错误，请重新输入!\n";
        }
    }
}
void log_in()
{
    char name[20];
    cout<<"请输入用户名:\n";
    cin>>name;
    cin.get();
    if(strcmp(name,"Admin")==0)
    {
        cout<<"请输入密码：\n";
        char password[20];
        cin>>password;
        if(strcmp(password,"P@ssw0rd")!=0)
        {
            cout<<"密码错误！\n";
            return;
        }
        else admin_window();
    }
    else if(find_out_student(name))
        student_window(name);
    else if(find_out_assistant(name))
        assistant_window(name);
    else if(find_out_teacher(name))
        teacher_window(name);
    else
        cout<<"用户名不存在！\n";
}
void main_window()
{
    char op;
    while(true)
    {
        cout<<"1:注册\n2:登录\n0:退出\n";
        cout<<"请输入指令以执行操作:\n";
        cin>>op;
        switch(op)
        {
            case '1':
                sign_up();
                break;
            case '2':
                log_in();
                break;
            case '0':
                return;
            default:
                cout<<"指令错误，请重新输入!\n";
        }
    }
}