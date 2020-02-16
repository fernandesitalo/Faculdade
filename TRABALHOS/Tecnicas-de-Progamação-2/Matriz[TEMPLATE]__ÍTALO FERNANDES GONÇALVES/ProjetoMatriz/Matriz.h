#ifndef MATRIZ_H
#define MATRIZ_H
#include<QString>

namespace MAT{
template<class New_Type>
class Matriz
{
private:
    int quantidadeDeColunas;
    int quantidadeDeLinhas;
    New_Type *ptMatriz;

public:
    Matriz(int qLinhas, int qColunas); /// CONSTRUTOR..

    ~Matriz(); // DESTRUTOR..

    int getQuantidadeDeLinhas()const{return quantidadeDeLinhas;}

    int getQuantidadeDeColunas()const{return quantidadeDeColunas;}

    void setElemento(New_Type elemento, int linha, int coluna)const;

    New_Type getElemento(int linha, int coluna)const;

    Matriz<New_Type> *operator+(Matriz<New_Type> const * const mat)const;

    Matriz<New_Type> *operator-(Matriz<New_Type> const * const mat)const;

    Matriz<New_Type> *operator*(Matriz<New_Type> const * const mat)const;

    Matriz<New_Type> *Transposta()const;

    Matriz<New_Type> *MultipicaPorUmNumero(int numero)const; /// constante sempre sera inteira?

    Matriz<New_Type> *copyMatriz()const;

    Matriz<New_Type> *Potencia(int grau)const; /// potencia somente inteira?

    bool operator==(Matriz<New_Type> const * const mat)const;

    bool operator!=(Matriz<New_Type> const * const mat)const;

    bool EIdentidade()const;

    bool ESimetrica()const;

    bool ETriangularInferior()const;

    bool ETriangularSuperior()const;

    bool EOrtogonal()const;

    bool EPermutada_1()const;
};

template<class New_Type>
Matriz<New_Type>::~Matriz<New_Type>(){ // DESTRUTOR DA CLASSE MATRIZ, DESALOCA PONTEIRO
    if(ptMatriz) delete[] ptMatriz;
}


template<class New_Type>
void Matriz<New_Type>::setElemento(New_Type elemento, int linha, int coluna) const{  // SETA UM UNICO ELEMENTO
    if(linha < 0 || linha>=quantidadeDeLinhas)
        throw QString("Linha fora do intervalo valido");
    if(coluna < 0 || coluna>=quantidadeDeColunas)
        throw QString("Coluna fora do intervalo valido");

    int pos = linha*quantidadeDeColunas+coluna;
    *(ptMatriz+pos) = elemento;
}

template<class New_Type>
New_Type Matriz<New_Type>::getElemento(int linha, int coluna) const{  // RETORNA UM ÚNICO ELEMENTO
    if(linha<0 || linha>=quantidadeDeLinhas)
        throw QString("Linha fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas)
        throw QString("Coluna fora do intervalo valido");

    int pos = linha*quantidadeDeColunas+coluna;
    return *(ptMatriz+pos);
}

template<class New_Type>
Matriz<New_Type> *Matriz<New_Type>::operator+(const Matriz * const mat) const // SOBRECARGA DO OPERADOR DE ADICAO
{

    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() ||
            quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString("Nao pode ser adicionadas matriz de tamanhos diferentes");
    try{
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);

        for(int linha=0; linha < quantidadeDeLinhas; linha++){
            for(int coluna=0; coluna < quantidadeDeColunas; coluna++){
                New_Type valor = this->getElemento(linha,coluna) + mat->getElemento(linha,coluna);
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


template<class New_Type>
Matriz<New_Type> *Matriz<New_Type>::operator-(const Matriz * const mat) const /* ok_implementado-testado*/
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
                New_Type valor = this->getElemento(linha,coluna) - mat->getElemento(linha,coluna);
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

template<class New_Type>
Matriz<New_Type> *Matriz<New_Type>::operator*(const Matriz * const mat) const /*ok_implementado-testado*/
{
    try{
        if( quantidadeDeColunas  != mat->getQuantidadeDeLinhas())
            throw QString("NAO E POSSIVEL MULTIPLICAR AS MATRIZ... DIMENSOES IMCOMPATIVEIS!");

        Matriz *aux = new Matriz(quantidadeDeLinhas,mat->quantidadeDeColunas);

        New_Type AUX;

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

template<class New_Type>
bool Matriz<New_Type>::operator==(const Matriz * const mat) const /* ok_implementado-testado*/
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


template<class New_Type>
bool Matriz<New_Type>::operator!=(const Matriz * const mat) const /* ok_implementado-testado*/
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


template<class New_Type>
bool Matriz<New_Type>::EIdentidade() const
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

template<class New_Type>
bool Matriz<New_Type>::ESimetrica() const
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


template<class New_Type>
bool Matriz<New_Type>::ETriangularInferior() const
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


template<class New_Type>
bool Matriz<New_Type>::ETriangularSuperior() const
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


template<class New_Type>
Matriz<New_Type> *Matriz<New_Type>::copyMatriz() const
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

template<class New_Type>
Matriz<New_Type> *Matriz<New_Type>::Potencia(int grau) const
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
    New_Type AUX;

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


template<class New_Type>
bool Matriz<New_Type>::EOrtogonal() const
{
    /// E ORTOGONAL SE A^-1 == A^t , LOGO A*A^t = IDENTIDADE
    Matriz *resultado = * this->Transposta() * this; /// A^t * A
    bool retorno = resultado->EIdentidade(); /// resultado(A^t * A) == IDENTIDADE?
    delete resultado;
    return retorno;
}


template<class New_Type>
bool Matriz<New_Type>::EPermutada_1() const
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
        if(c == 0 || c == 0) return false;
    }
    return true;
}

template<class New_Type>
Matriz<New_Type> *Matriz<New_Type>::MultipicaPorUmNumero(int numero) const
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

template<class New_Type>
Matriz<New_Type> *Matriz<New_Type>::Transposta() const
{
    Matriz *aux = new Matriz(quantidadeDeColunas,quantidadeDeLinhas);

    for(int linha = 0 ; linha < quantidadeDeLinhas ; ++linha){
        for(int coluna = 0 ; coluna < quantidadeDeColunas ; ++coluna){
            aux->setElemento(this->getElemento(linha,coluna),coluna,linha);
        }
    }
    return aux;
}


template<class New_Type>
Matriz<New_Type>::Matriz(int qLinhas, int qColunas){ // METODO CONSTRUTOR
    quantidadeDeLinhas =  quantidadeDeColunas = 0;
    ptMatriz = 0;

    if(qLinhas<=0) throw QString("ATENÇÃO! Quantidade de Linhas somente positiva!!");
    if(qColunas<=0) throw QString("ATENÇÃO! Quantidade de Colunas somente positiva!!");

    try{
        ptMatriz = new New_Type[qLinhas*qColunas];

        for(int i  = 0 ; i < (qLinhas*qColunas) ; ++i) ptMatriz[i] = 0;

    }
    catch(std::bad_alloc&){ // CAPTA EXCESSAO BAD_ALLOC (QUANDO NAO HÁ MAIS MEMORIA)
        throw QString("Memoria Insuficiente para a execução do progama!");
    }
    quantidadeDeLinhas = qLinhas;
    quantidadeDeColunas = qColunas;
}


}

#endif // MATRIZ_H
