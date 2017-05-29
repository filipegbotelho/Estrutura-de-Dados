/*Nome1:Thayanna Klysnney Moreira Nunes
  Nome2:Filipe Gon�alves Botelho
  Mat1:16/0146232
  Mat2:16/0120276
  Curso:Computa��o(Noturno)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Lista{
	char novonome[20];
	char novoenderecoeletronico[20];
	char novotelefone[20];

	struct Lista *proximo;
};

typedef struct Lista L;
int Perguntas (L *LISTA);
void opcoes (int op, L *LISTA);
void inicia(L *LISTA);
void Inserir(L* LISTA);
int vazia(L *LISTA);
void mostrar (L *LISTA);
int buscar (L *LISTA);
void ordenar(L *LISTA);
void editar(L *LISTA);
void remover (L* LISTA);
int verificaduplicidade (L *LISTA, L* ListaInserir);

int main(){

   L *LISTA=(L*)malloc(sizeof(L));

	if(!LISTA){
    	printf("\t\t\t\t\t\tSem memoria!");
    	exit(1);
	}
	printf("\t\t\t\t\t      AGENDA TELEFONICA\n");
	int op;
	inicia(LISTA);
	do{
 	 op=Perguntas(LISTA);	   //esse while e para que seja sempre mostrado na tela as opcoes e tambem enviado para outra funcao a lista e tambem a opcao desejada do meu usuario
	 opcoes(op,LISTA);
	 #ifdef_WIN32
     system("cls");
     #else
     system("clear");
     #endif
	}while(op);

	return 0;
}

void inicia(L *LISTA){

  LISTA->proximo=NULL;

}

int Perguntas (L *LISTA){
  int op;

   printf("\t\t\t============================Opcoes============================\n");
   printf("\t\t\t\t\t\t(1)Inserir\n");
   printf("\t\t\t\t\t\t(2)Ordenar.\n");
   printf("\t\t\t\t\t\t(3)Listar.\n");
   printf("\t\t\t\t\t\t(4)Buscar.\n");
   printf("\t\t\t\t\t\t(5)Mostrar.\n");
   printf("\t\t\t\t\t\t(6)Editar.\n");
   printf("\t\t\t\t\t\t(7)Remover.\n");
   printf("\t\t\t\t\t\tResposta: ");
   scanf("%d",&op);

   return op;
}


void opcoes (int op, L *LISTA){
	 int p;
 switch (op){
 	case 1:
 		Inserir(LISTA);
 		break;
 	case 2:
 		ordenar(LISTA);
	    break;
	case 3:
		mostrar(LISTA);
	 	break;
	case 4:
		p=buscar(LISTA);
		 printf("\t\t\t\t\t\tO elemento procurado esta na posicao: %d\n",p); //Imprimo na tela a posi��o que estao o elemento que o usuario deseja buscar
		 break;
	case 5:
		mostrar(LISTA);
		break;
	case 6:
		editar(LISTA);
		break;
	case 7:
		remover(LISTA);
		break;
	default:
	 	printf("\t\t\t\t\t\tNem uma opcao valida!");

 }

}

void Inserir(L* LISTA){
   int x=1;
   L *ListaInserir=(L*)malloc(sizeof(L));

    if(!LISTA){
    	printf("\t\t\t\t\t\tSem memoria");
   		exit(1);
    }
    L* aux=LISTA->proximo;
	  fflush(stdin);
      printf("\t\t\t\t\t\tDigite outro nome: ");
	  //scanf("%s", ListaInserir->novonome);
		gets(ListaInserir->novonome);
	while(verificaduplicidade(LISTA,ListaInserir)) {
		fflush(stdin);
		printf("\t\t\t\tDigite nome com sobrenome, pois ja existe outra pessoa com esse nome: "); //verificando se ja existe alguem na lista com esse nome
	    //scanf("%s", ListaInserir->novonome);
		gets(ListaInserir->novonome);
	}


	printf("\t\t\t\t\t\tInsira o Email: ");
    //scanf("%s",ListaInserir->novoenderecoeletronico);
    gets(ListaInserir->novoenderecoeletronico);
	printf("\t\t\t\t\t\tInsira o Telefone: ");
    //scanf("%s",ListaInserir->novotelefone);

    gets(ListaInserir->novotelefone);
   ListaInserir->proximo=NULL; //apontando para NULL O proximo elemento, apos inserir o ultimo elemento

	 if(vazia(LISTA)){  //se a lista ainda nao tiver elementos, insiro no inicio
     	LISTA->proximo=ListaInserir;
	 }
	 else{
	 	L *aux;
	 	aux=LISTA->proximo;
	 	while(aux->proximo!=NULL){
	 		aux=aux->proximo;
		 }
	 	aux->proximo=ListaInserir; //Inserir no lugar de NULL. Lembrando que j� foi apontado l� em cima o pr�ximo elemento para NULL
	 }

 }

int vazia(L *LISTA){  //verifico se esta vazia a minha lista.
	if(LISTA->proximo==NULL){
		return 1; //verificando se a lista esta vazia
	}
	return 0;
}

void mostrar (L *LISTA){

	if(vazia(LISTA)){
		printf("\t\t\t\t\t\tNao tem o que mostrar esta tudo vazio, querido!");
		exit(1);
	}
	L*aux = LISTA->proximo;  //mostrando na tela os elementos da lista
	int cont=0;
    printf("\t\t\t==========================SUA AGENDA===========================\n");
	while(aux!=NULL){
		 //fun��o que mostra na tela os elementos da struct

		printf("\t\t\t\t\t\tElemento: %d\n\t\t\t\t\t\tNome: %s\n\t\t\t\t\t\tEndereco Eletronico: %s\n\t\t\t\t\t\tTelefone: %s\n",cont,aux->novonome,aux->novoenderecoeletronico,aux->novotelefone);
		aux=aux->proximo;
		cont++;
	}
	printf("\n");

}

int buscar (L *LISTA){
    L *achar=(L*)malloc(sizeof(L));
   int op,contposition=0;
       printf("\t\t\t==========================BUSCA============================\n");
     if(vazia(LISTA)){
     	printf("\t\t\t\t\t\tLista vazia, nao tem elemento a se buscar\n");
     	exit(1);
	 }
	 printf("\t\t\t\tVoce deseja buscar na lista por qual referencia:\n\t\t\t\t\t\t(1)Nome\n\t\t\t\t\t\t(2)Email\n\t\t\t\t\t\t(3)Telefone\n\t\t\t\t\t\tResposta: ");
	 scanf("%d",&op);
   switch(op){ 			//meu usuario pode buscar os elementos da agenda por telefone, nome, ou email.
   	 case 1:
   	 	fflush(stdin);
   	 	printf("\t\t\t\t\t\tDigite o nome completo desejado: ");
   	 	//scanf("%s",achar->novonome);
 		 gets(achar->novonome);
		   L *aux=LISTA->proximo;
		   while(aux!=NULL){
		   		contposition++;
				 if(strcmp(aux->novonome,achar->novonome)==0){ //funcao que busca semelhanca nas strings e verifica se sao iguais
				 return contposition;
				 }
				aux=aux->proximo;
		    }
   	 	break;
   	 case 2:
   	 	fflush(stdin);
		printf("\t\t\t\t\t\tDigite o email completo desejado: ");
   	 	//scanf("%s",achar->novoenderecoeletronico);
 		gets(achar->novoenderecoeletronico);
		   L *auxb=LISTA->proximo;
		   while(auxb!=NULL){
		   		contposition++;
				 if(strcmp(auxb->novoenderecoeletronico,achar->novoenderecoeletronico)==0){ //funcao que busca semelhanca nas strings e verifica se sao iguais
				 return contposition;
				 }
				auxb=auxb->proximo;
		    }
		break;
	 case 3:
	 	fflush(stdin);
	 	printf("\t\t\t\t\t\tDigite o telefone completo desejado: ");
   	 	//scanf("%s",achar->novotelefone);
 		 gets(achar->novotelefone);
		   L *auxc=LISTA->proximo;
		   while(auxc!=NULL){
		   		contposition++;
				 if(strcmp(auxc->novotelefone,achar->novotelefone)==0){ //funcao que busca semelhanca nas strings e verifica se sao iguais
				 return contposition;
				 }
				auxc=auxc->proximo;
		    }
	  	break;
     default :
	 	printf("\t\t\t\t\t\tOpcao invalida");
   }

}
void ordenar(L *LISTA){


	 if(vazia(LISTA)){
	 	printf("\t\t\t\t\t\tLista vazia");
	 	exit(1);
	 }
    //L *temp=(L*)malloc(sizeof(L));
     char tempn[20];
	 char tempe[20];
	 char tempt[20];
	  L *auxo;
      L *auxm;
      auxo=LISTA->proximo;
      auxm=auxo->proximo;


	 for(auxo=LISTA->proximo;auxo!=NULL;auxo=auxo->proximo){  //ordena��o de todos os dados inseridos de uma vez

 	  	for(auxm=auxo->proximo;auxm!=NULL;auxm=auxm->proximo){  //ordenando as strings usando as funcoes da biblioteca string.h

	 		if(strcmp(auxo->novonome,auxm->novonome) > 0){
                 strcpy(tempn,auxo->novonome);
                 strcpy(tempe,auxo->novoenderecoeletronico);
                 strcpy(tempt,auxo->novotelefone);

				 strcpy(auxo->novonome,auxm->novonome);
				 strcpy(auxo->novoenderecoeletronico,auxm->novoenderecoeletronico);
				 strcpy(auxo->novotelefone,auxm->novotelefone);

				 strcpy(auxm->novonome,tempn);
                 strcpy(auxm->novoenderecoeletronico,tempe);
                 strcpy(auxm->novotelefone,tempt);

			}
       }
    }
}

void editar(L *LISTA){

	char nome[20],newnome[20];
	int p,cont,x=0,op;

	 if(vazia(LISTA)){
	 	printf("\t\t\t\t\t\tLista esta vazia");
	 	exit(1);
	 }
	printf("\t\t\tAbaixo darei 3 opcoes para voce buscar o contato para editar!\n");
	p=buscar(LISTA);
	  L *troca=(L*)malloc(sizeof(L));

	  L *aux=LISTA->proximo;

	  while(aux!=NULL && x==0){
	  	cont++;
		if(p==cont){
		  printf("\t\t\t\t\t\t%s\n",aux->novonome);
		  printf("\t\t\t\t\t\t%s\n",aux->novoenderecoeletronico);
		  printf("\t\t\t\t\t\t%s\n",aux->novotelefone);
	 	  x=1; //fiz um elemento que faz com que o while acima seja falso em algum momento para poder sair do la�o e ir para o proximo passo da fun��o
	 	  continue;
		 }

	   aux=aux->proximo;
	  }
	  if(x==0){
	  	printf("\t\t\t\t\t\tNao existe esse elemento em sua agenda!");
	    exit(1);
	  }
   	  printf("\t\t\t\t\t\tVoce deseja editar : \n\t\t\t\t\t\t(1)Nome\n\t\t\t\t\t\t(2)Email\n\t\t\t\t\t\t(3)Telefone\n\t\t\t\t\t\t(4)Todos os dados\n\t\t\t\t\t\tEscolha: ");
   	  scanf("%d",&op);
	  switch(op){  //nessa parte do programa eu altero os elementos que meu usuario pede.
	  	 case 1:
	  	 	fflush(stdin);
	 		printf("\t\t\t\t\t\tNome atual %s\n",aux->novonome);
	 		printf("\t\t\t\t\t\tDigite o nome que substituira esse: ");		//ele pode querer alterar um elemento especifico, seja telefone ou nome ou email...Ou alterar todos. Deixo aberta essa op��o para ele
	 		//scanf("%s",aux->novonome);
			gets(aux->novonome);
			break;
	  	 case 2:
	  	 	fflush(stdin);
			printf("\t\t\t\t\t\tEndereco atual %s\n",aux->novoenderecoeletronico);
	 		printf("\t\t\t\t\t\tDigite o nome que substituira esse: ");
	 		//scanf("%s",aux->novoenderecoeletronico);
		   	gets(aux->novoenderecoeletronico);
			   break;
		 case 3:
		 	fflush(stdin);
			printf("\t\t\t\t\t\tTelefone atual %s\n",aux->novotelefone);
	 		printf("\t\t\t\t\t\tDigite o nome que substituira esse: ");
	 		//scanf("%s",aux->novotelefone);
		 	gets(aux->novotelefone);
			break;
		 case 4:
		 	fflush(stdin);
		 	printf("\t\t\t\t\t\tNome atual %s\n",aux->novonome);
	 		printf("\t\t\t\t\t\tDigite o nome que substituira esse: ");
	 		//scanf("%s",aux->novonome);
	 		gets(aux->novonome);
		 	fflush(stdin);
			printf("\t\t\t\t\t\tEndereco atual %s\n",aux->novoenderecoeletronico);
	 		printf("\t\t\t\t\t\tDigite o endereco que substituira esse: ");
	 		//scanf("%s",aux->novoenderecoeletronico);
		 	gets(aux->novoenderecoeletronico);
			fflush(stdin);
			printf("\t\t\t\t\t\tTelefone atual %s\n",aux->novotelefone);
	 		printf("\t\t\t\t\t\tDigite o telefone que substituira esse: ");
	 		//scanf("%s",aux->novotelefone);
	 		gets(aux->novotelefone);
			break;
		 default:
		  printf("\t\t\t\t\t\tOpcao invalida");
	  }

}
void remover (L* LISTA){

    int cont=1, x=0,p;
    if(vazia(LISTA)){
    	printf("\t\t\t\t\t\tLista esta vazia,nao tem elemento para remover.");  //Remover um elemento , uso o mesmo que em uma lista encadeada normal. Dou um free no final , no elemento que desejam remover da lista
    	exit(1);
	}
    L *rem=(L*)malloc(sizeof(L));
    printf("\t\t\t\t\t\tDarei algumas opcoes:\n ");
    p=buscar(LISTA);

	L *aux=LISTA;
	L *auxprox=LISTA->proximo;
	  while(p!=cont){ //nessa e em algumas outras funcoes eu uso a propria funcao de busca, onde pego a variavel p e uso para marcar onde esta o elemento que desejo ou remover ou alterar.

		  aux=auxprox;
	      auxprox=auxprox->proximo;
		  cont++;
		 }
	   aux->proximo=auxprox->proximo;
	   free(auxprox);
 }

int verificaduplicidade (L *LISTA, L* ListaInserir)	{
	L *aux=LISTA->proximo;
	 while(aux!=NULL){
	 	if(strcmp(ListaInserir->novonome,aux->novonome)==0){ //funcao que retorna se existe ou nao alguem com o mesmo nome do que estao dando entrada no sistema
	 		return 1;
		 }
		 aux=aux->proximo;
	 }
	 return 0;

}
