
#define NRMC  "\x1B[0m"         // Normal color (White)
#define REDC  "\x1B[31m"        // Red color
#define GRNC  "\x1B[32m"        // Green color
#define CYNC  "\x1B[36m"        // Cyan color

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
    printf(CYNC "**Add new student**\n" NRMC);
    printf("Enter the first name:\n");
    scanf("%s", newStd->name);
    printf("Enter the last name:\n");
    scanf("%s", newStd->lastName);
    printf("Enter the year of birth:\n");
    scanf("%d", &newStd->year);
    char ntlTmp[12];
    while(1)
    {
        printf("Enter the national code:\n");
        scanf("%s", ntlTmp);
        if(checkNtnlNum(ntlTmp)) break;
        printf(REDC "ERR->Enter the correct national code(10 digit)\n" NRMC);
    }
    strcpy(newStd->idCode, ntlTmp);
    stdNum++;
    newStd->stdCode = stdCodeCrtr();
    system("cls");
    printf(GRNC "**New student was added**\n" NRMC);
}
//-----------------------------------------------------------

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
    while(1)
    {
        printf("Enter the national code:\n");
        scanf("%s", ntlTmp);
        if(checkNtnlNum(ntlTmp)) break;
        printf(REDC "ERR->Enter the correct national code(10 digit)\n" NRMC);
    }
    strcpy(newProf->idCode, ntlTmp);
    profNum++;                                  
    newProf->code = profCodeCrtr();
    system("cls");
    printf(GRNC "**New professor was added**\n" NRMC);
}
//------------------------------------------------------------------
void addCourse(){
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
    while (1)
    {
        printf("Enter number of unit course:\n");
        scanf("%d", &un);
        if(un <= 3 && un>=1) break;
        printf(REDC "ERR->The number of units must be between 1 and 3.\n" NRMC);
    }
    newCors->unit = un;
    corsNum++;
    newCors->code=corsCodeCrtr();
    system("cls");
    printf(GRNC "**New course was added**\n" NRMC);
}

void showCrs(){                                     // Show saved courses
    courseNode *p;
    p = corsHead;
    printf("name-> course code (unit)\n");
    for(int i=1; i<=corsNum; i++){
        printf(CYNC "%d) " NRMC "%8s-> " CYNC "%d" NRMC " (%d)\n", i, p->name, p->code, p->unit);
        p = p->next;
    }
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
            printf("here");
            return p;
        }
        p = p->next;
    }
    printf("here2");
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


