#include "livroNotFoundException.h"


livroNotFoundException::livroNotFoundException(const std::string &arg) : invalid_argument(arg) {}

const char *livroNotFoundException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
    return "O livro desejado não foi encontrado!";
}
