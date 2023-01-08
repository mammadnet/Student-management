courseNode *getCourseNode(){      // For creat a course node and return a pointer to point it
    courseNode *tmp;
    tmp=(courseNode *)malloc(sizeof(courseNode));
    tmp->next=NULL;
    return tmp;
}

stdNode *getStdNode(){
    stdNode *tmp;
    tmp = (stdNode *)malloc(sizeof(stdNode));
    tmp->next=NULL;
    return tmp;
}


profNode *getProfNode(){
    profNode *tmp;
    tmp=(profNode *)malloc(sizeof(profNode));
    tmp->next=NULL;
    return tmp;
}


