#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int32_t T = 0;
    std::cin >> T;

    while (T--) {
        int32_t S = 0, A = 0, F = 0;
        std::cin >> S >> A >> F;

        std::vector<int32_t> streets;
        std::vector<int32_t> avenue;

        for (int32_t i = 0 ; i < F ; i++) {
            int32_t X = 0, Y = 0;
            std::cin >> X >> Y;

            streets.emplace_back(X);
            avenue.emplace_back(Y);
        }

        std::sort(streets.begin(), streets.end());
        std::sort(avenue.begin(), avenue.end());


        std::cout << "(Street: ";
        std::cout << streets[(F - 1) / 2];
        std::cout << ", Avenue: ";
        std::cout << avenue[(F - 1) / 2];
        std::cout << ")" << std::endl;

    }


    return 0;
}
