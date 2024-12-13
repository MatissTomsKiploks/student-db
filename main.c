#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "common.h"

void data_input( int count, struct student *s );
void data_output( int count, struct student *s );
int data_save( int count, struct student *s, const char *file );
struct student * data_read( const char *file, int *count );

int main(){
        int c = 0;
        int yn = 0;
        char *file = "data.bin";
        struct student *s;
	struct student *data;
	int err = 0;

	printf("Do you want to see existing dtudent data?\n");
	scanf("%d", &yn);
	if (yn == 1 ) {
	        printf("Reading %s\n", file);
		data = data_read( file, &c );
		if ( !data  ){
			printf("Error reading database: %m\n");
		} else {
			printf("There are %d students in database:\n", c);
			data_output( c, data );
		}
	}
    
        printf("Please enter number of student: ");
        scanf("%d", &c);

        s = (struct student *)malloc( sizeof(struct student) * c );

        data_input( c, s );
        data_output( c, s );

        printf("Do you want to save your data(1/0)");
        scanf("%d", &yn);
        if (yn == 1 ) {
		printf("Saving data to %s ...\n", file);
		err = data_save( c, s, file );
		if ( err ) {
			printf("Error saving data: %d(%m)\n", err);
		};
        }
	free(s);
        return 0;
}
