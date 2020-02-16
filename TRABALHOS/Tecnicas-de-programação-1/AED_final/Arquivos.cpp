#include "Arquivos.h"
#include <fstream>
using namespace std;

#include "IndiceCl.h"
#include "IndiceEq.h"
#include "IndiceAl.h"
#include <cstdio>
#include <stdlib.h>

void Arquivos::NovoCliente(Cliente *A)
{
    fstream CadrastroClientes("DADOS.dat",ios::app|ios::binary); // abri o arquivo, mesmo se nao existir ele cria(app)

        if(!CadrastroClientes.is_open())
        {
           fstream aux("DADOS.dat",ios::out);

           if(!aux)
              throw 1.2;  /// lança execessao
           fstream CadrastroClientes("Dados.dat",ios::app|ios::binary);

        }
    CadrastroClientes.write((char *)A,sizeof(Cliente));
    CadrastroClientes.close();
}

void Arquivos::PegaCliente(Cliente *A, int posicao)
{
    fstream CadrastroClientes("DADOS.dat",ios::in |ios::binary);
    // lancar exeção que o arquivo nao existir !!!

    CadrastroClientes.seekg(posicao* sizeof(Cliente),ios::beg);

    CadrastroClientes.read((char*)A,sizeof(Cliente));

    CadrastroClientes.close();
}

void Arquivos::SobreescreveCliente(Cliente *A, int posicao) // essa e a posicao que ele esta no arquivo
{
    fstream CadrastroClientes("DADOS.dat",ios_base::in |ios_base::out|ios_base::binary); // abri o arquivo, mesmo se nao existir ele cria(app)

    CadrastroClientes.seekp(posicao * sizeof(Cliente),ios_base::beg); //inicia a gravação nessa posicao

     if(!CadrastroClientes.is_open())
    {
        throw "erro"; /// lança execessao se tiver acontecido merda
    }

    CadrastroClientes.write((char *)A,sizeof(Cliente));

    CadrastroClientes.close();
}

void Arquivos::EsvaziarLixeiraClientes()
{
    fstream Arquivos("DADOS.dat",ios_base::in);


    fstream ArqAuxiliar("AUX.dat",ios_base::app);
    /// colocar atributo lixo na classe cliente para faciliar o esvaziamento

    IndiceCl I;
    Cliente aux;
    char temp[80];
    int i,j = 0;

    int TAM = I.getqtd();


    for(i = 0 ; i < TAM ; i++)
    {

        Arquivos.read((char *)&aux,sizeof(Cliente));
        aux.getnome(temp);

        if(aux.getlixo())
        {
            I.IsolaINDCL(temp);
        }
        else
        {

            ArqAuxiliar.write((char *)&aux,sizeof(Cliente));
            I.ModificaPosicao(temp,j);
            j++;
        }
    }

    remove("DADOS.dat");
    system("mv AUX.dat DADOS.dat");
    Arquivos.close();
    ArqAuxiliar.close();
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Arquivos::NovoEquipamento(Equipamentos *B)
{
    fstream CadrastroEquipamentos("EQ.dat",ios::app|ios::binary); // abri o arquivo, mesmo se nao existir ele cria(app)

        if(!CadrastroEquipamentos.is_open())
        {
           fstream aux("EQ.dat",ios::out);    //  se nao existir o arquivo, o criamos....

           if(!aux)
              throw 1.2;  /// lança execessao
           aux.close();
           CadrastroEquipamentos.open("EQ.dat",ios::app|ios::binary); // para abrir no fluxo original

        }
    CadrastroEquipamentos.write((char *)B,sizeof(Equipamentos));
    CadrastroEquipamentos.close();
}

void Arquivos::PegaEquipamento(Equipamentos *B,int posicao)
{
    fstream CadrastroEquipamentos("EQ.dat",ios::in |ios::binary);
    // lancar exeção que o arquivo nao existir !!!

    CadrastroEquipamentos.seekg(posicao* sizeof(Equipamentos),ios::beg);

    CadrastroEquipamentos.read((char*)B,sizeof(Equipamentos));

    CadrastroEquipamentos.close();
}

void Arquivos::SobreescreveEquipamento(Equipamentos *B, int posicao)
{
    fstream CadrastroEquipamentos("EQ.dat",ios_base::in |ios_base::out|ios_base::binary); // abri o arquivo, mesmo se nao existir ele cria(app)

    CadrastroEquipamentos.seekp(posicao * sizeof(Equipamentos),ios_base::beg); //inicia a gravação nessa posicao

     if(!CadrastroEquipamentos.is_open())
    {
        throw "erro"; /// lança execessao se tiver acontecido merda
    }
    CadrastroEquipamentos.write((char *)B,sizeof(Equipamentos));

    CadrastroEquipamentos.close();
}


void Arquivos::EsvaziarLixeiraEquipamentos()
{
    fstream Arquivos("EQ.dat",ios_base::in);
    fstream ArqAuxiliar("AUX.dat",ios_base::app);
    /// colocar atributo lixo na classe cliente para faciliar o esvaziamento

    IndiceEq I;
    Equipamentos aux;
    int i,j = 0;

    int TAM = I.getqtd();
    for(i = 0 ; i < TAM ; i++)
    {
        Arquivos.read((char *)&aux,sizeof(Equipamentos));

        if(aux.getlixo())
        {
            I.IsolaINDEQ(aux.getcodigo()); /// EXCLUIR
        }
        else
        {
            ArqAuxiliar.write((char *)&aux,sizeof(Equipamentos));
            I.ModificaPosicao(aux.getcodigo(),j);
            j++;
        }
    }

    remove("EQ.dat");
    system("mv AUX.dat EQ.dat");
    Arquivos.close();
    ArqAuxiliar.close();
}

// // // ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Arquivos::NovoAluguel(INDALUGA *A)
{
    fstream arquivo("Alugueis.dat",ios_base::app | ios_base::binary);

    if(!arquivo.is_open())
    {
        fstream aux("Alugueis.dat",ios_base::out);
        aux.close();
        arquivo.open("Alugueis.dat",ios_base::app | ios_base::binary);
    }

    arquivo.write((char *)A,sizeof(INDALUGA));
    arquivo.close();
}

void Arquivos::PegaAluguel(INDALUGA *A,int posicao)
{
    fstream fluxo("Alugueis.dat",ios::in |ios::binary);

    fluxo.seekg(posicao* sizeof(INDALUGA),ios::beg);

    fluxo.read((char*)A,sizeof(INDALUGA));

    fluxo.close();
}

void Arquivos::SobreescreveAluguel(INDALUGA *A, int posicao)
{
    fstream FLUXO("Alugueis.dat",ios_base::in |ios_base::out|ios_base::binary); // abri o arquivo, mesmo se nao existir ele cria(app)

    FLUXO.seekp(posicao * sizeof(INDALUGA),ios_base::beg); //inicia a gravação nessa posicao

     if(!FLUXO.is_open())
    {
        throw "erro"; /// lança execessao se tiver acontecido merda
    }

    FLUXO.write((char *)A,sizeof(INDALUGA));

    FLUXO.close();
}

void Arquivos::EsvaziarLixeiraAluguel()
{
    fstream Arquivos("Alugueis.dat",ios_base::in);
    fstream ArqAuxiliar("AUX.dat",ios_base::app);
    /// colocar atributo lixo na classe cliente para faciliar o esvaziamento

    IndiceAl A;
    INDALUGA aux;
    int i,j = 0;

    int TAM = A.getqtd();

    for(i = 0 ; i < TAM ; i++)
    {
        Arquivos.read((char *)&aux,sizeof(INDALUGA));

        if(aux.getLixo())
        {
            A.IsolaINDALUGA(aux.getCodigoDoAluguel());
        }
        else
        {
            ArqAuxiliar.write((char *)&aux,sizeof(INDALUGA));
            A.ModificaPosicao(aux.getCodigoDoAluguel(),j);
            j++;
        }
    }

    remove("Alugueis.dat");
    system("mv AUX.dat Alugueis.dat");
    Arquivos.close();
    ArqAuxiliar.close();
}

Arquivos::Arquivos()
{

}
