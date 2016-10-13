#include <vector>
#include <iostream>

using namespace std;


void print_grid(const vector<char>& grid, int r, int c) {
  for (int r_i = 0; r_i < r; r_i++) {
    for (int c_i = 0; c_i < c; c_i++) {
      cout << grid[(r_i * c) + c_i];
    }
    cout << endl;
  }
}

void explode(const vector<char>& grid_in, vector<char>& grid_out,
             int r, int c) {
  for (int r_i = 0; r_i < r; r_i++) {
    for (int c_i = 0; c_i < c; c_i++) {
      int pos = (r_i * c) + c_i;
      if (grid_in[pos] == '.' &&
          (r_i == 0 || grid_in[pos - c] == '.') &&
          (c_i == 0 || grid_in[pos - 1] == '.') &&
          (r_i == (r - 1) || grid_in[pos + c] == '.') &&
          (c_i == (c - 1) || grid_in[pos + 1] == '.')) {
        grid_out[pos] = 'O';
      } else {
        grid_out[pos] = '.';
      }
    }
  }
}

bool is_same_grid(const vector<char>& grid_a, const vector<char>& grid_b,
                  int r, int c) {
  for (int r_i = 0; r_i < r; r_i++) {
    for (int c_i = 0; c_i < c; c_i++) {
      int pos = (r_i * c) + c_i;
      if (grid_a[pos] != grid_b[pos]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int r, c, n;
  cin >> r >> c >> n;

  if (n < 2) {  // print the input grid

    char el;
    for (int r_i = 0; r_i < r; r_i++) {
      for (int c_i = 0; c_i < c; c_i++) {
        cin >> el;
        cout << el;
      }
      cout << endl;
    }

  } else if (n % 2 == 0) {  // print grid full of bombs

    for (int r_i = 0; r_i < r; r_i++) {
      for (int c_i = 0; c_i < c; c_i++) {
        cout << 'O';
      }
      cout << endl;
    }

  } else {  // explode until converges

    vector< vector<char> > history(2);  // circular array
    int history_count = 0;

    vector<char> grid(r * c);
    for (int r_i = 0; r_i < r; r_i++) {
      for (int c_i = 0; c_i < c; c_i++) {
        int pos = (r_i * c) + c_i;
        cin >> grid[pos];
      }
    }
    history[0] = grid;
    history_count++;

    for (int i = 0; i < (n - 1) / 2; i++) {
      vector<char> previous_grid = history[(history_count - 1) % 2];
      vector<char> new_grid(r * c);
      explode(previous_grid, new_grid, r, c);
      if (history_count >= 2 &&
          is_same_grid(new_grid, history[history_count % 2], r, c)) {
        break;  // converges
      } else {
        history[history_count % 2] = new_grid;
        history_count++;
      }
    }

    int convergence_time = 3 + 2 * (history_count - 2);
    // cout << convergence_time << ":" << n << endl;
    if ((n - convergence_time) % 4 == 0) {
      print_grid(history[(history_count - 1) % 2], r, c);
    } else {
      print_grid(history[history_count % 2], r, c);
    }

  }
  return 0;
}
