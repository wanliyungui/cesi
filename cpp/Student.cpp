#include <cstring>
#include "../h/Student.h"
#include "../h/Function.h"
int Student::ID = 0;
Student::Student(char ch[]) : id(++ID)
{
    strcpy(name,ch);
}
void Student::Show_help()
{
    cout << "1:查看已读通知\n";
    cout << "2:查看已提交作业\n";
    cout << "3:提交作业\n";
    cout << "4:查看作业成绩\n";
    cout << "5:加入课程\n";
    cout << "6:退出课程\n";
    cout << "7:评教\n";
    cout << "8:注销账户\n";
    cout << "0:退出\n";
    cout << "请输入指令以执行操作\n";
}

void Student::Show_unread_notice()
{
    for(int i = 0; i < course_num; ++i)
    {
        Course &c = read_course(course_id[i]);
        c.get_name();
        int cnt=0;
        for(int j = 0; j < c.notice_ID; ++j)
        {
            if(!is_read[c.id][j])
            {
                cnt++;
                cout<< "第" << j + 1 << "条通知：" << c.comment_notice[j] << endl;
                is_read[c.id][j] = true;
            }
        }
        if(cnt==0)cout<<"该课程暂无未读通知！\n";
    }
    
}

void Student::Show_read_notice(Course & c) const
{
    for(int i = 0; i < c.notice_ID; ++i)
    {
        if(is_read[c.id][i])
            cout<< "第" << i + 1 << "条通知：" << c.comment_notice[i] << endl;
    }
}

void Student::Show_unsubmitted_assignment() const
{
    for(int i = 0; i < course_num; ++i)
    {
        Course &c = read_course(course_id[i]);
        c.get_name();
        int cnt=0;
        int index;
        for(index=0;index<c.number_student;++index)
            if(c.student_id[index]==id)break;
        for(int j = 0; j < c.Assignment_ID; ++j)
        {
            if(!c.is_submitted[j][index])
            {
                ++cnt;
                cout<< "第" << j + 1 << "项作业：" << c.content[j] << endl;
            }
        }
        if(cnt==0)cout<<"该课程暂无未提交作业！\n";
    }
    
}

void Student::Show_submitted_assignment(Course& c) const
{
    int index;
    for(index=0;index<c.number_student;++index)
        if(c.student_id[index]==id)break;
    for(int i = 0; i < c.Assignment_ID; ++i)
    {
        if(c.is_submitted[i][index])
            cout<< "第" << i + 1 << "项作业：" << c.content[i] << endl;
    }
}

void Student::Join_course(int course_ID)
{
    course_id[course_num++] = course_ID;
    Course &c = read_course(course_ID);
    c.addstudent(id);
    cout<<"加入成功！\n";
}

void Student::Exit_course(int course_ID)
{
    bool flag = false;
    for(int i = 0; i < course_num; ++i)
    {
        if(course_id[i] == course_ID)
            flag = true;
        if(flag)
            course_id[i] = course_id[i + 1];
    }
    if(flag)
    {
        course_num--;
        Course &c = read_course(course_ID);
        c.exitstudent(id);
        cout<<"退出成功！\n";
    }
    else
        cout << "课程不存在！" << endl;
}

void Student::Show_score(int assignment_ID, const Course& Cou) const
{
    int i;
    for(i=0;i<Cou.number_student;++i)
        if(Cou.student_id[i]==id)break;
    cout << "该作业得分为：" << Cou.score[assignment_ID-1][i] << endl;
}

void Student::Submit_assignment(char assignment[], int assignment_ID, Course&  Cou) const
{
    int i;
    for(i=0;i<Cou.number_student;++i)
        if(Cou.student_id[i]==id)break;
    Cou.is_submitted[assignment_ID-1][i] = true;
    strcpy(Cou.submitted_assignment[assignment_ID-1][i] , assignment);
    Cou.score[assignment_ID-1][i]=100;
}

void Student::Teaching_evaluation(int score, char com[], Course& Cou) const
{
    for(int i=0;i<Cou.number_student;i++)
    {
        if(Cou.student_id[i]==id)
        {
            if(!Cou.is_commented[i])
            {
                strcpy(Cou.comment[i],com);
                Cou.evaluation_score[i]=score;
                Cou.is_commented[i] = true;
                break;
            }
            else{
                cout << "不可重复评教！\n";
                break;
            }
        }
    }
}

int Student::GetCourseID(char CourseName[]) const
{
    for(int i = 0; i < course_num; ++i)
    {
        Course &Cou = read_course(course_id[i]);
        if(strcmp(Cou.name , CourseName)==0)
            return course_id[i];
    }
    return 0;
}

void Student::get_name()
{
    cout<<"学生用户名："<<name<<endl;
}

void Student::get_courses()
{
    cout<<"该学生加入的课程如下：\n";
    for(int i=0;i<course_num;++i)
    {
        Course &c=read_course(course_id[i]);
        c.get_name();
    }
}

Student::~Student(){}