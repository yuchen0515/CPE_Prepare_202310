#include <iostream>
#include <vector>
#include <string>

int main() {

    int32_t t = 0;
    while (true) {
        int32_t n = 0 , m = 0;
        std::cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }
        t += 1;

        if (t > 1) {
            std::cout << std::endl;
        }
        std::cout << "Field #" << t << ":" << std::endl;

        std::vector<std::vector<int32_t>> muze;
        for (int32_t i = 0 ; i < n ; i++) {
            std::string temp;
            std::cin >> temp;
            std::vector<int32_t> arr_t;
            for (int32_t i = 0 ; i < temp.length() ; i++) {
                if (temp[i] == '*') {
                    arr_t.emplace_back(-1);
                } else if (temp[i] == '.') {
                    arr_t.emplace_back(0);
                } else {
                    std::cout << "error\n";
                }
            }
            muze.emplace_back(arr_t);
        }

        std::vector<std::vector<int32_t>> dir = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1},
            {1, 1},
            {-1, 1},
            {1, -1},
            {-1, -1}
        };

        for (int32_t i = 0 ; i < n ; i++) {
            for (int32_t j = 0 ; j < m ; j++) {
                if (muze[i][j] == -1) {
                    std::cout << "*";
                    continue;
                }
                int32_t total = 0;
                for (int32_t k = 0 ; k < 8 ; k++) {
                    auto x = i + dir[k][0];
                    auto y = j + dir[k][1];

                    if (x < 0 || x >= n || y < 0 || y >= m) {
                        continue;
                    }
                    if (muze[x][y] == -1) {
                        total += 1;
                    }
                }
                muze[i][j] = total;
                std::cout << total;
            }
            std::cout << std::endl;
        }

    }

    return 0;
}
