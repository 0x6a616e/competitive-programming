#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  vector<int> packets(7, 0);
  while (cin >> packets[1] >> packets[2] >> packets[3] >> packets[4] >>
         packets[5] >> packets[6]) {
    if (all_of(packets.begin(), packets.end(), [](int i) { return i == 0; })) {
      break;
    }
    int sol = packets[6];
    sol += packets[5];
    if (packets[5]) {
      int potential_ones = packets[5] * 11;
      if (potential_ones >= packets[1]) {
        packets[1] = 0;
      } else {
        packets[1] -= potential_ones;
      }
    }
    sol += packets[4];
    if (packets[4]) {
      int area = 20 * packets[4];
      int potential_twos = area / 4;
      if (potential_twos >= packets[2]) {
        area -= packets[2] * 4;
        packets[2] = 0;
      } else {
        area = 0;
        packets[2] -= potential_twos;
      }
      int potential_ones = area;
      if (potential_ones >= packets[1]) {
        packets[1] = 0;
      } else {
        packets[1] -= potential_ones;
      }
    }
    sol += packets[3] / 4;
    if (packets[3] % 4 != 0) {
      ++sol;
      int used = (packets[3] % 4) * 9;
      int area = 36 - used;
      int potential_twos = (area == 9 ? 1 : area == 18 ? 3 : 5);
      if (potential_twos >= packets[2]) {
        area -= packets[2] * 4;
        packets[2] = 0;
      } else {
        area -= potential_twos * 4;
        packets[2] -= potential_twos;
      }
      int potential_ones = area;
      if (potential_ones >= packets[1]) {
        packets[1] = 0;
      } else {
        packets[1] -= potential_ones;
      }
    }
    sol += packets[2] / 9;
    if (packets[2] % 9 != 0) {
      ++sol;
      int used = (packets[2] % 9) * 4;
      int area = 36 - used;
      int potential_ones = area;
      if (potential_ones >= packets[1]) {
        packets[1] = 0;
      } else {
        packets[1] -= potential_ones;
      }
    }
    sol += packets[1] / 36;
    if (packets[1] % 36 != 0) {
      ++sol;
    }
    cout << sol << '\n';
  }

  return 0;
}
