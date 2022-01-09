// Concatenate two files - concat2files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *file_1, *file_2, *output_file;



main(int argc, char *argv[])
{
char string_1[2048];
char string_2[1024];

char *stat1, *stat2;
	printf("\n\n");

	printf("\n\t *****************************************************************");
	printf("\n\t *                                                               *");
	printf("\n\t *                        W E L C O M E                          *");
	printf("\n\t *                                                               *");
	printf("\n\t *                             To                                *");
	printf("\n\t *                                                               *");
	printf("\n\t *    	              Concatenate two Files                      *");
	printf("\n\t *                                                               *");
	printf("\n\t *****************************************************************");
	printf("\n\n\n");

	if(argc == 1)  {
	   fprintf(stderr, "\n\t Usage: %s <File 1> <File 2> <Output file name>\n\n", argv[0]);
	   exit(1);
	}


	if( (file_1 = fopen(argv[1], "r")) == NULL) {
	   char buffer[200];
	   sprintf(buffer, "Cannot open %s", argv[1]);
	   perror(buffer);
	   exit(1);
	}
	if( (file_2 = fopen(argv[2], "r")) == NULL) {
	   char buffer[200];
	   sprintf(buffer, "Cannot open %s", argv[2]);
	   perror(buffer);
	   exit(1);
	}
	if( (output_file = fopen(argv[3], "w")) == NULL) {
	   char buffer[200];
	   sprintf(buffer, "Cannot open %s", argv[3]);
	   perror(buffer);
	   exit(1);
	}
	fprintf(stderr, "\n\t The Output file has been created\n\n");
	stat1 = fgets(string_1, sizeof(string_2) - 1, file_1);
	stat2 = fgets(string_2, sizeof(string_2) - 1, file_2);
	while( stat1 && stat2 ) {
	   if(string_1[strlen(string_1) - 1] == 0x0a) {
	     if(string_1[strlen(string_1) - 2] == 0x0d) 
		string_1[strlen(string_1) - 2] = '\0';
	     else
		string_1[strlen(string_1) - 1] = '\0';
	   }
	   strcat(string_1, string_2);
	   fputs(string_1, output_file);
	stat1 = fgets(string_1, sizeof(string_2) - 1, file_1);
	stat2 = fgets(string_2, sizeof(string_2) - 1, file_2);

	}
return 0;
}
