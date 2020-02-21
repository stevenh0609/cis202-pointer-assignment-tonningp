#include <string>
#include <vector>
#include <memory>
#include <iostream>

struct Course;

struct Student {
  std::string name;
  std::vector<std::shared_ptr<Course>> courses;
};

struct Course {
  std::string name;
  std::vector<std::shared_ptr<Student>> students;
};

void print_student(std::shared_ptr<Student> s) {
  std::cout << s->name << "\n";
  for (auto ptr : s->courses) {
    std::cout << ptr->name << "\n";
  }
  std::cout << "\n";
}

void print_course(std::shared_ptr<Course> c) {
  std::cout << c->name << "\n";
  for (auto ptr : c->students) {
    std::cout << ptr->name << "\n";
  }
  std::cout << "\n";
}

void enroll(std::shared_ptr<Student> s, std::shared_ptr<Course> c) {
  s->courses.push_back(c);
  c->students.push_back(s);
}

void enroll_mod2(std::vector<std::shared_ptr<Student>> students, std::vector<std::shared_ptr<Course>> courses) {
  for (auto i = 0u; i < students.size(); ++i) {
    for (auto j = 0u; j < courses.size(); ++j) {
      if (rand() % 2) {
        enroll(students[i], courses[j]);
      }
    }
  }
}

int main() {
  srand(time(NULL));

  auto student_names = { "Matthew", "Sean", "Leon", "Daphne", "Mark", "Luke", "John", "Ringo", "Starr", "Stephanie", "Tiffany" };
  auto course_names = { "CIS101", "CIS201", "CIS202" };
  
  std::vector<std::shared_ptr<Student>> students;
  std::vector<std::shared_ptr<Course>> courses;

  for (const auto & sn : student_names) {
    students.push_back(std::make_shared<Student>());
    students.back()->name = sn;
  }
  for (const auto & cn : course_names) {
    courses.push_back(std::make_shared<Course>());
    courses.back()->name = cn;
  }

  enroll_mod2(students, courses);

  for (const auto & s : students) {
      print_student(s);
    }
  for (const auto & c : courses) {
      print_course(c);
    }

  return 0;
}
