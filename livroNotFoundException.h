#ifndef BUNDASUJA_LIVRONOTFOUNDEXCEPTION_H
#define BUNDASUJA_LIVRONOTFOUNDEXCEPTION_H
#include <stdexcept>


class livroNotFoundException : std::invalid_argument{
public:
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
    explicit livroNotFoundException(const std::string &arg);
};


#endif //BUNDASUJA_LIVRONOTFOUNDEXCEPTION_H
