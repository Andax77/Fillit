#include <stdio.h>

typedef struct map
{
	unsigned long	part1 : 64;
	unsigned long	part2 : 64;
	unsigned long	part3 : 64;
	unsigned long	part4 : 64;
}				tmap;

int main(int argc, const char *argv[])
{
	tmap	test = {15, 0, 0, 0};
	printf("%lu, %lu, %lu, %lu", test.part1, test.part2, test.part3, test.part4);
	test.part1 <<= 64;
	printf("%lu, %lu, %lu, %lu", test.part1, test.part2, test.part3, test.part4);

	return 0;
}
