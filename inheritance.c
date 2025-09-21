#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// كل شخص ليه اتنين parents و اتنين alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

// عدد الأجيال اللي هنطبعها
const int GENERATIONS = 3;

// دوال
person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele(void);

int main(void)
{
    // نعمل random seed
    srand(time(0));

    // نعمل family tree
    person *p = create_family(GENERATIONS);

    // نطبع الشجرة
    print_family(p, 0);

    // نفرغ الميموري
    free_family(p);
}

// إنشاء family tree بالـ recursion
person *create_family(int generations)
{
    // allocate memory للشخص
    person *p = malloc(sizeof(person));
    if (p == NULL)
    {
        return NULL;
    }

    // لو لسه في أجيال نكملها
    if (generations > 1)
    {
        // نعمل الاتنين parents بالـ recursion
        p->parents[0] = create_family(generations - 1);
        p->parents[1] = create_family(generations - 1);

        // نحدد alleles للشخص من parents
        p->alleles[0] = p->parents[0]->alleles[rand() % 2];
        p->alleles[1] = p->parents[1]->alleles[rand() % 2];
    }
    else
    {
        // لو وصلنا للجدود، يبقى مفيش parents
        p->parents[0] = NULL;
        p->parents[1] = NULL;

        // random alleles
        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
    }

    return p;
}

// طباعة الشجرة
void print_family(person *p, int generation)
{
    // base case
    if (p == NULL)
    {
        return;
    }

    // indent حسب الجيل
    for (int i = 0; i < generation * 4; i++)
    {
        printf(" ");
    }

    // اطبع الشخص
    printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);

    // اطبع parents
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// تحرير الميموري بالـ recursion
void free_family(person *p)
{
    if (p == NULL)
    {
        return;
    }
    free_family(p->parents[0]);
    free_family(p->parents[1]);
    free(p);
}

// random allele
char random_allele(void)
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}