/* Marcus Botacin
 * Buffer Overflow Example
 * Security Course Presentation
 * UFPR - 2018
 */

/* Print things */
#include<stdio.h>

/* Use struct to ensure GCC will allocate contiguously */
typedef struct _st{
	char str[4]; 	/* overflowing variable */
	int num;	/* overflowed one */
}data,*pdata;

int main()
{
	data d;
	/* Put value */
	d.num=10;
	/* fills variable */
	scanf("%s",d.str);
	/* check whether the same value is printed */
	printf("%d\n",d.num);
	return 0;
}
