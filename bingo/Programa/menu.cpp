#include <iostream>
#include <vector>
#include "bingo.h"

using namespace std;

// Função que exibe o menu
void showMenu()
{
    cout << "===== Menu =====" << endl;
    cout << "1. Jogar" << endl;
    cout << "2. Sair" << endl;
    cout << "================" << endl;
    cout << "Escolha uma opcao: "; // Solicita que o usuário escolha uma opção
}

int main()
{
    int choice;  // Variável para armazenar a escolha do usuário
    bool exit = false; // Flag para controlar a saída do loop do menu

    // Loop do menu principal
    while (!exit)
    {
        showMenu();    // Exibe o menu
        cin >> choice; // Lê a escolha do usuário

        switch (choice)
        {
        case 1:
        // Iniciar o jogo de Bingo
        {
            int numPlayers; // Variável para armazenar o número de jogadores
            cout << "Digite o numero de jogadores: ";
            cin >> numPlayers; // Lê o número de jogadores

            vector<string> playerNames; // Vetor para armazenar os nomes dos jogadores
            
            // Loop para obter o nome de cada jogador
            for (int i = 0; i < numPlayers; ++i)
            {
                string name; // Variável para armazenar o nome de um jogado
                cout << "Digite o nome para o jogador " << i + 1 << ": ";
                cin >> name; // Lê o nome do jogador
                playerNames.push_back(name); // Adiciona o nome ao vetor de nomes dos jogadores
            }
            
            // Cria uma instância do jogo de Bingo com os nomes dos jogadores
            BingoGame game(playerNames);
            game.play(); // Inicia o jogo
            break;  // Sai do switch após iniciar o jogo
        }
        case 2:
            cout << "Saindo do jogo!" << endl;
            exit = true; // Define a flag de saída como verdadeira para sair do loop
            break;  // Sai do switch após definir a flag de saída
        default:
            // Opção invalida
            cout << "Opcao invalida, tente novamente:" << endl;
            // Exibe uma mensagem de erro se a escolha for inválida
        }
    }

    return 0; // Termina o programa
}
