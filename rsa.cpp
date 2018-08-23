#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
 
using namespace std;
 //Declaração de variáveis e marcadores que serão necessários durante o programa.
long int p, q, n, z, aux, e, d, temporario[100], j, charlimpo[100], charencriptado[100], i;
char nome[100];

//Função para se encriptar o nome
void encriptar()
{
	//Define algumas variáveis que serão usadas nesta função
    long int pt, ct, resultado, len;
    //Atribui 0 a um marcador
    i = 0;
    //Atribui à variável len o número de caracteres que o vetor "nome" contém.
    len = strlen(nome);
    //Usa um laço de repetição que ficará em execução enquanto o marcador "i" acima for diferente do número de caracteres do nome.
    while (i != len)
    {
    	/* O vetor m[i] contém o nome que foi inserido, foi feito o transporte dos valores para este vetor para que ele possa ser manipulado e mudado sem alterar a mensagem inicial.
    	então a variável pt recebe a posição "i" do vetor m.*/
        pt = charlimpo[i];
        //Transforma o caracter para a tabela ASCII
        pt = pt - 96;
        //Atribui 1 à variável que servirá para fazer a exponenciação
        resultado = 1;
        // Neste laço de repetição o valor de pt será multiplicado até que j atinja o valor de e, pois para encriptar a mensagem temos n^e. Depois faremos o mod da divisão de resultado por n.		
        for (j = 0; j < e; j++)
        {
            resultado = resultado * pt;
            resultado = resultado % n;
        }
        //Aqui atribuimos ao vetor temporario o valor de resultado para que seja armazenado.
        temporario[i] = resultado;
        //Aqui já temos a mensagem encriptada, então vamos tirar da tabela ASCII adicionando 96 ao número, pois o A na tabela ASCII é 96.
        ct = resultado + 96;
        //Transportamos o caracter da variável ct para o vetor charencriptado, que é a mensagem que será mostrada.
        charencriptado[i] = ct;
        //Este é o marcador para o laço de repetição while.
        i++;
    }
    //Aqui atribuimos o valor -1 à posição i do vetor, pois este marcador será usado em um laço de repetição na hora de transformar a mensagem em mensagem clara novamente.
    charencriptado[i] = -1;
        cout << "\n" << "Seu nome encriptado eh: ";
    //Este laço de repetição serve para mostrar, caracter por caracter, a mensagem encriptada.
    for (i = 0; charencriptado[i] != -1; i++)
        printf("%c", charencriptado[i]);
}

//Função para mostrar novamente a mensagem clara.
void desencriptar()
{
	//Declara algumas variáveis usadas e variáveis de transporte da função.
    long int pt, ct, resultado;
    //Atribui 0 a um marcador
    i = 0;
    //Usa um laço de repetição que ficará em execução enquanto o marcador "i" acima for um número diferente de -1, pois usamos -1 como marcador na função encriptar para determinar o fim do vetor.
    while (charencriptado[i] != -1)
    {
    	//pegamos o valor do vetor temporario na posição i e transportamos para a variável ct.
        ct = temporario[i];
        //Atribuimos 1 à variável resultado
        resultado = 1;
         // Neste laço de repetição o valor de pt será multiplicado até que j atinja o valor de d, pois para desencriptar a mensagem temos n^d. Depois faremos o mod da divisão de resultado por n.
        for (j = 0; j < d; j++)
        {
            resultado = resultado * ct;
            resultado = resultado % n;
        }
        //Aqui já temos a mensagem clara, então vamos tirar da tabela ASCII adicionando 96 ao número, pois o A na tabela ASCII é 96.
        pt = resultado + 96;
        //Aqui atribuímos à posição i do vetor charlimpo o caracter já traduzido novemtne.
        charlimpo[i] = pt;
        //Este é o marcador para o laço de repetição while.
        i++;
    }
    charlimpo[i] = -1;
    cout << "\n"<< "A mensagem limpa eh: ";
    for (i = 0; charlimpo[i] != -1; i++)
        printf("%c", charlimpo[i]);
}

int main()
{
	//Definição de p e q como os números primos 17 e 23, e calculando n e 
	p = 17;
	q = 23;
	n = p * q;
    z = (p - 1) * (q - 1);
    //Define o valor da chave pública e da chave privada, já calculadas por mim.
    e = 31;
    d = 159;
	//Cabeçalho
	cout << "Encriptando seu nome e depois mostrando a mensagem clara novamente.\n";
	//Entrada do nome que deseja ser encriptado
    cout << "\n" << "Digite seu nome somente com minusculas: ";
    cin >> nome;
	/* Neste for transportamos os caracteres do "nome" para a variável m, posição por posição, até que o programa ache uma posição vazia, o que signfica que o nome já terminou.*/    
    for (i = 0; nome[i] != NULL; i++)
        charlimpo[i] = nome[i];   
    encriptar();
    cout << "\n";
    desencriptar();
    cout << "\n\n";
    system ("PAUSE");
    return 0;
}
