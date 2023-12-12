#include "headers/AcervoB.h"
#include "headers/LivroB.h"
#include "headers/UsuarioB.h"
#include "exceptions/livroNotFoundException.h"
#include <map>

AcervoB::AcervoB() {
    vecAcervo = new std::vector<LivroB>;
}

void AcervoB::armazenarLivro(LivroB &livro) {
    if(!vecAcervo)
        vecAcervo = new std::vector<LivroB>;
    livro.setDisponivel(true);
    vecAcervo->push_back(livro);
}

LivroB* AcervoB::buscarLivroPorCodigo(const std::string &codigo) {
    if(vecAcervo){
        for (const LivroB &livro: *vecAcervo) {
            if (livro.getCodigoCadastro() == codigo) {
                return const_cast<LivroB *>(&livro);
            }
        }
    }
    throw livroNotFoundException("Livro não encontrado no Acervo.\n");
}


void AcervoB::realizarPesquisaPorAutor(const std::string &autor) {
    if(vecAcervo){
        for (const LivroB& livro: *vecAcervo) {
            if (livro.getAutor() == autor){
                livro.mostrarInformacoes();
            }
        }
    }
}
void AcervoB::realizarPesquisaPorTitulo(const std::string& titulo)  {
    if(vecAcervo) {
        for (const LivroB& livro: *vecAcervo) {
            if (livro.getTitulo() == titulo) {
                // Exibir informações do livro encontrado
                livro.mostrarInformacoes();
            }
        }
    }
}

void AcervoB::realizarPesquisaPorGenero(const std::string &genero) {
    if(vecAcervo){
        for (const auto &livro: *vecAcervo) {
            if (livro.getGenero() == genero) {
                livro.mostrarInformacoes();
            }
        }
    }
}

void AcervoB::registrarEmprestimo(LivroB &livro, UsuarioB &usuario) {
    if (!hasLivro(livro))
        throw livroNotFoundException("Livro não encontrado no Acervo.\n");
    else if (!livro.isDisponivel())
        std::cout << "O livro não está disponível para empréstimo.\n";
    else{
        livro.setCurUser(&usuario);
        usuario.adicionarHistorico(livro.getCodigoCadastro());
        livro.setDisponivel(false);
        std::cout << "Empréstimo realizado com sucesso.\n";
    }
}

void AcervoB::registrarDevolucao(LivroB &livro) {
    if(!hasLivro(livro))
        throw livroNotFoundException("Livro não encontrado no Acervo. \n");

    if (livro.getCurUser()){
        livro.setCurUser(nullptr);
    }else{
        std::cout << "O livro não está emprestado!\n";
    }

}

std::vector<LivroB> *AcervoB::getVecAcervo() const {
    return vecAcervo;
}

void AcervoB::setVecAcervo(std::vector<LivroB> *vecAcervo) {
    AcervoB::vecAcervo = vecAcervo;
}

AcervoB::~AcervoB() {
    delete vecAcervo;
}

bool AcervoB::hasLivro(LivroB const& livro) {
    for(const LivroB& l : *vecAcervo){
        if(livro == l){
            return true;
        }
    }
    return false;
}

