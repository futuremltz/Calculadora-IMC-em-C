#include <stdio.h>
#include <stdlib.h>

// Limpar buffer do teclado
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Faz a conta do IMC
double conta(double peso, double altura){
  return peso / (altura * altura);
}

// Checa o IMC
void checagem(double imc, int idade){
  printf("Seu IMC é de %.2lf\n", imc);
  if (idade >= 60){

    if (imc < 22.0){
      printf("\033[31m O seu peso está abaixo do indicado para saude \033[0m\n");
    }else if (imc <= 27.0)
    {
      printf("\033[32m O seu peso está no peso adequado baseado na sua idade \033[0m\n");
    }else{
      printf("\033[31m O seu peso está acima do peso adequado baseado na sua idade \033[0m\n");
    }
  }else if (idade >= 20 && idade <= 59){
    
    if (imc < 18.5){
      printf("\033[31m O seu peso está abaixo do indicado para saude \033[0m\n");

    }else if (imc >= 18.5 && imc <= 24.9){
      printf("\033[32m O seu peso está no peso adequado baseado na sua idade \033[0m\n");

    }else if (imc >= 25.0 && imc <= 29.9){
      printf("\033[33m O seu peso está acima do peso adequado baseado na sua idade \033[0m\n");

    }else if (imc >= 30.0 && imc <= 34.9){
      printf("\033[31m O seu IMC é considerado como obesidade grau I \033[0m\n");

    }else if (imc >= 35.0 && imc <= 39.9){
      printf("\033[31m O seu IMC é considerado como obesidade grau II \033[0m\n");

    }else{
      printf("\033[31m O seu IMC é considerado como obesidade grau III \033[0m\n");
    }
  }else{
    printf("Para idade de 0 a 19 não existe uma tabela de valores fixos\n");
  }
}

// Puxa tudo
int main(){
  char nome[30];
  int idade;
  double peso, altura;
  char escolha;
  int menu = 1;
  while (menu){
    printf("Por favor digite seu nome: ");
    scanf("%29s", nome);
    limpar_buffer();
    printf("Por favor digite sua idade: ");
    if (scanf("%d", &idade) != 1 || idade <= 0){
      printf("\033[31mEntrada inválida! Tente novamente.\033[0m\n");
      limpar_buffer();
      continue;
    }
    printf("Digite o seu peso: ");
    if (scanf("%lf", &peso) != 1 || peso <= 0){
      printf("\033[31mEntrada inválida! Tente novamente.\033[0m\n");
      limpar_buffer();
      continue;
    }
    printf("Digite sua altura: ");
    if (scanf("%lf", &altura) != 1 || altura <= 0){
      printf("\033[31mEntrada inválida! Tente novamente.\033[0m\n");
      limpar_buffer();
      continue;
    }
    limpar_buffer();

    double imc = conta(peso, altura);
    checagem(imc, idade);

    printf("Deseja salvar? ");
    scanf("%c", &escolha);
    limpar_buffer();

    if (escolha == 's' || escolha =='S'){
      FILE *arquivo = fopen("historico_imc.txt", "a");
      if (arquivo != NULL){
        fprintf(arquivo, "Nome: %s | Idade: %d | Peso: %.2lf | Altura: %.2lf | IMC: %.2lf\n", nome, idade, peso, altura, imc);
        fclose(arquivo);
        printf("\033[32mSalvo com sucesso em 'historico_imc.txt'!\033[0m\n");
      }else{
        printf("\033[31mErro ao abrir o arquivo!\033[0m\n");
      }
    }
    
    printf("Deseja calcular outro IMC?(s/n)");
    scanf("%c", &escolha);
    limpar_buffer();
  
    if (escolha != 's' && escolha != 'S')
    {
      printf("Desligando sistema....");
      menu = 0;
    }
  }
  
 return 0;
}