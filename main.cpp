#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    vector<string> courses;
};

int main()
{
    vector<Student> students;

    int choice;

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
        cin.ignore();

        if (choice == 1)
        {
            Student s;

            cout << "Enter student name: ";
            getline(cin, s.name);

            students.push_back(s);

            cout << "Student \"" << s.name << "\" added." << endl;
        }

        else if (choice == 2)
        {
            string name;
            cout << "Enter student name: ";
            getline(cin, name);

            bool found = false;

            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].name == name)
                {
                    students.erase(students.begin() + i);
                    cout << "Student deleted." << endl;
                    found = true;
                    break;
                }
            }

            if (found == false)
            {
                cout << "Student not found." << endl;
            }
        }

        else if (choice == 3)
        {
            string name;
            string course;

            cout << "Enter student name: ";
            getline(cin, name);

            bool found = false;

            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].name == name)
                {
                    cout << "Enter course name: ";
                    getline(cin, course);

                    students[i].courses.push_back(course);

                    cout << "Course \"" << course
                         << "\" added to " << name << "." << endl;

                    found = true;
                    break;
                }
            }

            if (found == false)
            {
                cout << "Student not found." << endl;
            }
        }

        else if (choice == 4)
        {
            string name;
            string course;

            cout << "Enter student name: ";
            getline(cin, name);

            bool foundStudent = false;

            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].name == name)
                {
                    foundStudent = true;

                    cout << "Enter course name: ";
                    getline(cin, course);

                    bool foundCourse = false;

                    for (int j = 0; j < students[i].courses.size(); j++)
                    {
                        if (students[i].courses[j] == course)
                        {
                            students[i].courses.erase(
                                students[i].courses.begin() + j
                            );

                            cout << "Course deleted." << endl;

                            foundCourse = true;
                            break;
                        }
                    }

                    if (foundCourse == false)
                    {
                        cout << "Course not found." << endl;
                    }

                    break;
                }
            }

            if (foundStudent == false)
            {
                cout << "Student not found." << endl;
            }
        }

        else if (choice == 5)
        {
            if (students.size() == 0)
            {
                cout << "No students." << endl;
            }
            else
            {
                for (int i = 0; i < students.size(); i++)
                {
                    cout << "\nStudent: " << students[i].name << endl;

                    cout << "Courses: ";

                    if (students[i].courses.size() == 0)
                    {
                        cout << "No courses";
                    }
                    else
                    {
                        for (int j = 0;
                             j < students[i].courses.size();
                             j++)
                        {
                            cout << students[i].courses[j];

                            if (j < students[i].courses.size() - 1)
                            {
                                cout << ", ";
                            }
                        }
                    }

                    cout << endl;
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
