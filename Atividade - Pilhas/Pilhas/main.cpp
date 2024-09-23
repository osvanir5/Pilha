#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Função para verificar se o caractere de abertura corresponde ao de fechamento
bool corresponde(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') || (abertura == '[' && fechamento == ']');
}

// Função para validar a expressão
bool validaExpressao(const string& expressao) {
    stack<char> pilha; // Pilha para armazenar parênteses e colchetes

    for (char c : expressao) {
        // Se for uma abertura de parênteses ou colchetes, empilha
        if (c == '(' || c == '[') {
            pilha.push(c);
        }
        // Se for um fechamento de parênteses ou colchetes, verifica correspondência
        else if (c == ')' || c == ']') {
            if (pilha.empty() || !corresponde(pilha.top(), c)) {
                return false; // Expressão inválida
            }
            pilha.pop(); // Remove o par de parênteses/colchetes correto
        }
    }

    // Se a pilha estiver vazia, todos os parênteses/colchetes foram fechados corretamente
    return pilha.empty();
}

int main() {
    string expressao;

    // Solicita ao usuário a expressão matemática
    cout << "Digite a expressao matematica: ";
    cin >> expressao;

    // Verifica a validade da expressão
    if (validaExpressao(expressao)) {
        cout << "OK" << endl;
    } else {
        cout << "Errado" << endl;
    }

    return 0;
}
