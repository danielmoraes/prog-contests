/*
 *
 * EPI
 * Enumerate All Primes to N (6.8)
 *
 */

#include <math.h>
#include <utils.h>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

// x is prime if it is not multiple of any prime
// compare x to previous computed primes
vector<int> primes_brute_force(int n) {
  vector<int> primes_vec {2};
  // iterate over the odd numbers
  for (int i = 3; i <= n; i += 2) {
    bool is_prime = true;
    // exclude multiples of odd primes
    for (int j = 1; j < primes_vec.size(); j++) {
      if (i % primes_vec[j] == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime) {
      primes_vec.push_back(i);
    }
  }
  return primes_vec;
}

// if x is prime, exclude from the list of potential primes all multiples of x
// O(n lg lg n)
vector<int> primes_exclude_multiples(int n) {
  vector<int> primes;
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = false;
  is_prime[1] = false;
  for (int i = 2; i < n; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return primes;
}

// if x is prime, exclude from the list of potential primes all multiples of x
// that is greater than x^2
// O(n lg lg n)
vector<int> primes_exclude_multiples_improved(int n) {
  vector<int> primes;
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = false;
  is_prime[1] = false;
  for (int i = 2; i < n; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (long j = pow(i, 2); j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return primes;
}

int main() {
  int n = 1000;
  vector<int> a = primes_brute_force(n);
  vector<int> b = primes_exclude_multiples(n);
  vector<int> c = primes_exclude_multiples_improved(n);
  assert(a == b && a == c);
  print_vector(a);
  return 0;
}
