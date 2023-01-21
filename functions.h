
#define NRMC  "\x1B[0m"             // Normal color (White)
#define REDC  "\e[0;31m"            // Red color
#define GRNC  "\e[0;32m"            // Green color
#define CYNC  "\e[0;36m"            // Cyan color
#define YLWC  "\e[0;33m"            // Yellow color
#define PRPC  "\e[0;35m"            // Purple color

#define BREDC "\e[1;31m"            // Bold Red color
#define BGRNC "\e[1;32m"            // Bold Green color
#define BCYNC "\e[1;36m"            // Bold Cyan color
#define BYLWC "\e[1;33m"            // Bold Yellow color
#define BBLUC "\e[1;34m"            // Bold Blue color
#define BPRPC "\e[1;35m"            // Bold Purple color

int stdNum=0;                   // Number of students
int profNum=0;                  // Number of professors
int corsNum=0;                  // Number of courses
stdNode *stdHead=NULL;          // First element of student link list
profNode *profHead=NULL;        // First element of professor link list
courseNode *corsHead=NULL;      // First element of course link list


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
    system("cls");
    printf(GRNC "****New student was added****\n\n" NRMC);
    printf("Press any key for continue...\n");
    getch();
    system("cls");
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
    system("cls");
    printf(GRNC "**New professor was added**\n\n\n" NRMC);
    printf("press any key for continue...");
    getch();
    system("cls");
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
    system("cls");
    printf(GRNC "**New course was added**\n\n" NRMC);
    printf("press any key for continue...\n");
    getch();
    system("cls");
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
    printf("\n");
}

void showCrs(int code){                      // Show one course by course code
        courseNode *crs;
        crs = findCrs(code);
        printf(YLWC "Name" PRPC "->" NRMC "%s\n", crs->name);
        printf(YLWC "Code" PRPC "->" NRMC "%d\n", crs->code);
        printf(YLWC "Unit" PRPC "->" NRMC "%d\n", crs->unit);
        printf("---------------\n");
}

void showStdcrs(stdNode *std){                      // Show the lessons taken by the student
    courseNode *crs;
    for(int i=0; i<std->crsNum; i++){
        showCrs(std->crsCode[i]);
    }

}

void showAllStd(){                  // Show information of all saved students
    stdNode *p;
    p=stdHead;
    printf(BBLUC "    name\t  lastName\t   idCode\tstudent code\t    year\t geted unit\t\n");
    printf(YLWC "------------\t------------\t------------\t------------\t------------\t------------\n"NRMC);
    for(int i=0; i<stdNum; i++){
        printf("%-11s\t%-11s\t%-11s\t%-11d\t%-11d\t%-11d\n",
        p->name, p->lastName, p->idCode, p->stdCode, p->year, p->units);
        p = p->next;
    }
    printf("\n");
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
    
    printf("    name\t  lastName\t   idCode      professor code\t   courses\t\n");
    printf("------------\t------------\t------------\t------------\t------------\n");
    for(int i=0; i<profNum; i++){
        printf("%-11s\t%-11s\t%-11s\t%-11d\t%-11d\n",
        p->name, p->lastName, p->idCode, p->code, p->courseNum);
        p=p->next;
    }
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
        printf(CYNC "1)" NRMC "Edit name\n");
        printf(CYNC "2)" NRMC "Edit last name\n");
        printf(CYNC "3)" NRMC "Edit id code\n");
        printf(CYNC "4)" NRMC "Back to previous menu\n");

        choice = getchar();
        choice = choice=='\n' ? getchar() : choice;
        switch (choice)
        {
        case '1':
            printf(CYNC "current name is " PRPC "%s\n" NRMC, p->name);
            printf(CYNC "New name: " NRMC);
            scanf("%s", tmp);
            strcpy(p->name, tmp);
            break;
        case '2':
            printf(CYNC "current last name is " PRPC "%s\n" NRMC, p->lastName);
            printf(CYNC "New last name: " NRMC);
            scanf("%s", tmp);
            strcpy(p->lastName, tmp);
            break;
        case '3':
            printf(CYNC "current id is " PRPC "%s\n" NRMC, p->name);
            printf(CYNC "New id code: " NRMC);
            scanf("%s", tmp);
            strcpy(p->idCode, tmp);
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
            printf(CYNC "current name is " PRPC "%s\n" NRMC, p->name);
            printf(CYNC "New name: " NRMC);
            scanf("%s", tmp);
            strcpy(p->name, tmp);
            break;
        case '2':
            printf(CYNC "current unit is " PRPC "%d\n" NRMC, p->unit);
            printf(CYNC "New name: " NRMC);
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
}
//-------------------------------------------------

void removeStdQuest(){                          // Get approval to remove a student
    int code;
    char choice;
    stdNode *p;
    printf(CYNC "Enter the student code: " CYNC);
    scanf("%d", &code);
    p=findStd(code);
    showStd(p);
    printf("here\n");
    while(choice !='y' || choice != 'n'){
        printf(REDC "do you want to remove this student?(y of n)\n" NRMC);
        choice = getchar();
        choice = choice=='\n' ? getchar() : choice;
        if(choice == 'y'){
            printf("here2\n");
            removeStd(code);
            printf("here3\n");
            printf(REDC "**Student was deleted**\n" NRMC);
            break;
        }else if (choice == 'n')
        {
            printf(REDC "Delete operation was cancelled\n" NRMC);
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

void removeProfQuest(){                                     // Get approval to remove a professor
    profNode *p;
    char choice;
    int code;
    
    printf(CYNC "Enter the professor code: " CYNC);
    scanf("%d", &code);
    p=findProf(code);
    showProf(p);

    while(choice !='y' || choice != 'n'){
        printf(REDC "Do you want to remove this professor?(y of n)\n" NRMC);
        scanf("%c", &choice);
        switch (choice)
        {
        case 'y':
            removeProf(code);
            printf(REDC "**Professor was deleted**\n" NRMC);
            break;
        case 'n':
            printf(REDC "Delete operation was cancelled\n" NRMC);
            break;
        default:
            printf(REDC "ERR->Enter the currect number\n" NRMC);
            break;
        }
    }
}

void removeProf(int profcode){
    profNode *p, *previouseNode, *remvNode;

    if(profHead->code == profcode){
        remvNode = profHead;
        profHead = profHead->next;
        free(remvNode);
        profNum--;
    }else{
        p=profHead;
        for(int i=0; i<profHead; i++)
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

void takeStdCourse(stdNode *std){                   // Choosing a course by the student
    courseNode *crs;
    int code;

    while (1)
    {
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
        }
    }
}


