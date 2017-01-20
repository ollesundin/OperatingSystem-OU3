#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * Simple test program that puts the I/O scheduler under load by writing data and then removing it.
 * argv[1] = path to write
 * argv[2] = size of the file to write
 */
int main(int argc, char **argv){
	clock_t start;
	clock_t end;

	start = clock();

	//allocate for the path string
	char* path = malloc(strlen(argv[1])+1);
	
	int fileSize = atoi(argv[2]);
	
	//copy the string
	strcpy(path, argv[1]);
	FILE* filep;
	
	//open the path, create new file if not found
	if(filep = fopen(path, "w+")){
		for(int i = 0; i < fileSize; i++){
			fputc('a', filep);
		}
	}else{
		perror("fopen");
	}
	
	fsync(fileno(filep));
		
	fclose(filep);
	
	//removes the file
	remove(path);

	//free the input path
	free(path);
	end = clock();

	printf("Time taken: %f\n", ((double)end-start)) / CLOCKS_PER_SEC;
	return 0;
}
