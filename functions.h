
#define NRMC  "\x1B[0m"         // Normal color (White)
#define REDC  "\x1B[31m"        // Red color
#define GRNC  "\x1B[32m"        // Green color
#define CYNC  "\x1B[36m"        // Cyan color

int stdNum=0;                   // Number of students
stdNode *stdHead=NULL;          // First element of student link list



stdNode *addStudent(){         // Add new student to end of the linklist
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
        printf(REDC "->Enter the correct national code(10 digit)<-\n" NRMC);
    }
    printf("here2");
    strcpy(newStd->nationalCode, ntlTmp);
    newStd->stdCode = stdCodeCrtr(stdNum);
    stdNum++;
    system("cls");
    printf(GRNC "**New student was added**\n" NRMC);
    return stdHead;
}

int stdCodeCrtr(int stdNum){            // Creating a student code based on the current year 
    int code = curntYear()*10000+1600;
    code += stdNum+1;
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