#include <stdio.h>
#include <stdlib.h>
// #include "structure.h"

courseNode *getCourseNode(){      // For creat a course node and return a pointer to point it
    courseNode *tmp;
    tmp=(courseNode *)malloc(sizeof(courseNode));
    tmp->next=NULL;
    return tmp;
}

stdCourseNode *getStdCourseNode(){
    stdCourseNode *tmp;
    tmp = (stdCourseNode *)malloc(sizeof(stdCourseNode));
    tmp->course=NULL;
    tmp->next=NULL;
    return tmp;
}

stdNode *getStdNode(){
    stdNode *tmp;
    tmp = (stdNode *)malloc(sizeof(stdNode));
    tmp->course=NULL;
    tmp->next=NULL;
    return tmp;
}

profCourseNode *getProfCourseNode(){
    profCourseNode *tmp;
    tmp=(profCourseNode *)malloc(sizeof(profCourseNode));
    tmp->course=NULL;
    tmp->next=NULL;
    return tmp;
}

profNode *getProfNode(){
    profNode *tmp;
    tmp=(profNode *)malloc(sizeof(profNode));
    tmp->course=NULL;
    tmp->next=NULL;
}


