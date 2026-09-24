#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    vector<string> courses;

    Student(string studentName)
    {
        name = studentName;
    }

    void addCourse(string course)
    {
        courses.push_back(course);
    }

    void deleteCourse(string course)
    {
        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i] == course)
            {
                courses.erase(courses.begin() + i);
                cout << "Course \"" << course << "\" deleted from "
                     << name << "." << endl;
                return;
            }
        }

        cout << "Course not found." << endl;
    }

    void display()
    {
        cout << "Student: " << name << endl;
        cout << "Courses: ";

        if (courses.empty())
        {
            cout << "No courses";
        }
        else
        {
            for (int i = 0; i < courses.size(); i++)
            {
                cout << courses[i];

                if (i < courses.size() - 1)
                    cout << ", ";
            }
        }

        cout << endl;
    }
};

int main()
{
    vector<Student> students;

    int choice;
    string name;
    string course;

    do
    {
        cout << "\n=== Student Management System ===" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Add Course to Student" << endl;
        cout << "4. Delete Course from Student" << endl;
        cout << "5. Display All Students" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter student name: ";
            cin >> name;

            students.push_back(Student(name));

            cout << "Student \"" << name << "\" added." << endl;
        }

        else if (choice == 2)
        {
            cout << "Enter student name: ";
            cin >> name;

            bool found = false;

            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].name == name)
                {
                    students.erase(students.begin() + i);
                    cout << "Student \"" << name << "\" deleted." << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Student not found." << endl;
            }
        }

        else if (choice == 3)
        {
            cout << "Enter student name: ";
            cin >> name;

            bool found = false;

            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].name == name)
                {
                    cout << "Enter course name: ";
                    cin >> course;

                    students[i].addCourse(course);

                    cout << "Course \"" << course
                         << "\" added to " << name << "." << endl;

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Student not found." << endl;
            }
        }

        else if (choice == 4)
        {
            cout << "Enter student name: ";
            cin >> name;

            bool found = false;

            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].name == name)
                {
                    cout << "Enter course name: ";
                    cin >> course;

                    students[i].deleteCourse(course);

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Student not found." << endl;
            }
        }

        else if (choice == 5)
        {
            if (students.empty())
            {
                cout << "No students found." << endl;
            }
            else
            {
                for (int i = 0; i < students.size(); i++)
                {
                    students[i].display();
                }
            }
        }

        else if (choice == 6)
        {
            cout << "Goodbye!" << endl;
        }

        else
        {
            cout << "Invalid option." << endl;
        }

    } while (choice != 6);

    return 0;
}
