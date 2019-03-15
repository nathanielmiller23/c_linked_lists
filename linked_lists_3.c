#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sPerson {
	int age;
	char name[16];
	struct sPerson *nextInLine;
};

void printPerson(struct sPerson *person)
{
    printf("name:%s age:%d address:%X nextInLine:%X\n", person->name,
    person->age, person, person->nextInLine);
}

void PrintList(struct sPerson *list)
{
	printf("Printing List:\n");
	struct sPerson *t;
	t = list;
    if(t == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while(t)
        {
            printPerson(t);
            t = t->nextInLine;
        }
    }
}

struct sPerson *getNewPerson(const int age, const char *name) 
{
    struct sPerson *newPerson = NULL;
    newPerson = (struct sPerson*)malloc(sizeof(struct sPerson));
	newPerson->nextInLine = NULL;
	newPerson->age = age;
    sprintf(newPerson->name, "%s", name);
    printf("new person at %X\n", newPerson);
    return newPerson;
}

int main() 
{
	printf("** START **\n");

    struct sPerson *first = NULL;
    struct sPerson *added = NULL;

    char command[64];
	char name[16];
	int age;

    while(1)
    {
        printf( "Enter a command or value : ");
		fgets(command, 64, stdin);
		if (strncmp("q", command, 1) == 0) 
		{
			printf("Quitting..\n");
			break;
		}
		else if (strncmp("print", command, 5) == 0) 
		{
			printf("Printing..\n");
			PrintList(first);
		}
        else
        {
            if (sscanf(command, "%s %d",  name, &age) != 0)
            {
				printf("Adding %s %d\n", name, age);
                if (first == NULL)
                {
                    first = getNewPerson(age, name);
                    added = first;
                }
                else
                {
                    added->nextInLine = getNewPerson(age, name);
					added = added->nextInLine;
                }
                
            }
        }
        
    }

	return 0;
}


























