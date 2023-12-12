#ifndef USUARIODOESNOTEXISTEXCEPTION_H
#define USUARIODOESNOTEXISTEXCEPTION_H


#include <stdexcept>

class usuarioDoesNotExistException : std::invalid_argument{
public:
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
    explicit usuarioDoesNotExistException(const std::string &arg);
};


#endif //USUARIODOESNOTEXISTEXCEPTION_H
