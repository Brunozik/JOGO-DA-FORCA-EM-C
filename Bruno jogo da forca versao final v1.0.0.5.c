#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

#define LINHA 15
#define COLUNA 40

int main (void) {

    setlocale (LC_ALL, "portuguese");


    char jogo[LINHA][COLUNA] = {{"fusca"}, {"motocicleta"}, {"papagaio"}, {"casa"},
    {"gato"}, {"cachoeira"}, {"apartamento"}, {"camundongo"}, {"bicicleta"},
    {"girassol"}, {"caminhonete"}, {"sal"}, {"flamengo"}, {"ibicui"}, {"carnaval"}};

    char vetor[LINHA];
    char tentativa[COLUNA];
    int menu_opcao, i, j, aux, vida;
    int cont=0, ajuda=0, vencer;

    srand (time (NULL));
    aux = 0 + rand() % LINHA;

    do {
        system ("cls");

        printf("\n\n\n\t\t************************************\n");
        printf("\t\t******** JOGO DA FORCA EM C ********\n");
        printf("\t\t************************************\n\n");

        printf("\t     +---------------------------------------+\n");
        printf ("\t     |   [1] - NOVO JOGO                     |\n");
        printf("\t     |   [2] - MOSTRAR BANCO DE DADOS        |\n");
        printf("\t     |   [3] - SOBRE                         |\n");
        printf("\t     |   [4] - AJUDA                         |\n");
        printf("\t     |   [0] - SAIR                          |\n");
        printf("\t     +---------------------------------------+\n\n\n");
        printf("\t\t\t\t\t\tV1.0.0.5\n");
        printf("\t\t  ");

        scanf("%d", &menu_opcao);

        switch (menu_opcao) {

            case 1:

                system ("cls");
                printf("\n\n\n\t***********************************************\n");
                printf ("\t**** DIGITE UMA LETRA PARA FORMAR A PALAVRA ***\n");
                printf("\t***********************************************\n\n");

                vencer = 0;
                vida = strlen (jogo[aux]);
                vetor[0] = jogo[aux];

                for (i = 0; i < (strlen (jogo[aux])); i++) {

                    vetor[i] = '_';
                    printf ("%c ", vetor[i]);

                }

                printf("\n\n\t[%d] - CHANCES\n\n", vida);

                while (vida > 0) {

                    fflush (stdin);

                    scanf ("%c", &tentativa[ajuda]);

                    for(j = 0; j < COLUNA; j++)
                        {
                        if (tentativa[ajuda] == jogo[aux][j]) {

                            vetor[j] = tentativa[ajuda];
                            vencer ++;

                        }
                        else if (jogo[aux][j] == '\0') {
                        break;
                        }
                        else
                        {
                            cont ++;
                        }
                    }

                    if (cont == strlen (jogo[aux]))
                        {
                        vida --;
                        }

                    for (i = 0; i < strlen (jogo[aux]); i++)
                        {
                            printf ("%c ", vetor[i]);
                        }

                    cont = 0;
                    ajuda++;

                    printf ("\t[%d] - CHANCES RESTANTES\n\n", vida);

                    if (vencer == strlen (jogo[aux]))
                        {
                            printf ("\n\t********** VOCE ACERTOU!!! **********\n\n\n");

                            system ("pause");
                            break;
                        }

                    if (vida == 0)
                        {
                            printf ("\n\t********** GAME OVER **********\n\n\n");

                            system ("pause");
                        }
                }break;

            case 2:

                system ("cls");

                printf("\n\n");
                for (i = 0; i < LINHA; i++) {

                    printf ("[%d] >>> %s\n", (i + 1), jogo[i]);


                } printf("\n\n");
                system ("pause");
                break;

            case 3:
                system ("cls");

                printf("\n\n\n\t\t************** SOBRE **************\n\n\n");
                printf("\t+-------------------------------------------------+\n");
                printf("\t|    UNIVERSIDADE ESTADUAL DE SANTA CRUZ - UESC   |\n");
                printf("\t|    GRADUACAO: Ciencia da Computacao             |\n");
                printf("\t|    PROGRAMADOR: Bruno dos Santos Padre          |\n");
                printf("\t|    FINALIDADE: criterio de avaliacao            |\n");
                printf("\t|    VERSAO: 1.0                                  |\n");
                printf("\t+-------------------------------------------------+\n\n\n");


                system ("pause");
                break;

            case 4:
                system ("cls");

                printf("\n\n\n\t\t***************** AJUDA *****************");
                printf("\n\n\n\t+--------------------------------------------------------+\n");
                printf ("\t|   O objetivo deste game é descobrir uma palavra        |\n");
                printf ("\t|   adivinhando as letras que ela possui.                |\n");
                printf ("\t|   A cada rodada, o jogador ira escolher uma letra      |\n");
                printf ("\t|   que possa fazer parte da palavra.                    |\n");
                printf ("\t|   Caso a palavra contenha esta letra,                  |\n");
                printf ("\t|   será mostrado em que posicao ela está.               |\n");
                printf ("\t|   caso esta letra não exista na palavra,               |\n");
                printf ("\t|   o jogador perdera uma chance. Se zerar as chances,   |\n");
                printf ("\t|   o jogador estará fora da partida.                    |\n");
                printf("\t+--------------------------------------------------------+\n");

                system ("pause");
                break;

            case 0:

                exit (0);
                break;

            default:

                printf ("\t******** ERRO. TENTE NOVAMENTE!!! ********\n");
        }

    } while (menu_opcao != 5);

    return 0;
}
