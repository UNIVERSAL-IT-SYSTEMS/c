/*         DATE : 2010.6.24
        关于C中的位端igned或者int
*/
#include <stdio.h>
#define SQUARE(a) ((a)*(a))
int main()
{
    int a=5;
	int b = SQUARE(a++);
	printf("%d",b);
printf("%d",a);
    return 0;
}
