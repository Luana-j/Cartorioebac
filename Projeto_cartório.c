#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //bibliotexa de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // Fun��o responsavel por cadastrar o usuario no sistemas
{
	// inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��es do usu�rio
	scanf("%s",cpf); //%s para armazenar os dados da string
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das string, para puxar o mesmo valor
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	
	file = fopen(arquivo,"a"); //altera o arquivo
	fprintf(file,",");
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Mensagem solicitando ao usuario para digitar o nome
	scanf("%s", nome); //salvando o conteudo dentro da variavel nome
	
	file = fopen(arquivo,"a"); //abrindo o arquivo e alterando/salvando o conteudo dentro da variavel nome
	fprintf(file,nome);
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,","); 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause"); //para pausar o sistema
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //para colocar acentos do Brasil, definindo a linguagem
	
	char cpf [40]; //essa variavel � a onde a gente vai armazenas a resposta do usuario
	char conteudo[200]; //� a onde a gente vai armazenar o conteudo que esta dentro do arquivo, nesse caso, o cpf
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // o r � para ler o que esta dentro do arquivo cpf
	
	if(file == NULL) // se ele procurar e n�o encontrar o arquivo, ele � nulo
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n"); //se for nulo, dar� essa msg
	}
	
	while(fgets(conteudo, 200, file) != NULL) //while � enquanto, enquanto procura
	printf("\nEssas s�o as informa��es do usu�rio: "); //esta escrevendo para o usuario as informa��es solicitadas
	printf("%s", conteudo); // printf ao inves de scanf, pois queremos mostrar o conteudo e nao salvar
	printf("\n\n");
	
	system("pause");
		
}

int deletar()
{
	char cpf[40]; //string cpf
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // usuario vai digitar o cpf a ser deletado
	scanf("%s", cpf); // vamos scanear e armazenas dentro da string cpf
	
	remove(cpf); // para deletar caso encontrar o cpf for encontrado
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main ()
	{
	int opcao=0; // definindo as variaveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao; 
	
	printf("### Cartorio da EBAC ### \n\n");
	printf("Login de administrador \n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
		system ("cls");
	
		for(laco=1;laco=1;)
		{
		
			system("cls"); //deleta todas as mensagens que tinha antes
	
		
			setlocale(LC_ALL, "Portuguese"); //para colocar acentos do Brasil, definindo a linguagem
		
			printf("### Cartorio da EBAC ### \n\n"); //inicio do menu
			printf("Escolha a op��o desejada do menu: \n\n"); //escrevendo para o cliente
			printf("\t 1 - Registrar nomes\n"); //escrevendo para o cliente
			printf("\t 2 - Consultar os nomes\n"); //escrevendo para o cliente
			printf("\t 3 - Deletar nomes\n"); //escrevendo para o cliente
			printf("\t 4 - Sair do sistema \n\n");
			printf("Op��o: "); //fim do menu
		
			scanf("%d", &opcao); //armazenando a escolha do usuario
		
			system("cls"); //deleta todas as mensagens que tinha antes
				
			switch(opcao) //para o programa ficar mais limpo e leve e inicio da sele��o do menu
				{
				case 1:
				registro(); //chamada de fun��es
				break;
					
				case 2:
				consultar();
				break;
					
				case 3:
				deletar();
				break;
					
				case 4:
				printf("Obrigada por utilizar o sistema!\n");
				return 0;
				break;
					
				default: //diferente das op��es que tem
				printf("Essa op��o n�o esta disponivel.\n");
				system("pause");
				break;
			}
		}
	}
	
	else
		printf("Senha incorreta!");
}

