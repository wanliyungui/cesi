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
void READ();//���ļ��ж�ȡ����
void WRITE();//���ļ���д������

int main() {
    READ();//���ļ��ж�ȡ����
    cout<<"��ӭʹ�����߽�ѧ����ϵͳ��\n";
    main_window();
    WRITE();//���ļ���д������
    return 0;
}
void READ()//���ļ��ж�ȡ����
{
    char NAME[20]="NAME";
    ifstream file1("../data/student.dat", ios::in | ios::binary);
    Student data1(NAME);
    while (file1.read((char *)(&data1), sizeof(Student)))
        STUDENT.push_back(data1);
    file1.close();//��ȡѧ������
    if(!STUDENT.empty())Student::ID=STUDENT[STUDENT.size()-1]._id();

    ifstream file2("../data/teacher.dat", ios::in | ios::binary);
    Teacher data2(NAME);
    while (file2.read((char *)(&data2), sizeof(Teacher)))
        TEACHER.push_back(data2);
    file2.close();//��ȡ��ʦ����
    if(!TEACHER.empty())Teacher::ID=TEACHER[TEACHER.size()-1]._id();

    ifstream file3("../data/assistant.dat", ios::in | ios::binary);
    Assistant data3(NAME);
    while (file3.read((char *)(&data3), sizeof(Assistant)))
        ASSISTANT.push_back(data3);
    file3.close();//��ȡ��������
    if(!ASSISTANT.empty())Assistant::ID=ASSISTANT[ASSISTANT.size()-1]._id();

    ifstream file4("../data/course.dat", ios::in | ios::binary);
    Course data4(0,NAME);
    while (file4.read((char *)(&data4), sizeof(Course)))
        COURSE.push_back(data4);
    file4.close();//��ȡ�γ�����
    if(!COURSE.empty())Course::ID=COURSE[COURSE.size()-1]._id();

    ifstream file5("../data/admin.dat", ios::in | ios::binary);
    Admin data5;
    file5.read((char *)(&data5), sizeof(Admin));
    ad=data5;
    file5.close();//��ȡ����Ա����

}
void WRITE()//���ļ���д������
{
    ofstream o1("../data/student.dat",ios::out | ios::binary | ios::trunc);
    for (auto & i : STUDENT)
        o1.write((const char *)(&i), sizeof(Student));
    o1.close();//д��ѧ������

    ofstream o2("../data/teacher.dat",ios::out | ios::binary | ios::trunc);
    for (auto & i : TEACHER)
        o2.write((const char *)(&i), sizeof(Teacher));
    o2.close();//д���ʦ����

    ofstream o3("../data/assistant.dat",ios::out | ios::binary | ios::trunc);
    for (auto & i : ASSISTANT)
        o3.write((const char *)(&i), sizeof(Assistant));
    o3.close();//д����������

    ofstream o4("../data/course.dat",ios::out | ios::binary | ios::trunc);
    for (auto & i : COURSE)
        o4.write((const char *)(&i), sizeof(Course));
    o4.close();//д��γ�����

    ofstream o5("../data/admin.dat",ios::out | ios::binary | ios::trunc);
    o5.write((const char *)(&ad), sizeof(Admin));
    o5.close();//д�����Ա����
}
void sign_up()
{
    char op;
    cout<<"0:��ʦ\n1:����\n2:ѧ��\n";
    cout<<"��������ݣ�\n";
    cin>>op;
    if(op!='0' && op!='1' && op!= '2')
    {
        cout<<"�������!\n";
        return;
    }
    char name[20];
    cout<<"�������û�����\n";
    cin>>name;
    if(strlen(name)==0)
    {
        cout<<"�û�������Ϊ��!\n";
        return;
    }
    while(find_out_student(name)|find_out_teacher(name)|find_out_assistant(name))
    {
        cout<<"�û����ѱ�ʹ�ã������ԣ�\n";
        return;
    }
    if(op=='0')
    {
        Teacher t(name);
        add_teacher(t);
        cout<<"ע��ɹ���\n";
    }
    if(op=='1')
    {
        Assistant as(name);
        add_assistant(as);
        cout<<"ע��ɹ���\n";
    }
    if(op=='2')
    {
        Student stu(name);
        add_student(stu);
        cout<<"ע��ɹ���\n";
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
            case '0'://�˳�
                return;
            case '1'://��ʾ���пγ�
                Admin::Show_all_courses();
                break;
            case '2'://��ʾ����ѧ��
                Admin::Show_all_students();
                break;
            case '3'://��ʾ���н�ʦ
                Admin::Show_all_teachers();
                break;
            case '4'://��ʾ��������
                Admin::Show_all_assistants();
                break;
            case '5'://�����û�������ݲ�ѯ�γ�
                Admin::Query_course();
                break;
            case '6'://��ɢ�γ�
                Admin::Dismiss_course();
                break;
            case '7'://���ʦ��֪ͨ
                cout<<"������֪ͨ���ݣ�\n";
                cin.get();
                cin.getline(content,50);
                ad.Post_notice(content);
                break;
            case '8'://��ѧ������γ�
            case '9'://��ѧ���Ƴ��γ�
                cout<<"������ѧ���û�����\n";
                cin>>student_name;
                cout<<"������γ�����\n";
                cin>>course_name;
                cout<<"�������ο���ʦ�û�����\n";
                cin>>teacher_name;
                if(op=='8')
                    Admin::Join_course(read_student(find_out_student(student_name)),
                                   find_out_course(course_name, find_out_teacher(teacher_name)));
                if(op=='9')
                    Admin::Exit_course(read_student(find_out_student(student_name)),
                                   find_out_course(course_name, find_out_teacher(teacher_name)));
                break;
            default:
                cout<<"ָ���������������!\n";
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
                cout<<"��������Ӧ�γ̣�\n";
                cin>>course_name;
                id=stu.GetCourseID(course_name);
                if(id==0)cout<<"�γ̲����ڻ���δ����ÿγ̣�\n";
                else
                {
                    if(op=='1')stu.Show_read_notice(read_course(id));
                    if(op=='2')stu.Show_submitted_assignment(read_course(id));
                }
                break;
            case '3':
                cout<<"��������Ӧ�γ̣�\n";
                cin>>course_name;
                id=stu.GetCourseID(course_name);
                if(id==0)cout<<"�γ̲����ڻ���δ����ÿγ̣�\n";
                else
                {
                    cout<<"������Ҫ�ύ����ҵ��ţ�\n";
                    int asid;
                    cin>>asid;
                    if(asid >= 1 && asid <= read_course(id)._number_assignment()){
                        cout<<"��������ҵ���ݣ�\n";
                        char content[100];
                        cin.get();
                        cin.getline(content, 100); // cin>>content;
                        stu.Submit_assignment(content,asid,read_course(id));
                        cout<<"�ύ�ɹ���\n";
                    }
                    else{
                        cout << "����ҵ�����ڣ� \n";
                    }
                }
                break;
            case '4':
                cout<<"��������Ӧ�γ̣�\n";
                cin>>course_name;
                id=stu.GetCourseID(course_name);
                if(id==0)cout<<"�γ̲����ڻ���δ����ÿγ̣�\n";
                else
                {
                    cout<<"������Ҫ�鿴����ҵ��ţ�\n";
                    int asid;
                    cin>>asid;
                    stu.Show_score(asid,read_course(id));
                }
                break;
            case '5':
                cout<<"������Ҫ����Ŀγ̣�\n";
                cin>>course_name;
                cout<<"��������ʦ���û�����\n";
                cin>>teacher_name;
                id=find_out_course(course_name, find_out_teacher(teacher_name));
                if(id==0)cout<<"�γ̲����ڣ�\n";
                else stu.Join_course(id);
                break;
            case '6':
                cout<<"������Ҫ�˳��Ŀγ̣�\n";
                cin>>course_name;
                id=stu.GetCourseID(course_name);
                if(id==0)cout<<"�γ̲����ڻ���δ����ÿγ̣�\n";
                else stu.Exit_course(id);
                break;
            case '7':
                cout<<"������Ҫ���̵Ŀγ̣�\n";
                cin>>course_name;
                id=stu.GetCourseID(course_name);
                if(id==0)cout<<"�γ̲����ڻ���δ����ÿγ̣�\n";
                else
                {
                    int score;
                    char comment[100];
                    cout<<"���������̷�����\n";
                    cin>>score;
                    cout<<"����������:\n";
                    cin.get();
                    cin.getline(comment, 50); // cin>>comment;
                    stu.Teaching_evaluation(score,comment,read_course(id));
                    cout<<"���̳ɹ���\n";
                }
                break;
            case '8':
                delete_student(stu);
                cout<<"ע���ɹ���\n";
                return ;
            default:
                cout<<"ָ���������������!\n";
        }
    }
}
void teacher_window(char name[])
{
    Teacher &tea=read_teacher(find_out_teacher(name));
    char op;
    tea.Show_unread_notice(ad);//��ʾ���Խ����δ��֪ͨ
    while(true) {
        tea.show_help();
        cin >> op;
        char course_name[20], content[100];
        int Id, t;
        switch (op) {
            case '0':
                return;
            case '1':
                cout << "������γ����ƣ�\n";
                cin>>course_name;
                Id = find_out_course(course_name, tea.id);
                if (Id != 0) {
                    cout << "���Ѵ���ͬ���γ̣�\n";
                } else {
                    tea.Create_course(course_name);
                    cout << "�γ̴����ɹ���\n";
                }
                break;
            case '2':
                cout << "������Ҫ��ɢ�Ŀγ����ƣ�\n";
                cin>>course_name;
                Id = find_out_course(course_name, tea.id);
                if (Id == 0) {
                    cout << "����δ�����ÿγ̣�\n";
                } else {
                    delete_course(read_course(Id));
                    cout << "�γ̽�ɢ�ɹ���\n";
                }
                break;
            case '3':
                cout << "������γ����ƣ�\n";
                cin>>course_name;
                Id = find_out_course(course_name, tea.id);
                if (Id == 0) {
                    cout << "�γ̲����ڣ�\n";
                } else {
                    cout << "������֪ͨ���ݣ�\n";
                    cin.get();
                    cin.getline(content, 50); // cin>>content ;
                    Teacher::Post_notice(read_course(Id), content);
                }
                break;
            case '4':
                cout << "������γ����ƣ�\n";
                cin>>course_name;
                Id = find_out_course(course_name, tea.id);
                if (Id == 0) {
                    cout << "�γ̲����ڣ�\n";
                } else {
                    Teacher::Show_notice(read_course(Id));
                }
                break;
            case '5':
                cout << "������γ����ƣ�\n";
                cin>>course_name;
                Id = find_out_course(course_name, tea.id);
                if (Id == 0) {
                    cout << "�γ̲����ڣ�\n";
                } else {
                    cout << "��������ҵ���ݣ�\n";
                    cin.get();
                    cin.getline(content, 50); // cin>>content ;
                    Teacher::Assign_assignment(read_course(Id), content);
                    cout << "��ҵ���óɹ���\n";
                }
                break;
            case '6':
                cout << "������γ����ƣ�\n";
                cin>>course_name;
                Id = find_out_course(course_name, tea.id);
                if (Id == 0) {
                    cout << "�γ̲����ڣ�\n";
                } else {
                    Teacher::Show_assignment(read_course(Id));
                }
                break;
            case '7':
                cout << "������γ����ƣ�\n";
                cin>>course_name;
                Id = find_out_course(course_name, tea.id);
                if (Id == 0) {
                    cout << "�γ̲����ڣ�\n";
                } else {
                    cout << "������ڼ�����ҵ��\n";
                    cin >> t;
                    if(t >= 1 && t <= read_course(Id)._number_assignment()){
                        Teacher::Grade_assignment(read_course(Id), t);
                    }
                    else{
                        cout << "����ҵ�����ڣ� \n";
                    }
                }
                break;
            case '8':
                cout << "������γ����ƣ�\n";
                cin>>course_name;
                Id = find_out_course(course_name, tea.id);
                if (Id == 0)
                    cout << "�γ̲����ڣ�\n";
                else
                    Teacher::Show_evaluation(read_course(Id));
                break;
            case '9':
                cout << "������γ����ƣ�\n";
                cin>>course_name;
                Id = find_out_course(course_name, tea.id);
                if (Id == 0) {
                    cout << "�γ̲����ڣ�\n";
                } else {
                    int tt;
                    cout << "��������Ҫ�鿴�ڼ�����ҵ��\n";
                    cin >> tt;
                    if(tt >= 1 && tt <= read_course(Id)._number_assignment()){
                        Teacher::Show_score(read_course(Id), tt);
                    }
                    else{
                        cout << "����ҵ�����ڣ� \n";
                    }
                }
                break;
            case 'A':
                delete_teacher(tea);
                cout << "ע���ɹ���\n";
                return;
            default:
                cout << "ָ���������������!\n";
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
                cout<<"������Ҫ����Ŀγ̣�\n";
                cin>>course_name;
                cout<<"��������ʦ���û�����\n";
                cin>>teacher_name;
                Id=find_out_course(course_name, find_out_teacher(teacher_name));
                if(Id==0)cout<<"�γ̲����ڣ�\n";
                else as.join_course(Id);
                break;
            case '2':
                cout<<"������Ҫ�˳��Ŀγ̣�\n";
                cin>>course_name;
                Id=as.GetCourseID(course_name);
                if(Id==0)cout<<"�γ̲����ڻ���δ����ÿγ̣�\n";
                else as.exit_course(Id);
                break;
            case '3':
                cout<<"������γ����ƣ�\n";
                cin>>course_name;
                Id=as.GetCourseID(course_name);
                if(Id==0)
                {
                    cout<<"�γ̲����ڣ�\n";
                }
                else
                {
                    cout<<"������֪ͨ���ݣ�\n";
                    cin.get();
                    cin.getline(content, 50); // cin>>content;
                    Assistant::Post_notice(read_course(Id),content);
                }
                break;
            case '4':
                cout<<"������γ����ƣ�\n";
                cin>>course_name;
                Id=as.GetCourseID(course_name);
                if(Id==0)
                {
                    cout<<"�γ̲����ڣ�\n";
                }
                else
                {
                    Assistant::Show_notice(read_course(Id));
                }
                break;
            case '5':
                cout<<"������γ����ƣ�\n";
                cin>>course_name;
                Id=as.GetCourseID(course_name);
                if(Id==0)
                {
                    cout<<"�γ̲����ڣ�\n";
                }
                else
                {
                    cout<<"������ڼ�����ҵ��\n";
                    cin>>t;
                    if(t >= 1 && t <= read_course(Id)._number_assignment()){
                        Assistant::Grade_assignment(read_course(Id),t);
                    }
                    else{
                        cout << "����ҵ�����ڣ� \n";
                    }
                }
                break;
            case '6'://��ʾ��ҵ�ɼ�
                cout<<"������γ����ƣ�\n";
                cin>>course_name;
                cout<<"�������ο���ʦ�û�����\n";
                cin>>teacher_name;
                Id= find_out_course(course_name, find_out_teacher(teacher_name));
                if(Id==0)
                    cout<<"�γ̲����ڣ�\n";
                else
                {
                    int tt;
                    cout<<"��������Ҫ�鿴�ڼ�����ҵ��\n";
                    cin>>tt;
                    if(tt >= 1 && tt <= read_course(Id)._number_assignment()){
                        Assistant::Show_score(read_course(Id),tt);
                    }
                    else{
                        cout << "����ҵ�����ڣ� \n";
                    }
                }
                break;
            case '7':
                delete_assistant(as);
                cout<<"ע���ɹ���\n";
                return ;
            default:
                cout<<"ָ���������������!\n";
        }
    }
}
void log_in()
{
    char name[20];
    cout<<"�������û���:\n";
    cin>>name;
    cin.get();
    if(strcmp(name,"Admin")==0)
    {
        cout<<"���������룺\n";
        char password[20];
        cin>>password;
        if(strcmp(password,"P@ssw0rd")!=0)
        {
            cout<<"�������\n";
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
        cout<<"�û��������ڣ�\n";
}
void main_window()
{
    char op;
    while(true)
    {
        cout<<"1:ע��\n2:��¼\n0:�˳�\n";
        cout<<"������ָ����ִ�в���:\n";
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
                cout<<"ָ���������������!\n";
        }
    }
}