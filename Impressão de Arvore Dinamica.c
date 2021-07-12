#include<stdio.h>
#include<stdlib.h>

typedef struct item{
	int cod;
}Item;

typedef struct node{
	Item item;
	struct node *left;
	struct node *right;
}Node;

Node *tree_initialize(){
	return NULL;
}

void menu_aluno(void){
	printf("********************************************************************************");
	printf("Aluno:Lucas Vinícius Sampaio Lima                                 R.A:20026518-5Faculdade:Bacharelado em Engenharia de Software");
	printf("\n********************************************************************************\n\n");
	printf("");
}

void menu_mostrar(){
	printf("Menu da Arvore binaria\n\n1-Inserindo valores pre_definidos na arvore.\n2-Inserir um no manualmente. ");
	printf("\n3-Mostra arvore em modelo de piramide horizontal.\n4-Mostrar valores da arvore.\n0-Sair...\n\nEscolha uma opcao:");
}

Item itemCreate(int cod){
	Item item;
	item.cod=cod;
	return item;
}

//Inserindo um novo No na arvore, de forma dinamica, ela será odenada onde o valor menor ficaram para a esquerda e os maiores a direita.
Node *tree_insert(Node *root, Item x){
	if(root==NULL){
		Node *aux=(Node*)malloc(sizeof(Node));
		aux->item=x;
		aux->left=NULL;
		aux->right=NULL;
		return aux;
	}else{
		if(x.cod>root->item.cod){
		root->right=tree_insert(root->right, x);
	}else if(x.cod< root->item.cod){
			root->left=tree_insert(root->left, x);
	}
	return root;
	}
}

//Impressão simples da arvore
void tree_print(Node *root){
	if(root!=NULL){  
		printf("%d ", root->item.cod);
        tree_print(root->left);
		tree_print(root->right);
	} 
}

//Impresso do Nos da arvore em forma de piramede, os menores ficam para baixo e os maiores para cima
void print2DUtil(Node *root, int space){
   if (root == NULL){
    	return 0;
	}  
  	space += 5;
    print2DUtil(root->right, space);
    printf("\n");
    for (int i = 1; i < space; i++)
    printf(" ");
    
    printf("%d\n", root->item);
    
    print2DUtil(root->left, space);
}

void print2D(struct Node *root){
   print2DUtil(root, 0);
}

//liberação da arvore.
void tree_free(Node *root){
	if(root!=NULL){	
		tree_free(root->left);
		tree_free(root->right);
		free(root);
	}	
}

int main(){
	int opt,valor;
	Node *root = tree_initialize();
	do{
		system("cls");
		menu_aluno();
 		menu_mostrar();
		scanf("%d",&opt);
		
		switch(opt){
			case 1:
				system("cls");
				printf("Inserindo valores, aguarde...\n\n");
				root= tree_insert(root, itemCreate(30));
				root= tree_insert(root, itemCreate(15));
				root= tree_insert(root, itemCreate(35));
				root= tree_insert(root, itemCreate(36));
				root= tree_insert(root, itemCreate(34));
				root= tree_insert(root, itemCreate(8));
				root= tree_insert(root, itemCreate(16));
				system("pause");
			break;
				
			case 2:
				system("cls");
				printf("Insira um valor:");
				scanf("%d",&valor);
				root= tree_insert(root, itemCreate(valor));
				printf("\n");
				system("pause");
			break;
				
			case 3:
				system("cls");
				printf("Arvore Binaria, modelo de piramende horizontal\n\n"); 
				print2D(root);
				printf("\n");
				system("pause");
				break;
					
			case 4:
				system("cls");
				printf("Elementos integrados a arvore binaria:\n\n");
				tree_print(root);
				printf("\n\n");
				system("pause");
				break;
		}		
	}while(opt !=0);
	
	tree_free(root);
	system("pause");
	return 0;
}
