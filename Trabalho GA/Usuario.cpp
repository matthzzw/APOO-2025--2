#include "Usuario.h"

Usuario::Usuario() : nomeUsuario(""), senha("") {}
Usuario::Usuario(const std::string& nome, const std::string& pwd) : nomeUsuario(nome), senha(pwd) {}
bool Usuario::verificarLogin(const std::string& nome, const std::string& pwd) const {
    return (this->nomeUsuario == nome && this->senha == pwd);
}
std::string Usuario::getNomeUsuario() const { return nomeUsuario; }
Album& Usuario::getAlbum() { return album; }