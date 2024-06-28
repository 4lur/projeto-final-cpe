#ifndef BINGO_H
#define BINGO_H

#include <vector>
#include <string>

using namespace std;

const int size = 5;
const int max_number = 75;

// Classe BingoCard representa uma cartela de Bingo
class BingoCard
{
private:
    vector<vector<int>> card;       // Matriz para armazenar os números da cartela
    vector<vector<bool>> marked;    // Matriz para armazenar os números marcados

public:
    BingoCard();                                       // Contrutor
    void generateCard();                               // Gera a carrtela com números aleatórios
    void displayCard();                                // Exibe a cartela 
    bool markNumber(int number);                       // Marca um número na cartela
    bool checkWin();                                   // Verifica se há uma vitoria
    bool operator==(const BingoCard &other) const;     // Sobrecarga do aoperador de comparador para cartelas
};

// Classe Player representa um jogador no jogo de Bingo
class Player
{
public:
    string name;    // Nome do jogador
    BingoCard card; // Cartela do jogador

    Player(const string &name);
};

// Classe BingoGame representa o jogo de Bingo
class BingoGame
{
private:
    vector<Player> players;   // Vetor de jogadores
    vector<int> numbersDrawn; // Vetor para armazenar os números sorteados

public:
    BingoGame(const vector<string> &playerNames);
    void play();

private:
    int drawsCount;                 // Contador de números sorteados
    int drawNumber();               // Sorteia um número
    BingoCard generateUniqueCard(); // Métodos para gerar uma cartela única
};

#endif // BINGO_H
