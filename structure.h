typedef struct courses
{
    int code;
    char name[40];
    int unit;                   // The number of units in a course
    struct courses *next;       // Point to next course (link list structure)
} courseNode;



typedef struct student{
    char name[20];
    char lastName[20];
    int year;
    int stdCode;
    char idCode[12];
    int crsCode[10];
    int crsNum;
    int units;
    struct student *next;       // Point to next student (link list structure)
}stdNode;

typedef struct professor{
    char name[20];
    char lastName[20];
    char idCode[12];
    int code;
    int courseNum;
    int crsCode[5];
    struct professor *next;             // Point to next professor (link list structure)
}profNode;


