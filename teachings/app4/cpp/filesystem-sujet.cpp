#include <memory>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

/// On implemente un simulateur de systeme de fichier.
///
/// Un systeme de fichier contient:
///   - des fichiers définis par un nom et une taille en octet
///   - des répertoires qui contiennent des fichiers ou des répertoires et qui sont
///     définis par un nom
///
/// Les opérations qui nous intéressent sont: 
///   - la création d'une chaine de caractère représentant l'arborescence des fichiers 
///     affichant nom et taille
///   - le calcul récursif de l'espace disque consommée par l'ensemble des fichiers

/// La classe node définit l'interface de travail sur les éléments
/// du système de fichier.
struct node
{
  // level: niveau d'indentation, ie le nombre de paire d'espace blanc
  // à insérer devant la sortie
  virtual std::string ls(int level = 0) const = 0;
  virtual std::size_t du() const = 0;
  virtual ~node() {}
};

/// La classe file représente un fichier dans l'arborescence
/// Elle contient:
///   - un membre de type chaine de caractere contenant le nom du fichier
///   - un membre de type std::size_t contenant la taille en octet du fichier
/// Implémentez les éléments nécessaires pour que file soit complet.
/// Utilisez les tests pour structurer la chaine construite par ls()
struct file : public node
{

};

/// La classe folder représente un répertoire dans l'arborescence
/// Elle contient:
///   - un membre de type chaine de caractere contenant le nom du répertoire
///   - un membre contenant l'ensemble des sous-node du répertoire
///
/// Implémentez les éléments nécessaires pour que folder soit complet.
/// Respectez la Règle du Zero et utilisez les bons types pour le stockage des
/// sous-nodes.
/// 
/// Utilisez les tests pour structurer la chaine construite par ls()
/// La taille renvoyée par du() est la somme récursive des tailles de toutes
/// les nodes contenues dans un répertoire
struct folder : public node
{
  /// Ajoute un file à l'intérieur du folder
  void add(file&& f)    { }
  
  /// Ajoute un folder à l'intérieur du folder
  void add(folder&& f)  { }
};

int main(int argc, char const *argv[]) 
{
  file movie("avatar2.mp4", 4000000);
  assert( movie.du() == 4000000 );
  assert( movie.ls() == "avatar2.mp4 : 4000000" );

  folder home("/");
  assert( home.du() == 0 );
  assert( home.ls() == "/" );

  folder f("data");
  assert( f.du() == 0 );
  assert( f.ls() == "data" );

  f.add( file("test.txt" , 128)   );
  assert( f.du() == 128 );
  assert( f.ls() == "data\n"
                    "  test.txt : 128"
        );

  f.add( file("test2.txt", 128)    );
  assert( f.du() == 256 );
  assert( f.ls() == "data\n"
                    "  test.txt : 128\n"
                    "  test2.txt : 128" 
        );
  
  home.add( std::move(f) );
  home.add( file("test3.bin.copy", 100000) );
  assert( home.du() == 100256 );
  assert( home.ls() == "/\n"
                       "  data\n"
                       "    test.txt : 128\n"
                       "    test2.txt : 128\n"
                       "  test3.bin.copy : 100000" 
        );

  std::cout << home.ls() << "\n";
  std::cout << home.du() << "\n";
}