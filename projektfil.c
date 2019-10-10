#include <stdio.h>
#include <stdlib.h>

void opret(int deltagere[][15])
{
    int i, j;
    char m;
    float euro = 7.47;
    printf("\n\nDu er nu i opret funktionen\n\n");

    // viser de initielle værdier under hver deltager
    printf("Deltagernes omkostninger vil blive vist i dette layout:\n");
    printf("Deltager\t | Madomkostninger\t | Rejseomkostninger\t | Ophold\n");

    for (j = 0; j < 15; j++)
    {
        printf("%3d\t\t | DKK%5d\t\t | DKK%5d\t\t | DKK%5d\n",
               deltagere[0][j], deltagere[1][j], deltagere[3][j], deltagere[5][j]);
    }

    // While loop over hvorvidt brugeren vil indtaste oplysninger
    printf("Vil du indtaste oplysninger om en eller flere deltagere?\n");
    printf("j/n: ");
    if (scanf(" %c", &m) != 'n')
    {
        while (m != 'n')
        {

            printf("Hvilken deltagers (1-15) oplysninger vil du taste ind?: ");
            scanf("%d", &i);
            i = i - 1;
            // brugeren bedes om at indtaste oplysningerne
            printf("Indtast deltagerens omkostninger.\n");

            // indtast madomkostninger i dkk
            printf("Madomkostninger for deltager %d i DKK. Skriv 0 hvis omkostningerne er i Euro: ", deltagere[0][i]);
            scanf("%d", &deltagere[1][i]);

            // indtast madomkostninger i euro
            if (deltagere[1][i] == 0)
            {
                printf("Madomkostninger for deltager %d i EUR: ", deltagere[0][i]);
                scanf("%d", &deltagere[2][i]);
            }

            // indtast rejseomkostninger i dkk.
            printf("Rejseomkostninger for deltager %d i DKK. Skriv 0 hvis billetterne er koebt i Euro: ",
                   deltagere[0][i]);
            scanf("%d", &deltagere[3][i]);

            // rejseomkostninger i euro hvis der tastes 0
            if (deltagere[3][i] == 0)
            {
                printf("Rejseomkostninger for deltager %d i EUR: ",
                       deltagere[0][i]);
                scanf("%d", &deltagere[4][i]);
            }

            // indtast deltagerens omkostninger til ophold
            printf("Omkostninger til ophold for deltager %d i DKK: ",
                   deltagere[0][i]);
            scanf("%d", &deltagere[5][i]);

            // Beregning af hver deltagers omkostninger,
            // eur beløb omregnes til dkk
            // omregning af EUR madkomkostninger til DKK
            if (deltagere[1][i] == 0)
            {
                deltagere[1][i] = deltagere[2][i] * euro;
            }

            // omregning af EUR rejseomkostninger til DKK
            if (deltagere[3][i] == 0)
            {
                deltagere[3][i] = deltagere[4][i] * euro;
            }

            // hver deltagers samlede udgifter
            deltagere[6][i] = deltagere[1][i] + deltagere[3][i] + deltagere[5][i];

            // viser de indtastede værdier under hver deltager
            printf("Deltagerens omkostninger er som foelger:\n");
            printf("Deltager\t | Madomkostninger\t | Rejseomkostninger\t | Ophold\n ");
            printf("%3d\t\t |  DKK%5d\t\t |  DKK%5d\t\t |  DKK%5d\n",
                   deltagere[0][i], deltagere[1][i], deltagere[3][i], deltagere[5][i]);

            // spørg brugeren om der skal indtastes flere deltagere
            printf("\n\nVil du indtaste flere deltagere j/n?: ");
            scanf(" %c", &m);
        }
    }
}
// udskriv funktionen
void udskriv(int deltagere[8][15])
{
    int userInput2 = 1;
    int j, i;
    printf("______________________________________________________________________________________________\n");
    printf("Funktionen Udskriv\n\n");
    printf("Tast 1 - for at udskrive for en bestemt deltager.\n");
    printf("Tast 2 - for at udskrive alt.\n");
    printf("Tast 0 - for at gaa tilbage til hovedmenuen.\n");
    printf("______________________________________________________________________________________________\n");
    printf("Indtast her: ");
    scanf("%d", &userInput2);

    switch (userInput2)
    {
    case 1:
        printf("\n\nIndtast brugerID: ");
        scanf("%d", &i);
        i -= 1;
        printf("Deltager\t | Madomkostninger\t | Rejseomkostninger\t | Ophold\n ");
        printf("%3d\t\t | DKK%5d\t\t | DKK%5d\t\t | DKK%5d\n", deltagere[0][i], deltagere[1][i],
               deltagere[3][i], deltagere[5][i]);
        break;
    case 2:
        printf("Deltager\t | Madomkostninger\t | Rejseomkostninger\t | Ophold\n ");
        for (j = 0; j < 15; j++)
        {
            printf("%3d\t\t | DKK%5d\t\t | DKK%5d\t\t | DKK%5d\n ", deltagere[0][j], deltagere[1][j],
                   deltagere[3][j], deltagere[5][j]);
        }
        break;
    case 0:
        break;
    }
}
// Menu funktionen
void menu(void)
{
    // Definere variable
    int userInput1 = 1;
    int j;
    int totalSum = 0, maximum, minimum, id = 0, id1 = 0, aggr = 0;
    int deltagere[8][15] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}};

    while (userInput1 != 0)
    {
        // Selve menuen
        printf("______________________________________________________________________________________________\n");
        printf("Menu\n\n");
        printf("Tast 1 - for at oprette deltagere.\n");
        printf("Tast 2 - for at udskrive (enkelt eller samlet).\n");
        printf("Tast 3 - for samlede udgifter.\n");
        printf("Tast 4 - for at udskrive feriens samlede pris og balance for hver deltager.\n");
        printf("Tast 5 - for at se hvilke deltagere der har haft hhv. den stoerste og mindste betaling til turen.\n");
        printf("Tast 0 - for at afslutte.\n\n");
        printf("______________________________________________________________________________________________\n");
        // Bruger vælger
        printf("Indtast her: ");
        scanf("%d", &userInput1);

        switch (userInput1)
        {
        case 1:

            opret(deltagere);
            break;
        case 2:
            udskriv(deltagere);
            break;
        case 3:
            printf("\n\nTabellen viser hver udgiftspost og samlede udgifter for alle deltagere.\n");
            printf("Deltagere\t | Madomkostninger\t | Rejseomkostninger\t | Ophold\t"
                   "Total\n");
            for (j = 0; j < 15; j++)
            {
                printf("%3d\t\t | DKK%5d\t\t | DKK%5d\t\t | DKK%5d\t | DKK%5d\n", deltagere[0][j], deltagere[1][j], deltagere[3][j], deltagere[5][j], deltagere[6][j]);
            }
            break;
        case 4:
            /*beregning af feriens samlede pris, pris pr deltager og hvorvidt hver deltager
                    skal betale mere eller have penge i retur. Samlet pris for hver deltager er beregnet i forvejen*/
            for (j = 0; j < 15; j++)
            {
                totalSum = totalSum + deltagere[6][j];
            }

            //udskriver feriens samlede pris
            printf("\n\nDen samlede pris for ferien er: DKK%d\n", totalSum);

            //beregner gennemsnit for udgifter
            aggr = totalSum / 15;

            //udfylder den søjle hvor differencen for hver deltager er
            for (j = 0; j < 15; j++)
            {
                deltagere[7][j] = deltagere[6][j] - aggr;
            }

            //udskriver balancen for hver deltager
            printf("De samlede udgifter er fordelt som nedenstaaende. Tabellen viser ogsaa hvad den enkelte deltager har af penge til gode, eller skal betale til gruppen.\n");
            printf("Deltager\t | Total\t\t | Difference\n");
            for (j = 0; j < 15; j++)
            {
                printf("%3d\t\t | DKK%5d\t\t | DKK%8d\n", deltagere[0][j], deltagere[6][j], deltagere[7][j]);
            }

            totalSum = 0;
            aggr = 0;
            break;
        case 5:
            maximum = deltagere[6][0];
            minimum = deltagere[6][0];
            //find hvem der har haft henholdsvis det største og mindste udlæg
            for (j = 1; j < 15; j++)
            {
                if (deltagere[6][j] > maximum)
                {
                    maximum = deltagere[6][j];
                    id = deltagere[0][j];
                }
            }

            for (j = 1; j < 15; j++)
            {
                if (deltagere[6][j] < minimum)
                {
                    minimum = deltagere[6][j];
                    id1 = deltagere[0][j];
                }
            }

            printf("\nDen deltager der har mindst og dermed skylder en omgang er deltager %d med %d og den deltager der har betalt mest er deltager %d med %d.\n\n",
                   id1, minimum, id, maximum);
            break;

        case 0:
            break;
        }
    }
}
int main()
{

    // Kalder menu funktionen
    menu();

    return 0;
}
