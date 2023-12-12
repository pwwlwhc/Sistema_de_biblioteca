#include "usuarioDoesNotExistException.h"

usuarioDoesNotExistException::usuarioDoesNotExistException(const std::string &arg) : invalid_argument(arg) {}

const char *usuarioDoesNotExistException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
    return "Tentativa de acesso de usuario inexistente!";
}
