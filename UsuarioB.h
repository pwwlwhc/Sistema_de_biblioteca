#ifndef USUARIOB_H
#define USUARIOB_H

#include <string>
#include <vector>

class UsuarioB {
private:
    std::string nomeUsuario;
    std::string senha;
    std::string email;
    std::vector<std::string> *historicoEmprestimos;

public:
    UsuarioB(const std::string& nome, const std::string& senha, const std::string& email);
    const std::string& getNomeUsuario() const;
    const std::string& getSenha() const;
    const std::string& getEmail() const;
    std::vector<std::string> getHistorico();
    void adicionarHistorico(std::string codigoLivro);


};


#endif //USUARIOB_H
