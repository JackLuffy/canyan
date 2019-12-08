#include <stdio.h>
#include <string.h>

typedef struct 
{
	char a[10];
	char b[20];
	int c; 
}Tunion;
typedef  Tunion	*punion;

int  fun2(punion test, char *d, int *e)
{
	snprintf(test->a, sizeof(test->a), "%s", "aaaaaa");
	snprintf(test->b, sizeof(test->b), "%s", "bbbbbb");
	sprintf(d , "%s", "ddddd");
	test->c = 99;

	return 0;
}
int  fun(punion test, char *d, int *e)
{
	printf("123\n");
	*e = 2;
	fprintf(stderr, "fun1[%d][%d]\n", sizeof(test->a), sizeof(test->b));
	fun2(test, d, &(*e));	

	return 0;
	
	
}

int  fun3(punion test, punion test1, punion test2)
{
	Tunion tmp;	
	fprintf(stderr, "fun3 sizeoftest[%d]---tmp=[%d]\n", sizeof(*test), sizeof(tmp));

	memcpy(&tmp, test, sizeof(*test));
	memcpy(test2, test, sizeof(*test));

	fprintf(stderr, "fun3 test2 a=[%s]--b=[%s]--c=[%d]\n", test2->a, test2->b, test2->c);

	fprintf(stderr, "fun3 tmp a=[%s]--b=[%s]--c=[%d]\n", tmp.a, tmp.b, tmp.c);

	fprintf(stderr, "fun3 test a=[%s]--b=[%s]--c=[%d]\n", test->a, test->b, test->c);
	fprintf(stderr, "fun3 test1 a=[%s]--b=[%s]--c=[%d]\n", test1->a, test1->b, test1->c);

		

	return 0;

}
char a[10];

int fun5()
{}

void fun4(int *e, fun5())
{
	*e = 4;
	return;
	snprintf(a, sizeof(a), "%s", "1010100");
}

int main()
{
	Tunion test;
	Tunion test2;
	Tunion test1;
	
	snprintf(test1.a, sizeof(test1.a), "%s", "000000");
        snprintf(test1.b, sizeof(test1.b), "%s", "222222");
	test1.c = 100;

	char d[10];
	int e;
	
	memset(&test, 0, sizeof(test));
	fun(&test, d, &e);
	fprintf(stderr, "main a=[%s]--b=[%s]--c=[%d]--d=[%s]--e=[%d]\n", test.a, test.b, test.c, d,e);
	
	fun3(&test, &test1, &test2);
	fprintf(stderr, "main test2 a=[%s]--b=[%s]--c=[%d]--d=[%s]--e=[%d]\n", test2.a, test2.b, test2.c, d,e);
	
	fun4(&e, fun5);
	
	fprintf(stderr, "a=[%s]\n", a);
	
	
	return 0;
	
}
