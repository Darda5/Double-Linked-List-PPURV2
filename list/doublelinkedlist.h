#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_

#include <inttypes.h>
#include <stdbool.h>

#define NAME_SIZE 15
#define TAG_SIZE 4

typedef struct student
{
	uint_least16_t id;
	uint_least16_t year;
	char course_tag[TAG_SIZE];
	char name[NAME_SIZE];
	char last_name[NAME_SIZE];

	struct student* prev;
	struct student* next;
} student;

typedef struct StudentList
{
	student* head;
	student* tail;
} StudentList;


/* Creates empty list */
void StudentListCreate(StudentList* const list);

/* Frees all memory allocated to this list */
void StudentListDestroy(StudentList* const list);

/* Inserts student in a specific location*/
bool StudentListInsert(StudentList* list, student* location, const char* const sname, const char* const lname,
const char* const tag, const uint_least16_t student_id, const uint_least16_t student_year);

/* Deletes student from a specific location */
bool StudentListDelete(StudentList* const list, student* const location);

/* Checks if the list is empty */
bool StudentListIsEmpty(const StudentList* const list);

/* Prints out the list*/
void StudentListPrint(const StudentList* const list);

#endif /*DOUBLELINKEDLIST_H_*/
