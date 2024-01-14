#include <cstring>
#include "../h/Teacher.h"
#include "../h/Function.h"
int Teacher::ID = 0;
void Teacher::show_help()
{
    cout << "1:创建课程\n";
    cout << "2:解散课程\n";
    cout << "3:发布通知\n";
    cout << "4:查看已发布通知\n";
    cout << "5:发布作业\n";
    cout << "6:查看已发布作业\n";
    cout << "7:查看作业并打分\n";
    cout << "8:查看评分和评语\n";
    cout << "9:查看某次作业分数\n";
    cout << "A:注销\n";
    cout << "0:退出\n";
    cout << "请输入指令以执行操作\n";
}//显示帮助
void Teacher::Assign_assignment(Course & c ,char content[])
{
    strcpy(c.content[c.Assignment_ID],content);//课程作业内容
    c.Assignment_ID++;
}//布置作业
void Teacher::Show_assignment(const Course &c)
{
   for(int i=0;i<c.Assignment_ID;i++)
   {
       cout<<"第"<<i+1<<"项作业为：\n"<<c.content[i]<<endl;
   }
} //显示已布置作业
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
}//创建课程
void Teacher::exit_course(int course_ID)
{
    bool flag=false;
    for(int i=0;i<course_num;++i)
    {
        if(course_id[i]==course_ID)flag=true;
        if(flag)course_id[i]=course_id[i+1];
    }
    if(flag)course_num--;
}//退出课程,方便解散

void Teacher::Show_evaluation(Course& c)
{
    cout<<"课程的评教均分为："<<endl;
    c.calaverage();
    cout<<c.averagescore<<endl;
    for(int i=0;i<c.number_student;i++)
    cout<<"第"<<i+1<<"条评语为："<<c.comment[i]<<endl;
}//显示评教的均分和所有评语

void Teacher::Show_unread_notice(Admin& ad){
    int cnt=0;
    for(int i = 0; i < ad.notice_ID; ++i){
        if(!is_read[i]){
            cout<< "第" << ++cnt << "条通知为：" << ad.comment_notice[i] << endl;
            is_read[i] = true;
        }
    }
    if(cnt==0)cout<<"暂无未读通知。\n";
}

void Teacher::get_name()
{
    cout<<"教师用户名："<<name<<endl;
}
void Teacher::get_courses()
{
    cout<<"该教师创建的课程如下：\n";
    for(int i=0;i<course_num;++i)
    {
        Course &c=read_course(course_id[i]);
        c.get_name();
    }
}

Teacher::~Teacher() {}
