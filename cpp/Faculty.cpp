#include <cstring>
#include "../h/Faculty.h"
#include "../h/Function.h"
void Faculty::Post_notice(Course& c ,char content[] )
{
    strcpy(c.comment_notice[c.notice_ID],content);
    c.notice_ID++;
    cout << "通知已成功发布。\n";
}
void Faculty::Show_notice(const Course& c)
{
    for(int i=0;i<c.notice_ID;++i)
    {
        cout<<"第"<<i+1<<"条通知：\n"<<c.comment_notice[i]<<endl;
    }
}
void Faculty::Grade_assignment(Course& c,int t)
{
    for(int i=0;i<c.number_student;++i)
    {
        if(c.is_submitted[t-1][i])
        {
            cout<<"作业内容为：\n";
            cout<<c.submitted_assignment[t-1][i]<<endl;
            cout<<"请输入评分：\n";
            cin>>c.score[t-1][i];
            cout<<"评分成功！\n";
        }
    }
    cout<<"该门课程评分已完成。\n";
}
void Faculty::Show_score(const Course& c,int t)//教师和助教可以具体查看某次作业全班所有同学的分数
{
    for(int i=0;i<c.number_student;++i)
        cout<<"第"<<i+1<<"位学生的分数为："<<c.score[t-1][i]<<endl;
}