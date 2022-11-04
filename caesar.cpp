#include <algorithm>
#include <cmath>
#include <string>
#include <cctype>
#include <limits>
#include <vector>
#include "funcs.h"

// Caesar cipher encryption
std::string encryptCaesar(std::string plaintext, int rshift)
{
    std::string s;
    for (auto& c : plaintext)
        s.push_back(shiftChar(c, rshift));
    return s;
}

double distance(std::vector<double> first, std::vector<double> second) {
    double sum;
    for(int i = 0; i < first.size(); i++) {
        sum += std::pow((first[i] - second[i]), 2);
    }
    return std::sqrt(sum);
}

std::string solve(std::string encrypted_string) {
    static constexpr std::size_t TOTAL_ALPHABET_LETTERS = 26;
    std::vector<double> FREQUENCY{0.084966, 0.020720, 0.045388, 0.033844, 0.111607, 0.018121, 0.024705, 0.030034, 0.075448, 0.001964, 0.011016, 0.054893, 0.030129, 0.066544, 0.071635, 0.031671, 0.001962, 0.075809, .057351, 0.069509, 0.036308, 0.010074, 0.012899, 0.002902, 0.017779, 0.002722};
    std::string encrypted_string_lower;
    std::transform(encrypted_string.cbegin(), encrypted_string.cend(), std::back_inserter(encrypted_string_lower), [](char c){return std::tolower(c);});
    const std::size_t TOTAL_STRING_LETTERS = std::count_if(encrypted_string_lower.cbegin(), encrypted_string_lower.cend(), [](char c){return std::isalpha(c);});

    int shift;
    double min_distance = std::numeric_limits<double>::max();
    for (int i = 0; i < TOTAL_ALPHABET_LETTERS; i++) {
        std::string cipher_text = encryptCaesar(encrypted_string_lower, i);
        std::vector<double> frequency(26);

        for (char c : cipher_text)
        {
            if(std::isalpha(c))
            {
                double letter_count = 0;
                for (int j = 0; j < cipher_text.length(); j++)
                    if (cipher_text[j] == c)
                        letter_count++;

                frequency[c - 'a'] = letter_count / TOTAL_STRING_LETTERS;
            }
            auto dist = distance(FREQUENCY, frequency);
            if(dist < min_distance) {
                min_distance = dist;
                shift = i;
            }
        }
    }
    return encryptCaesar(encrypted_string, shift);
}
