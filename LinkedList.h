// Assignment #1
// Name: Easa El Sirgany
// ASU Email Address: eelsirga@asu.edu
// Description: This file contains the methods and functions to be utilized by
//		Assignment1.cpp completed by myself (the Assignment1.cpp file was
//		completed by professor Nakamura, as well as the skel of this file).

#include <iostream> //to use cout
#include <iomanip> //to format output
#include <string> //to use strings
#include <cstdlib> //For malloc

using namespace std;


//struct Course represents some course information
struct Course
{
    string number;
    string title;
    struct Course * next;
};

class LinkedList
{
private:
    struct Course * head;
	int size; //Addition of tracking number
    
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
	size = 0; //Let's initialize to note that there are no elems yet
}

//Destructor
//Description: Destructs the object
LinkedList::~LinkedList()
{
	struct Course *tmp;

	while(this->head->next){
		tmp = this->head->next;
		this->head->next = tmp->next;
		delete tmp;
	}
	if(this->head) delete head; //If nothing was ever added to the list
}

//Description: Adds a Course as long as index is in bounds
bool LinkedList::addElement(string newNumber, string newTitle, int index)
 {
	if(index < 0 || index > this->size) return false;

	//Let's create the element to add, and declare any variables to be used
	struct Course *newCourse;
	newCourse = (struct Course *)malloc(sizeof(struct Course));
	newCourse->number = newNumber;
	newCourse->title = newTitle;
	newCourse->next = NULL;

	int pos = 1; //We want the course that'll point to the new course
	struct Course *tmp;

	//Find the correct position to insert the new Course
	//If the list is empty, then just make the newCourse the head
	if(!this->size){
		if(this->head) goto error1; //This should never happen!
		this->head = newCourse;
		this->size++;
		return true;
	}
	//Otherwise, let's traverse to the node that we want
	for(tmp=this->head; pos<index; pos++){
		if(tmp->next) tmp = tmp->next;
		else goto error2; //This should never happen either!
	}

	//Now let's insert the new course
	newCourse->next = tmp->next; //This can be NULL
	tmp->next = newCourse;
	this->size++;
	return true;


error1:
	cout << "**************************************************************\n";
	cout << "An error occured while trying to add an element!" << endl;
	cout << "The size was zero, but head was pointing to something nonNULL!\n";
	cout << "Bro, do you even code? Can you even logic?" << endl;
	cout << "**************************************************************\n";
	if(newCourse) delete newCourse;
	return false;

error2:
	cout << "**************************************************************\n";
	cout << "An error occured while trying to add an element!" << endl;
	cout << "Attempted to traverse past end-of-list!" << endl;
	cout << "I remember my first programming assignment!" << endl;
	cout << "**************************************************************\n";
	if(newCourse) delete newCourse;
	return false;
 }

//Description: Attempts to remove an element with the number and title passed
bool LinkedList::removeElement(string someNumber, string someTitle)
 {
	struct Course *pre, *del = NULL;

	//If there is only one element in the list
	if(!this->head->next){
		if(this->head->number.compare(someNumber) == 0 &&
		this->head->title.compare(someTitle) == 0){
			delete this->head;
			this->head = NULL;
			return true;
		}
		else return false;
	}

	//Let's find the element that we want to delete
	for(pre=this->head; pre->next; pre = pre->next){
		if(pre->next->number.compare(someNumber) == 0 &&
		pre->next->title.compare(someTitle) == 0)
			del = pre->next;
	}

	//If del points to something, then let's delete
	if(del){
		pre->next = del->next;
		delete del;
		return true;
	}
	else return false;
 }

//Description: Prints the list in order
void LinkedList::printList()
{
	struct Course *tmp;

	if(!this->head) cout << "The list is empty" << endl;
	else{
		for(tmp=this->head; tmp->next; tmp = tmp->next){
			cout << "Course Number: " << tmp->number << ", ";
			cout << "Course Title: " << tmp->title << endl;
		}
		//Don't forget to print the last element of the list
		cout << "Course Number: " << tmp->number << ", ";
		cout << "Course Title: " << tmp->title << endl;
	}
}
