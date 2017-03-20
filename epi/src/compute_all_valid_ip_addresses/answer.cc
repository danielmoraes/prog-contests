/*
 *
 * EPI
 * Compute All Valid IP Addresses (7.10)
 *
 */

#include <vector>
#include <string>
#include <utils.h>

using std::stoi;
using std::string;
using std::vector;

bool is_valid_part(const string& s);

// @include
vector<string> compute_valid_ip_addresses(const string& s) {
  vector<string> valid_ips;

  for (unsigned int i = 0; i < s.length() - 3; ++i) {
    string part1 = s.substr(0, i + 1);
    if (!is_valid_part(part1)) continue;

    for (unsigned int j = i + 1; j < s.length() - 2; ++j) {
      string part2 = s.substr(i + 1, j - i);
      if (!is_valid_part(part2)) continue;

      for (unsigned int k = j + 1; k < s.length() - 1; ++k) {
        string part3 = s.substr(j + 1, k - j), part4 = s.substr(k + 1);
        if (!is_valid_part(part3) || !is_valid_part(part4)) continue;

        string ip = part1 + "." + part2 + "." + part3 + "." + part4;
        valid_ips.push_back(ip);
      }
    }
  }
  return valid_ips;
}

bool is_valid_part(const string& part) {
  if (part.size() > 3) {
    return false;
  }

  if (part.front() == '0' && part.length() > 1) {
    return false;
  }

  return (stoi(part) >= 0 && stoi(part) <= 255);
}
// @exclude

int main(int argc, char* argv[]) {
  print_vector(compute_valid_ip_addresses("19216811"));
  return 0;
}
