#include <cstring>
#include "../h/Teacher.h"
#include "../h/Function.h"
int Teacher::ID = 0;
void Teacher::show_help()
{
    cout << "1:�����γ�\n";
    cout << "2:��ɢ�γ�\n";
    cout << "3:����֪ͨ\n";
    cout << "4:�鿴�ѷ���֪ͨ\n";
    cout << "5:������ҵ\n";
    cout << "6:�鿴�ѷ�����ҵ\n";
    cout << "7:�鿴��ҵ�����\n";
    cout << "8:�鿴���ֺ�����\n";
    cout << "9:�鿴ĳ����ҵ����\n";
    cout << "A:ע��\n";
    cout << "0:�˳�\n";
    cout << "������ָ����ִ�в���\n";
}//��ʾ����
void Teacher::Assign_assignment(Course & c ,char content[])
{
    strcpy(c.content[c.Assignment_ID],content);//�γ���ҵ����
    c.Assignment_ID++;
}//������ҵ
void Teacher::Show_assignment(const Course &c)
{
   for(int i=0;i<c.Assignment_ID;i++)
   {
       cout<<"��"<<i+1<<"����ҵΪ��\n"<<c.content[i]<<endl;
   }
} //��ʾ�Ѳ�����ҵ
Teacher::Teacher(char ch[]) {
    id=++ID;
    strcpy(name,ch);
}
void Teacher::Create_course(char Name[])
{
    Course c(id,Name);
    course_id[course_num]=c._id();
    course_num++;
    add_course(c);
}//�����γ�
void Teacher::exit_course(int course_ID)
{
    bool flag=false;
    for(int i=0;i<course_num;++i)
    {
        if(course_id[i]==course_ID)flag=true;
        if(flag)course_id[i]=course_id[i+1];
    }
    if(flag)course_num--;
}//�˳��γ�,�����ɢ

void Teacher::Show_evaluation(Course& c)
{
    cout<<"�γ̵����̾���Ϊ��"<<endl;
    c.calaverage();
    cout<<c.averagescore<<endl;
    for(int i=0;i<c.number_student;i++)
    cout<<"��"<<i+1<<"������Ϊ��"<<c.comment[i]<<endl;
}//��ʾ���̵ľ��ֺ���������

void Teacher::Show_unread_notice(Admin& ad){
    int cnt=0;
    for(int i = 0; i < ad.notice_ID; ++i){
        if(!is_read[i]){
            cout<< "��" << ++cnt << "��֪ͨΪ��" << ad.comment_notice[i] << endl;
            is_read[i] = true;
        }
    }
    if(cnt==0)cout<<"����δ��֪ͨ��\n";
}

void Teacher::get_name()
{
    cout<<"��ʦ�û�����"<<name<<endl;
}
void Teacher::get_courses()
{
    cout<<"�ý�ʦ�����Ŀγ����£�\n";
    for(int i=0;i<course_num;++i)
    {
        Course &c=read_course(course_id[i]);
        c.get_name();
    }
}

Teacher::~Teacher() {}
