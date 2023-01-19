// Jednoduche kalkulacka v C.
// Autor: Erika

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define QUIT 'q'

const int POCET_OPERACI = 6;
const char *MENU[] = {
    "scitani", "+",
    "odcitani", "-",
    "nasobeni", "*",
    "deleni", "/",
    "modulo", "%%",
    "exponent", "^"};

/* funkce menu.
Na vyber je:
scitani, odcitani, nasobeni, deleni
Texty pro menu jsou uložené v poli stringu.
Výběr dané operace je proveden pomocí zadání znalu operace.
*/
void menu(void)
{
    printf("Menu: \n");
    for (int i = 0; i < 2*POCET_OPERACI; i += 2)
    {
        printf("(%s) %s \n", MENU[i + 1], MENU[i]);
    }
    printf("\n");
}

// funkce help
void help(void)
{
    printf("Program kalkulacka v C, ktera umi scitat, odcitat, nasobit a delit.\n");
    printf("Autor: Erika\n");
    printf("Verze: 1.0\n");
    printf("Pouziti: ./kalkulacka\n");
    printf("Operace: \n");
    for (int i = 0; i < 2*POCET_OPERACI; i += 2)
    {
        printf(" » %s \t %s \n", MENU[i + 1], MENU[i]);
    }
}

void clear_stdin(void)
{
    while (getchar() != '\n')
        ;
}

void nacti_operaci(char *operace)
{
    scanf(" %c", operace);
    while (getchar() != '\n')
        ;
}

void nacti_cislo(float *cislo)
{
    while (scanf("%f", cislo) != 1)
    {
        printf("Zadali jste cislo spatne.\n");
        printf("Zadejte cislo znovu: ");
        while (getchar() != '\n')
            ;
    }
    while (getchar() != '\n')
        ;
}

void nacti_nenulove_cislo(float *cislo)
{
    while (nacti_cislo(cislo), *cislo == 0)
    {
        /* operator carky */
        printf("Zadali jste nulu.\n");
        printf("Zadejte nenulove cislo: ");
    }
}

// Funkce pro vypocet
int vypocet(float a, float b, char operace, float *vysledek)
{
    switch (operace)
    {
    case '+':
        *vysledek = a + b;
        break;
    case '-':
        *vysledek = a - b;
        break;
    case '*':
        *vysledek = a * b;
        break;
    case '^':
        *vysledek = pow(a, b);
        break;
    case '%':
        if (b == 0)
        {
            printf("Nelze delit nulou!\n");
            return false;
        }
        *vysledek = (int)a % (int)b;
        break;
    case '/':
        if (b == 0)
        {
            printf("Nelze delit nulou!\n");
            return false;
        }
        *vysledek = a / b;
        break;
    default:
        printf("Neplatna operace!\n");
        return false;
    }

    return true;
}



/* funkce main
-h - help
*/ 
int main(int argc, char *argv[])
{   
    // help
    if (argc == 2 && strcmp(argv[1], "-h") == 0)
    {
        help();
        return 0;
    }

    float a, b, vysledek;
    char operace;
    char opakovat;

    // opakuj dokud uzivatel nezada q
    do
    {
        // vypis menu
        menu();

        // zadej cisla a operaci
        printf("Zadejte operaci: ");
        nacti_operaci(&operace);
        printf("Zadejte prvni cislo: ");
        nacti_cislo(&a);
        printf("Zadejte druhe cislo: ");
        // nacti_nenulove_cislo(&b);
        nacti_cislo(&b);

        // vypocet
        if (!vypocet(a, b, operace, &vysledek))
        {
            printf("Vysledek nelze vypocitat.\n");
        }
        else
        {
            printf("Vysledek je: %.3f\n", vysledek);
        }

        // opakovat?
        printf("Chcete pokracovat? (%c pro ukonceni) \n", QUIT);
        printf("Zadejte znak: ");
        nacti_operaci(&opakovat);
    } while (opakovat != QUIT);

    return 0;
}
