#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    int32_t t = 0;
    std::cin >> t;

    while (t--) {
        int32_t m = 0, n = 0;
        std::cin >> m >> n;
        std::vector<std::string> DNA_arr;
        std::vector<std::map<char, int32_t>> count;

        for (int32_t i = 0 ; i < m ; i++) {
            std::string temp;
            std::cin >> temp;

            DNA_arr.emplace_back(temp);

            // std::cout << temp << std::endl;

            for (int32_t j = 0 ; j < temp.length() ; j++) {
                if (i == 0) {
                    std::map<char, int32_t> map_temp;
                    count.emplace_back(map_temp);
                }

                count[j][temp[j]] += 1;
            }
        }

        std::string want(n, 'A');
        // std::cout << "origin: " << want << std::endl;
        int32_t total_miss = 0;
        for (int32_t i = 0 ; i < n ; i++) {
            int32_t max = 0;
            for (auto& c: count[i]) {
                if (max < c.second) {
                    max = c.second;
                    want[i] = c.first;
                }
            }
            for (int32_t j = 0 ; j < m ; j++) {
                if (want[i] != DNA_arr[j][i]) {
                    total_miss += 1;
                }
            }
        }

        std::cout << want << std::endl;
        std::cout << total_miss << std::endl;
    }

    return 0;
}
