#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
float heron(triangle *t){
    float twop = (t->a + t->b + t->c)/2.0;
    //printf("%f = %d  %d  %d\n", twop, t->a, t->b, t->c);
    twop =pow((twop*(twop - t->a) * (twop - t->b) * (twop -t->c)), 0.5);
    return twop;
}


int heron_cmp(const void *a, const void *b){
    return heron((triangle*)a) > heron((triangle*) b);
}
void sort_by_area(triangle* tr, int n) {
    /**
    * Sort an array a of the length n
    */
    qsort(tr,n , sizeof(*tr), heron_cmp);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("\n%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
