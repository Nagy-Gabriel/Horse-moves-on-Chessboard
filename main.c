#include <stdio.h>
#include <stdlib.h>

int N=8; 

int** alocare_dinamica(int linii, int coloane)
{
    int i,j;
    int **matrice = (int**)malloc(linii * sizeof(int*));
    if(matrice == NULL)
    {
        printf("Eroare la alocarea de memorie pentru linii!\n");
        exit(EXIT_FAILURE);
    }
    for(i = 0 ; i < linii ; i++)
    {
        matrice[i] = (int*)malloc(coloane * sizeof(int));
        if(matrice[i] == NULL)
        {
            printf("Eroare la alocarea de memorie pentru coloane!\n");
            //eliminam memoria alocata anterior pentru a nu avea scurgeri de memorie!
            for(j = 0 ; j < i ; j++)
            {
                free(matrice[j]);
            }
            free(matrice);
            exit(EXIT_FAILURE);
        }
    }
    return matrice;
}

void eliberare_memorie(int **matrice, int linii)
{
    int i;
    if(matrice != NULL)
    {
        for(i = 0; i < linii; i++)
        {
            if(matrice[i]!=NULL)
            free(matrice[i]);
        }
    free(matrice);
    }
}

int traseu_cal_pasi(int x, int y, int miscarei, int **solutii, int miscareX[], int miscareY[]);
void afisare(int **solutii)
{
    int x,y;
    printf("Solutia pentru traseul calului plecand de la 0,0 cu dimensiunea tablei de sah %d: \n", N);
    for(x = 0 ; x < N; x++)
    {
        for(y = 0; y < N; y++)
        {
            printf("|%2d", solutii[x][y]);
        }
        printf("|\n");
    }
    printf("\n");
}
int posibil(int x, int y, int **solutii)
{
    return (x >= 0 && x < N && y >= 0 && y < N && solutii[x][y] == -1);
}

int traseu_cal()
{
    int **solutii;
    int i, x, y;
    //alocare dinamica pentru matricea de solutii;
    solutii=alocare_dinamica(N, N);

//initializez matricea  de solutii:
for(x = 0; x < N; x++)
{
    for(y = 0; y < N; y++)
    {
        solutii[x][y]= -1;
    }
}

//pentru deplasarile la stanga sau in jos vom folosii valorii cu  -, iar pentru cele la dreapta pozitive;
int miscareX[8]={2, 1, -1, -2, -2 , -1, 1, 2};
int miscareY[8]={1, 2, 2, 1, -1, -2, -2, -1};
 
solutii[0][0] = 0;
//plecam de la pozitia i=0,j=0;
//pentru a continua aceasta functie ne trebuie o alta functie prin care 
//sa parcurgem toate caiile calului posibile pe tabla de sah.
if(traseu_cal_pasi(0, 0, 1, solutii, miscareX, miscareY) == 0)
{
    printf("Nu exista solutie pentru cazul in care calul pleaca de la 0,0 cu dimnesiunea tablei de sah %d", N);
    return 0;
}
else
{
    afisare(solutii);
}
    eliberare_memorie(solutii, N);
return 1;
}

int traseu_cal_pasi(int x, int y, int miscarei, int **solutii, int miscareX[], int miscareY[])
{
    int k, x_urm, y_urm;

    if(miscarei == N*N)
    {

        return 1; //solutie gresita!
    }

    for(k = 0; k < 8; k++)
    {
        x_urm = x + miscareX[k];
        y_urm = y + miscareY[k];
        //urmeaza sa verificam daca pozitia urmatoare a lui x si y( adica x_urm si y_urm)
        //este sigura si daca a fost sau nu vizitata inca. In acest caz de folosim de prima functie creata, si mai exact functia posibil.

        if(posibil(x_urm, y_urm, solutii)) 
        {
            solutii[x_urm][y_urm] = miscarei;//marcam pozitia curenta cu numarul de mutare.
                 if(traseu_cal_pasi(x_urm ,y_urm ,miscarei +1, solutii, miscareX, miscareY) == 1)
                return 1; //in cazul in care s-a gasit o solutie returnam 1.
                //apelam functia rercursiv pentru a explora restul posibilitatiilor de deplasare ale calului incepand
                //de la noua pozitie x_urm si y_urm.
                    else
                solutii[x_urm][y_urm]  = -1; 
                //daca nu se gaseste o solutie, revine la starea anterioara, se anuleaza mutarea cu ajutorul backtracking-ului
                //prin setarea valorii matricei la -1, aceste se sterge. 
        }
    }
return 0; //in cazul in care nu exista o solutie pentru pozitia curenta
}

int main()
{

/*printf("Introduceti dimensiunea tablei de sah: ");
scanf("%d", &N);

if(N<=0||N>8)
{
    printf("Dimensiunea nu este corecta! Introduceti o valoare mai mare decat 0 si mai mica decat 9\n");
    return 1; //iesire cu cod de eroare.
}*/

traseu_cal();
    return 0;
}
