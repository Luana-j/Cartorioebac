#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //bibliotexa de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // Função responsavel por cadastrar o usuario no sistemas
{
	// inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informações do usuário
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
	
	char cpf [40]; //essa variavel é a onde a gente vai armazenas a resposta do usuario
	char conteudo[200]; //é a onde a gente vai armazenar o conteudo que esta dentro do arquivo, nesse caso, o cpf
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // o r é para ler o que esta dentro do arquivo cpf
	
	if(file == NULL) // se ele procurar e não encontrar o arquivo, ele é nulo
	{
		printf("Não foi possivel abrir o arquivo, não localizado!. \n"); //se for nulo, dará essa msg
	}
	
	while(fgets(conteudo, 200, file) != NULL) //while é enquanto, enquanto procura
	printf("\nEssas são as informações do usuário: "); //esta escrevendo para o usuario as informações solicitadas
	printf("%s", conteudo); // printf ao inves de scanf, pois queremos mostrar o conteudo e nao salvar
	printf("\n\n");
	
	system("pause");
		
}

int deletar()
{
	char cpf[40]; //string cpf
	
	printf("Digite o CPF do usuário a ser deletado: "); // usuario vai digitar o cpf a ser deletado
	scanf("%s", cpf); // vamos scanear e armazenas dentro da string cpf
	
	remove(cpf); // para deletar caso encontrar o cpf for encontrado
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
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
			printf("Escolha a opção desejada do menu: \n\n"); //escrevendo para o cliente
			printf("\t 1 - Registrar nomes\n"); //escrevendo para o cliente
			printf("\t 2 - Consultar os nomes\n"); //escrevendo para o cliente
			printf("\t 3 - Deletar nomes\n"); //escrevendo para o cliente
			printf("\t 4 - Sair do sistema \n\n");
			printf("Opção: "); //fim do menu
		
			scanf("%d", &opcao); //armazenando a escolha do usuario
		
			system("cls"); //deleta todas as mensagens que tinha antes
				
			switch(opcao) //para o programa ficar mais limpo e leve e inicio da seleção do menu
				{
				case 1:
				registro(); //chamada de funções
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
					
				default: //diferente das opções que tem
				printf("Essa opção não esta disponivel.\n");
				system("pause");
				break;
			}
		}
	}
	
	else
		printf("Senha incorreta!");
}

