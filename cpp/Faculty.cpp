#include <cstring>
#include "../h/Faculty.h"
#include "../h/Function.h"
void Faculty::Post_notice(Course& c ,char content[] )
{
    strcpy(c.comment_notice[c.notice_ID],content);
    c.notice_ID++;
    cout << "֪ͨ�ѳɹ�������\n";
}
void Faculty::Show_notice(const Course& c)
{
    for(int i=0;i<c.notice_ID;++i)
    {
        cout<<"��"<<i+1<<"��֪ͨ��\n"<<c.comment_notice[i]<<endl;
    }
}
void Faculty::Grade_assignment(Course& c,int t)
{
    for(int i=0;i<c.number_student;++i)
    {
        if(c.is_submitted[t-1][i])
        {
            cout<<"��ҵ����Ϊ��\n";
            cout<<c.submitted_assignment[t-1][i]<<endl;
            cout<<"���������֣�\n";
            cin>>c.score[t-1][i];
            cout<<"���ֳɹ���\n";
        }
    }
    cout<<"���ſγ���������ɡ�\n";
}
void Faculty::Show_score(const Course& c,int t)//��ʦ�����̿��Ծ���鿴ĳ����ҵȫ������ͬѧ�ķ���
{
    for(int i=0;i<c.number_student;++i)
        cout<<"��"<<i+1<<"λѧ���ķ���Ϊ��"<<c.score[t-1][i]<<endl;
}