/*
 *
 * EPI
 * Search a Maze (19.1)
 *
 */

#include <iostream>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::vector;

// @include
struct Coordinate {
  bool operator==(const Coordinate& that) const {
    return r == that.r && c == that.c;
  }
  int r, c;
};

bool is_valid(const Coordinate& c, const vector<vector<int>>& maze) {
  if (c.r >= 0 && c.r < maze.size() && c.c >= 0 && c.c < maze[c.r].size() &&
      maze[c.r][c.c] == 0) {
    return true;
  }
  return false;
}

bool find_path_helper(const Coordinate& c, const Coordinate& e,
                      vector<vector<int>>& maze,
                      vector<Coordinate>& path) {
  if (c == e) {
    return true;
  }

  vector<pair<int, int>> shift = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  for (auto s: shift) {
    Coordinate n = {c.r + s.first, c.c + s.second};
    if (is_valid(n, maze)) {
      path.push_back(n);
      maze[n.r][n.c] = 1;
      if (find_path_helper(n, e, maze, path)) {
        return true;
      }
      path.pop_back();
    }
  }
  return false;
}

vector<Coordinate> find_path(const Coordinate& s, const Coordinate& e,
                             vector<vector<int>> maze) {
  vector<Coordinate> path;
  path.push_back({s.r, s.c});
  maze[s.r][s.c] = 1;
  if (!find_path_helper(s, e, maze, path)) {
    path.pop_back();
  }
  return path;
}
// @exclude

int main(int argc, char* argv[]) {
  vector<vector<int>> maze(10);
  maze[0] = {1, 0, 0, 0, 0, 0, 1, 1, 0, 0};
  maze[1] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
  maze[2] = {1, 0, 1, 0, 0, 1, 1, 0, 1, 1};
  maze[3] = {0, 0, 0, 1, 1, 1, 0, 0, 1, 0};
  maze[4] = {0, 1, 1, 0, 0, 0, 0, 0, 0, 0};
  maze[5] = {0, 1, 1, 0, 0, 1, 0, 1, 1, 0};
  maze[6] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
  maze[7] = {1, 0, 1, 0, 1, 0, 1, 0, 0, 0};
  maze[8] = {1, 0, 1, 1, 0, 0, 0, 1, 1, 1};
  maze[9] = {1, 0, 1, 1, 0, 0, 0, 1, 1, 1};

  vector<Coordinate> path = find_path({9, 0}, {0, 9}, maze);

  for (auto c: path) {
    cout << c.r << "," << c.c << endl;
  }

  return 0;
}
