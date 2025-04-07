#include <iostream>
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()

using namespace std;

// Função para preencher o baralho com as cartas (Matriz 2x52)
void preencherBaralho(string baralho[2][52]) {
    string naipes[4] = {"1", "2", "3", "4"}; // 1-Copas, 2-Paus, 3-Ouro, 4-Espada
    string valores[13] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13"};
    
    int index = 0;
    for (int b = 0; b < 2; b++) { // Para cada baralho (0 e 1)
        index = 0; // Resetar o índice para cada baralho
        for (int n = 0; n < 4; n++) { // Para cada naipe
            for (int v = 0; v < 13; v++) { // Para cada valor
                baralho[b][index++] = naipes[n] + "-" + valores[v] + "-" + to_string(b + 1);
            }
        }
    }
}

// Função para embaralhar as cartas (Vetor de 104 elementos)
void embaralharCartas(string baralho[2][52], string cartasEmbaralhadas[104]) {
    int index = 0;
    // Copiar todas as cartas para um vetor linear
    for (int b = 0; b < 2; b++) {
        for (int c = 0; c < 52; c++) {
            cartasEmbaralhadas[index++] = baralho[b][c];
        }
    }
    // Embaralhar usando randomização
    for (int i = 103; i > 0; i--) {
        int j = rand() % (i + 1); // Índice aleatório
        swap(cartasEmbaralhadas[i], cartasEmbaralhadas[j]); // Trocar posições
    }
}

// Função para distribuir as cartas (Matriz 4x11)
void distribuirCartas(string cartasEmbaralhadas[104], string maos[4][11]) {
    int index = 0;
    for (int c = 0; c < 11; c++) { // Para cada carta
        for (int j = 0; j < 4; j++) { // Para cada jogador
            maos[j][c] = cartasEmbaralhadas[index++];
        }
    }
}

// Função para exibir as mãos dos jogadores (Matriz 4x11)
void exibirMaos(string maos[4][11]) {
    for (int j = 0; j < 4; j++) {
        cout << "Mao do Jogador " << j + 1 << ": ";
        for (int c = 0; c < 11; c++) {
            cout << maos[j][c] << " ";
        }
        cout << endl;
    }
}

// Função principal
int main() {
    // Inicializar o gerador de números aleatórios
    srand(time(0));

    // Declaração das variáveis
    string baralho[2][52];          // Matriz para os dois baralhos
    string cartasEmbaralhadas[104]; // Vetor para as cartas embaralhadas
    string maos[4][11];             // Matriz para as mãos dos jogadores

    // Preencher o baralho
    preencherBaralho(baralho);

    // Embaralhar as cartas
    embaralharCartas(baralho, cartasEmbaralhadas);

    // Distribuir as cartas
    distribuirCartas(cartasEmbaralhadas, maos);

    // Exibir as mãos dos jogadores
    exibirMaos(maos);

    return 0;
}