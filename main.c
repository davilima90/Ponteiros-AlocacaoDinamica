#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// **************************************************************************
int *numbers_create(int size); // aloca os espaços para um tamanho fixo
void numbers_read(int *numbers, int size); // ler todos os valores para os espaços
float numbers_average(int *numbers, int size); // calcula a média e retorna o valor
void numbers_show(int *numbers, int size); // exibe os valores alocados
void numbers_destroy(int *numbers); // desaloca a variável alocada

int numbers_maior(int *numbers, int size); // retorna o maior número
int numbers_min(int *numbers, int size); // retorna o menor número
void numbers_show_even(int *numbers, int size); // exibe os pares
void numbers_show_odd(int *numbers, int size); // exibe os ímpares
int numbers_count_multiples_of_5(int *numbers, int size); // conta múltiplos de 5
// **************************************************************************

// **************************** Implementação ******************************

int *numbers_create(int size) {
  int *num = NULL;
  num = (int *)malloc(size * sizeof(int));
  if (num == NULL)
    return NULL;
  return num;
}

void numbers_read(int *numbers, int size) {
  if (numbers != NULL) {
    for (int i = 0; i < size; i++)
      numbers[i] = rand() % 50; // valores de 0 a 49
  }
}

float numbers_average(int *numbers, int size) {
  float sum = 0.0;
  if (numbers != NULL)
    for (int i = 0; i < size; i++)
      sum += numbers[i];
  if (sum != 0)
    return sum / (float)size;
  return 0;
}

void numbers_show(int *numbers, int size) {
  printf("[");
  if (numbers != NULL) {
    for (int i = 0; i < size; i++)
      if (i == (size - 1))
        printf("%d", numbers[i]);
      else
        printf("%d, ", numbers[i]);
  }
  printf("]\n");
}

void numbers_destroy(int *numbers) { free(numbers); }

// ------------------ funcoes novas ----------------------

int numbers_maior(int *numbers, int size) {
  int max = numbers[0];
  for (int i = 1; i < size; i++) {
    if (numbers[i] > max)
      max = numbers[i];
  }
  return max;
}

int numbers_min(int *numbers, int size) {
  int min = numbers[0];
  for (int i = 1; i < size; i++) {
    if (numbers[i] < min)
      min = numbers[i];
  }
  return min;
}

void numbers_show_even(int *numbers, int size) {
  printf("Numeros pares: [");
  int first = 1;
  for (int i = 0; i < size; i++) {
    if (numbers[i] % 2 == 0) {
      if (!first) printf(", ");
      printf("%d", numbers[i]);
      first = 0;
    }
  }
  printf("]\n");
}

void numbers_show_odd(int *numbers, int size) {
  printf("Numeros impares: [");
  int first = 1;
  for (int i = 0; i < size; i++) {
    if (numbers[i] % 2 != 0) {
      if (!first) printf(", ");
      printf("%d", numbers[i]);
      first = 0;
    }
  }
  printf("]\n");
}

int numbers_count_multiples_of_5(int *numbers, int size) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (numbers[i] % 5 == 0) {
      count++;
    }
  }
  return count;
}

// *************************************************************************

int main() {
  srand(time(NULL));
  int *numbers; 
  int size = rand() % 20 + 5; // tamanho entre 5 e 24 para testes
  numbers = numbers_create(size);
  numbers_read(numbers, size);

  printf("Conjunto de numeros: ");
  numbers_show(numbers, size);

  float avg = numbers_average(numbers, size); 
  printf("Media = %.2f\n", avg);

  printf("Maior numero = %d\n", numbers_maior(numbers, size));
  printf("Menor numero = %d\n", numbers_min(numbers, size));

  numbers_show_even(numbers, size);
  numbers_show_odd(numbers, size);

  int mult5 = numbers_count_multiples_of_5(numbers, size);
  printf("Quantidade de multiplos de 5 = %d\n", mult5);

  numbers_destroy(numbers);
  return 0;
}
