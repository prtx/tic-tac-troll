#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "funcammo.h"
#include "2player.h"
#include "easy.h"
#include "almosteasy.h"
#include "notsoeasy.h"

int main()
{
    int i;
    system("clear");
    printf("\n\t\t\t\tTicTacTroll\n\n");
    printf("\n\t\t\t1. Two Player");
    printf("\n\t\t\t2. Easy");
    printf("\n\t\t\t3. Almost Easy");
    printf("\n\t\t\t4. Not So Easy\n\t\t\t   ");
    scanf("%d",&i);
    switch(i)
    {
        case 1:
            twoplay();
            break;
        case 2:
            easy();
            break;
        case 3:
            almosteasy();
            break;
        case 4:
            notsoeasy();
            break;
        default:
            printf("\n\t\tInvalid Request");
    }
    return 0;
}
