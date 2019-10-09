#include <stdio.h>
#include <stdlib.h>

void opret(float deltagere[][15], int i, int j, char m)
{
    float euro = 7.47;
    printf("Du er i opret funktionen\n");
    // vi bruger et enkelt to-dimensionelt array for at holde koden "ren"
    // vores array har to pladser til indtastning af rejseudgifter, da
    // de kan både være dkk og eur. Hvis dkk indekset er tom, bliver det regnet
    // om. layout for array: 0, j: deltager id 1, j: madomkostninger i dkk 2, j:
    // madomkostninger i eur 3, j: Rejseomkostninger i dkk 4, j: rejseomkostninger
    // i eur 5, j: ophold 6, j: totalomkostninger for hver deltager 7, j:
    // difference ift gennemsnittet

    // vis de initielle værdier under hver deltager
    printf("Deltagernes omkostninger vil blive vist i dette layout:\n");
    printf("Deltager\t | Madomkostninger\t | Rejseomkostninger\t | Ophold\t | "
           "Total\t | Difference\n");

    for (j = 0; j < 15; j++)
    {
        printf("%03.0f\t\t | DKK%5.2f\t\t | DKK%5.2f\t\t | DKK%5.2f\t | DKK%5.2f\t "
               "| DKK%5.2f\n",
               deltagere[0][j], deltagere[1][j], deltagere[3][j], deltagere[5][j],
               deltagere[6][j], deltagere[7][j]);
    }
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

            // loop gennem alle deltagere og indtast oplysninger
            // denne metode låser indtasteren til at udføre opgaven på en gang
            // for(i=0;i<15;i++){

            // indtast madomkostninger i dkk
            printf("Madomkostninger for deltager %03.0f i DKK. Skriv 0 hvis "
                   "omkostningerne er i Euro: ",
                   deltagere[0][i]);
            scanf("%f", &deltagere[1][i]);
            // indtast madomkostninger i eur
            if (deltagere[1][i] == 0)
            {
                printf("Madomkostninger for deltager %03.0f i EUR: ", deltagere[0][i]);
                scanf("%f", &deltagere[2][i]);
            }

            // indtast rejseomkostninger i dkk. Hvis billetten er købt i eur,
            // skrives der nul
            printf("Rejseomkostninger for deltager %03.0f i DKK. Skriv 0 hvis "
                   "billetterne er koebt i Euro: ",
                   deltagere[0][i]);
            scanf("%f", &deltagere[3][i]);

            // rejseomkostninger i eur. Hvis billetten er købt i dkk,
            // skrives der nul
            if (deltagere[3][i] == 0)
            {
                printf("Rejseomkostninger for deltager %03.0f i EUR: ",
                       deltagere[0][i]);
                scanf("%f", &deltagere[4][i]);
            }

            // indtast deltagerens omkostninger til ophold
            printf("Omkostninger til ophold for deltager %03.0f i DKK: ",
                   deltagere[0][i]);
            scanf("%f", &deltagere[5][i]);

            // Beregning af hver deltagers omkostninger,
            // eur beløb omregnes til dkk

            // omregning af EUR madkomkostninger til DKK
            if (deltagere[1][i] == 0)
            {
                deltagere[1][i] = deltagere[2][i] * euro;
            };

            // omregning af EUR rejseomkostninger til DKK
            if (deltagere[3][i] == 0)
            {
                deltagere[3][i] = deltagere[4][i] * euro;
            };

            // hver deltagers samlede udgifter
            deltagere[6][i] = deltagere[1][i] + deltagere[3][i] + deltagere[5][i];

            // vis de indtastede værdier under hver deltager
            printf("Deltagerens omkostninger er som foelger:\n");
            printf("Deltager\t Madomkostninger\t Rejseomkostninger\t Ophold\t\t "
                   "Total\n");
            printf("%03.0f\t\t DKK%8.2f\t\t DKK%8.2f\t\t DKK%8.2f\t DKK%8.2f\n",
                   deltagere[0][i], deltagere[1][i], deltagere[3][i], deltagere[5][i],
                   deltagere[6][i]);

            // spørg brugeren om der skal indtastes flere deltagere
            printf("Vil du indtaste flere deltagere j/n?: ");
            scanf(" %c", &m);
        };
    };

    printf("Ude af opret modulet. Tryk på en tast OG [Enter] for at "
           "afslutte.");
    char afslut;
    scanf(" %c", &afslut);

    // beregning af hvad differencen er for hver deltager
}
// udskriv funktionen (rykkes som ovenstående funktionen)
void udskriv(void)
{
    printf("Du er i udskriv funktionen");
    float deltagere[8][15] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}};
    float totalsum, gennemsnit;
    int i, j, k;
    char m = 'j';

    opret(deltagere, 15, 15, 'j');

    // visning af alle omkostninger
    printf("Overblik over alle omkostninger:\n");
    printf("Deltager\t | Madomkostninger\t | Rejseomkostninger\t | Ophold\t | "
           "Total\t | Difference\n");
    for (j = 0; j < 15; j++)
    {
        printf("%03.0f\t\t | DKK%5.2f\t\t | DKK%5.2f\t\t | DKK%5.2f\t | DKK%5.2f\t "
               "| DKK%5.2f\n",
               deltagere[0][j], deltagere[1][j], deltagere[3][j], deltagere[5][j],
               deltagere[6][j], deltagere[7][j]);
    };

    // beregning af de samlede omkostninger og fordeling
    totalsum = totalsum + deltagere[6][i];
    printf("Det totale regnskab indtil videre: %8.2f\n", totalsum);
}
// Menu funktionen (Rykkes som ovenstående)
void menu(void)
{
    // Definere variable
    int userInput1;
    float deltagere[8][15] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}};
    char m = 'j';

    // Selve menuen som printer opret og udskriv delen
    printf("For at oprette tast: 1\n");
    printf("For at udskrive tast: 2\n");
    printf("For at afslutte tast: 0\n");

    // Bruger vælger
    printf("Indtast her: ");
    scanf("%d", &userInput1);

    switch (userInput1)
    {
    case 1:

        opret(deltagere, 15, 15, 'j');
        break;
    case 2:
        udskriv();
        break;
    case 0:
        break;
    }
}

int main()
{

    // Kalder menu funktionen
    menu();

    return 0;
}
