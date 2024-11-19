#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cifradeHill(char mensagem[], int key[2][2], char resultado[]) {
    int len = strlen(mensagem);

    for (int i = 0; i < len - 1; i += 2) {
        int x = mensagem[i] - 'A';       
        int y = mensagem[i + 1] - 'A';  
        
        resultado[i] = ((key[0][0] * x + key[0][1] * y) % 26) + 'A';
        resultado[i + 1] = ((key[1][0] * x + key[1][1] * y) % 26) + 'A';
    }

    if (len % 2 != 0) {
        int x = mensagem[len - 1] - 'A';
        resultado[len - 1] = ((key[0][0] * x) % 26) + 'A';
    }
}

int main() {
    char mensagem[100];          
    char encriptado[100] = "";  
    int key[2][2] = { {3, 3},   
                      {2, 5} }; 

    char opcao = 'Y'; 

    while (opcao == 'Y' || opcao == 'y') {
        printf("Digite a mensagem a ser criptografada (somente letras): ");
        fgets(mensagem, sizeof(mensagem), stdin);

        mensagem[strcspn(mensagem, "\n")] = '\0';

        int contemNumeros = 0;
        for (int i = 0; mensagem[i] != '\0'; i++) {
            if (isdigit(mensagem[i])) {
                contemNumeros = 1;
                break;
            }
        }

        if (contemNumeros) {
            printf("Erro: A mensagem não pode conter números. Tente novamente.\n\n");
            continue; 
        }

        int j = 0;
        for (int i = 0; mensagem[i] != '\0'; i++) {
            if (isalpha(mensagem[i])) {
                mensagem[j++] = toupper(mensagem[i]);
            }
        }
        mensagem[j] = '\0';

        printf("Mensagem ajustada: %s\n", mensagem);

        cifradeHill(mensagem, key, encriptado);

        printf("Mensagem criptografada: %s\n", encriptado);

        
        printf("\nDeseja criptografar outra mensagem? (Y/N): ");
        scanf(" %c", &opcao);
        getchar(); 
    }

    printf("Programa encerrado! \n");
    return 0;
}
