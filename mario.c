#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int height, row ,c, space ;
    do
    {
        height = get_int ("enter height here :");
    }
    while (height <1 || height>8);
    for(row =0 ; row<height; row++)
    {
        for (space =0; space <height - row - 1; space++)
        {
            printf(" ");
        }
        for(c =0; c<=row ;c++)
        {
            printf("#");
        }
        printf("\n");
    }

}
