#include <iostream>

// 0) Crie uma função que receba três variveis inteiras como parâmetro, da seguinte forma:
//    - A primeira deve ser passada por valor
//    - A segunda deve ser passada por referência 
//    - A terceira deve ser passada "por referência" usando apontadores (passagem "por referência" disponível em C)
//    A função deverá somar 1 ao valor de cada uma das 3 variáveis e retornar.
void somaUm(int valor, int& valorRef, int* valorPtr) {
    valor += 1;
    valorRef += 1;
    (*valorPtr) += 1;
}

int main(){

    using namespace std;

    int entrada;
    cout << "Digite uma entrada: ";
    cin >> entrada;

    // 1) Declare uma variavel do tipo inteiro e preencha com o valor informado na entrada
    int n = entrada;

    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int* p = nullptr;

    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com dados lidos da entrada
    cout << "Digite " << entrada << " valores: ";
    int vetorTam;
    cin >> vetorTam;
    int* vet = new int[vetorTam];
    for (int i = 0; i < vetorTam; i++) {
        cin >> vet[i];
    }

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << "Endereço da variável n: ";
    cout << &n << endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    cout << "Valor da variável n: ";
    cout << n << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << "Endereço da variável p: ";
    cout << &p << endl;
    
    // 7) Imprima o VALOR da variável declarada em (2)
    cout << "Valor da variável p: ";
    cout << p << endl;    

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << "Endereço da variável vet: ";
    cout << &vet << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << "Endereço da primeira posição do vetor vet: ";
    cout << &vet[0] << endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << "Valor da primeira posição do vetor vet: ";
    cout << vet[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    p = &n;    

    // 12) Imprima o VALOR da variável declarada em (2)
    cout << "Valor da variável p: ";
    cout << p << endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << "Valor guardado no endereço apontado por p: ";
    cout << *p << endl;

    // 14) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *p = 5;    

    // 15) Imprima o VALOR da variável declarada em (1)
    cout << "Valor da variável n: ";
    cout << n << endl;    

    // 16) Atribua o VALOR da variável (3) à variável declarada em (2)
    p = vet;    

    // 17) Imprima o VALOR da variável declarada em (2)
    cout << "Valor da variável p: ";
    cout << p << endl;    

    // 18) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << "Valor guardado no endereço apontado por p: ";
    cout << *p << endl;    

    // 19) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    p = &vet[0];    

    // 20) Compare o valor variáveis (2) e (3), imprimindo 'S' se forem iguais e 'N' se forem diferentes
    cout << "Comparação entre p e vet: ";
    cout << (p == vet ? "S" : "N") << endl;

    // 21) Imprima o VALOR da variável declarada em (2)
    cout << "Valor da variável p: ";
    cout << p << endl;    

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << "Valor guardado no endereço apontado por p: ";
    cout << *p << endl;    

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for (int i = 0; i < vetorTam; i++) {
        *(p + i) *= 10;
    }    

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    cout << "Elementos do vetor vet: ";
    for (int i = 0; i < (vetorTam-1); i++) {
        cout << vet[i] << " ";
    }
    cout << vet[vetorTam-1] << endl;

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    cout << "Elementos do vetor vet: ";
    for (int i = 0; i < (vetorTam-1); i++) {
        cout << *(vet + i) << " ";
    }
    cout << *(vet + (vetorTam-1)) << endl;
    
    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (2)
    cout << "Elementos do vetor vet: ";
    for (int i = 0; i < (vetorTam-1); i++) {
        cout << *(p + i) << " ";
    }
    cout << *(p + (vetorTam-1)) << endl;

    // 27) Atribua o ENDEREÇO da última posição de (3) à variável declarada em (2)
    p = &vet[vetorTam - 1];    

    // 28) Imprima o VALOR da variável declarada em (2)
    cout << "Valor da variável p: ";
    cout << p << endl;    

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << "Valor guardado no endereço apontado por p: ";
    cout << *p << endl;    

    // 30) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int** pp = &p;    

    // 31) Imprima o VALOR da variável declarada em (30)
    cout << "Valor da variável pp: ";
    cout << pp << endl;    

    // 32) Imprima o ENDEREÇO da variável declarada em (30)
    cout << "Endereço da variável pp: ";
    cout << &pp << endl;    

    // 33) Imprima o VALOR guardado no ENDEREÇO apontado por (30)
    cout << "Valor guardado no endereço apontado por pp: ";
    cout << *pp << endl;    

    // 34) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (30)
    cout << "Valor guardado no endereço apontado por *pp: ";
    cout << **pp << endl;    

    // 35) Crie 3 variáveis interiras e leia o valor delas da entrada
    int a, b, c;
    cout << "Digite 3 valores: ";
    cin >> a >> b >> c;
    
    // 36) Chame a função criada em (0) passando as 3 variáveis criadas em (35) como parâmetro.
    somaUm(a, b, &c);
    
    // 37) Imprima o valor das 3 variáveis criadas em (35)
    cout << "Valores das variáveis a, b e c: ";
    cout << a << " " << b << " " << c << endl;    

    delete[] vet;

    return 0;
}