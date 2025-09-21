#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char rotate(char c, int key);

int main(int argc, string argv[])
{
    // لازم يبقى فيه Argument واحد بس (المفتاح)
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // تأكد إن كل حرف في argv[1] رقم
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // حوّل المفتاح من string → int
    int key = atoi(argv[1]) % 26; // ناخد باقي القسمة عشان المفتاح الكبير

    // اطلب النص من المستخدم
    string plaintext = get_string("plaintext: ");

    // اطبع النص المشفّر
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");
}

// دالة لتشفير الحروف
char rotate(char c, int key)
{
    if (isupper(c)) // لو Capital
    {
        return 'A' + (c - 'A' + key) % 26;
    }
    else if (islower(c)) // لو Small
    {
        return 'a' + (c - 'a' + key) % 26;
    }
    else
    {
        return c; // لو مش حرف (زي المسافة أو علامات الترقيم) سيبه زي ما هو
    }
}