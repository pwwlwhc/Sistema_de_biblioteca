#ifndef LIVROB_H
#define LIVROB_H

#include <vector>
#include <string>
#include "UsuarioB.h"

class LivroB {
private:
    UsuarioB* curUser;
    std::string codigoCadastro;
    std::string titulo;
    std::string autor;
    std::string edicao;
    std::string editora;
    std::string sinopse;
    int numPaginas;
    std::string genero;
    bool disponivel;
public:
    LivroB(std::string codigo, std::string t, std::string a, std::string e, std::string ed, std::string s, int np, std::string gen);

    UsuarioB *getCurUser() const;

    void setCurUser(UsuarioB *curUser);

    const std::string &getCodigoCadastro() const;

    void setCodigoCadastro(const std::string &codigoCadastro);

    const std::string &getTitulo() const;

    void setTitulo(const std::string &titulo);

    const std::string &getAutor() const;

    void setAutor(const std::string &autor);

    const std::string &getEdicao() const;

    void setEdicao(const std::string &edicao);

    const std::string &getEditora() const;

    void setEditora(const std::string &editora);

    const std::string &getSinopse() const;

    void setSinopse(const std::string &sinopse);

    int getNumPaginas() const;

    void setNumPaginas(int numPaginas);

    const std::string &getGenero() const;

    void setGenero(const std::string &genero);

    bool isDisponivel() const;

    void setDisponivel(bool disponivel);

    void mostrarInformacoes() const;
    void atualizarInformacoes();
    void marcarComoDisponivel();
    void marcarComoIndisponivel();
    void atualizarTitulo(const std::string& novoTitulo);
    void atualizarSinopse(const std::string& novaSinopse);

    bool operator==(const LivroB &rhs) const;

    virtual ~LivroB();
};


#endif //BULIVROB_H
