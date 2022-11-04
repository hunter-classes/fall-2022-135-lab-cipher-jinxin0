#include <string>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"

TEST_CASE("Caesar Cipher")
{
    CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
    CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
    CHECK(encryptCaesar("Hello, World!", 36) == "Rovvy, Gybvn!");
}

TEST_CASE("SOLVE CAESAR")
{
    std::string a = "This is a long and unique test string use for testing.";
    std::string b = "An apple is growing on an apple tree on the beach.";
    std::string c = "A quick brown fox jumped over the lazy dog.";
    CHECK(solve(encryptCaesar(a, 123)) == a);
    CHECK(solve(encryptCaesar(b, 321)) == b);
    CHECK(solve(encryptCaesar(c, 12)) == c);
}

