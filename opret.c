#include <stdio.h>

const float EURO = 7.47;
int main() {
    //vi bruger et enketl to-dimensionelt array for at holde koden "ren"
    //vores array har to pladser til indtastning af rejseudgifter, da
    //de kan både være dkk og eur. Hvis dkk indekset er tom, bliver det regnet om.
    //layout for array:
    //0, j: deltager id
    //1, j: madomkostninger i dkk
    //2, j: madomkostninger i eur
    //3, j: Rejseomkostninger i dkk
    //4, j: rejseomkostninger i eur
    //5, j: ophold
    //6, j: totalomkostninger for hver deltager
    //7, j: difference ift gennemsnittet
    int deltagere[8][15] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
        {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500}
    };
    int i, j;
    
    //vis de initielle værdier under hver deltager
    printf("Deltagernes omkostninger er som følger:\n");
    printf("Deltager\t Madomkostninger\t Rejseomkostninger\t Ophold\t\t Total\t\t Difference\n");
    
        for(j = 0; j < 15; j++) {
            printf("%03d\t\t DKK%5d\t\t DKK%5d\t\t DKK%5d\t DKK%5d\t DKK%5d\n",
                   deltagere[0][j],
                   deltagere[1][j],
                   deltagere[3][j],
                   deltagere[5][j],
                   deltagere[6][j],
                   deltagere[7][j]);
        }
    //brugeren bedes om at indtaste oplysningerne
    printf("Indtast deltagernes omkostninger.\n");

    //indtast madomkostninger i dkk
    printf("Madomkostninger for deltager %03d i DKK. Skriv 0 hvis omkostningerne er i Euro: ", deltagere[0][0]);
    scanf("%d", &deltagere[0][1]);
    //indtast madomkostninger i eur
    printf("Madomkostninger for deltager %03d i EUR. Skriv 0 hvis omkostningerne er i DKK: ", deltagere[0][0]);
    scanf("%d", &deltagere[0][2]);

    //indtast rejseomkostninger i dkk. Hvis billetten er købt i eur,
    //skrives der nul

    //rejseomkostninger i eur. Hvis billetten er købt i dkk,
    //skrives der nul

    //beregning af hver deltagers omkostninger,
    //eur beløb omregnes til dkk

    //beregning af de samlede omkostninger og fordeling

    //beregning af hvad differencen er for hver deltager
    return 0;
}