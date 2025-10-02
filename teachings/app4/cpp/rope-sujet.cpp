#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>

/// Structure de corde (rope):
/// - substrings : un tableau de sous-chaînes uniques
/// - index_list : une séquence d'indices qui pointent vers les sous-chaînes dans substrings
///
/// Pour obtenir la chaîne finale, on concatène les sous-chaînes dans l'ordre
/// défini par index_list. Cette approche évite la duplication de sous-chaînes
/// identiques.
///
/// Exemple :
///
/// substrings = { "lol", "il", "ol" }
/// index_list = { 0, 1, 2, 1, 2 }
///
/// => "lolilolilol"

struct rope_t
{
  std::vector<std::string> substrings;
  std::vector<std::size_t> index_list;

  /// Constructeur de rope_t par std::initializer_list<std::string>.
  /// Pour chaque element de la liste, on vérifie s'il n'existe pas deja dans la
  /// liste des sous-chaines. Si c'est le cas on ajoute seulement l'index
  /// vers la sous-chaine qui correspond, sinon on ajoute la sous-chaine a
  /// substrings et on ajoute l'index vers ce nouvel element dans index_list.
  ///
  /// std::initializer_list fonctionne comme une sequence classique et peut
  /// être utilisé directement avec for(auto e : )
  ///
  /// Input example: {"lol", "ol", "ol", "il"}
  /// Result:
  /// substrings = { "lol", "ol", "il" }
  /// index_list = { 0, 1, 1, 2 }
  rope_t(std::initializer_list<std::string> list)
  {
    /// TODO
  }
  // Indice : n'hésitez pas à vous aider de std::find.

  /// Renvoie la taille du resultat de la corde en nombre de caracteres.
  std::size_t size() const
  {
    std::size_t res = 0;
    /// TODO
    return res;
  }
};

// Questions:
// - Que se passe-t-il a la destruction ?
//
// Réponse: A COMPLETER

// - On pourrait stocker des pointeurs ou iterateurs vers des strings...
//   Quel serait le souci ?
//
// Réponse: A COMPLETER


// Implementer le reste.

/// Renvoie la chaine representee par r.
std::string to_string(rope_t const &r)
{
  std::string res;
  // TODO
  return res;
}

/// Concatène la chaine str a la corde rope.
rope_t operator+(rope_t r, std::string const& str)
{
  // TODO
  return r;
}

/// Concatène la corde r a la suite de la corde l.
/// Veillez a réutiliser les substrings de l des que possible.
///
/// eg.:
/// l =     {.substrings = {"a", "b"}, .index_list = {0,1,1,0}}
/// r =     {.substrings = {"a", "b", "c"}, .index_list = {0,0,1,0,2}}
/// l + r = {.substrings = {"a", "b", "c"}, .index_list = {0,1,1,0,0,0,1,0,2}}
rope_t operator+(rope_t l, rope_t const &r)
{
  // TODO

  return l;
}

/// Renverse la corde r tel que le resultat soit renverse lettre par lettre.
rope_t reverse(rope_t r)
{
  // TODO
}

int main(int argc, char const *argv[])
{
  rope_t r = {"lol", "il", "ol", "ol"};

  assert(to_string(r) == "lolilolol");
  assert(to_string(reverse(r)) == "lololilol");
  assert(to_string(reverse(r) + r) == "lololilollolilolol");
}
