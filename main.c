#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "structure.h"
#include "creatNodes.h"
#include "functions.h"

void mainMenu();
void stdMenu();
void adminMenu();
int adminLogin();
stdNode *stdLogin();


int main(){
    // addCourse();
    // addCourse();
    // addCourse();
    // addCourse();
    // showCrs();
    addStudent();
    printf("%d\n", stdHead->stdCode);
    printf("%s\n", stdHead->idCode);
    mainMenu();
}

void mainMenu(){
    while (1)
    {
        printf(CYNC "1)" NRMC " Login Student\n");
        printf(CYNC "2)" NRMC " Login Admin\n");
        printf(CYNC "3)" NRMC " exit\n");
        char choc;
        getchar();
        choc = getchar();
        switch (choc)
        {
        case '1':
            stdMenu();
            break;
        case '2':
            adminMenu();
            break;
        case '3':
            exit(0);
            break;
        default:
            printf(REDC "->Enter the correct number\n" NRMC);
            break;
        }
    }
}

void stdMenu(){
    int finish;
    if(stdLogin() != NULL){
        finish =1;
    }else{
        printf(REDC "**Back to menu**\n" NRMC);
        finish =0;
    }

    while(finish){
        printf(CYNC "1)" NRMC " Add course\n");
        printf(CYNC "2)" NRMC " Delete course\n");
        printf(CYNC "3)" NRMC " List of courses taken\n");
        printf(CYNC "4)" NRMC " List of all courses\n");
        printf(CYNC "5)" NRMC " Back to main menu\n");
        char choc;
        choc = getchar();
        getchar();
        switch (choc)
        {
        case '1':
            /* code */
            break;
        case '2':
            /* code */
            break;
        case '3':
            /* code */
            break;
        case '4':
            /* code */
            break;
        case '5':
            finish = 0;                                         // Break the loop and finish the function operation
            break;
        default:
            printf(REDC "Enter the correct number\n" NRMC);
            break;
        }
    }
}

void adminMenu(){
    int finish;
    if(adminLogin()){
        finish = 1;
    }else{
        finish =0;
    }
    while(finish){
        printf(CYNC "1)" NRMC " Student managment\n");
        printf(CYNC "2)" NRMC " Professor managment\n");
        printf(CYNC "3)" NRMC " Course managment\n");
        printf(CYNC "4)" NRMC " Back to main menu\n");
        char choc;
        choc = getchar();                                      // Get newline
        switch (choc)
        {
        case '1':
            /* code */
            break;
        case '2':
            /* code */
            break;
        case '3':
            /* code */
            break;
        case '4':
            finish=0;
            break;
        default:
            printf(REDC "Enter the correct number\n" NRMC);
            break;
        }
    }
}

int adminLogin(){                       // Check username and password for admin login
    char username[10]="admin";
    char password[10]="admin123";
    char pass[30], user[20];
    for(int i=0; i<=3; i++){
        printf(CYNC "Enter your username:\n" NRMC);
        scanf("%s", user);
        printf(CYNC "Enter your password:\n" NRMC);
        scanf("%s", pass);
        getchar();
        if(strcmp(user, username) && strcmp(pass, password)){
                printf(REDC "ERR->Invalid username or password\n" NRMC);
        }else{
            return 1;
        }
    }
    return 0;
}

stdNode *stdLogin(){
    stdNode *p;
    int stdCode;
    char ntlId[20];
    p=findStd(stdCode);
    for(int i=0; i<3; i++){
        printf("Enter the student number:\n");
        scanf("%d", &stdCode);
        p= findStd(stdCode);
        if(p==NULL){
            printf(REDC "ERR->There is no student with this code\n" NRMC);
            continue;
        }
        printf("Enter the id number:\n");
        scanf("%s", ntlId);
        if(strcmp(ntlId, p->idCode)){
            printf(REDC "ERR->Wrong idCode\n" NRMC);
        }else return p;
    }
    return NULL;
}


