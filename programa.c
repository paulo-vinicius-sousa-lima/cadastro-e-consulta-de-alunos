#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS (100)
#define MAX_STR (100)

#define NOME (0)
#define MATRICULA (1)
#define TURMA (2)
#define CURSO (3)


void cadastrarAluno(char alunos[MAX_ALUNOS][4][MAX_STR], int *quantidade) {
    if (*quantidade < MAX_ALUNOS) {
        printf("\nCADASTRAR ALUNO\n");
        printf("NOME COMPLETO: ");
        scanf(" %[^\n]", alunos[*quantidade][NOME]); 
        setbuf(stdin, NULL);
        printf("MATRICULA: ");
        scanf(" %[^\n]", alunos[*quantidade][MATRICULA]);
        setbuf(stdin, NULL); 
        printf("TURMA: ");
        scanf(" %[^\n]", alunos[*quantidade][TURMA]); 
        setbuf(stdin, NULL);
        printf("CURSO: ");
        scanf(" %[^\n]", alunos[*quantidade][CURSO]); 
        setbuf(stdin, NULL);

        (*quantidade)++;
        printf("\nAluno cadastrado com sucesso!\n");
    } else {
        printf("\nLimite de alunos atingido!\n");
    }
}

void consultarAluno(char alunos[MAX_ALUNOS][4][MAX_STR], int quantidade) {
    int opConsulta;
    char busca[MAX_STR];
    int encontrado = 0;

    if (quantidade == 0) {
        printf("\nNenhum aluno cadastrado!\n");
        return;
    }

    printf("\nCONSULTAR ALUNO\n");
    printf("1. CONSULTAR POR NOME\n2. CONSULTAR POR MATRICULA\n\n");
    scanf("%d", &opConsulta);
    setbuf(stdin, NULL);

    switch (opConsulta) {
    case 1:
        printf("\nDigite o nome do aluno: ");
        scanf(" %[^\n]", busca);

        for (int i = 0; i < quantidade; i++) {
            if (strcmp(alunos[i][NOME], busca) == 0) {
                printf("\nAluno encontrado:\n");
                printf("Nome: %s\n", alunos[i][NOME]);
                printf("Matricula: %s\n", alunos[i][MATRICULA]);
                printf("Turma: %s\n", alunos[i][TURMA]);
                printf("Curso: %s\n", alunos[i][CURSO]);
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("\nAluno nao encontrado.\n");
        }
        break;

    case 2:
        printf("\nDigite a matricula do aluno: ");
        scanf(" %[^\n]", busca);
        setbuf(stdin, NULL);

        for (int i = 0; i < quantidade; i++) {
            if (strcmp(alunos[i][MATRICULA], busca) == 0) {
                printf("\nAluno encontrado:\n");
                printf("Nome: %s\n", alunos[i][NOME]);
                printf("Matricula: %s\n", alunos[i][MATRICULA]);
                printf("Turma: %s\n", alunos[i][TURMA]);
                printf("Curso: %s\n", alunos[i][CURSO]);
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("\nAluno nao encontrado.\n");
        }
        break;

    default:
        printf("\nOpcao de consulta invalida!\n");
        break;
    }
}

int main() {
    char alunos[MAX_ALUNOS][4][MAX_STR]; 
    int quantidade = 0;
    int op;

    do {
        printf("\nESCOLHA:\n  1. CADASTRAR ALUNO\n  2. CONSULTAR\n  3. SAIR\n\n");
        scanf("%d", &op);
        setbuf(stdin, NULL);

        switch (op) {
        case 1:
            cadastrarAluno(alunos, &quantidade);
            break;
        case 2:
            consultarAluno(alunos, quantidade);
            break;
        case 3:
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("\nOPCAO INVALIDA\n");
            continue;
        }
    } while (op != 3);

    return 0;
}
