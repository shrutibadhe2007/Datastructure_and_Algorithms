


#include <iostream>
using namespace std;

// Structure of Student Node
struct Student {
    int rollNo;
    string name;
    float marks;

    Student *left, *right;
};

// Create a new student node
Student* createNode(int r, string n, float m) {
    Student* newNode = new Student;

    newNode->rollNo = r;
    newNode->name = n;
    newNode->marks = m;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert student into BST
Student* insert(Student* root, int r,
                string n, float m) {
    if (root == NULL)
        return createNode(r, n, m);

    if (r < root->rollNo)
        root->left = insert(root->left, r, n, m);

    else if (r > root->rollNo)
        root->right = insert(root->right, r, n, m);

    else
        cout << "Roll number already exists!\n";

    return root;
}

// Search student by roll number
void search(Student* root, int r) {
    if (root == NULL) {
        cout << "Student not found!\n";
        return;
    }

    if (r == root->rollNo) {
        cout << "\nStudent Found!\n";
        cout << "Roll Number: " << root->rollNo << endl;
        cout << "Name: " << root->name << endl;
        cout << "Marks: " << root->marks << endl;
    }

    else if (r < root->rollNo)
        search(root->left, r);

    else
        search(root->right, r);
}

// Find minimum node in right subtree
Student* findMin(Student* root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

// Delete student from BST
Student* deleteNode(Student* root, int r) {
    if (root == NULL)
        return root;

    if (r < root->rollNo)
        root->left = deleteNode(root->left, r);

    else if (r > root->rollNo)
        root->right = deleteNode(root->right, r);

    else {
        // Case 1: No left child
        if (root->left == NULL) {
            Student* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: No right child
        else if (root->right == NULL) {
            Student* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Student* temp = findMin(root->right);

        root->rollNo = temp->rollNo;
        root->name = temp->name;
        root->marks = temp->marks;

        root->right = deleteNode(
            root->right, temp->rollNo);
    }

    return root;
}

// Display records in ascending order
void display(Student* root) {
    if (root != NULL) {
        display(root->left);

        cout << root->rollNo << "\t"
             << root->name << "\t"
             << root->marks << endl;

        display(root->right);
    }
}

// Main function
int main() {
    Student* root = NULL;

    int choice, roll;
    string name;
    float marks;

    do {
        cout << "\n--- STUDENT RECORD MANAGEMENT ---\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display Students\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Roll Number: ";
            cin >> roll;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Marks: ";
            cin >> marks;

            root = insert(root, roll, name, marks);
            break;

        case 2:
            cout << "Enter Roll Number: ";
            cin >> roll;

            search(root, roll);
            break;

        case 3:
            cout << "Enter Roll Number to Delete: ";
            cin >> roll;

            if (root == NULL) {
                cout << "No student records available!\n";
            } else {
                root = deleteNode(root, roll);
                cout << "Deletion operation completed.\n";
            }
            break;

        case 4:
            cout << "\nRoll No\tName\tMarks\n";
            display(root);
            break;

        case 5:
            cout << "Program Exited Successfully!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
/*

--- STUDENT RECORD MANAGEMENT ---
1. Add Student
2. Search Student
3. Delete Student
4. Display Students
5. Exit
Enter your choice: 1
Enter Roll Number
1. Add Student
2. Search Student
3. Delete Student
4. Display Students
5. Exit

Enter your choice: 1
Enter Roll Number: 105
Enter Name: Rahul
Enter Marks: 85

Enter your choice: 1
Enter Roll Number: 102
Enter Name: Amit
Enter Marks: 90

Enter your choice: 1
Enter Roll Number: 110
Enter Name: Priya
Enter Marks: 92


Roll No    Name    Marks
102        Amit    90
105        Rahul   85
110        Priya   92
Enter Roll Number: 10

Student Found!
Roll Number: 105
Name: Rahul
Marks: 85

Enter Roll Number to Delete: 102

Deletion operation completed.


Roll No    Name    Marks
105        Rahul   85
110        Priya   92

 */
    
