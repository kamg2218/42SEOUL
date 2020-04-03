#include <stdio.h>
#include "new.h"

int		test(void);

int		main()
{
	printf("Hello Everyone!\n");
	test();
	printf("My age is %s.\n", MYAGE);
	printf("Your age is %s.\n", YRAGE);
	return (0);
}
