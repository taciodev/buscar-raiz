#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float FUNC(float x)
{
  float result;
  result = pow(x, 3) - 6 * pow(x, 2) + 4 * x + 12;
  return result;
}

int main()
{
  int firstValue, secondValue, productFunction;
  float a, b, m, m_ant, margem_error = 0.001;

  srand(time(NULL));

  firstValue = rand() % 10;
  secondValue = rand() % 10;

  productFunction = FUNC(firstValue) * FUNC(secondValue);
  printf("%d\n\n", productFunction);

  while (productFunction > 0)
  {
    firstValue = rand() % 10;
    secondValue = rand() % 10;

    productFunction = FUNC(firstValue) * FUNC(secondValue);
    printf("%d\n\n", productFunction);
  }

  if (productFunction == 0)
  {
    printf("IGUAL A 0");
  }
  else if (productFunction < 0)
  {
    printf("MENOR QUE 0");
  }
}