#include <stdio.h>

#define MAX_ALUNOS 40
#define MAX_TURMAS 10
#define MAX_CURSOS 3

int main() {
    int l = 0;
    char nome[MAX_ALUNOS][40];
    int matricula[MAX_ALUNOS];
    int turma[MAX_TURMAS];
    char curso[MAX_CURSOS][40];
    
    while (l < MAX_ALUNOS) {
        printf("\nCADASTRO DE ALUNO (Aluno %d):", l + 1);
        
        printf("\nNOME: ");
        scanf("%39s", nome[l]); 
        
        printf("MATRICULA: ");
        scanf("%d", &matricula[l]);  
        
        printf("CURSO: ");
        scanf("%s", curso[l]);  
        
        printf("TURMA: ");
        scanf("%d", &turma[l]);

        l++;  
        
        int continuar;
        printf("Deseja cadastrar outro aluno? digite 1 para encerrar: ");
        scanf(" %d", &continuar);
        if (continuar == 1) {
            break; 
        }
    }
    
    printf("\nALUNOS CADASTRADOS:\n");
    for (int i = 0; i < l; i++) {
        printf("Aluno %d: Nome: %s, Matricula: %d, Curso: %s, Turma: %d\n", 
                i + 1, nome[i], matricula[i], curso[i], turma[i]);
    }

    return 0;
}
