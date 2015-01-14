// Assignment #1
// Name:
// ASU Email Address:
// Description: To be completed

#include <iostream> //to use cout
#include <iomanip> //to format output
#include <string> //to use strings

using namespace std;

//struct Course represents some course information
struct Course
{
    string number;
    string title;
    struct Course * next;
};

//class LinkedList will contains a linked list of courses
class LinkedList
{
    private:
    struct Course * head;
    
    public:
    LinkedList();
    ~LinkedList();
    bool addElement(string number, string title, int index);
    bool removeElement(string number, string title);
    void printList();
};

//Constructor to initialize the linked list
LinkedList::LinkedList()
{
    head = NULL;
}

//Destructor
//Description: ...... to be completed
LinkedList::~LinkedList()
{
    //To be completed
}

//Description: .... to be completed
bool LinkedList::addElement(string newNumber, string newTitle, int index)
 {
    //To be completed
 }

//Description: .... to be completed
bool LinkedList::removeElement(string someNumber, string someTitle)
 {
    //To be complete
 }

//Description: .... to be completed
void LinkedList::printList()
{
    //To be complete
}

