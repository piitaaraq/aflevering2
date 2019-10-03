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
    int deltagere[7][15] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}
    };
    int i, j;
    
    //vis de initielle værdier under hver deltager
    printf("Deltagernes omkostninger er som følger:\n");
    printf("Deltager\t Madomkostninger\t Rejseomkostninger\t Ophold\t\t Total\t\t Difference\n");
    
    for(j = 0; j < 15; j++) {
        for(i = 0; i < 7; i++) {
            printf("%d\t %d\t %d\t %d\t %d\t %d\n", 
            deltagere[0][j],
            deltagere[1][j],
            deltagere[3][j], 
            deltagere[5][j], 
            deltagere[6][j], 
            deltagere[7][j] );
        }
    }
    //brugeren bedes om at indtaste oplysningerne
    // printf("Indast deltagernes omkostninger.");

    //indtast madomkostninger i eur

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