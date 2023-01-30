#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char nomeDoProduto[20];
    int quantidade;
    int situacao;
    int preco;


}lista;


int menu(){

    int opcao;

    printf("\n ----- MENU -----");
    printf("\n1- Inserir um item na lista de compras");
    printf("\n2- Inserir valor de um item ");
    printf("\n3- Inserir situacao de um item ");
    printf("\n4- Imprimir a lista de compras");
    printf("\n5- Finalizar o programa");

    printf("\n Qual opcao desejas? ");
    scanf("%d", &opcao);

    if(opcao<1 || opcao >5){
        printf("\n Qual opcao, dentro do menu, desejas? ");
        scanf("%d", &opcao);
    }

    return opcao;

}


void insereNaLista(){

    FILE *pontArq;
    lista novoProduto;

    pontArq = fopen("lista_de_compras.txt", "a+");

    printf("\n Qual o nome do produto que deseja comprar?");
    gets(novoProduto.nomeDoProduto);
    gets(novoProduto.nomeDoProduto);

    printf("\n Quantos desse produto pretende comprar?");
    scanf("%d", &novoProduto.quantidade);

    fprintf(pontArq,"%s;",novoProduto.nomeDoProduto);
    fprintf(pontArq,"%d;\n",novoProduto.quantidade);
   
    fclose(pontArq);

}


void imprimeLista(){
    FILE *pontArq;
    char recebeLinha[200], *vetPointer[4], *resulta;

    pontArq = fopen("lista_de_compras.txt", "a+");


    resulta = fgets(recebeLinha,200,pontArq);   

        vetPointer[0] = strtok(recebeLinha, ";");

        for(int i=1;i<4;i++){
            vetPointer[i] = strtok(NULL, ";"); 
        } 


    while(!feof(pontArq)){
        printf("\n\nNome do produto: %s", vetPointer[0]);
        printf("\nQuantidade de produtos a serem comprados: %s", vetPointer[1]);
        printf("\nPreco atual do produto: %s", vetPointer[2]);
        printf("\nSituacao do produto: %s", vetPointer[3]);
        resulta = fgets(recebeLinha,200,pontArq);

        vetPointer[0] = strtok(recebeLinha, ";");

        for(int i=1;i<4;i++){
            vetPointer[i] = strtok(NULL, ";"); 
        } 

    }
    fclose(pontArq);
}


void inserePreco(){
    FILE *arqAntigo, *arqNovo;
    int preco;
    char item[50], *resulta, recebeLinha[200], *vetPointer[4];

    printf("\n Deseja inserir o preco de qual item?");
    gets(item);
    gets(item);

    printf("\n Qual o preco do item?");
    scanf("%d", &preco);
    
   
    arqAntigo = fopen("lista_de_compras.txt", "a+");
    arqNovo = fopen("lista_de_compras_atualizada.txt", "w+");


    resulta = fgets(recebeLinha,200,arqAntigo);   

        vetPointer[0] = strtok(recebeLinha, ";");

        for(int i=1;i<4;i++){
            vetPointer[i] = strtok(NULL, ";"); 
        } 


    
    while(!feof(arqAntigo)){

        if(strcmp(item,vetPointer[0]) == 0){
        
            fprintf(arqNovo,"%s;",vetPointer[0]);
            fprintf(arqNovo,"%s;",vetPointer[1]);
            fprintf(arqNovo,"%d;",preco);
            fprintf(arqNovo,"%s;\n",vetPointer[3]);
            
        }else{
            fprintf(arqNovo,"%s;",vetPointer[0]);
            fprintf(arqNovo,"%s;",vetPointer[1]);
            fprintf(arqNovo,"%s;",vetPointer[2]);
            fprintf(arqNovo,"%s;\n",vetPointer[3]);
        }



        resulta = fgets(recebeLinha,200,arqAntigo);

        vetPointer[0] = strtok(recebeLinha, ";");

        for(int i=1;i<4;i++){
            vetPointer[i] = strtok(NULL, ";"); 
        } 

 
    }

    fclose(arqAntigo);
    fclose(arqNovo);

            arqNovo = fopen("lista_de_compras_atualizada.txt", "a+");
            arqAntigo = fopen("lista_de_compras.txt", "w+");
    
    
    
          resulta = fgets(recebeLinha,200,arqNovo);   

          vetPointer[0] = strtok(recebeLinha, ";");

        for(int i=1;i<4;i++){
            vetPointer[i] = strtok(NULL, ";"); 
        } 
    
    
    while(!feof(arqNovo)){
            fprintf(arqAntigo,"%s;",vetPointer[0]);
            fprintf(arqAntigo,"%s;",vetPointer[1]);
            fprintf(arqAntigo,"%s;",vetPointer[2]);
            fprintf(arqAntigo,"%s;\n",vetPointer[3]);


            resulta = fgets(recebeLinha,200,arqNovo);   

          vetPointer[0] = strtok(recebeLinha, ";");

            for(int i=1;i<4;i++){
                vetPointer[i] = strtok(NULL, ";"); 
            } 



    }

    fclose(arqAntigo);
    fclose(arqNovo);

}


void insereSituacao(){
    FILE *arqAntigo, *arqNovo;
    int preco;
    char item[50], *resulta, recebeLinha[200], *vetPointer[4];

    printf("\n Deseja inserir a situacao de qual item?");
    gets(item);
    gets(item);

    printf("\n Qual a situacao do item? [1-Esta disponivel, 2- Nao esta disponivel]: ");
    scanf("%d", &preco);
    
   
    arqAntigo = fopen("lista_de_compras.txt", "a+");
    arqNovo = fopen("lista_de_compras_atualizada.txt", "w+");


    resulta = fgets(recebeLinha,200,arqAntigo);   

        vetPointer[0] = strtok(recebeLinha, ";");

        for(int i=1;i<4;i++){
            vetPointer[i] = strtok(NULL, ";"); 
        } 


     
    while(!feof(arqAntigo)){


        if(strcmp(item,vetPointer[0]) == 0){

            fprintf(arqNovo,"%s;",vetPointer[0]);
            fprintf(arqNovo,"%s;",vetPointer[1]);
            fprintf(arqNovo,"%s;",vetPointer[2]);
            fprintf(arqNovo,"%d;\n",preco);

        }else{

            fprintf(arqNovo,"%s;",vetPointer[0]);
            fprintf(arqNovo,"%s;",vetPointer[1]);
            fprintf(arqNovo,"%s;",vetPointer[2]);
            fprintf(arqNovo,"%s;\n",vetPointer[3]);
        }



        resulta = fgets(recebeLinha,200,arqAntigo);

        vetPointer[0] = strtok(recebeLinha, ";");

        for(int i=1;i<4;i++){
            vetPointer[i] = strtok(NULL, ";"); 
        } 


    }

    fclose(arqAntigo);
    fclose(arqNovo);

            arqNovo = fopen("lista_de_compras_atualizada.txt", "a+");
            arqAntigo = fopen("lista_de_compras.txt", "w+");
    
    
    
          resulta = fgets(recebeLinha,200,arqNovo);   

          vetPointer[0] = strtok(recebeLinha, ";");

        for(int i=1;i<4;i++){
            vetPointer[i] = strtok(NULL, ";"); 
        } 
    
    
    while(!feof(arqNovo)){
            fprintf(arqAntigo,"%s;",vetPointer[0]);
            fprintf(arqAntigo,"%s;",vetPointer[1]);
            fprintf(arqAntigo,"%s;",vetPointer[2]);
            fprintf(arqAntigo,"%s;\n",vetPointer[3]);


            resulta = fgets(recebeLinha,200,arqNovo);   

          vetPointer[0] = strtok(recebeLinha, ";");

            for(int i=1;i<4;i++){
                vetPointer[i] = strtok(NULL, ";"); 
            } 



    }

    fclose(arqAntigo);
    fclose(arqNovo);







}


void main (){
    int opcao;

    opcao = menu();

    while(opcao != 5){

        switch(opcao){
            case 1:

            insereNaLista();


         
           opcao = menu();
           break;
            case 2:

            inserePreco();
         
           opcao = menu();
           break;
            case 3:

            insereSituacao();
         
           opcao = menu();
           break;
            case 4:

            imprimeLista();

           opcao = menu();
           break;
            default:
                printf("\n [ERROR] Digitou uma opcao invalida!");
            opcao = menu();


        }


    }

    printf("\n Finalizando o programa!");




}
