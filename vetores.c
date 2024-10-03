#include <stdio.h>
#include <stdlib.h>

//vetor global
int *vetor;

//funcao equivalente a malloc
void *alocar(size_t tamanho) {
    void *ptr = malloc(tamanho);
    if (ptr == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    return ptr;
}

//função equivalente a free
void liberar(void *ptr) {
    free(ptr);
}

// alocar dinamicamente o vetor
void alocarVetor() {
    int tamanho = 8192 / sizeof(int);  // Limite de 8 KB, calculando a quantidade de inteiros
    vetor = (int *)alocar(tamanho * sizeof(int)); 
}

//liberar a memória alocada
void liberarVetor() {
    liberar(vetor);  // Substitui free por liberar
}

int main(void) {
   
    alocarVetor();

   
    int tamanho = 8192 / sizeof(int);  // 2048 inteiros (8 KB)
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i; 
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

   
    liberarVetor();  

    return 0;
}
