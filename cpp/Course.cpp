#include <cstring>
#include "../h/Course.h"
#include "../h/Function.h"
using namespace std;
int Course::ID = 0;
Course::Course(int id_teacher,char course_name[])
{
    id=++Course::ID;
    teacher_id=id_teacher;
    strcpy(name,course_name);
}
void Course::calaverage()
{
    double sum=0;
    for(int i=0;i<number_student;i++)
        sum+=evaluation_score[i];
    averagescore=double(sum/number_student);
}
void Course::addstudent(int id_student)
{
    student_id[number_student++]=id_student;
}
void Course::addassistant(int id_assistant)
{
    assistant_id[number_assistant++]=id_assistant;
}
void Course::exitstudent(int id_student)
{
    int index;
    bool flag=false;
    for(int i=0;i<number_student;i++)
    {
        if(student_id[i] == id_student)
        {
            index=i;
            flag = true;
        }
        if(flag) student_id[i] = student_id[i + 1];
    }
    if(flag)
        for(int i=index;i<number_student;i++)
        {
            strcpy(comment[i],comment[i+1]);
            is_commented[i]=is_commented[i+1];
            evaluation_score[i]=evaluation_score[i+1];
            for(int j=0;j<Assignment_ID;j++)
            {
                strcpy(submitted_assignment[j][i],submitted_assignment[j][i+1]);
                is_submitted[j][i]=is_submitted[j][i+1];
                score[j][i]=score[j][i+1];
            }
        }
    number_student--;
}
void Course::exitassistant(int id_assistant)
{
    bool flag = false;
    for(int i = 0; i < number_assistant; ++i)
    {
        if(assistant_id[i] == id_assistant) flag = true;
        if(flag) assistant_id[i] = assistant_id[i + 1];
    }
    number_assistant--;
}
void Course::get_name()
{
    cout<<"¿Î³ÌÃû³Æ£º"<<name<<endl;
}
Course::~Course(){}


