 #include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    int id;
    double grade;

    void print()
    {
        cout << id << " | " << name << " | " << grade << endl;
    }
};

// Selection Sort by Grade
void sortByGrade(vector<Student>& students)
{
    int n = students.size();

    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (students[j].grade > students[maxIndex].grade)
            {
                maxIndex = j;
            }
        }

        Student temp = students[i];
        students[i] = students[maxIndex];
        students[maxIndex] = temp;
    }
}

// Selection Sort by ID
void sortByID(vector<Student>& students)
{
    int n = students.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (students[j].id < students[minIndex].id)
            {
                minIndex = j;
            }
        }

        Student temp = students[i];
        students[i] = students[minIndex];
        students[minIndex] = temp;
    }
}

// Linear Search by Name
int linearSearch(vector<Student>& students, string name)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].name == name)
        {
            return i;
        }
    }

    return -1;
}

// Binary Search by ID
int binarySearch(vector<Student>& students, int id)
{
    int left = 0;
    int right = students.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (students[mid].id == id)
        {
            return mid;
        }
        else if (students[mid].id < id)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

// Recursion
double totalGrades(vector<Student>& students, int index)
{
    if (index == students.size())
    {
        return 0;
    }

    return students[index].grade + totalGrades(students, index + 1);
}

// Display Students
void printStudents(vector<Student>& students)
{
    for (int i = 0; i < students.size(); i++)
    {
        students[i].print();
    }
}

int main()
{
    vector<Student> students;

    int choice;

    do
    {
        cout << "\n===== Student Grades System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Sort by Grade\n";
        cout << "4. Search by Name\n";
        cout << "5. Search by ID\n";
        cout << "6. Calculate Total Grades\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Student s;

            cout << "Enter name: ";
            cin >> s.name;

            cout << "Enter ID: ";
            cin >> s.id;

            cout << "Enter grade: ";
            cin >> s.grade;

            students.push_back(s);

            cout << "Student added successfully.\n";
        }

        else if (choice == 2)
        {
            if (students.empty())
            {
                cout << "No students found.\n";
            }
            else
            {
                printStudents(students);
            }
        }

        else if (choice == 3)
        {
            sortByGrade(students);

            cout << "Students sorted by grade:\n";
            printStudents(students);
        }

        else if (choice == 4)
        {
            string name;

            cout << "Enter student name: ";
            cin >> name;

            int result = linearSearch(students, name);

            if (result != -1)
            {
                cout << "Student found:\n";
                students[result].print();
            }
            else
            {
                cout << "Student not found.\n";
            }
        }

        else if (choice == 5)
        {
            int id;

            cout << "Enter student ID: ";
            cin >> id;

            sortByID(students);

            int result = binarySearch(students, id);

            if (result != -1)
            {
                cout << "Student found:\n";
                students[result].print();
            }
            else
            {
                cout << "Student not found.\n";
            }
        }

         else if (choice == 6)
        {
            double total = totalGrades(students, 0);

            cout << "Total grades = " << total << endl;
        }

        else if (choice == 7)
        {
            cout << "Exiting program...\n";

        }

        else
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}
