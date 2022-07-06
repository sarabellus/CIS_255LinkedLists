
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
            cout << n->standing() << endl;
            
            n = n->nxt_ptr;
        }
    }
}

int main()
{
    student *h, *r;
    string sName;
    //int opt;
    h = NULL;
    r = NULL;
    
    loadData(h, r);
    
    // = displayMenu();
    
    displayLinkedList(h);
    
   // while (opt != 5)
    //{
      //  if (opt == 1)
        //    displayLinkedList();
        //else if (opt == 2)
         //   addStudent();
        //else if (opt == 3)
          //  deleteStudent();
        //else if (opt == 4)
          //  searchStudent(sName);
        
       // cout << endl;
        
        //opt = int displayMenu();
    //}
    system("pause");
    return 0;
}
