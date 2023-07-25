#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 

void bolha(int n, int *v);
void rapida(int n, int *v);
void mergeSort_ordena(int *v, int esq, int dir);
void mergeSort_intercala(int *v, int esq, int meio, int dir);
void mergeSort(int *v, int n);
void insertionSort(int array[], int size);
void heapsort(int a[], int n);

void bolha(int n, int *v)
{
	int i, j, temp;
	for(i=n-1; i>0; i--)
		for(j=0; j<i; j++)
			if(v[j]> v[j+1])
			{
				temp = v[j]; // Troca
				v[j] = v[j+1];
				v[j+1] = temp;
			}
}

void rapida(int n, int *v)
{
 	if(n>1)
	 {
 		int x = v[0];
 		int a =1; int b = n-1;
 		while(1)
		 {
 			while(a<n && v[a] <=x) a++;
 			while(v[b]>x) b--;
 			if(a<b){
 				int temp = v[a];
 				v[a] = v[b];
 				v[b] = temp;
 				a++;b--; 
 				}else 
					break;
 }
 v[0] = v[b];
 v[b] = x; 
 rapida(b,v);
 rapida(n-a,&v[a]);
 } 
}

void mergeSort_ordena(int *v, int esq, int dir) {
 if (esq == dir)
 	return;
 int meio = (esq + dir) / 2;
 mergeSort_ordena(v, esq, meio);
 mergeSort_ordena(v, meio+1, dir);
 mergeSort_intercala(v, esq, meio, dir);
 return;
}

void mergeSort_intercala(int *v, int esq, int meio, int dir){
 int i, j, k;
 int a_tam = meio-esq+1;
 int b_tam = dir-meio;
 int *a = (int*) malloc(sizeof(int) * a_tam);
 int *b = (int*) malloc(sizeof(int) * b_tam);
 
 for (i = 0; i < a_tam; i++) a[i] = v[i+esq];
 for (i = 0; i < b_tam; i++) b[i] = v[i+meio+1];
 
 for (i = 0, j = 0, k = esq; k <= dir; k++) {
 if (i == a_tam) v[k] = b[j++];
 else if (j == b_tam) v[k] = a[i++];
 else if (a[i] < b[j]) v[k] = a[i++];
 else v[k] = b[j++];
 }
 free(a); free(b);
}

void mergeSort(int *v, int n) {
 mergeSort_ordena(v, 0, n-1);
}

void insertionSort(int array[], int size) {
    int i, j, key;

    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }
}

void heapsort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   while(1) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n <= 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}

void vet100()
{
	printf("VETOR 100\n");
	int vet[100];
	int i;
	for(i = 0; i < 100; i++)
	{
		vet[i] = rand() % 100;
	}
	double time_spent = 0.0;
	clock_t begin = clock();
	sleep(3);
	bolha(100,vet);
	clock_t end = clock();
	time_spent += (double)(end - begin)*1000/CLOCKS_PER_SEC;
	printf("BUBLLE: The elapsed time is %f miliseconds\n", time_spent);
	double time_spent1 = 0.0;
	clock_t begin1 = clock();
	sleep(3);
	rapida(100,vet);
	clock_t end1 = clock();
	time_spent1 += (double)(end1 - begin1)*1000/CLOCKS_PER_SEC;
	printf("QUICK: The elapsed time is %f miliseconds\n", time_spent1);
	double time_spent2 = 0.0;
	clock_t begin2 = clock();
	sleep(3);
	mergeSort(vet,100);
	clock_t end2 = clock();
	time_spent2 += (double)(end2 - begin2)*1000/CLOCKS_PER_SEC;
	printf("MERGESORT: The elapsed time is %f miliseconds\n", time_spent2);
	double time_spent3 = 0.0;
	clock_t begin3 = clock();
	sleep(3);
	insertionSort(vet,100);
	clock_t end3 = clock();
	time_spent3 += (double)(end3 - begin3)*1000/CLOCKS_PER_SEC;
	printf("INSECTIONSORT: The elapsed time is %f miliseconds\n", time_spent3);
	double time_spent4 = 0.0;
	clock_t begin4 = clock();
	sleep(3);
	heapsort(vet,100);
	clock_t end4 = clock();
	time_spent4 += (double)(end4 - begin4)*1000/CLOCKS_PER_SEC;
	printf("HEAPSORT: The elapsed time is %f miliseconds\n", time_spent4);
}

void vet1000()
{
	printf("VETOR 1000");
	int vet[1000];
	int i;
	for(i = 0; i < 1000; i++)
	{
		vet[i] = rand() % 100;
	}
	double time_spent = 0.0;
	clock_t begin = clock();
	sleep(3);
	bolha(1000,vet);
	clock_t end = clock();
	time_spent += (double)(end - begin)*1000/CLOCKS_PER_SEC;
	printf("BUBLLE: The elapsed time is %f miliseconds\n", time_spent);
	double time_spent1 = 0.0;
	clock_t begin1 = clock();
	sleep(3);
	rapida(1000,vet);
	clock_t end1 = clock();
	time_spent1 += (double)(end1 - begin1)*1000/CLOCKS_PER_SEC;
	printf("QUICK: The elapsed time is %f miliseconds\n", time_spent1);
	double time_spent2 = 0.0;
	clock_t begin2 = clock();
	sleep(3);
	mergeSort(vet,1000);
	clock_t end2 = clock();
	time_spent2 += (double)(end2 - begin2)*1000/CLOCKS_PER_SEC;
	printf("MERGESORT: The elapsed time is %f miliseconds\n", time_spent2);
	double time_spent3 = 0.0;
	clock_t begin3 = clock();
	sleep(3);
	insertionSort(vet,1000);
	clock_t end3 = clock();
	time_spent3 += (double)(end3 - begin3)*1000/CLOCKS_PER_SEC;
	printf("INSECTIONSORT: The elapsed time is %f miliseconds\n", time_spent3);
	double time_spent4 = 0.0;
	clock_t begin4 = clock();
	sleep(3);
	heapsort(vet,1000);
	clock_t end4 = clock();
	time_spent4 += (double)(end4 - begin4)*1000/CLOCKS_PER_SEC;
	printf("HEAPSORT: The elapsed time is %f miliseconds\n", time_spent4);
}

void vet10000()
{
	printf("VETOR 10000\n");
	int vet[10000];
	int i;
	for(i = 0; i < 10000; i++)
	{
		vet[i] = rand() % 100;
	}
	double time_spent = 0.0;
	clock_t begin = clock();
	sleep(3);
	bolha(10000,vet);
	clock_t end = clock();
	time_spent += (double)(end - begin)*1000/CLOCKS_PER_SEC;
	printf("BUBLLE: The elapsed time is %f miliseconds\n", time_spent);
	double time_spent1 = 0.0;
	clock_t begin1 = clock();
	sleep(3);
	rapida(10000,vet);
	clock_t end1 = clock();
	time_spent1 += (double)(end1 - begin1)*1000/CLOCKS_PER_SEC;
	printf("QUICK: The elapsed time is %f miliseconds\n", time_spent1);
	double time_spent2 = 0.0;
	clock_t begin2 = clock();
	sleep(3);
	mergeSort(vet,10000);
	clock_t end2 = clock();
	time_spent2 += (double)(end2 - begin2)*1000/CLOCKS_PER_SEC;
	printf("MERGESORT: The elapsed time is %f miliseconds\n", time_spent2);
	double time_spent3 = 0.0;
	clock_t begin3 = clock();
	sleep(3);
	insertionSort(vet,10000);
	clock_t end3 = clock();
	time_spent3 += (double)(end3 - begin3)*1000/CLOCKS_PER_SEC;
	printf("INSECTIONSORT: The elapsed time is %f miliseconds\n", time_spent3);
	double time_spent4 = 0.0;
	clock_t begin4 = clock();
	sleep(3);
	heapsort(vet,10000);
	clock_t end4 = clock();
	time_spent4 += (double)(end4 - begin4)*1000/CLOCKS_PER_SEC;
	printf("HEAPSORT: The elapsed time is %f miliseconds\n", time_spent4);
}
void vet100000()
{
	printf("VETOR 100000\n");
	int vet[100000];
	int i;
	for(i = 0; i < 100000; i++)
	{
		vet[i] = rand() % 100;
	}
	double time_spent = 0.0;
	clock_t begin = clock();
	sleep(3);
	bolha(100000,vet);
	clock_t end = clock();
	time_spent += (double)(end - begin)*1000/CLOCKS_PER_SEC;
	printf("BUBLLE: The elapsed time is %f miliseconds\n", time_spent);
	double time_spent1 = 0.0;
	clock_t begin1 = clock();
	sleep(3);
	rapida(100000,vet);
	clock_t end1 = clock();
	time_spent1 += (double)(end1 - begin1)*1000/CLOCKS_PER_SEC;
	printf("QUICK: The elapsed time is %f miliseconds\n", time_spent1);
	double time_spent2 = 0.0;
	clock_t begin2 = clock();
	sleep(3);
	mergeSort(vet,100000);
	clock_t end2 = clock();
	time_spent2 += (double)(end2 - begin2)*1000/CLOCKS_PER_SEC;
	printf("MERGESORT: The elapsed time is %f miliseconds\n", time_spent2);
	double time_spent3 = 0.0;
	clock_t begin3 = clock();
	sleep(3);
	insertionSort(vet,100000);
	clock_t end3 = clock();
	time_spent3 += (double)(end3 - begin3)*1000/CLOCKS_PER_SEC;
	printf("INSECTIONSORT: The elapsed time is %f miliseconds\n", time_spent3);
	double time_spent4 = 0.0;
	clock_t begin4 = clock();
	sleep(3);
	heapsort(vet,100000);
	clock_t end4 = clock();
	time_spent4 += (double)(end4 - begin4)*1000/CLOCKS_PER_SEC;
	printf("HEAPSORT: The elapsed time is %f miliseconds\n", time_spent4);
}

void vet1000000()
{
	printf("VETOR 1000000\n");
	int vet[1000000];
	int i;
	for(i = 0; i < 1000000; i++)
	{
		vet[i] = rand() % 100;
	}
	double time_spent = 0.0;
	clock_t begin = clock();
	sleep(3);
	bolha(1000000,vet);
	clock_t end = clock();
	time_spent += (double)(end - begin)*1000/CLOCKS_PER_SEC;
	printf("BUBLLE: The elapsed time is %f miliseconds\n", time_spent);
	double time_spent1 = 0.0;
	clock_t begin1 = clock();
	sleep(3);
	rapida(1000000,vet);
	clock_t end1 = clock();
	time_spent1 += (double)(end1 - begin1)*1000/CLOCKS_PER_SEC;
	printf("QUICK: The elapsed time is %f miliseconds\n", time_spent1);
	double time_spent2 = 0.0;
	clock_t begin2 = clock();
	sleep(3);
	mergeSort(vet,1000000);
	clock_t end2 = clock();
	time_spent2 += (double)(end2 - begin2)*1000/CLOCKS_PER_SEC;
	printf("MERGESORT: The elapsed time is %f miliseconds\n", time_spent2);
	double time_spent3 = 0.0;
	clock_t begin3 = clock();
	sleep(3);
	insertionSort(vet,1000000);
	clock_t end3 = clock();
	time_spent3 += (double)(end3 - begin3)*1000/CLOCKS_PER_SEC;
	printf("INSECTIONSORT: The elapsed time is %f miliseconds\n", time_spent3);
	double time_spent4 = 0.0;
	clock_t begin4 = clock();
	sleep(3);
	heapsort(vet,1000000);
	clock_t end4 = clock();
	time_spent4 += (double)(end4 - begin4)*1000/CLOCKS_PER_SEC;
	printf("HEAPSORT: The elapsed time is %f miliseconds\n", time_spent4);
}





int main(void) {
	vet100();
	vet1000();
	vet10000();
	vet100000();
	vet1000000();
	return 0;
}
