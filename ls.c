/*
CHAMADA ls - Lista os arquivos localizados em um determinado diretório. 
            Caso não seja especificado o diretório, usa
            o diretório de trabalho atual, que pode ser recuperado pela chamada de 
            sistema getcwd().
*/
#include <stdio.h> // entrada e saída em c
#include <dirent.h> // manipulação de diretórios
#include <stdlib.h> // funções como alocação de memória, conversão de números etc

// uso e chamadas de sistema opendir, readdir e closedir.

// código em si

/*
    parâmetros da função main() 

    agrc - inteiro que representa o num de argumentos passados (argument count)
    argv - array de strings  (argument )
*/

int main(int argc, char *argv[]){ // argumentos da função main
    // declaração de uma variável que é uma estrutura de dados usada para representar um diretório, sendo usada para manipulações e abrir
    DIR *dir;
    // declaração de uma var do tipo struct dirent, que contem informações sobre UM arquivo no diretório, ela lerá todos os nomes dos arquivos do diretório
    struct dirent *entry;
    // testa os argumentos
    if(argc != 2){
        printf("Não é possível executar com os dados fornecidos:\n");
        // função de c para imprimir dados formatados em um arquivo de saída - fprintf
        fprintf(stderr, "Comando esperado: %s <diretório>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // tentativa de abrir o diretório especificado
    dir = opendir(argv[1]); 
    if( dir  == NULL ){// se não for possível abrir o diretório
        perror("opendir");
        exit(EXIT_FAILURE);
    }
    // leitura dos nomes dos arquivos
    while( (entry = readdir(dir)) != NULL){
        printf("%s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}