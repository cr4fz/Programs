#include <stack>
#include <queue>
#include <cstring>
#include <iostream>

int prior(char car) {
    switch(car) {
        case '^': return 3;
        case '/':
        case '*': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

std::queue<char> cola;

void infija_postfija(const char q[]) {
    int k = 0;
    char car;
    std::stack<char> pila;
    while (k < strlen(q)) {
        switch (q[k]) {
            case '(': 
                pila.push(q[k]); 
                break;
            case ')': 
                while (!pila.empty() && pila.top() != '(') {
                    car = pila.top();
                    pila.pop();
                    cola.push(car);
                }
                pila.pop();
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^': 
                while (!pila.empty() && prior(q[k]) <= prior(pila.top())) {
                    car = pila.top();
                    pila.pop();
                    cola.push(car);
                }
                pila.push(q[k]);
                break;
            default:
                cola.push(q[k]);
                break;
        }
        k++;
    }
    while (!pila.empty()) {
        car = pila.top();
        pila.pop();
        cola.push(car);
    }
}

void evalua() {
    char car;
    while (!cola.empty()) {
        car = cola.front();
        cola.pop();
        std::cout << car;
    }
}

int main() {
    infija_postfija("(5-(6-7)*(2+9*2))");
    evalua();
    std::cin.get();
    return 0;
}
