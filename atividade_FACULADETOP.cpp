#include <iostream>
#include <cmath> // Para sqrt()

using namespace std;

int main() {
    float notas[100]; // Vetor para armazenar todas as notas
    int totalNotas = 0; // Quantidade de notas registradas
    float media = 0.0;
    int tentativasExtras = 0;
    int i;
    float somaNotas = 0.0;
    float mediaNotas = 0.0;
    float desvioPadrao = 0.0;
    float mediana = 0.0;
    float temp;
    int meio;

    // Recebendo as duas primeiras notas 
    printf("Digite a primeira nota: ");
    scanf("%f", &notas[0]);
    printf("Digite a segunda nota: ");
    scanf("%f", &notas[1]);
    totalNotas = 2;

    // Calcula a média inicial
    media = (notas[0] + notas[1]) / 2;

    // Enquanto a média for menor que 6.00
    while (media < 6.00) {
        float novaNota;
        int menorIndex = 0;

        printf("Media insuficiente (%.2f)! Digite uma nova nota: ", media);
        scanf("%f", &novaNota);

        // Adiciona nova nota ao histórico
        notas[totalNotas] = novaNota;
        totalNotas++;

        // Localiza o índice da menor nota
        for (i = 1; i < totalNotas; i++) {
            if (notas[i] < notas[menorIndex]) {
                menorIndex = i;
            }
        }

        // Substitui a menor nota pela nova nota
        notas[menorIndex] = novaNota;

        // Calcula novamente a média apenas das duas melhores notas atuais
        media = (notas[0] + notas[1]) / 2;

        // Conta tentativa extra
        tentativasExtras++;
    }

    // Exibição dos resultados
    printf("\nMedia final: %.2f\n", media);
    printf("Tentativas extras realizadas: %d\n", tentativasExtras);

    // Estatísticas 

    // Calculando a média de todas as notas
    somaNotas = 0.0;
    for (i = 0; i < totalNotas; i++) {
        somaNotas += notas[i];
    }
    mediaNotas = somaNotas / totalNotas;

    // Calculando o desvio padrão
    somaNotas = 0.0;
    for (i = 0; i < totalNotas; i++) {
        somaNotas += (notas[i] - mediaNotas) * (notas[i] - mediaNotas);
    }
    desvioPadrao = sqrt(somaNotas / totalNotas);

    // Ordenando as notas para calcular a mediana
    for (i = 0; i < totalNotas - 1; i++) {
        for (int j = i + 1; j < totalNotas; j++) {
            if (notas[i] > notas[j]) {
                temp = notas[i];
                notas[i] = notas[j];
                notas[j] = temp;
            }
        }
    }

    // Calculando a mediana
    if (totalNotas % 2 == 0) {
        meio = totalNotas / 2;
        mediana = (notas[meio - 1] + notas[meio]) / 2;
    } else {
        meio = totalNotas / 2;
        mediana = notas[meio];
    }

    printf("\nEstatísticas das notas:\n");
    printf("Media das notas: %.2f\n", mediaNotas);
    printf("Mediana das notas: %.2f\n", mediana);
    printf("Desvio padrao das notas: %.2f\n", desvioPadrao);

    return 0;
}
