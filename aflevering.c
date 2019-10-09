#include <stdio.h>
#include <stdlib.h>

void opret(float deltagere[][15])
{
    int i, j;
    char m;
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
}
// udskriv funktionen (rykkes som ovenstående funktionen)
void udskriv(float deltagere[8][15])
{
    int userInput1 = 1;
    int j, i;
    printf("For at udskrive for en bestemt deltager tast: 1\n");
    printf("For at udskrive alle de registrerede oplysninger: 2\n");
    printf("For at gå tilbage til hovedmenuen: 0\n\n");
    printf("Indtast her: ");
    scanf(" %d", &userInput1);

    switch (userInput1)
    {
    case 1:
        printf("Indtast brugerID: ");
        scanf("%d", &i);
        i = i - 1;
        printf("Deltager\t Madomkostninger\t Rejseomkostninger\t Ophold\t\t\n ");
        printf("%03.0f\t\t | DKK%5.2f\t\t | DKK%5.2f\t\t | DKK%5.2f\n", deltagere[0][i], deltagere[1][i], deltagere[3][i], deltagere[5][i]);
        break;
    case 2:
        printf("Deltager\t Madomkostninger\t Rejseomkostninger\t Ophold\t\t\n ");
        for (j = 0; j < 15; j++)
        {
            printf("%03.0f\t\t | DKK%5.2f\t\t | DKK%5.2f\t\t | DKK%5.2f\n",
                   deltagere[0][j], deltagere[1][j], deltagere[3][j], deltagere[5][j]);
        };
        break;
    case 0:
        break;
    }
}
// Menu funktionen (Rykkes som ovenstående)
void menu(void)
{
    // Definere variable
    float id = 0;
    float id1 = 0;
    int userInput1 = 1;
    int j;
    float totalSum = 0, maximum, minimum;
    int aggr = 0;
    float deltagere[8][15] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}};

    while (userInput1 != 0)
    {
        // Selve menuen som printer opret og udskriv delen
        printf("For at indtaste data tast: 1\n");
        printf("For at udskrive indtastede data tast: 2\n");
        printf("For at udskrive samlede udgifter tast: 3\n");
        printf("For at udskrive feriens samlede pris og balance for hver deltager: 4\n");
        printf("For at se hvilke deltager har haft henholdsvis det største og mindste udlæg til turen: 5\n");
        printf("For at afslutte tast: 0\n\n");

        // Bruger vælger
        printf("Indtast her: ");
        scanf(" %d", &userInput1);

        switch (userInput1)
        {
        case 1:

            opret(deltagere);
            break;
        case 2:
            udskriv(deltagere);
            break;
        case 3:
            printf("Tabellen viser hver udgiftspost og samlede udgifter for alle deltagere.\n");
            printf("Deltager\t Madomkostninger\t Rejseomkostninger\t Ophold\t\t "
                   "Total\n");
            for (j = 0; j < 15; j++)
            {
                printf("%03.0f\t\t | DKK%5.2f\t\t | DKK%5.2f\t\t | DKK%5.2f\t | DKK%5.2f\n",
                       deltagere[0][j], deltagere[1][j], deltagere[3][j], deltagere[5][j], deltagere[6][j]);
            }
            break;
        case 4:
            //beregning af feriens samlede pris, pris pr deltager og hvorvidt hver deltager
            //skal betale mere eller have penge i retur. Samlet pris for hver deltager er beregnet i forvejen
            for (j = 0; j < 15; j++)
            {
                totalSum = totalSum + deltagere[6][j];
            }

            //udskriv feriens samlede pris
            printf("Den samlede pris for ferien er: DKK%.2f\n", totalSum);

            //beregn gennemsnit for udgifter
            aggr = totalSum / 15;

            //udfyld den søjle hvor differencen for hver deltager er
            for (j = 0; j < 15; j++)
            {
                deltagere[7][j] = deltagere[6][j] - aggr;
            }

            //udskriv balance for hver deltager
            printf("De samlede udgifter er fordelt som nedenstående. Tabellen viser også hvad den enkelte deltager har af penge til gode, eller skal betale til gruppen.\n");
            printf("Deltager\t | Total\t | Difference\n");
            for (j = 0; j < 15; j++)
            {
                printf("%03.0f\t\t | DKK%5.2f\t | DKK%5.2f\n",
                       deltagere[0][j], deltagere[6][j], deltagere[7][j]);
            }

            break;
        case 5:
            maximum = deltagere[6][0];
            minimum = deltagere[6][0];
            //find hvem der har haft henholdsvis det største og mindste udlæg
            for (j = 0; j < 15; j++)
            {
                if (deltagere[6][j] > maximum)
                {
                    maximum = deltagere[6][j];
                    id = deltagere[0][j];
                }
            }

            for (j = 0; j < 15; j++)
            {
                if (deltagere[6][j] < minimum)
                {
                    minimum = deltagere[6][j];
                    id1 = deltagere[0][j];
                }
            }

            printf("Den deltager der har mindst og dermed skylder en omgang er %03.0f - for %8.2f og den deltager der havde størst udlæg er %03.0f - for %8.2f.\n\n", id1, minimum, id, maximum);
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
