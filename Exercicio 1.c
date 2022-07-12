#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limpa.h>


//região de declaração de funções
void asterisc(int quantidade);
void mostraMenu();
void perguntaOperacao(int *operacao);
int validaODia(int anoBiss, int recebeDiaParaValidar, int mes);


//tipo do cadastro dos clientes definido
typedef struct{
    char nome[30];
    char CPF[12];
    char endereco[30];
    char bairro[20];
    int diaNascimento, anoNascimento, mesNascimento, diaUltimaCompra, mesUltimaCompra, anoUltimaCompra;
    float valorAcumuladoComprado;
    char nascimentoFinal[11];
    char ultimaCompraFinal[11];
}clientes;




int main(){
    int operacaoNaMain, diaUltimaCompraTeclado, mesUltimaCompraTeclado, anoUltimaCompraTeclado,i, moradoresBairro=0, anoBissOuNao;
    float maiorValorAcumulado;
    char recebeLinha[300], *divisaoDaLinhaDoArquivo[9], recebeBairro[20],pessoaComMaiorValorAcumulado[30];
    FILE *limparArquivo;
    FILE *recebeArquivo;
    clientes cadastroPessoas;

     mostraMenu();
     perguntaOperacao(&operacaoNaMain);

     //cria/limpa o arquivo antes de utilizar, para evitar sujeira de memória em execuções em sequência
     limparArquivo = fopen("dados_clientes.txt", "w+");

     if(limparArquivo == NULL){                             //testa se o arquivo foi aberto
         printf("\nArquivo teve problemas para abrir!");
     }else{
         printf("\nArquivo aberto para limpeza sem problemas!");
     }
  
     fclose(limparArquivo);

        //estrutura de fluxo das opcoes menu principal
     while(operacaoNaMain !=5){
        switch(operacaoNaMain){
            case 1:  
              recebeArquivo = fopen("dados_clientes.txt", "a+"); //abre o arquivo
             
              if(recebeArquivo == NULL){                           //testa se ele foi aberto
                 printf("\nArquivo teve problemas para abrir!");
              }else{
                 printf("\nArquivo para cadastro aberto sem problemas!");
               }

                //coletando e validando os dados
                printf("\n Cadastrando cliente:");
                printf("\n Digite o nome do cliente: ");
                gets(cadastroPessoas.nome);
                gets(cadastroPessoas.nome);
                
                printf("\n Digite o cpf do cliente: ");
                gets(cadastroPessoas.CPF);

                while(strlen(cadastroPessoas.CPF)!= 11){                      //valida a quantidade de algarismos no cpf
                    printf("\n Nao existe um cpf com menos de 11 algarismos!");
                    printf("\n Digite o cpf do cliente: ");
                    gets(cadastroPessoas.CPF);
                }
                
                printf("\n Digite o endereco do cliente(Pais,Estado,Cidade): ");
                gets(cadastroPessoas.endereco);

                printf("\n Digite o nome do bairro do cliente: ");
                gets(cadastroPessoas.bairro);

                printf("\n Digite a data de nascimento do cliente:");
                printf("\n Ano: ");
                scanf("%d", &cadastroPessoas.anoNascimento);
                while(cadastroPessoas.anoNascimento>2022){
                    printf("Nao acredito que nasceste no futuro, digite um ano valido:");
                    printf("\n Ano: ");
                    scanf("%d", &cadastroPessoas.anoNascimento);
                }

                if(cadastroPessoas.anoNascimento %4 == 0){
                    if(cadastroPessoas.anoNascimento%100==0&&cadastroPessoas.anoNascimento %400 !=0){
                         anoBissOuNao = 28;
                    }else{
                        anoBissOuNao = 29;
                    }
                }else{
                    anoBissOuNao = 28;
                }


                printf("\n Mes: ");
                scanf("%d", &cadastroPessoas.mesNascimento);
                while(cadastroPessoas.mesNascimento>12 || cadastroPessoas.mesNascimento < 0){
                    printf("Digite um mes valido!");
                    printf("\n Mes: ");
                    scanf("%d", &cadastroPessoas.mesNascimento);
                }

                printf("\n Dia: ");
                scanf("%d", &cadastroPessoas.diaNascimento);
                while(cadastroPessoas.diaNascimento>31 || cadastroPessoas.diaNascimento < 0){
                    printf("Digite um dia valido!");
                    printf("\n Dia: ");
                    scanf("%d", &cadastroPessoas.diaNascimento);
                }
           
                cadastroPessoas.diaNascimento = validaODia(anoBissOuNao,cadastroPessoas.diaNascimento,cadastroPessoas.mesNascimento);



              
                printf("\n Digite a data de ultima compra do cliente:");
                printf("\n Ano: ");
                scanf("%d", &cadastroPessoas.anoUltimaCompra);
                while(cadastroPessoas.anoUltimaCompra>2022 || cadastroPessoas.anoUltimaCompra < cadastroPessoas.anoNascimento){
                    printf("Nao acredito que compraste no futuro ou antes de nascer, digite um ano valido:");
                    printf("\n Ano: ");
                    scanf("%d", &cadastroPessoas.anoUltimaCompra);
                }

                if(cadastroPessoas.anoUltimaCompra %4 == 0){
                    if(cadastroPessoas.anoUltimaCompra%100==0&&cadastroPessoas.anoUltimaCompra %400 !=0){
                        anoBissOuNao = 28;
                    }else{
                        anoBissOuNao = 29;
                    }
                }else{
                    anoBissOuNao = 28;
                }

                printf("\n Mes: ");
                scanf("%d", &cadastroPessoas.mesUltimaCompra);
                while(cadastroPessoas.mesUltimaCompra>12 || cadastroPessoas.mesUltimaCompra < 0){
                    printf("Digite um mes valido!");
                    printf("\n Mes: ");
                    scanf("%d", &cadastroPessoas.mesUltimaCompra);
                }
                printf("\ndia: ");
                scanf("%d", &cadastroPessoas.diaUltimaCompra);
               
                cadastroPessoas.diaUltimaCompra = validaODia(anoBissOuNao,cadastroPessoas.diaUltimaCompra,cadastroPessoas.mesUltimaCompra);

                printf("\n Digite o valor acumulado comprado pelo cliente: ");
                scanf("%f", &cadastroPessoas.valorAcumuladoComprado);
                while(cadastroPessoas.valorAcumuladoComprado<0){
                    printf("\n O cliente não pode ter um valor negativo de compras acumuladas: ");
                    scanf("%f", &cadastroPessoas.valorAcumuladoComprado);
                }
                
                //apenas para utilizar um valor existente no arquivo para comparação e não um valor arbitrário
                maiorValorAcumulado = cadastroPessoas.valorAcumuladoComprado;
                
                //salvando dados coletados no arquivo que está formatado como csv
                fprintf(recebeArquivo,"%s;",cadastroPessoas.nome);
                fprintf(recebeArquivo,"%s;",cadastroPessoas.CPF);
                fprintf(recebeArquivo,"%s;",cadastroPessoas.endereco);
                fprintf(recebeArquivo,"%s;",cadastroPessoas.bairro);
                fprintf(recebeArquivo,"%d;",cadastroPessoas.diaUltimaCompra);
                fprintf(recebeArquivo,"%d;",cadastroPessoas.mesUltimaCompra);
                fprintf(recebeArquivo,"%d;",cadastroPessoas.anoUltimaCompra);
                fprintf(recebeArquivo,"%f\n",cadastroPessoas.valorAcumuladoComprado);
                //para que não haja erro caso a última pessoa seja a com o maior valor
                strcpy(pessoaComMaiorValorAcumulado, cadastroPessoas.nome);

               fclose(recebeArquivo);
               mostraMenu();
               perguntaOperacao(&operacaoNaMain); 
                break;
            case 2:
                //opção para consultar lista de clientes por data
                recebeArquivo = fopen("dados_clientes.txt", "r");
                if(recebeArquivo == NULL){                           //testa se ele foi aberto
                 printf("\nArquivo teve problemas para abrir!");
              }else{
                //coleta os dados para comparação
                printf("\nDigite a data em que deseja saber se ha compras registradas: ");
                printf("\n Ano: ");
                scanf("%d", &anoUltimaCompraTeclado);

                   while(anoUltimaCompraTeclado>2022){
                    printf("Nao acredito que nasceste no futuro, digite um ano valido:");
                    printf("\n Ano: ");
                    scanf("%d", &anoUltimaCompraTeclado);
                }

                 if(anoUltimaCompraTeclado %4 == 0){
                    if(anoUltimaCompraTeclado%100==0&&anoUltimaCompraTeclado%400 !=0){
                         anoBissOuNao = 28;
                    }else{
                        anoBissOuNao = 29;
                    }
                    
                }else{
                    anoBissOuNao = 28;
                }


                printf("\n Mes: ");
                scanf("%d", &mesUltimaCompraTeclado);
                 while(mesUltimaCompraTeclado>12 || mesUltimaCompraTeclado < 0){
                    printf("Digite um mes valido!");
                    printf("\n Mes: ");
                    scanf("%d", &mesUltimaCompraTeclado);
                }

                printf("\n Dia: ");
                scanf("%d", &diaUltimaCompraTeclado);
                while(diaUltimaCompraTeclado>31 || diaUltimaCompraTeclado < 0){
                    printf("Digite um dia valido!");
                    printf("\n Dia: ");
                    scanf("%d", &diaUltimaCompraTeclado);
                }
             
                diaUltimaCompraTeclado = validaODia(anoBissOuNao,diaUltimaCompraTeclado,mesUltimaCompraTeclado);

                while(!feof(recebeArquivo)){            //lendo o arquivo linha por linha e colocando num vetor de ponteiros cada divisão da string 
                    fgets(recebeLinha,300,recebeArquivo);

                    divisaoDaLinhaDoArquivo[0] = strtok(recebeLinha, ";");  //dividindo a linha do arquivo
                     for(i=1;i<9;i++){
                       divisaoDaLinhaDoArquivo[i] = strtok(NULL, ";"); 
                     } 
                    //procurando se existe registro de compras naquele dia
                    if(diaUltimaCompraTeclado == atoi(divisaoDaLinhaDoArquivo[4]) && mesUltimaCompraTeclado == atoi(divisaoDaLinhaDoArquivo[5]) && anoUltimaCompraTeclado == atoi(divisaoDaLinhaDoArquivo[6])){
                        printf("\nEncontrado o cliente: ");
                        printf("\nNome: %s", divisaoDaLinhaDoArquivo[0]);
                        printf("\nCPF: %s", divisaoDaLinhaDoArquivo[1]);
                        printf("\nEndereco: %s", divisaoDaLinhaDoArquivo[2]);
                    }
                }
                fclose(recebeArquivo);
                mostraMenu();
                perguntaOperacao(&operacaoNaMain); 
                break;
              }
            case 3:
                //opcao que contabiliza quantas pessoas moram em certo bairro
                 recebeArquivo = fopen("dados_clientes.txt", "r");
              if(recebeArquivo == NULL){                           //testa se ele foi aberto
                 printf("\nArquivo teve problemas para abrir!");
              }else{
                printf("\nInforme qual bairro deseja pesquisar em nossos registros: ");
                gets(recebeBairro);
                gets(recebeBairro);
                                                    //lendo o arquivo novamente
                while(!feof(recebeArquivo)){
                    fgets(recebeLinha,300,recebeArquivo);

                    divisaoDaLinhaDoArquivo[0] = strtok(recebeLinha, ";");
                     for(i=1;i<9;i++){
                       divisaoDaLinhaDoArquivo[i] = strtok(NULL, ";"); 
                     } 
            

                    if(divisaoDaLinhaDoArquivo[3] != NULL){
                        if(strcmp(recebeBairro,divisaoDaLinhaDoArquivo[3]) == 0){
                        moradoresBairro++;
                    }
                    }
                }
            }
                printf("\nExiste(m) %d pessoa(m) registrada(s) morando nesse bairro!", moradoresBairro);
                moradoresBairro = 0;
                fclose(recebeArquivo);
                mostraMenu();
                perguntaOperacao(&operacaoNaMain); 
                break;
            case 4:
                    //opção que revela a pessoa com o maior valor acumulado no arquivo
                    recebeArquivo = fopen("dados_clientes.txt", "r");
              if(recebeArquivo == NULL){                           //testa se ele foi aberto
                 printf("\nArquivo teve problemas para abrir!");
              }else{

                while(!feof(recebeArquivo)){                //lendo o arquivo
                    fgets(recebeLinha,300,recebeArquivo);

                    divisaoDaLinhaDoArquivo[0] = strtok(recebeLinha, ";");
                     for(i=1;i<9;i++){
                       divisaoDaLinhaDoArquivo[i] = strtok(NULL, ";"); 
                     } 
                        if(atoi(divisaoDaLinhaDoArquivo[7])>maiorValorAcumulado){
                            strcpy(pessoaComMaiorValorAcumulado,divisaoDaLinhaDoArquivo[0]);
                        }
                }
            }
                printf("\nO cliente que tem o maior valor acumulado eh %s", pessoaComMaiorValorAcumulado);
                fclose(recebeArquivo);
                mostraMenu();
                perguntaOperacao(&operacaoNaMain); 
                break; 
              }
          }
     //finalizando o programa
    asterisc(20);
    printf("\nObrigado por utilizar dos nossos servicos!");
    asterisc(20);   

}



//função que imprime asteriscos
void asterisc(int quantidade){
    int i;
    printf("\n");
    for(i=0;i<quantidade;i++){
        printf("*");
    }
    printf("\n");

}

//função que mostra o menu
void mostraMenu(){
    asterisc(40);
    printf(" Menu de operacoes possiveis: ");
    printf("\n1.[Cadastrar cliente]");
    printf("\n2.[Listar clientes que fizeram compra em uma data especifica]");
    printf("\n3.[Quantos clientes moram em um bairro especifico]");
    printf("\n4.[Qual cliente tem o maior valor acumulado em compras]");
    printf("\n5.[Fim]");
    asterisc(40);
}

//função que pergunta e valida a operação
void perguntaOperacao(int *operacao){
    asterisc(20);  
    printf("\n");
    printf("Digite a operacao desejada: ");
     scanf("%d", operacao);
    asterisc(20);  
     while(*operacao<1 || *operacao>5){
        mostraMenu();
         printf("Digite uma operacao valida: ");
         scanf("%d", operacao);
      }
    asterisc(20);  

}

//função que valida o dia
int validaODia(int anoBiss, int recebeDiaParaValidar, int mes){

        switch(mes){
                
                    case 1:
                    while(recebeDiaParaValidar>31 || recebeDiaParaValidar < 0){
                    printf("Digite um dia valido!");
                    printf("\n Dia: ");
                    scanf("%d", &recebeDiaParaValidar);
                    }
                    break;

                    case 2:
                    while(recebeDiaParaValidar>anoBiss|| recebeDiaParaValidar < 0){
                    printf("Digite um dia valido!");
                    printf("\n Dia: ");
                    scanf("%d", &recebeDiaParaValidar);
                    }
                    break;
                    case 3:
                    while(recebeDiaParaValidar>31 || recebeDiaParaValidar < 0){
                    printf("Digite um dia valido!");
                    printf("\n Dia: ");
                    scanf("%d", &recebeDiaParaValidar);
                    }
                    break;

                    case 4:
                    while(recebeDiaParaValidar>30 || recebeDiaParaValidar < 0){
                    printf("Digite um dia valido!");
                    printf("\n Dia: ");
                    scanf("%d", &recebeDiaParaValidar);
                     }
                    break;

                    case 5:
                    while(recebeDiaParaValidar>31 || recebeDiaParaValidar < 0){
                    printf("Digite um dia valido!");
                    printf("\n Dia: ");
                    scanf("%d", &recebeDiaParaValidar);
                    }
                    break;

                    case 6:
                    while(recebeDiaParaValidar>30 || recebeDiaParaValidar < 0){
                    printf("Digite um dia valido!");
                    printf("\n Dia: ");
                    scanf("%d", &recebeDiaParaValidar);
                    }
                    break;

                    case 7:
                    while(recebeDiaParaValidar>31 || recebeDiaParaValidar < 0){
                    printf("Digite um dia valido!");
                    printf("\n Dia: ");
                    scanf("%d", &recebeDiaParaValidar);
                    }
                    break;

                    case 8:
                    while(recebeDiaParaValidar>31 || recebeDiaParaValidar < 0){
                    printf("Digite um dia valido!");
                    printf("\n Dia: ");
                    scanf("%d", &recebeDiaParaValidar);
                    }
                    break;

                    case 9:
                    while(recebeDiaParaValidar>30 || recebeDiaParaValidar < 0){
                    printf("Digite um dia valido!");
                    printf("\n Dia: ");
                    scanf("%d", &recebeDiaParaValidar);
                    }
                    break;

                    case 10:
                    while(recebeDiaParaValidar>31 || recebeDiaParaValidar < 0){
                    printf("Digite um dia valido!");
                    printf("\n Dia: ");
                    scanf("%d", &recebeDiaParaValidar);
                    }
                    break;

                    case 11:
                    while(recebeDiaParaValidar>30 || recebeDiaParaValidar < 0){
                    printf("Digite um dia valido!");
                    printf("\n Dia: ");
                    scanf("%d", &recebeDiaParaValidar);
                    }
                    break;

                    case 12:
                    while(recebeDiaParaValidar>31 || recebeDiaParaValidar < 0){
                    printf("Digite um dia valido!");
                    printf("\n Dia: ");
                    scanf("%d", &recebeDiaParaValidar);
                    }
                    break;

                }

    return recebeDiaParaValidar;
}

