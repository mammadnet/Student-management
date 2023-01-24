#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#include "structure.h"
#include "creatNodes.h"
#include "functions.h"

void mainMenu();
void stdMenu();
void adminMenu();
int adminLogin();
stdNode *stdLogin();


int main(){
    readFile();
    mainMenu();
    CrsWriteFile();

}

void mainMenu(){
    while (1)
    {
        system("cls");
        printf(CYNC "1)" NRMC " Login Student\n");
        printf(CYNC "2)" NRMC " Login Professor\n");
        printf(CYNC "3)" NRMC " Login Admin\n");
        printf(CYNC "4)" NRMC " exit\n");
        char choice;
        choice = getchar();
        choice = choice=='\n' ? getchar() : choice;
        switch (choice)
        {
        case '1':
            stdMenu();
            break;
        case '2':
            profMenu();
            break;
        case '3':
            adminMenu();
            break;
        case '4':
            exit(0);
            break;
        default:
            printf(REDC "->Enter the correct number\n" NRMC);
            break;
        }
    }
}
//-----------------------------------Elements of main menu------------------------------
void stdMenu(){                                     // Menu for student panel
    int finish;
    stdNode *std;
    system("cls");
    std = stdLogin();
    if(std != NULL){
        system("cls");
        finish =1;
    }else{
        printf(REDC "**Back to menu**\n" NRMC);
        finish =0;
    }

    while(finish){
        printf(CYNC "1) " NRMC "Take course\n");
        printf(CYNC "2) " NRMC "Delete course\n");
        printf(CYNC "3) " NRMC "List of courses taken\n");
        printf(CYNC "4) " NRMC "List of all courses\n");
        printf(CYNC "5) " NRMC "Back to main menu\n");
        char choice;
        choice = getchar();
        choice = choice=='\n' ? getchar() : choice;
        switch (choice)
        {
        case '1':
            takeStdCourse(std);
            break;
        case '2':
            removeTakenCourseQuest(std);
            break;
        case '3':
            showStdcrs(std);
            break;
        case '4':
            showAllCrs();
            pressAnyKey();
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

void profMenu(){
    int finish;
    profNode *prof;
    system("cls");
    prof=profLogin();
    if(prof != NULL){
        system("cls");
        finish = 1;
    }else{
        printf("back to menu");
        finish = 0;
    }

    while (finish)
    {
        while(finish){
            printf(CYNC "1) " NRMC "Take course\n");
            printf(CYNC "2) " NRMC "Delete course\n");
            printf(CYNC "3) " NRMC "List of courses taken\n");
            printf(CYNC "4) " NRMC "List of all courses\n");
            printf(CYNC "5) " NRMC "Back to main menu\n");
            char choice;
            choice = getchar();
            choice = choice=='\n' ? getchar() : choice;
            switch (choice)
            {
                case '1':
                    takeProfCrs(prof);
                    break;
                case '2':
                    // code
                    break;
                case '3':
                    showProfTakenCrs(prof);
                    break;
                case '4':
                    showAllCrs();
                    pressAnyKey();
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
}

void adminMenu(){
    int finish;
    system("cls");
    if(adminLogin()){
        finish = 1;
    }else{
        finish =0;
    }
    while(finish){
        system("cls");
        printf(CYNC "1) " NRMC "Student managment\n");
        printf(CYNC "2) " NRMC "Professor managment\n");
        printf(CYNC "3) " NRMC "Course managment\n");
        printf(CYNC "4) " NRMC "Back to main menu\n");
        char choice;
        choice = getchar();
        choice = choice=='\n' ? getchar() : choice;
        switch (choice)
        {
        case '1':
            stdManagMenu();
            break;
        case '2':
            profManagMenu();
            break;
        case '3':
            crsManagMenu();
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
//---------------------------------------------------------------------

void stdManagMenu(){
    int finish=1;
    system("cls");
    while(finish){
    printf(CYNC "1) " NRMC "Show all students\n");
    printf(CYNC "2) " NRMC "Student registration\n");
    printf(CYNC "3) " NRMC "Edit student information\n");
    printf(CYNC "4) " NRMC "Remove the student\n");
    printf(CYNC "5) " NRMC "Back to previous menu\n");
    char choice;
    choice = getchar();
    choice = choice=='\n' ? getchar() : choice;
    switch (choice)
    {
        case '1':
            showAllStd();
            break;
        case '2':
            addStudent();
            break;
        case '3':
            editStd();
            break;
        case '4':
            removeStdQuest();
            break;
        case '5':
            finish=0;
            break;    
        default:
            system("cls");
            printf(REDC "Enter the correct number\n" NRMC);
            break;
        }
    }
}

void profManagMenu(){
    int finish=1;
    char choice;
    system("cls");
    while(finish){
    printf(CYNC "1) " NRMC "professor registration\n");
    printf(CYNC "2) " NRMC "Show all professor\n");
    printf(CYNC "3) " NRMC "Edit professor information\n");
    printf(CYNC "4) " NRMC "Remove the professor\n");
    printf(CYNC "5) " NRMC "Back to previous menu\n");
    choice = getchar();
    choice = choice=='\n' ? getchar() : choice;
    switch (choice)
        {
        case '1':
            addProf();
            break;
        case '2':
            ShowAllProf();
            break;
        case '3':
            editCrs();
            break;
        case '4':
            removeProfQuest();
            break;
        case '5':
            finish=0;
            break;    
        default:
            system("cls");
            printf(REDC "Enter the correct number\n" NRMC);
            break;
        }
    }
}

void crsManagMenu(){
    int finish=1;
    system("cls");
    while(finish){
        printf(CYNC "1) " NRMC "Add course\n");
        printf(CYNC "2) " NRMC "Show all course\n");
        printf(CYNC "3) " NRMC "Edit course information\n");
        printf(CYNC "4) " NRMC "Remove the course\n");
        printf(CYNC "5) " NRMC "Back to previous menu\n");
        char choice;
        choice = getchar();
        choice= choice=='\n' ? getchar() : choice;
        switch (choice)
        {
        case '1':
            addCourse();
            break;
        case '2':
            showAllCrs();
            pressAnyKey();
            break;
        case '3':
            editCrs();
            break;
        case '4':
            removeCrsQuest();
            break;
        case '5':
            finish=0;
            break;    
        default:
            system("cls");
            printf(REDC "Enter the correct number\n" NRMC);
            break;
        }
    }
}




