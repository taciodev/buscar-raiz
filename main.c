#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double FUNC(double x)
{
  return pow(x, 3) - 6 * pow(x, 2) + 4 * x + 12;
}

int main()
{
  double A, B, M, MA, FM, FA, FB, erro;

  printf("Defina limite inferior do intervalo: ");
  scanf("%lf", &A);
  printf("Defina limite superior do intervalo: ");
  scanf("%lf", &B);
  printf("Defina o erro, em decimal: ");
  scanf("%lf", &erro);

  FA = FUNC(A);
  FB = FUNC(B);

  if (FA * FB == 0)
  {
    printf("A ou B são raízes\n");
    if (FA == 0)
    {
      printf("A é a raiz: %lf\n", A);
    }
    else
    {
      printf("B é a raiz: %lf\n", B);
    }
    return 0;
  }

  if (FA * FB > 0)
  {
    printf("Intervalo inválido! Tente novamente.\n");
    return 0;
  }

  M = (A + B) / 2;
  MA = A;
  while (fabs(MA - M) > erro)
  {
    FM = FUNC(M);
    if (FA * FM > 0)
    {
      A = M;
      FA = FM;
    }
    else
    {
      B = M;
      FB = FM;
    }
    MA = M;
    M = (A + B) / 2;
  }
  printf("A raiz da função é aproximadamente igual a %lf\n", M);
  return 0;
}