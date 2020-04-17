#include <cstdio>
#include <cstdlib>

int main(int argc, char const *argv[])
{
	char name[100];
	FILE *in_fine;

	printf("name?");
	fgets(name, sizeof(name), stdin);

	in_fine = fopen(name , "r");
	if (in_fine == NULL) {
		fprintf(stderr, "Could not open file\n");
		exit(8);
	}
	printf("File found \n");
	fclose(in_fine);

	return 0;
}