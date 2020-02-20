#include<iostream>
#include<string>
#include<vector>

struct Course;

struct Student
{
   std::string name;
   std::vector<Course*> courses;
};

struct Course 
{
   std::string name;
   std::vector<Student*> students;
};


int main()
{
   Student s1;
   Student *s2 = new Student;
   s2->name = "Fred Flintstone";
   Course *c1 = new Course;
   c1->name = "CIS101";
   c1->students.push_back(s2);

   return 0;
}
