/*
 * Codility - Find the minimal nucleotide from a range of sequence DNA.
 *
 * Lesson: 5 (PrefixSums)
 * Problem code: GenomicRangeQuery
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::vector;

// @include
unordered_map<char, int> impact_factors = {{ {'A', 1}, {'C', 2}, {'G', 3},
                                             {'T', 4} }};

vector<int> genomic_range_query(string &S, vector<int> &P, vector<int> &Q) {
  // index i stores the number of nucleotides within the subarray [0 .. i]
  vector<vector<int>> nucleotides_up_to(S.size());

  // number of nucleotides seen so far
  vector<int> nucleotides_count(5, 0);
  for (int i = 0; i < S.size(); ++i) {
    // for each nucleodite type
    nucleotides_up_to[i] = vector<int>(5);

    // we saw a new nucleodite; increments the counter
    nucleotides_count[impact_factors[S[i]]]++;

    for (int j = 1; j <= 4; ++j) {
      nucleotides_up_to[i][j] = nucleotides_count[j];
    }
  }

  vector<int> result;
  for (int i = 0; i < P.size(); ++i) {
    for (int j = 1; j <= 4; ++j) {
      // the number of nucleodites with impact j within [P .. Q]
      // is the number within [0 .. Q] - the number within [0 .. P - 1]
      int before = (P[i] > 0) ? nucleotides_up_to[P[i] - 1][j] : 0;
      int after = nucleotides_up_to[Q[i]][j];
      if ((after - before) > 0) {
        result.push_back(j);
        break;
      }
    }
  }

  return result;
}
// @exclude

int main(int argc, char* argv[]) {
  string S = "CAGCCTA";
  vector<int> P = {2, 5, 0};
  vector<int> Q = {4, 5, 6};
  for (auto v : genomic_range_query(S, P, Q)) {
    cout << v << endl;
  }
  return 0;
}
