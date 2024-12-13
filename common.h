#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_STUDENTS	10

enum {
	DATA_SAVE_OK,
	DATA_SAVE_ERR_INPUT,
	DATA_SAVE_ERR_OPEN,
	DATA_SAVE_ERR_WRITE,
	DATA_READ_ERR_FILE
};


struct student{
        char name[20];
        char lastname[20];
        int group_id;
        int course;
};

void data_input( int count, struct student *s );
void data_output( int count, struct student *s );
int data_save( int count, struct student *s, const char *file);