#include "headers/UsuarioB.h"
#include <vector>

UsuarioB::UsuarioB(const std::string& nome, const std::string& senha, const std::string& email)
        : nomeUsuario(nome), senha(senha), email(email) {
    historicoEmprestimos = new std::vector<std::string>;
}

const std::string& UsuarioB::getNomeUsuario() const {
    return nomeUsuario;
}

const std::string& UsuarioB::getSenha() const {
    return senha;
}

const std::string& UsuarioB::getEmail() const{
    return email;
}

std::vector<std::string> UsuarioB::getHistorico(){
    return *historicoEmprestimos;
}

void UsuarioB::adicionarHistorico(std::string codigoLivro) {
    if(!historicoEmprestimos)
        historicoEmprestimos = new std::vector<std::string>;

    historicoEmprestimos->push_back(codigoLivro);
}
