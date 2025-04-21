// ******************************************************
// * Nome: Erick Diego de Jesus Soares                  *
// * ADS Tarde 3 semsestre                              *
// * Estrutura de dados                                 *
// ******************************************************
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAMANHO_PLACA 8
#define CAPACIDADE_ESTACIONAMENTO 10

typedef struct{
    char placa[TAMANHO_PLACA];
} T_carro;

typedef struct{
    T_carro carro;
    int manobras;
} T_carro_estacionado;

typedef struct {
    T_carro_estacionado *carros;
    int capacidade;
    int vagas;
}T_estacionamento;

void ConstroiEstacionamento(int capacidade, T_estacionamento *estacionamento);
void ConstroiCarro(char *placa, T_carro *carro);
void ConstroiCarroEstacionado(T_carro_estacionado *carroEstacionado,T_carro *carro);
int EstacionamentoCheio(T_estacionamento *estacionamento);
int EstacionamentoVazio(T_estacionamento *estacionamento);
void ExibirEstacionamento(T_estacionamento *estacionamento);
void LiberarEstacionamento(T_estacionamento *estacionamento);
void LiberarCarro(int indice, T_estacionamento *estacionamento);
void Push(T_estacionamento *estacionamento, T_carro_estacionado *carro);
void Pop(T_estacionamento *estacionamento, T_carro *carro);

int main(){
    T_estacionamento estacionamento;
    ConstroiEstacionamento(CAPACIDADE_ESTACIONAMENTO, &estacionamento);
    int entrada; 
    char placa[TAMANHO_PLACA];
    ExibirEstacionamento(&estacionamento);
    while(scanf("%1d %7s", &entrada, &placa) != EOF){
        T_carro carro;
        ConstroiCarro(placa, &carro);
        if(entrada == 0){
            T_carro_estacionado carroEstacionado;
            ConstroiCarroEstacionado(&carroEstacionado, &carro);
            Push(&estacionamento, &carroEstacionado);
            ExibirEstacionamento(&estacionamento);
        }
        else if(entrada == 1){
            Pop(&estacionamento, &carro);
            ExibirEstacionamento(&estacionamento);
        }
        else{
            printf("\nEntrada invalida!");
        }
    }
    LiberarEstacionamento(&estacionamento);
    return 0;
}

void ConstroiEstacionamento(int capacidade, T_estacionamento *estacionamento){
    estacionamento->carros = (T_carro_estacionado *) malloc(capacidade * (sizeof(T_carro_estacionado)));
    estacionamento->capacidade = capacidade;
    estacionamento->vagas = capacidade;
    for (int i = 0; i < capacidade; i++) {
        estacionamento->carros[i].carro.placa[0] = '\0';
        estacionamento->carros[i].manobras = 0;
    }
}

void ConstroiCarro(char *placa, T_carro *carro){
    strcpy(carro->placa, placa);
}

void ConstroiCarroEstacionado(T_carro_estacionado *carroEstacionado,T_carro *carro){
    carroEstacionado->carro = *carro; 
    carroEstacionado->manobras = 0;
}

int EstacionamentoCheio(T_estacionamento *estacionamento){
    return !estacionamento->vagas;
}

int EstacionamentoVazio(T_estacionamento *estacionamento){
    return estacionamento->vagas == estacionamento->capacidade;
}

void ExibirEstacionamento(T_estacionamento *estacionamento){
    if(!EstacionamentoVazio(estacionamento)){
        printf("\n********* Estacionamento *********\n");
        
        for(int i=0; i<estacionamento->capacidade - estacionamento->vagas; i++){
            printf("\nCarro: %s, qtdmanobras: %d", estacionamento->carros[i].carro.placa, estacionamento->carros[i].manobras);
            printf("\n**********************************");
        }
    }
    else{
        printf("\nEstacionamento vazio!");
    }
}

void LiberarEstacionamento(T_estacionamento *estacionamento){
    free(estacionamento->carros);
}

void LiberarCarro(int indice, T_estacionamento *estacionamento){
    estacionamento->carros[indice].manobras = 0;
    estacionamento->carros[indice].carro.placa[0] = '\0';
}

void Push(T_estacionamento *estacionamento, T_carro_estacionado *carro){
    if(!EstacionamentoCheio(estacionamento)){
        estacionamento->carros[estacionamento->capacidade - estacionamento->vagas--] = *carro;
    }
    else{
        printf("\nEstacionamento cheio! Nao foi possivel estacionar.");
    }
}

void Pop(T_estacionamento *estacionamento, T_carro *carro){
    if (!EstacionamentoVazio(estacionamento)) {
        int indice = 0;

        while (indice < estacionamento->capacidade - estacionamento->vagas && strcmp(carro->placa, estacionamento->carros[indice].carro.placa) != 0){
            indice++;
        }

        if (indice == estacionamento->capacidade - estacionamento->vagas) {
            printf("\nCarro de placa %s não encontrado no estacionamento.\n", carro->placa);
            return;
        }

        printf("\nO carro de placa %s fez %d manobras antes de sair do estacionamento\n", estacionamento->carros[indice].carro.placa, estacionamento->carros[indice].manobras);

        T_estacionamento aux;
        ConstroiEstacionamento(estacionamento->capacidade-1, &aux);
        for(int i = estacionamento->capacidade-estacionamento->vagas-1; i>=indice; i--){
           
            if(i != indice){
                estacionamento->carros[i].manobras++;
                Push(&aux, &estacionamento->carros[i]);
            }
            LiberarCarro(i, estacionamento);

            estacionamento->vagas++;
            
        }
        
        while(!EstacionamentoVazio(&aux)){
            Push(estacionamento, &aux.carros[aux.capacidade - aux.vagas-1]);
            aux.vagas++;
        }
        LiberarEstacionamento(&aux);
    } else {
        printf("\nEstacionamento vazio!\n");
    }
}
