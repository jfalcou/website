#pragma once

#include <array>
#include <cstddef>

// Type vec(tor)

// Implementez vec, qui est un vecteur (au sens mathematique, pas un std::vector
// de taille dynamique). Les donnees sont stockees dans un std::array, et la
// structure fournit un operator[] (const et non-const), un constructeur par
// valeur pour initialiser toutes les valeurs (ce que ne fait pas std::array),
// et un membre size().

template <typename T, std::size_t N> struct vec
{
private:
 // A COMPLETER
public:
  vec(T const &val = T{})
  {
    // A COMPLETER
  }

  std::size_t size() const { /* A COMPLETER */ }

  // AJOUTER LES OPERATOR[]
};

// Sur le meme modele, implementez mat qui est un type matrice.
// Elle doit fournir un constructeur par valeur pour initialiser le contenu,
// des membres m() et n() pour acceder aux dimensions (respectivement hauteur
// et largeur), un operator()(std::size_t, std::size_t) (const et non-const)
// pour l'acces aux elements, ainsi que deux methodes col(std::size_t) et
// row(std::size_t), qui permettent d'extraire respectivement une colonne ou une
// ligne de la matrice.

template <typename T, std::size_t M, std::size_t N> struct mat
{
private:
 // A COMPLETER

public:
  mat(T const &val = T{})
  {
    // A COMPLETER
  }

  std::size_t n() const { /* A COMPLETER */ }
  std::size_t m() const { /* A COMPLETER */ }

  T const &operator()(std::size_t i, std::size_t j) const
  {
    // A COMPLETER
  }

  T &operator()(std::size_t i, std::size_t j)
  {
    // A COMPLETER
  }

  std::array<T, M> col(std::size_t j) const
  {
    // A COMPLETER
  }

  std::array<T, N> row(std::size_t i) const
  {
    // A COMPLETER
  }
};

// Implementez dot(vec, vec) qui effectue un produit scalaire
// entre deux vecteurs
template <typename T, std::size_t N>
T dot(vec<T, N> const &u, vec<T, N> const &v)
{
  // A COMPLETER
}

// Implementez un operator* entre deux objets de type vec, qui effectue un
// produit dyadique (https://fr.wikipedia.org/wiki/Produit_dyadique)
// Genere une matrice m dans laquelle chaque valeur aux coordonnees (i,j)
// vaut u[i] * v[j].

template <typename T, std::size_t M, std::size_t N>
mat<T, M, N> operator*(vec<T, M> const &u, vec<T, N> const &v)
{
  // A COMPLETER
}

// Implementez un operator* qui multiplie les valeurs de u par n
// (en faisant une copie ou transfert du vector)

template <typename T, std::size_t M>
vec<T, M> operator*(vec<T, M> u, T const &n)
{
  // A COMPLETER
}

int main()
{
  // IMPLEMENTER LES TESTS NECESSAIRES SUR LES OBJETS ET FONCTIONS DEFINIS
}