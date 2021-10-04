#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number:\n");

    long primeiro, segundo;

    int contador = 0, verifica = 0, resultado = 0;

    while (number > 0)
    {
        // Os pares soma
        if (contador % 2 == 0)
        {
            resultado = resultado + (number % 10);
        }
        else
        {
            // Impares multiplica
            verifica = (number % 10) * 2;

            // Se a multiplicação der mais que 10 soma um ao outro
            if (verifica % 10 != 0 || verifica % 10 == 0)
            {
                verifica = (verifica % 10) + (verifica / 10);
            }

            // Soma as multiplicações
            resultado = resultado + verifica;
        }

        //Salvando os primeiros numeros para verificação da bandeira
        segundo  = primeiro;
        primeiro = number;
        contador ++;
        number = number / 10;
    }

    if (resultado % 10 == 0 && (primeiro == 4 || primeiro == 3 || primeiro == 5))
    {
        //All American Express numbers start with 34 or 37
        if ((segundo == 34 || segundo == 37) && contador == 15)
        {
            printf("AMEX\n");
        }
        else
            //MasterCard numbers start with 51, 52, 53, 54, or 55
            if ((segundo == 51 || segundo == 52 || segundo == 53 || segundo == 54 || segundo == 55) && contador == 16)
            {
                printf("MASTERCARD\n");
            }
            else
                //Visa numbers start with 4
                if ((primeiro == 4) && (contador == 13 || contador == 16))
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
    }
    else
    {
        //Cartões inválidos
        printf("INVALID\n");
    }
}