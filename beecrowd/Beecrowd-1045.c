// Tipos de Triângulos
#include <stdio.h>

void ordenarDecrescente(float *a, float *b, float *c) {
    float temp;
    if (*b < *c) { temp = *b; *b = *c; *c = temp; }
    if (*a < *b) { temp = *a; *a = *b; *b = temp; }
    if (*b < *c) { temp = *b; *b = *c; *c = temp; }
}

void classificarTriangulo(float a, float b, float c) {
    if (a >= b + c) {
        printf("NAO FORMA TRIANGULO\n");
        return;
    }
    if (a * a == b * b + c * c) {
        printf("TRIANGULO RETANGULO\n");
    }
    else if (a * a > b * b + c * c) {
        printf("TRIANGULO OBTUSANGULO\n");
        
    }
    else if (a * a < b * b + c * c) {
        printf("TRIANGULO ACUTANGULO\n");
        
    }
    if (a == b && b == c) printf("TRIANGULO EQUILATERO\n");
    else if (a == b || b == c || a == c) printf("TRIANGULO ISOSCELES\n");
}

int main() {
    float v1, v2, v3;
    scanf("%f %f %f", &v1, &v2, &v3);
    ordenarDecrescente(&v1, &v2, &v3);
    classificarTriangulo(v1, v2, v3);
    return 0;
}
