#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fun��o para verificar se o caractere de abertura corresponde ao de fechamento
bool corresponde(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') || (abertura == '[' && fechamento == ']');
}

// Fun��o para validar a express�o
bool validaExpressao(const string& expressao) {
    stack<char> pilha; // Pilha para armazenar par�nteses e colchetes

    for (char c : expressao) {
        // Se for uma abertura de par�nteses ou colchetes, empilha
        if (c == '(' || c == '[') {
            pilha.push(c);
        }
        // Se for um fechamento de par�nteses ou colchetes, verifica correspond�ncia
        else if (c == ')' || c == ']') {
            if (pilha.empty() || !corresponde(pilha.top(), c)) {
                return false; // Express�o inv�lida
            }
            pilha.pop(); // Remove o par de par�nteses/colchetes correto
        }
    }

    // Se a pilha estiver vazia, todos os par�nteses/colchetes foram fechados corretamente
    return pilha.empty();
}

int main() {
    string expressao;

    // Solicita ao usu�rio a express�o matem�tica
    cout << "Digite a expressao matematica: ";
    cin >> expressao;

    // Verifica a validade da express�o
    if (validaExpressao(expressao)) {
        cout << "OK" << endl;
    } else {
        cout << "Errado" << endl;
    }

    return 0;
}
