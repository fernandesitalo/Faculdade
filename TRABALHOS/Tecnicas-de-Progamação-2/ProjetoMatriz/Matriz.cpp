#include "Matriz.h"
#include <QInputDialog>
#include <QMessageBox>


namespace MAT{//inicio

Matriz::Matriz(int qLinhas, int qColunas){ // METODO CONSTRUTOR
    quantidadeDeLinhas =  quantidadeDeColunas = 0;
    ptMatriz = 0;

    if(qLinhas<=0) throw QString("ATENÇÃO! Quantidade de Linhas somente positiva!!");
    if(qColunas<=0) throw QString("ATENÇÃO! Quantidade de Colunas somente positiva!!");

    try{
        ptMatriz = new int[qLinhas*qColunas];

        for(int i  = 0 ; i < (qLinhas*qColunas) ; ++i) ptMatriz[i] = 0;

    }
    catch(std::bad_alloc&){ // CAPTA EXCESSAO BAD_ALLOC (QUANDO NAO HÁ MAIS MEMORIA)
        throw QString("Memoria Insuficiente para a execução do progama!");
    }
    quantidadeDeLinhas = qLinhas;
    quantidadeDeColunas = qColunas;
}

Matriz::~Matriz(){ // DESTRUTOR DA CLASSE MATRIZ, DESALOCA PONTEIRO
    if(ptMatriz)
        delete[] ptMatriz;
}

void Matriz::setElemento(int elemento, int linha, int coluna)const{  // SETA UM UNICO ELEMENTO
    if(linha < 0 || linha>=quantidadeDeLinhas)
        throw QString("Linha fora do intervalo valido");
    if(coluna < 0 || coluna>=quantidadeDeColunas)
        throw QString("Coluna fora do intervalo valido");


    int pos = linha*quantidadeDeColunas+coluna;
    *(ptMatriz+pos) = elemento;
}


int Matriz::getElemento(int linha, int coluna)const{  // RETORNA UM ÚNICO ELEMENTO
    if(linha<0 || linha>=quantidadeDeLinhas)
        throw QString("Linha fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas)
        throw QString("Coluna fora do intervalo valido");


    int pos = linha*quantidadeDeColunas+coluna;
    return *(ptMatriz+pos);
}

///SOBRECARGA DO OPERADOR DE ADICAO DE DUAS MATRIZES
Matriz* Matriz::operator + (Matriz const * const mat)const{

    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() ||
            quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString("Nao pode ser adicionadas matriz de tamanhos diferentes");
    try{
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);

        for(int linha=0; linha<quantidadeDeLinhas; linha++){
            for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
                int valor = this->getElemento(linha,coluna) + mat->getElemento(linha,coluna);
                aux->setElemento(valor,linha,coluna);
            }
        }
        return aux; // retorna um ponteiro para a matriz alocada dinamicamente dentro desta função
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro){
        throw QString("Matriz auxiliar nao Criada nao podemos adicionar as matrizes");
    }
}


/// SOBRECARGA DO OPERADOR DE SUBTRACAO DE DUAS MATRIZES
Matriz *Matriz::operator-(const Matriz * const mat) const
{

    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() ||
            quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString("As matrizes nao podem ser subtraidas, pois possue dimensões diferentes");

    try{
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas); // matriz resultante depois do processo de Subtracao

        for(int linha=0; linha<quantidadeDeLinhas; linha++)
        {
            for(int coluna=0; coluna<quantidadeDeColunas; coluna++)
            {
                int valor = this->getElemento(linha,coluna) - mat->getElemento(linha,coluna);
                aux->setElemento(valor,linha,coluna);
            }
        }
        return aux;
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria! Falha de Segmentacao!");
    }
    catch(QString &erro){
        throw QString("Erro ao alocar uma matriz. Falha ao realizar ação");
    }
}

bool Matriz::operator==(const Matriz * const mat) const
{
    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() || quantidadeDeColunas != mat->getQuantidadeDeColunas())
        return false;

    for(int linha=0; linha<quantidadeDeLinhas; linha++){
        for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
            if(this->getElemento(linha,coluna) != mat->getElemento(linha,coluna)) return false;
        }
    }
    return true;
}


bool Matriz::operator!=(const Matriz * const mat) const
{
    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() || quantidadeDeColunas != mat->getQuantidadeDeColunas())
        return false;

    for(int linha=0; linha<quantidadeDeLinhas; linha++){
        for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
            if(this->getElemento(linha,coluna) == mat->getElemento(linha,coluna)) return false;
        }
    }
    return true;
}

bool Matriz::EIdentidade() const
{
    for(int linha = 0 ; linha < quantidadeDeLinhas ; linha++){
        for(int coluna = 0 ; coluna < quantidadeDeColunas ; coluna++){
            if(linha == coluna){
                if(getElemento(linha,coluna) != 1) return false;
            }
            else{
                if(getElemento(linha,coluna) != 0) return false;
            }
        }
    }
    return true;
}

Matriz *Matriz::Transposta() const
{
    Matriz *aux = new Matriz(quantidadeDeColunas,quantidadeDeLinhas);

    for(int linha = 0 ; linha < quantidadeDeLinhas ; ++linha){
        for(int coluna = 0 ; coluna < quantidadeDeColunas ; ++coluna){
            aux->setElemento(this->getElemento(linha,coluna),coluna,linha);
        }
    }
    return aux;
}

bool Matriz::ESimetrica() const
{
    if(quantidadeDeColunas != quantidadeDeLinhas)
        return false;

    try
    {
        for(int linha = 0 ; linha < quantidadeDeColunas ; ++linha){
            for(int coluna = 0 ; coluna < linha ; ++coluna){
                if(this->getElemento(linha,coluna) != this->getElemento(coluna,linha)){
                    return false;
                }
            }
        }
        return true;
    }
    catch(QString &erro){
        throw QString("Ops! Falha ao realizar ação!");
    }
}

bool Matriz::ETriangularInferior() const
{
    if(quantidadeDeColunas != quantidadeDeLinhas)
        return false;

    try
    {
        for(int linha = 0 ; linha < quantidadeDeLinhas ; linha++){
            for(int coluna = linha+1 ; coluna < quantidadeDeColunas ; ++coluna){
                if(this->getElemento(linha,coluna)){
                    return false;
                }
            }
        }
        return true;
    }
    catch(QString &erro){
        throw QString("Ops! Falha ao realizar ação!");
    }
}

bool Matriz::ETriangularSuperior() const
{
    if(quantidadeDeColunas != quantidadeDeLinhas)
        return false;

    try
    {
        for(int linha = 0 ; linha < quantidadeDeLinhas ; linha++){
            for(int coluna = 0 ; coluna < linha ; ++coluna){
                if(this->getElemento(linha,coluna)){
                    return false;
                }
            }
        }
        return true;
    }
    catch(QString &erro){
        throw QString("Ops! Falha ao realizar ação!");
    }
}

Matriz *Matriz::copyMatriz() const
{
    // retorna uma copia da matriz que chama a funcao, isto é,
    // aloca um espaco de memoria, copia elemento por elemento, e retorna o ponteiro

    try{
        Matriz * copia = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);

        for(int i = 0 ; i < quantidadeDeLinhas ; ++i){
            for(int j = 0 ; j < quantidadeDeColunas ; ++j){
                copia->setElemento(this->getElemento(i,j),i,j);
            }
        }

        return copia;
    }
    catch(std::bad_alloc&){
        throw QString("Memoria Cheia!");
    }
    catch(QString &erro){
        throw erro; // erro lancado pelo get ou set no for de copia
    }
}

Matriz *Matriz::Potencia(int grau) const
{
    if(quantidadeDeLinhas != quantidadeDeColunas)
        throw QString("Dimensões diferentes! Não é possivel execultar tal ação!");

    if(grau < 0)
        throw QString("Potência de numero negativo somente na versão 2.0!");

    if(grau == 0){
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha = 0 ; linha < quantidadeDeLinhas ; ++linha){
            for(int coluna = 0 ; coluna <quantidadeDeColunas ; ++coluna){
                if(linha == coluna)
                    aux->setElemento(1,linha,coluna);
                else aux->setElemento(0,linha,coluna);
            }
        }
        return aux;
    }

    if(grau == 1) return this->copyMatriz(); // ja retorna um ponteiro para a copia da matriz criada dinamicamente


    Matriz *aux = this->copyMatriz(); /// copyMatriz() RETORNA UM PONTEIRO PARA A COPIA DA MATRIZ, ALOCADA DINAMICAMENTE
    Matriz *Pot = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
    int AUX;

    /// MESMO CODIGO DE MULTIPLICACAO
    for(int potencia = 1 ; potencia < grau ; ++potencia) {
        for(int linha = 0 ; linha < quantidadeDeLinhas ; ++linha){/// FIXA A LINHA
            for(int coluna = 0 ; coluna < quantidadeDeColunas ; ++coluna){ /// FIXA A COLUNA
                AUX = 0;
                for(int temp = 0 ; temp < quantidadeDeLinhas ; ++temp){ /// VARIA ENTRE LINHA E COLUNA
                    AUX += (aux->getElemento(linha,temp)* this->getElemento(temp,coluna));
                }
                Pot->setElemento(AUX,linha,coluna);
            }
        }
        delete aux; /// DESALOCA MEMORIA ALOCADA
        aux = Pot->copyMatriz(); /// COPIA COM ALOCACAO DE MEMORIA
    }

    delete aux; // DELETA A ULTIMA COPIA FEITA NO FOR
    return Pot; // RETORNA A POTENCIA CALCULADA
}

bool Matriz::EOrtogonal() const
{
    /// E ORTOGONAL SE A^-1 == A^t , LOGO A*A^t = IDENTIDADE

    Matriz *resultado = * this->Transposta() * this;


    for(int i = 0 ; i < quantidadeDeLinhas ; ++i){
        for(int j = 0 ; j < quantidadeDeColunas ; ++j){
            if(i == j){
                if(resultado->getElemento(i,j) != 1){
                    delete resultado;
                    return false;
                }
            }
            else
                if(resultado->getElemento(i,j) != 0){
                    delete resultado;
                    return false;
                }
        }
    }
    delete resultado;
    return true;
}

bool Matriz::EPermutada_1() const
{
    if(quantidadeDeColunas != quantidadeDeLinhas) return false;

    int l,c;
    for(int i = 0 ; i < quantidadeDeLinhas ; i++){
        l = c = 0;
        for(int j = 0 ; j < quantidadeDeColunas ; j++){
            if(getElemento(i,j)){
                if(getElemento(i,j) != 1 || l++ == 1) return false;
            }
            if(getElemento(j,i)){
                if(getElemento(j,i) != 1 || c++ == 1) return false;
            }
        }
    }
    return true;
}

bool Matriz::EPermutada_2() const
{
    if(quantidadeDeColunas != quantidadeDeLinhas) return false;

    int l,c;
    for(int i = 0 ; i < quantidadeDeLinhas ; ++i){
        l = c = 0;
        for(int j = 0 ; j < quantidadeDeColunas; ++j){
            l += getElemento(i,j);
            c += getElemento(j,i);
        }
        if(l != 1 || c != 1 ) return false;
    }
    return true;
}


Matriz *Matriz::operator*(const Matriz * const mat) const
{
    try{
        if( quantidadeDeColunas  != mat->getQuantidadeDeLinhas())
            throw QString("NAO E POSSIVEL MULTIPLICAR AS MATRIZ... DIMENSOES IMCOMPATIVEIS!");

        Matriz *aux = new Matriz(quantidadeDeLinhas,mat->quantidadeDeColunas);

        int AUX;

        for(int i = 0; i < quantidadeDeLinhas ; i++){
            for(int j = 0 ; j < mat->quantidadeDeColunas ; j++){
                AUX = 0;
                for(int k = 0 ;k < quantidadeDeColunas ; k++){
                    AUX += getElemento(i,k)*mat->getElemento(k,j);
                }
                aux->setElemento(AUX,i,j);
            }
        }

        return aux;
    }
    catch(std::bad_alloc&){
        throw QString("Memoria Cheia!");
    }
    catch(QString &erro){
        throw erro;//Matriz auxiliar nao Criada nao podemos adicionar as matrizes
    }
}

Matriz* Matriz::MultipicaPorUmNumero(int numero) const
{
    try{
        Matriz *aux =  new Matriz(quantidadeDeLinhas,quantidadeDeColunas);

        for(int linha=0; linha<quantidadeDeLinhas; linha++){
            for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
                aux->setElemento(this->getElemento(linha,coluna) * numero,linha,coluna);
            }
        }
        return aux;
    }
    catch(QString &erro){ //exceções lançadas dentro do 'set' e do 'get' elemento
        throw QString("Erro ao alocar uma matriz. Falha ao realizar ação");
    }
    catch(std::bad_alloc&){
        throw QString("Memoria Cheia!");
    }
}



}

//fim
