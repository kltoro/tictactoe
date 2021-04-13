#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void kiir(char t[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("|%c|", t[i][j]);
        }
        printf("\n");
    }
}
void jatekos1(char t[3][3], int jatekos)
{
    int joe = 0;
    do
    {
        int sor;
        int oszlop;
        if (jatekos == 1)
        {
            printf("Melyik sorba rakjam az x-t : ");
            scanf("%d", &sor);
            printf("Melyik oszlopba rakjam az x-t : ");
            scanf("%d", &oszlop);
            system("clear");
        }
        if (jatekos == 2)
        {
            printf("Melyik sorba rakjam az O-t : ");
            scanf("%d", &sor);
            printf("Melyik oszlopba rakjam az O-t : ");
            scanf("%d", &oszlop);
            system("clear");
        }
        if (sor > 0 && sor < 4 && oszlop > 0 && oszlop < 4)
        {
            if (t[sor - 1][oszlop - 1] != 'x' && t[sor - 1][oszlop - 1] != 'O')
            {
                if (jatekos == 1)
                {
                    t[sor - 1][oszlop - 1] = 'x';
                    joe = 1;
                }
                else
                {
                    t[sor - 1][oszlop - 1] = 'O';
                    joe = 1;
                }
            }
            else
            {
                system("clear");
                kiir(t);
                printf("A hely már foglalt!\n");
            }
        }
        else
        {
            system("clear");
            kiir(t);
            printf("Nem megfelelő input!\n");
        }

    } while (joe != 1);
}
//vizszintesen 3
//függőlegesen 3
//átlók 2
int winner(char t[3][3])
{
    int nyertes;
    for (int i = 0; i < 3; i++)
    {
        //sor
        if (t[i][0] == 'x' && t[i][1] == 'x' && t[i][2] == 'x')
        {
            return 1;
        }
        if (t[i][0] == 'O' && t[i][1] == 'O' && t[i][2] == 'O')
        {
            return 2;
        }
        //oszlop
        if (t[0][i] == 'x' && t[1][i] == 'x' && t[2][i] == 'x')
        {
            return 1;
        }
        if (t[0][i] == 'O' && t[1][i] == 'O' && t[2][i] == 'O')
        {
            return 2;
        }
        //átló
    }

    if (t[0][0] == 'x' && t[1][1] == 'x' && t[2][2] == 'x')
    {
        return 1;
    }
    if (t[0][0] == 'O' && t[1][1] == 'O' && t[2][2] == 'O')
    {
        return 2;
    }
    if (t[0][2] == 'x' && t[1][1] == 'x' && t[2][0] == 'x')
    {
        return 1;
    }
    if (t[0][2] == 'O' && t[1][1] == 'O' && t[2][0] == 'O')
    {
        return 2;
    }
    return 0;
}
int main()
{
    char tabla[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};
    system("clear");
    kiir(tabla);
    int vege = 0;
    int jatekos = 1;
    int winpossible = 0;
    int draw = 0;
    while (vege == 0)
    {
        if (jatekos == 1)
        {
            //printf("Az első játékos következik!");
            jatekos1(tabla, jatekos);
            jatekos++;
            winpossible++;
            if(winpossible>4)
            {
                vege = winner(tabla);
            }
            if(winpossible>8&& vege==0)
            {
                draw = 1;
                break;
            }
        }
        else
        {
            jatekos1(tabla, jatekos);
            jatekos--;
            winpossible++;
            if(winpossible>4)
            {
                vege = winner(tabla);
            }
            if(winpossible>8&& vege==0)
            {
                draw = 1;
                break;
            }
        }
        kiir(tabla);
    }
    if(draw==1)
    {
        kiir(tabla);
        printf("Játék vége\nA meccs döntetlen\n");
    }
    else
    {
        printf("Játék vége\nNyert a(z) %d játékos\n", vege);
    }
    
    return 0;
}