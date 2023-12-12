#include "headers/UsuarioB.h"
#include "headers/LivroB.h"
#include "headers/AcervoB.h"
#include "exceptions/usuarioDoesNotExistException.h"
#include "exceptions/livroNotFoundException.h"


#include <iostream>
#include <vector>


void exibirResultados(std::vector<LivroB>* resultados) {
    if (resultados->empty()) {
        std::cout << "Nenhum resultado encontrado." << std::endl;
    } else {
        std::cout << "========================================================================\nResultados encontrados:" << std::endl;
        for (const LivroB& livro : *resultados) {
            std::cout << "Título: " << livro.getTitulo() << std::endl;
            std::cout << "Autor: " << livro.getAutor() << std::endl;
            std::cout << "Edição: " << livro.getEdicao() << std::endl;
            std::cout << "Editora: " << livro.getEditora() << std::endl;
            std::cout << "Sinopse: " << livro.getSinopse() << std::endl;
            std::cout << "Número de Páginas: " << livro.getNumPaginas() << std::endl;
            std::cout << "Gênero: " << livro.getGenero() << std::endl;
            std::cout << "==========================" << std::endl;
        }
    }
}

void registrarUsuario(std::vector<UsuarioB*> &usuarios){
    std::string nome, senha, email;
    std::cout << "Digite o nome do usuário:\n> ";
    std::cin.ignore();
    std::getline(std::cin, nome);
    std::cout << "Digite a senha:\n> ";
    std::cin.sync();
    std::getline(std::cin, senha);
    std::cout << "Digite o email:\n> ";
    std::cin.sync();
    std::getline(std::cin, email);

    usuarios.push_back(new UsuarioB(nome, senha, email));
}

UsuarioB* trocarUsuario(std::vector<UsuarioB*> &usuarios){
    std::string email, senha;
    std::cout << "Digite o seu email: \n> ";
    std::cin.ignore();
    std::getline(std::cin, email);
    std::cout << "Digite a sua senha: \n> ";
    std::cin.sync();
    std::getline(std::cin, senha);


    //Trocar loop for para um while e botar os inputs dentro?
    for (auto *user : usuarios){
        if (email == user->getEmail() && senha == user->getSenha()){
            std::cout << "Usuario trocado com sucesso!\n";
            return user;
        }
    }
    throw usuarioDoesNotExistException("Usuario não encontrado");
}

void CriarLivro(AcervoB &acervo){
    std::string codigo, titulo, autor, edition, editora, sinopse, genero;
    int numero_paginas;

    std::cout << "Digite o código do livro: \n> ";
    std::cin.ignore();
    std::getline(std::cin, codigo);
    std::cin.sync();
    std::cout << "Digite o titulo do livro: \n> ";
    std::getline(std::cin, titulo);
    std::cout << "Digite o autor do livro: \n> ";
    std::cin.sync();
    std::getline(std::cin, autor);
    std::cout << "Digite a edição do livro: \n> ";
    std::cin.sync();
    std::getline(std::cin, edition);
    std::cout << "Digite a editora do livro: \n> ";
    std::cin.sync();
    std::getline(std::cin, editora);
    std::cout << "Digite a sinopse do livro: \n> ";
    std::cin.sync();
    std::getline(std::cin, sinopse);
    std::cout << "Digite o numero de paginas do livro: \n> ";
    std::cin.sync();
    std::cin >> numero_paginas;
    std::cin.ignore();
    std::cout << "Digite o gênero do livro: \n> ";
    std::getline(std::cin, genero);


    LivroB* livro = new LivroB(codigo, titulo, autor, edition, editora, sinopse, numero_paginas, genero);
    acervo.armazenarLivro(*livro);
}

void pesquisa(AcervoB& acervo){
    int input;
    std::string istr;
    while(true){
        std::cout << "\n===============================================\nEscolha o metodo de busca:\n1. Por codigo\n2. Por autor\n3. Por titulo\n4. Por genero\n0. Cancelar\n";
        std::cin >> input;
        switch (input) {
            case 1:
                std::cout << "Digite o codigo a buscar" << std::endl;
                std::cin.ignore();
                getline(std::cin, istr);
                try {
                    acervo.buscarLivroPorCodigo(istr)->mostrarInformacoes();
                }catch(livroNotFoundException &e){
                    std::cerr << e.what() << std::endl;
                }
                break;
            case 2:
                std::cout << "Digite o autor a buscar" << std::endl;
                std::cin.ignore();
                getline(std::cin, istr);
                acervo.realizarPesquisaPorAutor(istr);
                break;
            case 3:
                std::cout << "Digite o titulo para buscar" << std::endl;
                std::cin.ignore();
                getline(std::cin, istr);
                acervo.realizarPesquisaPorTitulo(istr);
                break;
            case 4:
                std::cout << "Digite o genero para buscar" << std::endl;
                std::cin.ignore();
                getline(std::cin, istr);
                acervo.realizarPesquisaPorGenero(istr);
                break;
            case 0:
                return;
            default:
                std::cout << "Input inválido" << std::endl;
                break;
        }
    }
}

void emprestimo(AcervoB &acervo, UsuarioB &usuario){
    std::string codigo;
    std::cout << "Digite o código do livro que deseja realizar o empréstimo: ";
    std::cin >> codigo;

    LivroB* livro = acervo.buscarLivroPorCodigo(codigo);

    acervo.registrarEmprestimo(*livro, usuario);
}

void devolucao(AcervoB &acervo){
    std::string codigo;
    std::cout << "Digite o código do livro que deseja devolver \n";
    std::cin >> codigo;

    LivroB* livro = acervo.buscarLivroPorCodigo(codigo);

    acervo.registrarDevolucao(*livro);
}

int main() {
    int input;
    std::string istr;
    std::vector<UsuarioB*> usuarios;
    UsuarioB* usuario_atual = nullptr;
    AcervoB acervo;
    UsuarioB user("Paulo", "password", "paulo@hotmail.com");
    LivroB* livro1 = new LivroB("8535914846", "Nineteen-Eighty-Four", "George Orwell", "1", "Companhia das Letras", "Winston, herói de 1984, último romance de George Orwell, vive aprisionado na engrenagem totalitária de uma sociedade completamente dominada pelo Estado, onde tudo é feito coletivamente, mas cada qual vive sozinho.", 416, "Ficção");
    LivroB* livro2 = new LivroB("420", "Como fazer \"Massinha\" com maizena e JavaScript", "Ana Maria Braga", "1", "Moderna", "Ana Maria Braga ensina a fazer \"Massinha\" com Javascript", 420, "Culinária");
    acervo.armazenarLivro(*livro1);
    acervo.armazenarLivro(*livro2);

    while(true){
        std::cout << "Digite o que quer fazer:\n1. Registrar usuário\n2. Trocar Usuário\n3. Adicionar livro\n";
        std::cout << "4. Fazer pesquisa\n";
        std::cout << "5. Exibir acervo completo\n6. Realizar empréstimo\n7. Realizar devolução\n";
        std::cout << "0. Sair\n> ";
        std::cin >> input;
        std::cin.sync();
        switch(input){
            case 1:
                registrarUsuario(usuarios);
                break;
            case 2:
                if(!usuarios.empty())
                    try {
                        usuario_atual = trocarUsuario(usuarios);
                    }catch (usuarioDoesNotExistException &e) {

                    }
                else
                    std::cout << "Não há usuários registrados.\n";
                break;
            case 3:
                if(usuario_atual)
                    CriarLivro(acervo);
                break;
            case 4:
                pesquisa(acervo);
                break;
            case 5:
                std::cout << "Exibir acervo completo\n" << std::endl;
                exibirResultados(acervo.getVecAcervo());
                break;
            case 6:
                if(usuario_atual) {
                    try{
                        emprestimo(acervo, *usuario_atual);
                    }catch(livroNotFoundException& e){
                        std::cerr << e.what() << std::endl;
                    }
                }
                break;
            case 7:
                if(usuario_atual){
                    try{
                        devolucao(acervo);
                    }catch(livroNotFoundException& e){
                        std::cerr << e.what() << std::endl;
                    }
                }
                break;
            case 0:
                std::cout << "Encerrando programa" << std::endl;
                return 0;
            default:
                std::cout << "Input inválido.\n";
                break;
        }
    }
}