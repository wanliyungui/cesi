#ifndef SYSTEM_FUNCTION_H
#define SYSTEM_FUNCTION_H
#include<iostream>
#include<fstream>
#include "Student.h"
#include "Teacher.h"
#include "Assistant.h"
using namespace std;
int find_out_student(char []);
int find_out_teacher(char []);
int find_out_assistant(char []);
int find_out_course(char [],int);
Student &read_student(int);
Teacher &read_teacher(int);
Assistant &read_assistant(int);
Course &read_course(int);
void delete_student(Student &);
void delete_assistant(Assistant &);
void delete_course(Course &);
void delete_teacher(Teacher&);
void add_course(const Course&);
void add_student(const Student&);
void add_teacher(const Teacher&);
void add_assistant(const Assistant&);
#endif