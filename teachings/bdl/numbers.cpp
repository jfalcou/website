/*
 Entiers arbitraires

  Les entiers sont représentes en C++ par une série de bit de taille fixe. Cela implique
  un certain nombre de limitation. Dans cette exercice, nous allons implémenter un systême
  permettant de représenter un entier comme une série de chiffre de longueur arbitraire.
*/

/*
  ETAPE 1
  * Implémentez une enumeration digit qui contient des valeur énumérés pour les valeurs 0 à 9
    nommées digit0, digit1, etc...

  * Implémentez une fonction to_digit qui prend un entier en paramètre et renvoi l'énuméré de digit
    correspondant. Ex to_digit(2) renvoi digit::digit2. Utilisez assert() pour vérifier que l'entier
    en entrée est bien compris entre 0 et 9 inclus.

  * Ecrivez une fonction to_int qui prend un digit en entrée et renvoi l'entier correspondant.

  Pour ces deux fonctions, écrivez une fonction test_digit qui vérifie le comportement de ces
  fonctions de manière convaincante.
*/

enum class digit { /* A COMPLETER */ };

digit to_digit(int)  { /* A COMPLETER */  return {};  }
int   to_int(digit)  { /* A COMPLETER */  return 0;   }

void test_digit()
{
  /* A COMPLETER */
}

/*
  ETAPE 2
  * Implémentez une fonction decompose qui prend un nombre entier 64 bits non-signé et le decompose
    en la liste de ses chiffres. Cette decomposition sera renvoyée sous la forme d'un tableau de digit.

  Ecrivez une fonction test_decompose qui verifie le comportement de cette fonction de manière
  convaincante.
*/

#include <vector>
#include <cstdint>

std::vector<digit> decompose(std::uint64_t n)
{
  /* A COMPLETER */
  return {};
}

void test_decompose()
{
  /* A COMPLETER */
}

/*
  ETAPE 3
  * Implementez une structure number contenant un tableau de digit représentant les
    chiffres d'un nombre et un bool représentant son signe.

  * Implementez une fonction as_number qui convertit un entier 64 bits en une instance
    de la structure number. Réutilisez au plus les éléments déjà définis.

  * Implementez une fonction as_number qui convertit une chaine de caractere contenant
    un entier de taille arbitraire en une instance de la structure number.
    Réutilisez au plus les éléments déjà définis.

  Ecrivez une fonction test_as_number qui verifie le comportement de cette fonction de manière
  convaincante.
*/

#include <string>

struct number
{

};

number as_number(std::int64_t n)
{
  /* A COMPLETER */
  return {};
}


number as_number(std::string const& s)
{
  /* A COMPLETER */
  return {};
}

void test_as_number()
{
  /* A COMPLETER */
}

/*
  ETAPE 4
  * Implementez un operator<< permettant d'inserer une instance de number dans un flux de sortie

  Ecrivez une fonction test_stream qui verifie le comportement de ces fonctions de manière
  convaincante. Vous utiliserez pour ca un flux de chaine afin que votre test ne depende pas d'I/O
  clavier.
*/
#include <iostream>

std::ostream& operator<<(std::ostream& os, number const& n)
{
  /* A COMPLETER */
  return os;
}

void test_stream()
{
  /* A COMPLETER */
}

/*
  ETAPE 5
  * Implementez un operator+ permettant d'effectuer la somme de deux numbers s'ils sont positifs
    (bonus: gérer aussi les cas où ils peuvent être négatifs).

  Ecrivez une fonction test_add qui verifie le comportement de ces fonctions de manière
  convaincante.
*/
number operator+(number const& a, number const& b)
{
  /* A COMPLETER */
  return {};
}

void test_add()
{
  /* A COMPLETER */
}

/*
  ETAPE 6
  * Implementez une fonction abs  qui renvoit la valeur absolu d'un number
  * Implementez une fonction is_even  qui verifie si un number est pair
  * Implementez une fonction is_divisible_by_3  qui verifie si un number est divisible par 3
  * Implementez une fonction is_divisible_by_5  qui verifie si un number est divisible par 5
  * Implementez une fonction is_divisible_by_10 qui verifie si un number est divisible par 10
  * Implementez une fonction magnitude qui renvoit le nombre p tel que la valeur absolue de n
    est strictement superieur a 10^p. Par exemple, magnitude(-758) = 2 car 758 > 100 mais 758 < 1000.

  On rappel que n est divisible par 3 si la somme de ses chiffres est elle-même divisible par 3.

  Vous implémenterez toutes fonctions intermediaires necessaires au fonctionnement de ces
  fonctions.

  Ecrivez une fonction test_tests qui verifie le comportement de ces fonctions de manière
  convaincante.
*/

number abs( number const& n )               { /* A COMPLETER */ return {}; }
bool is_even( number const& n )             { /* A COMPLETER */ return {}; }
bool is_divisible_by_3( number const& n )   { /* A COMPLETER */ return {}; }
bool is_divisible_by_5( number const& n )   { /* A COMPLETER */ return {}; }
bool is_divisible_by_10( number const& n )  { /* A COMPLETER */ return {}; }
int magnitude( number const& n )            { /* A COMPLETER */ return {}; }

void test_tests()
{
}

int main()
{
  test_digit();
  test_decompose();
  test_as_number();
  test_stream();
  test_add();
  test_tests();
}
