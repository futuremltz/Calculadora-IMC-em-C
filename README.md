# PROJETO #01 — Calculadora de IMC com Diagnóstico

![C](https://img.shields.io/badge/linguagem-C-blue.svg)
![Status](https://img.shields.io/badge/status-conclu%C3%ADdo-brightgreen.svg)

## 📋 Descrição

Programa em C que recebe **peso** e **altura** do usuário, calcula o **IMC (Índice de Massa Corporal)** e exibe uma classificação personalizada — abaixo do peso, peso adequado, sobrepeso ou obesidade (graus I, II e III) — levando em conta também a **idade** informada, já que a tabela de referência de IMC muda para idosos (60+).

O foco principal deste projeto é fixar conceitos fundamentais de C:
- Variáveis e tipos de dados (`int`, `double`, `char`)
- Operadores aritméticos
- Estruturas condicionais (`if` / `else if` / `else`)

**Tempo estimado:** 2 a 3 horas
**Esforço:** Rápido

## 🚀 Funcionalidades

- **Cálculo do IMC** a partir de peso (kg) e altura (m), usando a fórmula padrão `IMC = peso / (altura²)`.
- **Classificação por faixa etária:**
  - **0 a 19 anos:** informa que não há tabela de valores fixos para essa faixa.
  - **20 a 59 anos:** classifica em abaixo do peso, peso adequado, sobrepeso, obesidade grau I, II ou III.
  - **60 anos ou mais:** usa uma tabela de referência específica para idosos.
- **Mensagens coloridas no terminal** via códigos ANSI: verde para peso adequado, amarelo para atenção (sobrepeso) e vermelho para risco (abaixo do peso ou obesidade).
- **Validação de entradas:** idade, peso e altura menores ou iguais a zero (ou não numéricos) são rejeitados, e o programa pede a informação novamente em loop.
- **Histórico opcional:** ao final do cálculo, o usuário escolhe se quer salvar os dados (nome, idade, peso, altura e IMC) em `historico_imc.txt`, no formato de log acumulativo.
- **Loop de execução:** ao final de cada cálculo, o usuário pode escolher calcular outro IMC ou encerrar o programa.

## 🧠 Lógica de classificação (20 a 59 anos)

| IMC | Classificação | Cor |
|-----|---------------|-----|
| < 18.5 | Abaixo do peso | 🔴 Vermelho |
| 18.5 – 24.9 | Peso adequado | 🟢 Verde |
| 25.0 – 29.9 | Sobrepeso | 🟡 Amarelo |
| 30.0 – 34.9 | Obesidade grau I | 🔴 Vermelho |
| 35.0 – 39.9 | Obesidade grau II | 🔴 Vermelho |
| ≥ 40.0 | Obesidade grau III | 🔴 Vermelho |

Para idosos (60+), a faixa considerada saudável é ampliada (até 27.0), refletindo recomendações de saúde específicas para essa idade.

## 🌍 Aplicação no mundo real

A lógica de **classificação por faixas** usada aqui é a base de diversos sistemas do mundo real:
- **Apps de telemedicina e saúde digital**, que classificam indicadores clínicos em níveis de risco.
- **Sistemas de crédito**, que enquadram um score numérico em faixas (ruim, regular, bom, excelente).
- **Precificação de seguros**, que calcula prêmios com base em faixas de risco do segurado.

Em todos os casos, o padrão é o mesmo: **transformar um valor numérico contínuo em uma categoria significativa para quem vai tomar uma decisão.**

## ⚙️ O desafio em C

O maior desafio técnico deste projeto foi lidar corretamente com a entrada de dados via `scanf`:
- Garantir que `scanf("%lf", ...)` capture corretamente valores `float`/`double`.
- **Tratar o buffer do teclado** após cada leitura (função `limpar_buffer()`), evitando que caracteres residuais (como o `\n` do `Enter`) atrapalhem a leitura seguinte — um problema clássico e recorrente em C.

## ✅ Boas práticas aplicadas (Clean Code em C)

- **Validação do retorno de `scanf`**: antes de prosseguir, o programa sempre verifica se `scanf` conseguiu ler a quantidade esperada de itens (`if (scanf(...) != 1)`), evitando processar lixo de memória como se fosse uma entrada válida.
- **Tratamento de edge cases desde o primeiro projeto**: peso, altura e idade menores ou iguais a zero são rejeitados e o usuário é solicitado a tentar novamente, em vez de o programa simplesmente travar ou gerar um resultado sem sentido.
- **Separação de responsabilidades**: o cálculo do IMC (`conta()`) e a lógica de classificação (`checagem()`) ficam em funções separadas da função `main()`, facilitando leitura e manutenção.
- **Uso de I/O seguro para arquivos**: o programa verifica se `fopen()` retornou um ponteiro válido antes de escrever no arquivo de histórico.

## 🛠️ Como compilar e executar

```bash
gcc calculadora_imc.c -o calculadora_imc
./calculadora_imc
```

## 💾 Exemplo de histórico salvo

```
Nome: Maria | Idade: 34 | Peso: 68.50 | Altura: 1.65 | IMC: 25.16
```

## 📌 Possíveis melhorias futuras

- Migrar a lógica de classificação para uma estrutura de dados (tabela/array de faixas) em vez de encadeamento de `if/else if`, facilitando a manutenção.
- Adicionar suporte a diferentes unidades de medida (libras/pés).
- Exportar o histórico também em formato CSV.

## 📝 Commit

```
feat: add BMI calculator with classification logic
```

---

*Projeto #01 de uma série de exercícios de programação em C, com foco em fixar fundamentos da linguagem através de projetos práticos e aplicáveis ao mundo real.*