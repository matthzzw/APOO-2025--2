#ifndef USUARIO_H
#define USUARIO_H
#include "Album.h"
#include <string>

class Usuario {
private:
    std::string nomeUsuario;
    std::string senha;
    Album album;
public:
    Usuario();
    Usuario(const std::string& nomeUsuario, const std::string& senha);
    bool verificarLogin(const std::string& nome, const std::string& senha) const;
    std::string getNomeUsuario() const;
    Album& getAlbum();
};
#endif