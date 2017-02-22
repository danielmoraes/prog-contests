/*
 *
 * EPI
 * Rectangle Intersection (5.11)
 *
 */

#include <iostream>

using namespace std;

struct Rectangle {
  int x, y, w, h;
};

void print_rectangle(const Rectangle& r) {
  cout << r.x << ":" << r.y << ":" << r.h << ":" << r.w << endl;
}

bool has_intersection(const Rectangle& a, const Rectangle& b) {
  return a.x <= ( b.x + b.w ) && ( a.x + a.w ) >= b.x &&
         a.y <= ( b.y + b.h ) && ( a.y + a.h ) >= b.y;
}

Rectangle intersection(const Rectangle& a, const Rectangle& b) {
  if (!has_intersection(a, b)) {
    return {0, 0, 0, 0};
  }

  return { max(a.x, b.x), max(a.y, b.y),
           min(a.x + a.w, b.x + b.w) - max(a.x, b.x),
           min(a.y + a.h, b.y + b.h) - max(a.y, b.y) };
}

int main() {
  Rectangle r1 = { 2, 2, 8, 8};
  Rectangle r2 = { 5, 5, 10, 10};
  Rectangle r3 = { 12, 12, 10, 10};
  print_rectangle(intersection(r1, r2));
  print_rectangle(intersection(r1, r3));
  print_rectangle(intersection(r2, r3));
}
