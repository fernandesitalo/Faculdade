// ************************************************
//  Tratamento de Exceções
//  Exemplo 2 - Tratamento de erros de alocação com NEW
// ************************************************
#include <iostream>
#include <exception>
using std::cout;
using std::cin;
using std::endl;
using std::string;
//using std::set_terminate;
//using std::set_unexpected;
//using std::set_new_handler;


using std::bad_alloc;

void Encerra()
{
     cout << "Função Alternativa para encerramento..." << endl;    

}
void ExcecaoInesperada()
{
     cout << "Execeção Inesperada..." << endl;     

}

void TrataFalhaNoNew()
{
     cout << "O 'new' falhou..." << endl;     


}
class ErroMem
{
      public:
      ErroMem(char *s);
};
ErroMem::ErroMem(char *s)
{
    cout << s;
}

int main() 
{
     
    double *ptr;
    
     //set_terminate(Encerra);
     //set_unexpected(ExcecaoInesperada);
     //set_new_handler(TrataFalhaNoNew); // Isto impede o lançamento da
                                       // exceção na falha do new  
     try
     {
        while (1)
        {
              cout << "Tentando Alocar...\n";
              ptr = new double[500000];
             // if (!ptr) 
//              {
//                  cout << "Faltou Memoria !!!" << endl;
//                  system("pause");          
//                  throw (ErroMem("Memoria"));
//              }
        }
        
     }
     catch (std::exception &e) 
     {    
          cout << "Faltou Memoria...\n" << endl;  

          // no DEVCPP o método What gera "St9bad_alloc"             
        
     } // aqui o objeto T não existe mais !!
     cout << "Fim..." << endl;

     return 0;
}
/*     

*/
