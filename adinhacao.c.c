#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main () {
    // ConfiguraÃ§Ã£o de localidade para exibir caracteres especiais 
    setlocale(LC_ALL, "Portuguese_Brazil");

    // CabeÃ§alho do Jogo
    printf("\n **************************************************** \n" );
    printf(" *         Bem Vindo Ao Jogo Do Robô!                   *\n " );
    printf("\n **************************************************** \n" );
    printf("\n");
    printf("                ______\n");
    printf("             .-'      -.\n");
    printf("            /            \\\n");
    printf("           |,  .-.  .-.  ,|\n");
    printf("           | )(_o/  \\o_)( |\n");
    printf("           |/     /\\     \\|\n");
    printf("           (_     ^^     _)\n");
    printf("            \\__|IIIIII|__/\n");
    printf("             | \\IIIIII/ |\n");
    printf("             \\          /\n");
    printf("              --------\n");
    printf("     O robô diz: \"Vamos ver se você consegue me derrotar!\"\n ");
   
    // InicializaÃ§Ã£o do gerador de nÃºmeros aleatÃ³rios com base no tempo atual
    srand(time(0));

    // Gera um nÃºmero aleatorio e define o nÃºmero secreto
    int numerosecreto = rand() % 100; // NÃºmero secreto entre 0 e 99         
    
    // DeclaraÃ§Ã£o das variÃ¡veis principais
    int chute;              // VariÃ¡vel para armazenar o chute do jogador       
    int tentativas = 1;    // Contador de tentativas
    double pontos = 1000;  // PontuaÃ§Ã£o inicial
    int acertou = 0;       // Indicador de acerto (0 = nÃ£o, 1 = sim)

    // SeleÃ§Ã£o de Dificuldade    
    int nivel;
    printf("Qual é o nivel de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);
    
    int numerodetentativas;

    switch (nivel) {
        case 1:
            numerodetentativas = 20; // FÃ¡cil
            break;

        case 2:
            numerodetentativas = 15; // MÃ©dio 
            break;

        default: 
            numerodetentativas = 6; // DifÃ­cil
            break;
    }
    
    // Loop principal para o jogo
    for(int i = 1; i <= numerodetentativas; i++) {
        printf("Tentativa %d\n", tentativas);
        printf("\nQual é o seu chute? ");

        // Leitura do chute do jogador
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        // ValidaÃ§Ã£o do nÃºmero negativo
        if (chute < 0) {
            printf("Eu sou um robô positivo! Números negativos não são aceitos. Tente novamente.\"\n");
            continue; // Pula para prÃ³xima iteraÃ§Ã£o do loop
        }
        
        // Verifica se o jogador acertou o nÃºmero secreto   
        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto; 
        
        if (acertou) {
            printf("\nParabéns! Você acertou!\n");
            break; // Sai do loop se o jogador acertar 
        } else if (maior) {
            printf("\nHahaha, seu chute foi maior que o número secreto!\n");
        } else {
            printf("\nHahaha, seu chute foi menor que o número secreto!\n");
        }

        // AtualizaÃ§Ã£o de tentativas e pontuaÃ§Ã£o
        tentativas++;
        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }

    // Exibe a mensagem final do jogo
    printf("\nFim de Jogo!");

    if (acertou) {
        printf("\nOh não, você ganhou!\n");
        printf("\nVocê acertou em %d tentativas\n", tentativas);
        printf("\nTotal de pontos: %.1f\n", pontos);

        // RobÃ´ triste na vitÃ³ria do jogador
        printf("                ______\n");
        printf("             .-'      -.\n");
        printf("            /            \\\n");
        printf("           |,  .-.  .-.  ,|\n");
        printf("           | )(@o/  \\o@)( |\n");
        printf("           |/     /\\     \\|\n");
        printf("           (_    snif    _)\n");
        printf("            \\__|IIIIII|__/\n");
        printf("             | \\IIIIII/ |\n");
        printf("             \\   ----   /\n");
        printf("              -----------\n");
        printf("     O robô diz: \"Oh não! Você me derrotou...\"\n");
    } else {
        // Mensagem de Derrota do jogador
        printf("                ______\n");
        printf("             .-'      -.\n");
        printf("            /            \\\n");
        printf("           |,  .-.  .-.  ,|\n");
        printf("           | )(@o/  \\o@)( |\n");
        printf("           |/     /\\     \\|\n");
        printf("           (_  hahaha!   _)\n");
        printf("            \\__|IIIIII|__/\n");
        printf("             | \\IIIIII/ |\n");
        printf("             \\   ----   /\n");
        printf("              -----------\n");
        printf("     O robô diz: \"Hahaha! Eu ganhei de você!\"\n");

        printf("\nTente de novo\n");
    }

    system("pause");

    return 0;
}
