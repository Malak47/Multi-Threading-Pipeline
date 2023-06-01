//
// Created by malaklinux on 5/31/23.
//

#include "prime_util.hpp"


bool primeUtil::is_prime(unsigned int number) {
    if (number <= 1) {
        return false;
    }

    if (number == 2) {
        return true;
    }

    if (number % 2 == 0) {
        return false;
    }

    for (unsigned int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}
