
#include "Album.h"
#include "Figurinha.h"
using namespace std;

int main() {
    Album meuAlbum;

    Figurinha f1(1, "Neymar", "Santos");
    Figurinha f2(2, "Messi", "Inter Miami");
    Figurinha f3(3, "Cristiano", "Al Nassr");

    meuAlbum.adicionar(f1);
    meuAlbum.adicionar(f2);
    meuAlbum.adicionar(f3);

    if (meuAlbum.possui(2)) {
        cout << "Album possui a figurinha numero 2." << endl;
    } else {
        cout << "Album nao possui a figurinha numero 2." << endl;
    }

    cout << "\nFigurinhas do album:" << endl;
    meuAlbum.listar();

    return 0;
}
