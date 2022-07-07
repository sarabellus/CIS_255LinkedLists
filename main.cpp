
// CIS 255 Assignment 9 and 10
// Sara Bellus 7/6/22

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "student.h"

using namespace std;

void loadData(student *&h, student *&r)
{
    ifstream infile;
    student *n;
    string fn, ln, standing;
    float gpa, credits;
    
    h = NULL;
    r = NULL;
    
    infile.open("Data.txt");
    
    while (!infile.eof())
    {
        infile >> fn >> ln >> gpa >> credits;
        n = new student;
        n->fName(fn);
        n->lName(ln);
        n->GPA(gpa);
        n->credits(credits);
        n->standing(credits);
        
        if (h == NULL)
        {
            h = n;
            r = n;
        }
        else
        {
          r->nxt_ptr = n;
            r = n;
        }
    }
    infile.close();
}
void displayLinkedList(student *h)
{
    student *n;
    
    if (h == NULL)
        cout << "Empty List" << endl;
    else
    {
        n = h;
        while (n != NULL)
        {
            cout << n->fName() << " " << n->lName() << endl;
            cout << n->GPA() << endl;
            cout << n->credits() << endl;
            cout << n->standing() << endl << endl;
            
            n = n->nxt_ptr;
        }
    }
}
int displayMenu()
{
    int opt;
    
    cout << "Enter an option, 1 - 5 below." << endl;
    cout << "1. Display Linked List" << endl;
    cout << "2. Add a Student" << endl;
    cout << "3. Delete a Student" << endl;
    cout << "4. Search for a Student" << endl;
    cout << "5. Exit" << endl;
    
    cin >> opt;
    
    return opt;
}
void addStudent(student *&r)
{
    string fn, ln;
    float gpa, credits;
    student *n;
    
    cout << "Enter first name";
    cin >> fn;
    cout << "Enter last name";
    cin >> ln;
    cout << "Enter GPA";
    cin >> gpa;
    cout << "Enter number of credits";
    cin >> credits;
    
    n = new student;
    n->fName(fn);
    n->lName(ln);
    n->GPA(gpa);
    n->credits(credits);
    n->standing(credits);
    
      r->nxt_ptr = n;
        r = n;
}
void deleteStudent(student *&h, student *&r)
{
    student *c;
    
    if (h == NULL)
    {
        cout << "List is empty." << endl;
        c = NULL;
        r = NULL;
    }
    
    else
        c = h;
    h = h->nxt_ptr;
    delete c;
}
void searchStudent(string sName, student *h)
{
    student *f = NULL;
    
    
    if (f == NULL);
    cout << sName << " not in the queue" << endl;
    
    else
    {
        cout << endl;
        cout << f->fName
    }
}
int main()
{
    student *h, *r;
    string sName;
    int opt;
    h = NULL;
    r = NULL;
    
    loadData(h, r);
    
    opt = displayMenu();
    
   while (opt != 5)
    {
      if (opt == 1)
        displayLinkedList(h);
    else if (opt == 2)
        addStudent(r);
    else if (opt == 3)
        deleteStudent(h, r);
    else if (opt == 4)
    {
        cout << "Enter search name:" << endl;
        cin >> sName;
        searchStudent(sName, *h, *r);
    }
       cout << endl;
        
        opt = displayMenu();
    }
    
    system("pause");
    return 0;
}
