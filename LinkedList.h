// Assignment #1
// Name: Easa El Sirgany
// ASU Email Address: eelsirga@asu.edu
// Description: This file contains the methods and functions to be utilized by
//		Assignment1.cpp completed by myself (the Assignment1.cpp file was
//		completed by professor Nakamura, as well as the skel of this file).

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
	cout << "The number of deleted courses is: " << this->size << endl << endl;
}

//Description: Adds a Course as long as index is in bounds
bool LinkedList::addElement(string newNumber, string newTitle, int index)
 {
	if(index < 0 || index > this->size) return false;

	//We need to allocate a new Course and add
	struct Course *newCourse, *tmp = this->head;
	newCourse = new Course;
	newCourse->number = newNumber;
	newCourse->title = newTitle;
	newCourse->next = NULL; //Just in case we are adding at head

	if(!this->head){
		if(size) goto size_error; //Sanity Check
		if(index!=0) return false;
		else{
			this->head = newCourse;
			this->size++;
			return true;
		}
	}
	else if(!index){ //Adding at head
		newCourse->next = this->head;
		this->head = newCourse;
		this->size++;
		return true;
	}
	else{ //Adding anywhere but head
		if(!size) goto size_error;

		//We need to find the pre-position in the list to add (pos=1)
		for(int pos=1; pos<index; pos++){
			if(tmp->next) tmp = tmp->next;
			else goto traverse_error;
		}

		//Add the course in the correct position and increment
		newCourse->next = tmp->next; //Can be NULL
		tmp->next = newCourse;
		this->size++; //Don't forget to increment
		return true;
	}

//Some helpful fallthrough errors that will not cause termination of program
size_error:
	cout << "**************************************************************\n";
	cout << "An error occured while trying to add an element!" << endl;
	cout << "Your size element does not match the actual size of the list!\n";
	cout << "Counting is hard!" << endl;
	cout << "**************************************************************\n";
	if(newCourse) delete newCourse;
	return false;

traverse_error:
	cout << "**************************************************************\n";
	cout << "An error occured while trying to add an element!" << endl;
	cout << "Attempted to traverse past end-of-list!" << endl;
	cout << "I remember my first programming assignment!" << endl;
	cout << "**************************************************************\n";
	if(newCourse) delete newCourse;
	return false;
 }

//Description: Attempts to remove an element with the number and title passed
//	My approach to this is setting a pointer to an element to delete, and
//	checking to see if that pointer is nonNULL at the end of the function
//	and taking the appropriate action.
bool LinkedList::removeElement(string someNumber, string someTitle)
 {
	struct Course *pre, *del = NULL;

	if(this->head->number.compare(someNumber)==0 &&
	   this->head->title.compare(someTitle)==0){ //Delete elem @ 0
		del = this->head;
		this->head = del->next;
	}
	else{
		//Let's find the element that we want to delete and set del
		//Note that if there are two Courses with the same info, this will
		//remove the last one in the list.
		for(pre=this->head; pre->next; pre = pre->next)
			if(pre->next->number.compare(someNumber) == 0 &&
			   pre->next->title.compare(someTitle) == 0){
				del = pre->next;
				pre->next = del->next;
		}
	}

	//If del points to something, then let's delete
	if(del){
		del->next = NULL; //Let's make sure we don't delete the whole list
		delete del;
		this->size--;
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
