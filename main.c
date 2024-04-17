#pragma CHECK_MISRA("none")
#include <stdio.h>
#pragma CHECK_MISRA("all")
#include "doublelinkedlist.h"

/* David Dardic RA228/2019 */

/*
U ovom zadatku je bilo potrebno napraviti dvostruko spregnutu listu
i izvesti je kao staticku biblioteku.Zatim je potrebno napraviti dve funkcije.
Prva funkcija proverava da li jedan od elemenata ispunjava uslov koji smo zadali,
dok druga ima pokazivac na prvu funkciju i njome se sluzi kako bi ispitala sve elemente
u listi, i ukoliko ne ispunjava zadati uslov brisemo ih. Ovaj zadatak sam uradio tako sto
sam napravio listu studenata i izbacivao ih ukoliko ih je godina upisa starija od 2019.
*/

/*
    STATICKA BIBLIOTEKA

    gcc -c doublelinkedlist.c
    ar rs liblist.a doublelinkedlist.o
    gcc --static -I./list -L./list main.c -o out -l:liblist.a
    ./out

*/

/*
    MISRA
    source set_env.sh
    cl6x --include_path=$TI_INCLUDE --compile_only --check_misra=all main.c
*/


/* Checks whether the student year is less than 2019*/
static bool checkOne(const student* const s);

/* Loops through the list and deletes students with year less than 2019 */
static void removeStudent(bool (*f)(const student* s), StudentList* const list);

void main()
{
    StudentList student_list;

    StudentListCreate(&student_list);

    StudentListInsert(&student_list, NULL, "David", "Dardic", "RA", (uint_least16_t)228, (uint_least16_t)2019);
    StudentListInsert(&student_list, student_list.tail, "Ana", "Markovic", "PSI", (uint_least16_t)14, (uint_least16_t)2020);
    StudentListInsert(&student_list, student_list.tail, "Miodrag", "Djukic", "GR", (uint_least16_t)100, (uint_least16_t)2019);
    StudentListInsert(&student_list, student_list.tail, "Jovana", "Pijetlovic", "GR", (uint_least16_t)100, (uint_least16_t)2004);
    StudentListInsert(&student_list, student_list.tail, "Milana", "Jankovic", "PSI", (uint_least16_t)251, (uint_least16_t)2023);
    StudentListInsert(&student_list, student_list.tail, "Marko", "Markovic", "RA", (uint_least16_t)251, (uint_least16_t)2003);
    StudentListInsert(&student_list, student_list.tail, "Branko", "Stefanovic", "RA", (uint_least16_t)56, (uint_least16_t)2018);
    StudentListInsert(&student_list, student_list.tail, "Milica", "Bojic", "AI", (uint_least16_t)17, (uint_least16_t)2020);

    StudentListPrint(&student_list);

    removeStudent(&checkOne, &student_list);
    printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n");

    StudentListPrint(&student_list);
    StudentListDestroy(&student_list);

    printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n");

    if(StudentListIsEmpty)
    {
        printf("List is now empty!\n\n");
    }

}

static bool checkOne(const student* const s)
{

    bool flag = (bool)false;

    if (s->year < (uint_least16_t)2019)
    {
        flag = (bool)true;
    }

    return flag;
}


static void removeStudent(bool (*f)(const student* s), StudentList* const list)
{

    student* current = list->tail;
    while (current != NULL)
    {
        bool x = f(current);

        if (x == true)
        {
            student* delete = current;
            current = current->prev;
            StudentListDelete(list, delete);
        }
        else
        {
            current = current->prev;
        }
    }
}
