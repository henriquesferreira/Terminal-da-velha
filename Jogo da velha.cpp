#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

//Area de definição de cabeçalhos de função
void Menu_inicial();

void limpa_tela(){
    system("CLS");
}

void iniciaTabuleiro(char tabuleiro[3][3]){

    int linha, coluna;

    for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 3; coluna++){
            tabuleiro[linha][coluna] = '-';
        }
    }

}

void exibeTabuleiro(char tabuleiro[3][3]){

     int linha, coluna;

     for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 3; coluna++){
            cout << tabuleiro[linha][coluna];
        }
        cout << "\n";
    }

}

//1 = X venceu, 2 = O venceu, 0 = nada aconteceu
int confereTabuleiro(char tabuleiro[3][3]){

        int linha, coluna;

        //Confere linhas
        for(linha = 0; linha < 3; linha++){
            if(tabuleiro[linha][0] == 'X' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
                return 1;
            }else if(tabuleiro[linha][0] == 'O' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
                return 2;
            }
        }

        //Confere colunas
        for(coluna = 0; coluna < 3; coluna++){
            if(tabuleiro[0][coluna] == 'X' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
                return 1;
            }else if(tabuleiro[0][coluna] == 'O' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
                return 2;
            }
        }

        //Confere Diagonal principal
        if(tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
            if(tabuleiro[0][0] == 'X'){
                return 1;
            }else{
                return 2;
            }
        }

        //Confere Diagonal secundaria
        if(tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
            if(tabuleiro[0][2] == 'X'){
                return 1;
            }else{
                return 2;
            }
        }

        return 0;
}

void exibeInstrucoes(){

    cout << "\nMapa de instrucoes:";
    cout << "\n 7 | 8 | 9";
    cout << "\n 4 | 5 | 6";
    cout << "\n 1 | 2 | 3";
    cout << "\n";
}

void jogo(string nomeDoJogadorUm, string nomeDoJogadorDois, int pontuacaoJogadorUm, int pontuacaoJogadorDois){

    ///Variaveis Gerais
    string nomeDoJogadorAtual;       //Nomes dos jogadores
    char tabuleiro[3][3];                                                //Tabuleiro do jogo
    int linha, coluna;                                                   //Variaveis auxiliares
    int linhaJogada, colunaJogada, posicaoJogada;                        //Posição em que o jogador posiciona sua marca
    int estadoDeJogo = 1;                                                //0 = Sem jogo, 1 = Em jogo;
    int turnoDoJogador = 1;                                              //1 = X, 2 = O;
    int rodada = 0;                                                      //Quantas vezes os jogadores jogaram  no total
    int opcao;                                                           //Opções de reinicio
    bool posicionouJogada;                                               //Verifica se o jogador colocou um marcador no tabuleiro

    iniciaTabuleiro(tabuleiro);

    while(rodada < 9 && estadoDeJogo == 1){

        limpa_tela();

        cout << "\nRodada: " << rodada << "\n";
        cout << "Pontucao: " << nomeDoJogadorUm << " " << pontuacaoJogadorUm << " x " << pontuacaoJogadorDois << " " << nomeDoJogadorDois << "\n";


        //Exibe tabuleiro na tela
        exibeTabuleiro(tabuleiro);

        //Exibe qual numero corresponde a qual posicao
        exibeInstrucoes();

        //Atualiza o nome do jogador atual
        if(turnoDoJogador == 1){

        nomeDoJogadorAtual = nomeDoJogadorUm;

    }else{

        nomeDoJogadorAtual = nomeDoJogadorDois;

    }

    posicionouJogada = false;

    //Matriz de posições posiveis
    int posicoes[9][2] = {{2,0}, {2,1}, {2,2}, {1,0}, {1,1}, {1,2}, {0,0}, {0,1}, {0,2}};

    while(posicionouJogada == false){

        cout << "\n" <<nomeDoJogadorAtual << " digite uma posicao conforme o mapa acima:";
        cin >> posicaoJogada;

        linhaJogada = posicoes[posicaoJogada-1][0];
        colunaJogada = posicoes[posicaoJogada-1][1];

        //Verifica se a função é vazia
        if(tabuleiro[linhaJogada][colunaJogada] == '-'){

            //Conseguiu posicionar um marcador
            posicionouJogada = true;

            //Verifica de quem é a vez de posicionar o marcador
            if(turnoDoJogador == 1){

                tabuleiro[linhaJogada][colunaJogada] = 'X';
                turnoDoJogador = 2;

            }else{

                tabuleiro[linhaJogada][colunaJogada] = 'O';
                turnoDoJogador = 1;

            }
        }
    }


    //Confere se o jogo acabou
    if(confereTabuleiro(tabuleiro) == 1){
        cout << "O jogador X venceu!";
        pontuacaoJogadorUm++;
        estadoDeJogo = 0;
    }else if(confereTabuleiro(tabuleiro) == 2){
        cout << "O jogador O venceu!";
        pontuacaoJogadorDois++;
        estadoDeJogo = 0;
    }

        rodada++;

    }

    cout << "\n";
    exibeTabuleiro(tabuleiro);
    cout << "Fim de jogo";

    cout << "\n que deseja fazer?";
    cout << "\n1-Continuar o jogo";
    cout << "\n2-Menu inicial";
    cout << "\n3-Sair";
    cin >> opcao;

    if(opcao == 1){
        jogo(nomeDoJogadorUm, nomeDoJogadorDois, pontuacaoJogadorUm, pontuacaoJogadorDois);
    }else if(opcao == 2){
        Menu_inicial();
    }

}

void Menu_inicial(){

    int opcao = 0;

    //Nomes do jogadores
    string nomeDoJogadorUm, nomeDoJogadorDois;

    while(opcao < 1 || opcao > 3){

        limpa_tela();

        cout << "Bem vindo ao jogo da velha";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";
        cout << "\nEscolha uma opcao e tecle ENTER ";
        cin >> opcao;

        switch(opcao){

            case 1:

                //Inicia o jogo
                cout << "Digite o nome do jogador 1: ";
                cin >> nomeDoJogadorUm;
                cout << "Digite o nome do jogador 2: ";
                cin >> nomeDoJogadorDois;

                jogo(nomeDoJogadorUm, nomeDoJogadorDois, 0, 0);

                break;

             case 2:

                cout << "Informacoes do jogo";

                break;

             case 3:

                cout << "Ate mais";

                break;
        }
    }

}

int main(){

    Menu_inicial();

    return 0;
}
