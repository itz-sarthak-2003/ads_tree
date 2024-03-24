#include <iostream>
using namespace std;

class Employee
{
public:
    string name;
    int age, bdate;
    string gender;
    double salary;
    Employee *left, *right;

    void accept();
    void insert(Employee *&root, Employee *next);
    void display_inorder(Employee *root);
    void find_employee(Employee *root, string x);
} *root = nullptr;

void Employee::accept()
{
    Employee *next = new Employee();
    cout << "Enter the following employee information :" << endl;
    cout << "Name, Age, Gender, Birthdate, Salary" << endl;
    cin >> next->name >> next->age >> next->gender >> next->bdate >> next->salary;
    next->left = nullptr;
    next->right = nullptr;
    insert(root, next);
}

void Employee::insert(Employee *&root, Employee *next)
{
    if (root == nullptr)
    {
        root = next;
    }
    else if (next->salary < root->salary)
    {
        insert(root->left, next);
    }
    else
    {
        insert(root->right, next);
    }
}

void Employee::display_inorder(Employee *root)
{
    if (root != nullptr)
    {
        display_inorder(root->left);
        cout << "\n" << root->name << "\t" << root->age << "\t" << root->gender << "\t" << root->bdate << "\t" << root->salary << endl;
        display_inorder(root->right);
    }
}

void Employee::find_employee(Employee *root, string x)
{
    if (root == nullptr)
    {
        cout << "Employee database is empty" << endl;
        return;
    }

    if (root->name == x)
    {
        cout << "Employee found: " << root->name << ", Salary: " << root->salary << endl;
    }
    else if (x < root->name)
    {
        find_employee(root->left, x);
    }
    else
    {
        find_employee(root->right, x);
    }
}

int main()
{
    Employee emp;
    int ch;
    string x;
    do
    {
        cout << "\nWELCOME TO EMPLOYEE MANAGEMENT SYSTEM!" << endl;
        cout << "1. Add an employee" << endl;
        cout << "2. Display employees (in order)" << endl;
        cout << "3. Find an employee" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            emp.accept();
            break;
        case 2:
            cout << "\nName\tAge\tGender\tDOB\tSalary" << endl;
            emp.display_inorder(root);
            break;
        case 3:
            cout << "Enter the name of the employee you want to search for: ";
            cin >> x;
            emp.find_employee(root, x);
            break;
        case 4:
            cout << "Thank you for using the Employee Management System." << endl;
            exit(0);
        default:
            cout << "Wrong choice" << endl;
        }
    } while (ch != 4);
    return 0;
}
