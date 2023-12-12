#ifndef LIVRONOTFOUNDEXCEPTION_H
#define LIVRONOTFOUNDEXCEPTION_H
#include <stdexcept>


class livroNotFoundException : std::invalid_argument{
public:
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
    explicit livroNotFoundException(const std::string &arg);
};


#endif //LIVRONOTFOUNDEXCEPTION_H
