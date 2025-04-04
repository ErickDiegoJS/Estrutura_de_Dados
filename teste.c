#include <stdio.h>
int main(){
    int a[5], b[5], c[10], i;

printf("Vetor A:\n");
for(i = 0; i < 5; i++) scanf("%d", &a[i]);

printf("Vetor B:\n");
for(i = 0; i < 5; i++) scanf("%d", &b[i]);

for(i = 0; i < 5; i++){
    c[2*i] = a[i];// 2 vezes 0 da 0, 2 vezes 1 da 2
    c[2*i + 1] = b[i];// 2 vezes 0 + 1 da 1, 2 vezes 1 + 1 da 3
}

printf("Vetor intercalado:\n");
for(i = 0; i < 10; i++) printf("%d ", c[i]);

}