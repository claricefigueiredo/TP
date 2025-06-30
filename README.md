
![logo campo minado](https://github.com/user-attachments/assets/128655a4-f35f-46cf-a40a-5f6888518fb5)

# 💣🚩 TP- Campo Minado
Este projeto é uma implementação do jogo **Campo Minado**, desenvolvida em **C++**. O objetivo do jogo é desvendar um campo de células sem detonar nenhuma mina, com as dicas (número de minas ao redor da célula escolhida) que o jogo fornece.

## ⚙️Requisitos

- **Compilador C++** (como o `g++`)
- **Git** (opcional, para clonar o repositório)
- Terminal com suporte a entrada/saída padrão

## 🚀 Como instalar
1. Clone o repositório `git clone https://github.com/claricefigueiredo/TP.git`

## ☕ Como usar
1. Compile o projeto `g++ main.cpp jogo.cpp tabuleiro.cpp Celula.cpp -o jogo`
2. Execute o jogo `./jogo`

Como alternativa, consulte a documentação do GitHub em [como criar uma solicitação pull](https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/creating-a-pull-request).

## 🎮 Como Jogar
Inicialmente, digite 0 para colocar/remover bandeira ou 1 para abrir uma célula
Digitando 1:
- Insira as coordenadas da célula que você gostaria de revelar (no formato "linha coluna")
- Caso apareça uma explosão (💥), você perdeu! Mas tem a chance de jogar novamente digitando 1 mais uma vez
- Caso apareça um número, significa que a célula está vazia
- Cada número indica quantas minas estão ao redor - cima, baixo, direita, esquerda e diagonais imediatas - do bloco que contém o valor
  
Digitando 0:
- Insira as coordenadas da célula que você gostaria de adicionar uma bandeira (no formato "linha coluna")
- Caso essa coordenada já possua uma bandeira, ela será removida
  
O jogo termina quando as células restantes não reveladas forem todas bombas

## 📫 Como contribuir
1. Bifurque este repositório.
2. Crie um branch: `git checkout -b nova-contribuicao`.
3. Faça suas alterações e confirme-as: `git commit -m '<mensagem do commit>'`
4. Envie para o branch original: `git push origin nova-contribuicao`
5. Crie a solicitação de pull.
