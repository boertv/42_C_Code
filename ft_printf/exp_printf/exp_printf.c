//#include <stdio.h>
#include <unistd.h>

int main(void)
{
/*  int i = 19;  
    printf("   |%6.i| \n", i);
    printf("   |%.6i| \n", i);
    printf("   |%  - -  - 6i| \n\n", i);

    printf("   |%06i| \n", i);
    printf("   |%06.4i| \n", i);
    printf("%i\n\n", printf("   hallo?|%.2147483647i| \n\n", i));

    printf("   |%6i| \n", i);
*//*
    char    c = 'c';
    printf("abc |%c| def\n", c);
    printf("abc |%-20c| def\n", c);
*//*
    char *s = "abc";
    printf("xx |%5s| zz\n", s);
*////*
    int		a = 42;
	void	*p = &a;
    write(0, &p, 16);
//	printf("--|%-16p|--\n", p);
//*/
}
