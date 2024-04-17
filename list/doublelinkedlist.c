#include "doublelinkedlist.h"

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/* Creates empty list */
void StudentListCreate(StudentList* const list){
    list->head = NULL;
    list->tail = NULL;
}

/* Frees all memory allocated to this list */
void StudentListDestroy(StudentList* const list)
{
	if (list->head == NULL)
	{
		return;
	}

	student* current = list->tail;

	while (current != list->head)
	{
		current = current->prev;
		free(current->next);
	}
	free(current);
	list->head = NULL;
	list->tail = NULL;
}

/* Inserts student in a specific location*/
bool StudentListInsert(StudentList* const list, student* const location, const char* const sname, const char* const lname, const char* const tag, const uint_least16_t student_id, const uint_least16_t student_year)
{
	student* element = malloc(sizeof(student));

	strncpy(element->name, sname, NAME_SIZE-1);
	element->name[NAME_SIZE-1] = '\0';

    strncpy(element->last_name, lname, NAME_SIZE-1);
	element->last_name[NAME_SIZE-1] = '\0';

	strncpy(element->course_tag, tag, TAG_SIZE-1);
	element->course_tag[TAG_SIZE-1] = '\0';

	element->year = student_year;
    element->id = student_id;

	if (location == NULL)
	{
		element->next = list->head;
		element->prev = NULL;
		list->head = element;
	}
	else
	{
		element->next = location->next;
		element->prev = location;
		location->next = element;
	}

	if(element->next != NULL)
	{
		element->next->prev = element;
	}
	else
	{
		list->tail = element;
	}

	return true;
}


/* Deletes student from a specific location */
bool StudentListDelete(StudentList* const list, student* const location)
{
	if(location == NULL)
	{
		return false;
	}

	if (location == list->head)
	{
		list->head = location->next;
	}
	else
	{
		location->prev->next = location->next;
	}

    	if(location == list->tail)
	{
		list->tail = location->prev;
	}
	else
	{
		location->next->prev = location->prev;
	}

	free(location);
	return true;
}

/* Checks if the list is empty */
bool StudentListIsEmpty(const StudentList* const list)
{
	return (list->head == NULL);
}

/* Prints out the list*/
void StudentListPrint(const StudentList* const list)
{
	student* current = list->head;
	while (current != NULL)
	{
		printf("------------------------------------------------\n");
		printf("NAME:       %s\n", current->name);
		printf("LAST NAME:  %s\n", current->last_name);
		printf("COURSE TAG: %s\n", current->course_tag);
		printf("ID:         %"PRIuLEAST16"\n", current->id);
        	printf("YEAR:       %"PRIuLEAST16"\n", current->year);
		current = current->next;
	}

}
