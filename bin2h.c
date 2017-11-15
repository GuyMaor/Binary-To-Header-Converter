#include <stdio.h>
#include <stdlib.h>
void main(int argc, char * argv[])
{
	char * fileName =  argv[1] ;

        printf("Opening input file...\n");

	FILE * fIN = fopen(fileName,"r");

	if(fIN==NULL)
	{
		printf("File does not exist. Sowwy.\n");
		return;
	}


	printf("Creating output file...\n");
	FILE * fOUT = fopen("newheader.txt","w");
	fprintf(fOUT,"#ifndef <NAME>\n");
        fprintf(fOUT,"#define <NAME>\n");
	fprintf(fOUT,"int8_t * <BIN_FILE> = {");

	char first = 1;
	char nextChar;
	while(!feof(fIN))
	{
		fscanf(fIN,"%c",&nextChar);
		if(!first)
			fprintf(fOUT,",");
		else
			first = 0;
		fprintf(fOUT,"%d",nextChar);
	}
	fprintf(fOUT,"};\n#endif\n");
	fclose(fIN);
	fclose(fOUT);
	printf("Complete.\n");
}
