#ifndef ACERVOB_H
#define ACERVOB_H


#include "LivroB.h"
#include <vector>
#include <iostream>


class AcervoB {
//    AcervoB();

    std::vector<LivroB>* vecAcervo;



public:
    AcervoB();
    std::vector<LivroB> *getVecAcervo() const;

    virtual ~AcervoB();

    void setVecAcervo(std::vector<LivroB> *vecAcervo);
    bool hasLivro(const LivroB& livro);
    void armazenarLivro(LivroB& livro);
    LivroB* buscarLivroPorCodigo(const std::string& codigo);

    std::vector<LivroB> * agruparPorGenero();
    std::vector<LivroB> * agruparPorAutor();

    void registrarEmprestimo(LivroB& livro, UsuarioB& usuario);
    void registrarDevolucao(LivroB& livro);


    void realizarPesquisaPorTitulo(const std::string& titulo);
    void realizarPesquisaPorAutor(const std::string& autor);
    void realizarPesquisaPorGenero(const std::string &genero);
};


#endif //ACERVOB_H
