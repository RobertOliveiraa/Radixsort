// C++ implementation of Radix Sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//#define namespace std; testeee
int troca = 0;
int comp = 0;
int test = 0;
double tempo;
clock_t start, endd;

// Uma função de utilidade para obter o valor máximo em arr []
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

/* Uma função para fazer a contagem do tipo arr [] de acordo com o dígito representado por exp.*/
void countSort(int arr[], int n, int exp)
{
    int output[n]; // matriz de saída
    int i, count[10] = {0};
    
    // Armazenar contagem de ocorrências em count []
    for (i = 0; i < n; i++){
        count[ (arr[i]/exp)%10 ]++;
        comp = i;
    }
    
    
    /* Alterar contagem [i] para que a contagem [i] agora contendo dados reais
     posição deste dígito na saída []*/
    for (i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
    
    // Construa o array de saída
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
    
   
    /* Copie a matriz de saída para arr [], de modo que arr [] agora contém números ordenados de acordo com o dígito atual*/
    for (i = 0; i < n; i++)
        arr[i] = output[i];
        troca = i;
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radisort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
    
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    
    printf( "\n\nExecucao foi de %f segundos", tempo);
    printf( "\n\nTrocas %d", troca);
    printf( "\n\nComparacoes: %d", comp);
}

void random_number(int arr[], int n)
{
    srand((unsigned int)time(NULL));
    for(int i=0; i<n; i++)
    {
        arr[i] = rand() % n;
    }
}

// Driver program to test above functions
int main()
{
    
    int n, i;
    
    printf("\nInforme o tamanho do vetor: ");
    scanf("%d",&n);
    
    int arr[n];
    
    
    random_number(arr, n);
    
    //Impressão vetor não ordenado
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    
    start = clock();
    radisort(arr, n);
    endd = clock();
    tempo = ((double) (endd - start))/CLOCKS_PER_SEC;
    printf("\n\n--------- ORDENACAO ---------\n\n");
    print(arr, n);
    
    return 0;
}
