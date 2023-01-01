typedef struct courses
{
    int code;
    char name[40];
    int unit;         // The number of units in a course
    int studentNum;
    struct courses *next;       // Point to next course (link list structure)
} courseNode;


typedef struct studentCourse        //-------
{
    courseNode *course;
    struct studentCourse *next;       // Point to the next course of the student
} studentCourse;

typedef struct student{
    char name[20];
    char lastName[20];
    int stdNumber;
    int nationalCode;
    studentCourse *course;
    struct student *next;       //Point to next student (link list structure)
}stdNode;

typedef struct professorCourse        //-------
{
    courseNode *course;
    struct professorCourse *next;       // Point to the next course of the professor
} professorCourse;

typedef struct professor{
    char name[20];
    char lastName[20];
    int code;
    int courseNum;
    professorCourse *profcourse;
    struct professor *next;             // Point to next professor (link list structure)
}


