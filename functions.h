#include <stdlib.h>
#include <windows.h>


// Colors for show information in console
#define NRMC  "\x1B[0m"             // Normal color (White)
#define REDC  "\e[0;31m"            // Red color
#define GRNC  "\e[0;32m"            // Green color
#define CYNC  "\e[0;36m"            // Cyan color
#define YLWC  "\e[0;33m"            // Yellow color
#define PRPC  "\e[0;35m"            // Purple color

#define BREDC "\e[1;31m"            // Bold Red color
#define BGRNC "\e[1;32m"            // Bold Green color
#define BCYNC "\e[1;36m"            // Bold Cyan color
#define BBLUC "\e[1;34m"            // Bold Blue color
#define BPRPC "\e[1;35m"            // Bold Purple color
//------------------------------------------------------------- 
#define MVLT "\033[1D"              // Move curser left 1 column 
//-------------------------------------------------------------

int stdNum=0;                   // Number of students
int profNum=0;                  // Number of professors
int corsNum=0;                  // Number of courses
stdNode *stdHead=NULL;          // First element of student link list
profNode *profHead=NULL;        // First element of professor link list
courseNode *corsHead=NULL;      // First element of course link list

void pressAnyKey(){
    printf("\n");
    printf("Press any key to continue...");
    getch();
    system("cls");
}

//-----------------------------add members of university-----------------------------------

void addStudent(){         // Add new student to end of the linklist
    stdNode *p, *newStd;
    newStd=getStdNode();
    if(stdHead == NULL){           // Checking that the first element of the linklist is filled
        stdHead=newStd;
    }else {
        p=stdHead;
        while(p->next != NULL){
            p = p->next;
        }
        p->next=newStd;
    }
    
    system("cls");// Clear console
    printf(BBLUC "****Add new student****\n" NRMC);
    printf(BBLUC "------------------------------\n" NRMC);
    printf(YLWC "Enter the first name:\n" CYNC);
    scanf("%s", newStd->name);
    printf(YLWC "Enter the last name:\n" CYNC);
    scanf("%s", newStd->lastName);
    printf(YLWC "Enter the year of birth:\n" CYNC);
    scanf("%d", &newStd->year);
    getchar();
    char ntlTmp[12];
    while(1)
    {
        printf(YLWC "Enter the national code:\n" CYNC);
        scanf("%s", ntlTmp);
        if(checkNtnlNum(ntlTmp)) break;
        printf(REDC "ERR->Enter the correct national code(10 digit)\n" NRMC);
    }
    strcpy(newStd->idCode, ntlTmp);
    stdNum++;
    newStd->stdCode = stdCodeCrtr();
    stdWriteFile();
    system("cls");
    printf(GRNC "****New student was added****\n\n" NRMC);
    pressAnyKey();
}

void addProf(){                         // Add new professor to end of the link list
    profNode *p, *newProf;
    newProf = getProfNode();
    if(profHead == NULL){               // Checking that the first element of the linklist is filled
        profHead = newProf;
    }else{                              // Add a new node to the end of the linked list
        p = profHead;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = newProf;
    }

    system("cls");
    printf(CYNC "**Add new professor**\n" NRMC);
    printf("Enter the first name:\n");
    scanf("%s", newProf->name);
    printf("Enter last name:\n");
    scanf("%s", newProf->lastName);
    char ntlTmp[12];
    while(1){
        printf("Enter the national code:\n");
        scanf("%s", ntlTmp);
        if(checkNtnlNum(ntlTmp)) break;
        printf(REDC "ERR->Enter the correct national code(10 digit)\n" NRMC);
    }
    strcpy(newProf->idCode, ntlTmp);
    profNum++;                                  
    newProf->code = profCodeCrtr();
    printf("slkfjdkl");
    profWriteFile();
    system("cls");
    printf(GRNC "**New professor was added**\n\n\n" NRMC);
    pressAnyKey();
}

void addCourse(){                           // Add a course to program
    courseNode *p, *newCors;
    newCors = getCourseNode();
    if(corsHead == NULL){
        corsHead = newCors;
    }else{
        p = corsHead;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = newCors;
    }
    system("cls");
    printf(CYNC "**Add new course**\n" NRMC);
    printf("Enter name of the course:\n");
    scanf("%s", newCors->name);
    int un;
    while (1){
        printf("Enter number of unit course:\n");
        scanf("%d", &un);
        if(un <= 3 && un>=1) break;
        printf(REDC "ERR->The number of units must be between 1 and 3.\n" NRMC);
    }
    newCors->unit = un;
    corsNum++;
    newCors->code=corsCodeCrtr();
    CrsWriteFile();
    system("cls");
    printf(GRNC "**New course was added**\n\n" NRMC);
    pressAnyKey();
}
//-----------------------------------------------------------

stdNode *findStd(int code){                 // Find student by student code and return a pointer to point it
    stdNode *p;
    p = stdHead;
        for(int i=0; i<stdNum; i++){
            if(p->stdCode == code){
                return p;
            }
            p = p->next;
        }
    return NULL;                            // Return NULL if there is no student with this profile
}

profNode *findProf(int code){               // Find professor by professor code and return a pointer to point it
    profNode *p;
    p = profHead;
    for(int i=0; i<profNum; i++){
        if(p->code == code){
            return p;
        }
        p = p->next;
    }
    return NULL;                            // Return 1 if there is no professor with this profile
}

courseNode *findCrs(int crsCode){           // Find course by course code and return a pointer to point it
    courseNode *p;
    p = corsHead;
    for(int i=0; i<corsNum; i++){
        if(p->code == crsCode){
            return p;
        }
        p = p->next;
    }
    return NULL;                            // Return NULL if there is no course with this profile
}
//------------------------------------------------------------------------

void showAllCrs(){                                     // Show all saved courses
    courseNode *p;
    p = corsHead;
    printf("name-> course code (unit)\n\n");
    for(int i=1; i<=corsNum; i++){
        printf(CYNC "%d) " NRMC "%-8s-> " CYNC "%d" NRMC " (%d)\n", i, p->name, p->code, p->unit);
        p = p->next;
    }
}

void showCrs(courseNode *crs){                      // Show one course
        printf(YLWC "Name" PRPC "->" NRMC "%s\n", crs->name);
        printf(YLWC "Code" PRPC "->" NRMC "%d\n", crs->code);
        printf(YLWC "Unit" PRPC "->" NRMC "%d\n", crs->unit);
        printf("---------------\n");
}

void showStdcrs(stdNode *std){                      // Show the lessons taken by the student
    courseNode *crs;
    for(int i=0; i<std->crsNum; i++){
        crs = findCrs(std->crsCode[i]);
        showCrs(crs);
    }

}

void showAllStd(){                  // Show information of all saved students
    stdNode *p;
    p=stdHead;
    system("cls");
    printf(BBLUC "    name\t  lastName\t   idCode\tstudent code\t    year\t geted unit\t\n");
    printf(YLWC "------------\t------------\t------------\t------------\t------------\t------------\n"NRMC);
    for(int i=0; i<stdNum; i++){
        printf("%-11s\t%-11s\t%-11s\t%-11d\t%-11d\t%-11d\n",
        p->name, p->lastName, p->idCode, p->stdCode, p->year, p->units);
        p = p->next;
    }
    pressAnyKey();
}

void showStd(stdNode *p){                         // Show information of one student
    printf(BBLUC "    name\t  lastName\t   idCode\tstudent code\t    year\t geted unit\t\n");
    printf(YLWC "------------\t------------\t------------\t------------\t------------\t------------\n"NRMC);
    printf("%-11s\t%-11s\t%-11s\t%-11d\t%-11d\n",p->name,
    p->lastName, p->idCode, p->stdCode, p->year, p->units);
}

void ShowAllProf(){                     // Show information of all professors
    profNode *p;
    p=profHead;
    
    printf(BBLUC "    name\t  lastName\t   idCode      professor code\t   courses\t\n");
    printf(YLWC "------------\t------------\t------------\t------------\t------------\n" NRMC);
    for(int i=0; i<profNum; i++){
        printf("%-11s\t%-11s\t%-11s\t%-11d\t%-11d\n",
        p->name, p->lastName, p->idCode, p->code, p->courseNum);
        p=p->next;
    }
    pressAnyKey();
}

void showProf(profNode *p){                                     // Show information of one student
    printf("    name\t  lastName\t   idCode      professor code\t   courses\t\n");
    printf("------------\t------------\t------------\t------------\t------------\n");
    printf("%-11s\t%-11s\t%-11s\t%-11d\t%-11d\n",
    p->name, p->lastName, p->idCode, p->code, p->courseNum);
}

//---------------------------------------------------------------------------

int stdCodeCrtr(){                           // Creat a student code based on the entry year 
    int code = curntYear()*10000+1600;
    code += stdNum;
    return code;
}

int profCodeCrtr(){                          // Creat a professor code based on entry year
    int code=curntYear()*10000 + 1100;
    code += profNum;
    return code;
}

int corsCodeCrtr(){                         // Creat a course code
    int code = curntYear()*10000 + 7700;
    code += corsNum;
    return code;
}

int curntYear(){            // Return current year
    int year;
    time_t t;
    struct tm* crntTime;
    t=time(NULL);
    crntTime=localtime(&t);
    year = crntTime->tm_year + 1900;
    return year;
}

int checkNtnlNum(char num[]){           // Check national code number
    if(strlen(num) == 10){
        return 1;
    }
    return 0;
}

//----------------------------------------------------------------------------------------------


stdNode *stdLogin(){                        // Find student by student number and check their national code
    stdNode *p;
    int stdCode;
    char ntlId[20];
    for(int i=0; i<3; i++){
        printf("Enter the student number:\n");
        scanf("%d", &stdCode);
        p= findStd(stdCode);
        if(p==NULL){
            printf(REDC "ERR->There is no student with this code\n" NRMC);
            continue;
        }
        printf("Enter the national number:\n");
        scanf("%s", ntlId);
        if(strcmp(ntlId, p->idCode)){
            printf(REDC "ERR->Wrong idCode\n" NRMC);
        }else return p;
    }
    return NULL;                            
}

profNode *profLogin(){                                      // Get professor code and national code and checking the user's eligibility to enter
    profNode *prof;
    int profCode;
    char ntlId[20];                                        // professor national code
    for(int i=0; i<3; i++){
        printf(YLWC "Enter professor number: \n" PRPC);
        scanf("%d", &profCode);
        prof = findProf(profCode);
        if(prof == NULL){
            printf(REDC "ERR->There is no professor with this code\n" NRMC);
            continue;
        }
        printf(YLWC "Enter the national Number:\n");
        scanf("%s", ntlId);
        if(strcmp(ntlId, prof->idCode)){
            printf(REDC "ERR->Wrong idCode\n" NRMC);
        }else return prof;
    }
    return NULL;                    
}



int adminLogin(){                       // Check username and password for admin login
    char username[10]="admin";
    char password[10]="admin123";
    char pass[30], user[20];
    for(int i=0; i<=3; i++){
        printf(CYNC "Enter your " BCYNC "username:\n" BPRPC);
        scanf("%s", user);
        printf(CYNC "Enter your " BCYNC "password:\n" BPRPC);
        scanf("%s", pass);
        printf(NRMC);
        if(strcmp(user, username) || strcmp(pass, password)){
                printf(REDC "ERR->Invalid username or password\n" NRMC);
        }else{
            return 1;
        }
    }
    return 0;
}

//---------------------------------------------------------------

void editStd(){                                     // Edit inforamtion of students
    int code,finish;
    stdNode *p;
    char choice, tmp[20];

    printf(CYNC "Enter the student code: " CYNC);
    scanf("%d", &code);
    p=findStd(code);
    if(p==NULL){
        printf(REDC "->No students have been saved yet\n" NRMC);
        finish = 0;
    }else finish=1;

    while(finish){
        printf(CYNC "1)" NRMC "Edit name\n");
        printf(CYNC "2)" NRMC "Edit last name\n");
        printf(CYNC "3)" NRMC "Edit id code\n");
        printf(CYNC "4)" NRMC "Edit year\n");
        printf(CYNC "5)" NRMC "Back to previous menu\n");
        choice = getchar();
        choice = choice=='\n' ? getchar() : choice;
        switch (choice)
        {
            case '1':
                printf(CYNC "current Name is %s\n" NRMC, p->name);
                printf(CYNC "New name : " NRMC);
                scanf("%s", tmp);
                strcpy(p->name, tmp);
                printf(GRNC "ID changed" NRMC);
                pressAnyKey();
                break;
            case '2':
                printf(CYNC "current last Name is %s\n" NRMC, p->lastName);
                printf(CYNC "New last name : " NRMC);
                scanf("%s", tmp);
                strcpy(p->lastName, tmp);
                break;
            case '3':
                printf(CYNC "current id code is %s\n" NRMC, p->idCode);
                printf(CYNC "New id code : " NRMC);
                scanf("%s", tmp);
                strcpy(p->idCode, tmp);
                break;
            case '4':
                printf(CYNC "current year is %d\n" NRMC, p->year);
                printf(CYNC "New year : " NRMC);
                scanf("%d", &p->year);
                break;
            case '5':
                finish=0;                               // Break the loop
                break;
            default:
                system("cls");
                printf(REDC "Enter the correct number\n" NRMC);
                break;
        }
    }
    stdWriteFile();
}

void editProf(){                // Edit professor inforamtion
    int code, finish;
    char tmp[20], choice;
    profNode *p;

    printf(CYNC "Enter professor code: " NRMC);
    scanf("%d", &code);
    p = findProf(code);
    if(p==NULL){
        finish = 0;
        printf(REDC "ERR->There is no professor with this code" NRMC);
    }else finish = 1;
    while (finish)
    {
        printf(CYNC "1) " NRMC "Edit name\n");
        printf(CYNC "2) " NRMC "Edit last name\n");
        printf(CYNC "3) " NRMC "Edit id code\n");
        printf(CYNC "4) " NRMC "Back to previous menu\n");

        choice = getchar();
        choice = choice=='\n' ? getchar() : choice;
        switch (choice)
        {
        case '1':
            system("cls");
            printf(CYNC "current name is " PRPC "%s\n" NRMC, p->name);
            printf(CYNC "New name: " NRMC);
            scanf("%s", tmp);
            strcpy(p->name, tmp);
            printf(GRNC "Name changed" NRMC);
            pressAnyKey();
            break;
        case '2':
        system("cls");
            printf(CYNC "current last name is " PRPC "%s\n" NRMC, p->lastName);
            printf(CYNC "New last name: " NRMC);
            scanf("%s", tmp);
            strcpy(p->lastName, tmp);
            printf(GRNC "Name changed" NRMC);
            pressAnyKey();
            break;
        case '3':
            printf(CYNC "current id is " PRPC "%s\n" NRMC, p->name);
            printf(CYNC "New id code: " NRMC);
            scanf("%s", tmp);
            strcpy(p->idCode, tmp);
            printf(GRNC "ID changed" NRMC);
            pressAnyKey();
            break;
        case '4':
            finish = 0;                             // Break the infinity loop
            break;
        default:
            system("cls");
            printf(REDC "Enter the correct number\n" NRMC);
            break;
        }
    }
    profWriteFile();   
}

void editCrs(){                                     // Edit course information
    int code, finish;
    char tmp[20], choice;
    courseNode *p;

    printf(CYNC "Enter course code: " NRMC);
    scanf("%d", &code);
    p = findProf(code);
    if(p==NULL){
        finish = 0;
        printf(REDC "ERR->There is no professor with this code" NRMC);
    }else finish = 1;
    while (finish)
    {
        printf(CYNC "1)" NRMC "Edit name\n");
        printf(CYNC "2)" NRMC "Edit unit\n");
        printf(CYNC "3)" NRMC "Back to previous menu\n");

        choice = getchar();
        choice = choice=='\n' ? getchar() : choice;
        switch (choice)
        {
        case '1':
            printf(YLWC "current name is " PRPC "%s\n" NRMC, p->name);
            printf(YLWC "New name: " PRPC);
            scanf("%s", tmp);
            strcpy(p->name, tmp);
            break;
        case '2':
            printf(YLWC "current unit is " PRPC "%d\n" NRMC, p->unit);
            printf(YLWC "New name: " PRPC);
            scanf("%d", &p->code);
            break;
        case '3':
            finish = 0;                         // Break the infinity loop
            break;
        default:
            system("cls");
            printf(REDC "Enter the correct number\n" NRMC);
            break;
        }
    }
    CrsWriteFile();
}
//-------------------------------------------------

void removeStdQuest(){                          // Get approval to remove a student
    int code;
    char choice;
    stdNode *p;
    system("cls");
    for(int i=0; i<3; i++){
        printf(CYNC "Enter the student code: " NRMC);
        scanf("%d", &code);
        p=findStd(code);
        if(p==NULL){
            printf(REDC"ERR->This student code was not found\n");
            continue;
        }else{
            showStd(p);
            while(choice !='y' && choice != 'n'){
                printf(YLWC "do you want to remove this student?(y of n)\n" CYNC);
                choice = getchar();
                choice = choice=='\n' ? getchar() : choice;
                switch (choice)
                {
                case 'y':
                    removeStd(code);
                    stdWriteFile();
                    system("cls");
                    printf(REDC "*** Student was deleted ***\n\n" NRMC);
                    pressAnyKey();
                    break;
                case 'n':
                    system("cls");
                    printf(REDC "Delete operation was cancelled\n\n" NRMC);
                    pressAnyKey();
                    break;
                default:
                    printf(REDC "ERR->Please Enter 'y' or 'n'\n" NRMC);
                    break;
                }
            }
            break;
        }
    }
}

void removeStd(int code){
    stdNode *p, *previouseNode, *remvNode;
    if(stdHead->stdCode == code){                        // If the element to be deleted is at the head of the linklist
        remvNode = stdHead;
        stdHead = stdHead->next;                    
        free(remvNode);
        stdNum--;
    }else{
        p=stdHead;
        for(int i=0; i<stdNum-1; i++){
            previouseNode = p;
            p=p->next;
            if(p->stdCode == code){
                remvNode = p;
                previouseNode->next = p->next;               // Pointing the previous node to the next node and deleting the selected node                            // Free allocated memory
                stdNum--;
                break;
            }
        }
    }
}

void removeTakenCourseQuest(stdNode *std){                  // Get approval to remove a taken course
    stdNode *student;
    student = std;
    int code;
    showStdcrs(student);
    for(int i=0;i<3; i++){
        printf(YLWC "Enter the course code do you want to delete: " PRPC);
        scanf("%d", &code);
        if(checkTakenCrs(student, code) == 0){
            printf(REDC "You didn't get this course\n");
            continue;
        }else{
            courseNode *crs;
            crs = findCrs(code);
            showCrs(crs);
            char choice;
            while (choice != 'y' && choice != 'n'){
                printf(YLWC "Do you want to delete this course(y or n)?\n");
                choice = getchar();
                choice = choice=='\n' ? getchar() : choice;
                switch (choice)
                {
                case 'y':
                    removeTakenCourse(student, code);
                    stdWriteFile();
                    system("cls");
                    printf(REDC "***Course was deleted***\n\n");
                    pressAnyKey();
                    break;
                case 'n':
                    system("cls");
                    printf(REDC "***Delete operation was canceled***\n\n"NRMC);
                    pressAnyKey();
                    break;
                default:
                    printf(REDC "Pleas enter 'y' or 'n'\n" NRMC);
                    break;
                }
            }
            break;
        }
    }
}

void removeTakenCourse(stdNode *std, int code){                     // Delete taken course 
    int pos;
    for(int i=0; i<std->crsNum; i++){
        printf("i -> %d\n", i);
        if(code == std->crsCode[i]){
            pos = i;
            for(int j=pos; j<std->crsNum-1; j++){
                printf("j -> %d\n", j);
                std->crsCode[j] = std->crsCode[j+1];                // Delete course code from list of taken courses
            }
            std->crsNum--;
            break;
        }
    }
}

int checkTakenCrs(stdNode *std, int code){
    for(int i=0; i<std->crsNum; i++){
        if(std->crsCode[i] == code){
            return 1;
        }
    }
    return 0;
}

void removeProfQuest(){                                     // Get approval to remove a professor
    profNode *p;
    char choice;
    int code;
    system("cls");
    for(int i=0; i<3; i++){
        printf(CYNC "Enter the professor code: " CYNC);
        scanf("%d", &code);
        p=findProf(code);
        if(p==NULL){
            printf(REDC"ERR->This professor code was not found\n");
            continue;
        }else{
            showProf(p);
            while(choice !='y' && choice != 'n'){
                printf(YLWC "Do you want to remove this professor?(y or n)\n" CYNC);
                choice = getchar();
                choice = choice=='\n' ? getchar() : choice;
                switch (choice)
                {
                case 'y':
                    removeProf(code);
                    profWriteFile();
                    system("cls");
                    printf(REDC "**Professor was deleted**\n" NRMC);
                    pressAnyKey();
                    break;
                case 'n':
                    system("cls");
                    printf(REDC "Delete operation was cancelled\n\n" NRMC);
                    pressAnyKey();
                    break;
                default:
                    printf(REDC "ERR->Please Enter 'y' or 'n'\n" NRMC);
                    break;
                }
            }
            break;              // Break the for loop
        }
    }
}

void removeProf(int profcode){
    profNode *p, *previouseNode, *remvNode;
    if(profHead->code == profcode){
        printf("here\n");
        remvNode = profHead;
        profHead = profHead->next;
        free(remvNode);
        profNum--;
    }else{
        p=profHead;
        for(int i=0; i<profNum; i++)
        previouseNode = p;
        p=p->next;
        if(p->code == profcode){
            remvNode = p;                                       // Save addres of selected Node for free up it
            previouseNode->next = p->next;
            free(remvNode);
            profNum--;
        }
    }
}

void removeCrsQuest(){
    int code;
    char choice;
    courseNode *p;
    showAllCrs();
    for(int i=0; i<3; i++){
        printf(YLWC "Enter the course code: " CYNC);
        scanf("%d", &code);
        p = findCrs(code);
        if(p==NULL){
            printf(REDC"ERR->This course code was not found\n");
            continue;
        }else{
            showCrs(p);
            printf(YLWC "Do you want to delete this course(y or n)?\n" PRPC);
            while (choice !='y' && choice != 'n'){
                choice = getchar();
                choice = choice=='\n' ? getchar() : choice;
                switch (choice)
                {
                case 'y':
                    removeCrs(code);
                    CrsWriteFile();
                    stdWriteFile();
                    printf(REDC "** Course was deleted **\n" NRMC);
                    break;
                case 'n':
                    printf(REDC "Delete operation was cancelled\n" NRMC);
                    break;
                default:
                    printf(REDC "ERR->Please Enter 'y' or 'n'\n" NRMC);
                    break;
                }
            }
            break;                          // Break the for loop
        }
    }   
}

void removeCrs(int crsCode){                                        // Delete a course from program and delete it from all of students
    courseNode *p, *previouseNode, *remvNode;

    if(corsHead->code == crsCode){
        remvNode = corsHead;
        corsHead = corsHead->next;
        corsNum--;
    }else{
        p=corsHead;
        for(int i=0; i<corsNum; i++){
            previouseNode = p;
            p=p->next;
            if(p->code == crsCode){
                remvNode = p;
                previouseNode->next = p->next;
                free(remvNode);
                corsNum--;
            }
        }
    }

    stdNode *ps;                    // Remove course code from all students
    ps = stdHead;
    for(int i=0; i<stdNum; i++){                    
        printf("here8\n");
        removeTakenCourse(ps, crsCode);
        ps->units -= remvNode->unit;
        ps = ps->next;
    }
    free(remvNode);
}

void takeStdCourse(stdNode *std){                   // Choosing a course by the student
    courseNode *crs;
    int code;
    while (1){
        showAllCrs();
        printf(YLWC "Enter the course code <or Enter 0 for back to the menu>: " CYNC);
        scanf("%d", &code);
        if(code == 0) break;
        crs = findCrs(code);
        if(crs == NULL){
            printf(REDC "--> Course not found\n" NRMC);
        }else{
            std->crsCode[std->crsNum] = code;
            std->crsNum = std->crsNum +1;
            std->units += crs->unit;
        }
    }
    stdWriteFile();
}

void takeProfCrs(profNode *prof){
    courseNode *crs;
    int code;
    while (1)
    {
        showAllCrs();
        printf(YLWC "Enter the course code <or Enter 0 for back to the menu>:" CYNC);
        scanf("%d", &code);
        if(code == 0) break;
        crs = findCrs(code);
        if(crs == NULL){
            printf(REDC "--> Course not found\n" NRMC);
        }else{
            prof->crsCode[prof->courseNum] = code;
            prof->courseNum +=1;
        }
    }
    profWriteFile();
}

void showProfTakenCrs(profNode *prof){
    courseNode *crs;
    for (int  i = 0; i < prof->courseNum; i++)
    {
        crs = findCrs(prof->crsCode[i]);
        showCrs(crs);
    }
}



//----------------------------read write in file-------------------------------------

int CrsWriteFile(){                         // Write elements of linked list to file
    courseNode *crs;
    crs=corsHead;
    FILE *file;

    file = fopen("course.bin", "wb");
        fseek(file, 0*sizeof(courseNode), SEEK_SET);
        for(int i=0; i<corsNum; i++){
            fwrite(crs, sizeof(courseNode), 1, file);
            crs=crs->next;
        }
    fclose(file);
}

int crsReadFile(){                     // Read courses from file and resaved to lenked list
    FILE *file;
    courseNode *p, *node;
    file=fopen("course.bin", "rb");
    if(!file){
        return 0;
    }else{
        node=getCourseNode();
        while(fread(node, sizeof(courseNode), 1, file)==1){
            if(corsHead == NULL){
                corsHead = node;
                p = corsHead;
            }else{
                p->next = node;
                p=p->next;
            }
            node=getCourseNode();
            corsNum++;
        }
    }
    fclose(file);
    p->next = NULL;
}

int stdWriteFile(){
    stdNode *std;
    FILE *file;
    std = stdHead;
    file=fopen("student.bin", "wb");
    fseek(file, 0*sizeof(stdNode), SEEK_SET);
    for(int i=0; i<stdNum; i++){
        fwrite(std, sizeof(stdNode), 1, file);
        std = std->next;
    }
    fclose(file);
}

int stdReadFile(){
    stdNode *p, *node;
    FILE *file;
    file=fopen("student.bin", "rb");
    if(!file){
        return 0;
    }else{
        node=getStdNode();
        while (fread(node, sizeof(stdNode), 1, file)==1){
            if(stdHead == NULL){
                stdHead = node;
                p=stdHead;
            }else{
                p->next = node;
                p = p->next;
            }
            node=getStdNode();
            stdNum++;
            p->next = NULL;
        }
    }
    fclose(file);
}

void profWriteFile(){                           // Write profesors information to file
    profNode *prof;
    FILE *file;
    prof = profHead;
    file=fopen("professor.bin", "wb");
    for(int i=0; i<profNum; i++){
        fwrite(prof, sizeof(profNode), 1, file);
        prof = prof->next;
    }
    fclose(file);
}

int profReadFile(){                                 // Read professor information from file
    profNode *p, *node;
    FILE *file;
    file = fopen("professor.bin", "rb");
    node = getProfNode();
    while (fread(node, sizeof(profNode), 1, file)){
        if(profHead == NULL){
            profHead = node;
            p = profHead;
        }else{
            p->next=node;
            p = p->next;
        }
        node=getProfNode();
        profNum++;
        p->next = NULL;
    }
    fclose(file);
}

void readFile(){                                // Read all data from file and save it to linked list
    system("cls");
    printf(BGRNC "-->Read database<--\n");
    Sleep(600);
    for(int i=0; i<15; i++){                    // Progress bar
        printf(BGRNC "--" BREDC ">");
        Sleep(60);
        printf(MVLT);                           // Move curser to left
    }
    printf("\n");
    crsReadFile();
    stdReadFile();
    profReadFile();
    Sleep(400);
    system("cls");
    printf(BGRNC "**COMPLET**" NRMC);
    Sleep(800);
    system("cls");
}