#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "creatNodes.h"
#include "structure.h"

int checkNtnlNum(char []);

#define NRMC  "\x1B[0m"         // Normal color (White)
#define REDC  "\x1B[31m"        // Red color
#define GRNC  "\x1B[32m"        // Green color
#define CYNC  "\x1B[36m"        // Cyan color



void addStudent(stdNode *head){         // Add new student to end of the linklist
    stdNode *p, *newStd;
    newStd=getStdNode();
    if(head == NULL){           // Checking that the first element of the linklist is filled
        head=newStd;
    }else {
        p=head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next=newStd
    }
    
    system("cls");// Clear console
    printf(CYNC "**Add new student**" NRMC);
    printf("Enter the first name:\n");
    scanf("%s", newStd->name);
    printf("Enter the last name:\n")
    scanf("%s", newStd->lastName);
    printf("Enter the year of birth:\n");
    scanf("%d", newStd->year);
    char ntlTmp[10];
    while(1)
    {
        printf("Enter the national code:\n");
        scanf("%s", ntlTmp)
        if(checkNtnlNum(ntlTmp)) break;
        printf("")
    }
    
    
    



}

int checkNtnlNum(char num[]){
    if(strlen(num) == 10){
        return 1;
    }
    return 0;
}