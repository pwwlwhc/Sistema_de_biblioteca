#include "headers/LivroB.h"
#include <vector>
#include <iostream>

bool LivroB::operator==(const LivroB &rhs) const {
    return codigoCadastro == rhs.codigoCadastro;
}

LivroB::LivroB(std::string codigo, std::string t, std::string a, std::string e, std::string ed, std::string s, int np, std::string gen)
        : codigoCadastro(codigo), titulo(t), autor(a), edicao(e), editora(ed), sinopse(s), numPaginas(np), genero(gen), disponivel(false) {}


void LivroB::mostrarInformacoes() const {
    std::cout << "\n============================\nCódigo de Cadastro: " << codigoCadastro << std::endl;
    std::cout << "Título: " << titulo << std::endl;
    std::cout << "Autor: " << autor << std::endl;
    std::cout << "Edição: " << edicao << std::endl;
    std::cout << "Editora: " << editora << std::endl;
    std::cout << "Sinopse: " << sinopse << std::endl;
    std::cout << "Número de Páginas: " << numPaginas << std::endl;
    std::cout << "Genero: " << genero << std::endl;
    std::cout << "Disponível: " << (disponivel ? "Sim" : "Não") << std::endl;
}

void LivroB::atualizarTitulo(const std::string& novoTitulo) {
    titulo = novoTitulo;
}

void LivroB::atualizarSinopse(const std::string& novaSinopse) {
    sinopse = novaSinopse;
}

UsuarioB *LivroB::getCurUser() const {
    return curUser;
}

void LivroB::setCurUser(UsuarioB *curUser) {
    LivroB::curUser = curUser;
}

const std::string &LivroB::getCodigoCadastro() const {
    return codigoCadastro;
}

void LivroB::setCodigoCadastro(const std::string &codigoCadastro) {
    LivroB::codigoCadastro = codigoCadastro;
}

const std::string &LivroB::getTitulo() const {
    return titulo;
}

void LivroB::setTitulo(const std::string &titulo) {
    LivroB::titulo = titulo;
}

const std::string &LivroB::getAutor() const {
    return autor;
}

void LivroB::setAutor(const std::string &autor) {
    LivroB::autor = autor;
}

const std::string &LivroB::getEdicao() const {
    return edicao;
}

void LivroB::setEdicao(const std::string &edicao) {
    LivroB::edicao = edicao;
}

const std::string &LivroB::getEditora() const {
    return editora;
}

void LivroB::setEditora(const std::string &editora) {
    LivroB::editora = editora;
}

const std::string &LivroB::getSinopse() const {
    return sinopse;
}

void LivroB::setSinopse(const std::string &sinopse) {
    LivroB::sinopse = sinopse;
}

int LivroB::getNumPaginas() const {
    return numPaginas;
}

void LivroB::setNumPaginas(int numPaginas) {
    LivroB::numPaginas = numPaginas;
}

const std::string &LivroB::getGenero() const {
    return genero;
}

void LivroB::setGenero(const std::string &genero) {
    LivroB::genero = genero;
}

bool LivroB::isDisponivel() const {
    return disponivel;
}

void LivroB::setDisponivel(bool disponivel) {
    LivroB::disponivel = disponivel;
}

LivroB::~LivroB() {
    delete curUser;
}

