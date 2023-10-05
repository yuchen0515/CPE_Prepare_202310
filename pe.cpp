#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

class tim {
    public:
        int32_t hour = 0;
        int32_t min = 0;
};

class compare {
    public:
        bool operator() (const std::pair<tim, tim> a, const std::pair<tim, tim> b) {
            if (a.first.hour == b.first.hour) {
                return a.first.min < b.first.min;
            }
            return a.first.hour < b.first.hour;
        }
};

int main() {
    int32_t row = 0;
    int32_t t = 0;
    while (std::cin >> row) {
        t += 1;
        // std::cout << "--------------row----" << row << "\n";
        std::vector<std::pair<tim, tim>> interval;

        tim begin;
        tim end;
        char tp;
        std::string str;
        // std::cout << row << std::endl;
        
        tim tpp;
        tpp.hour = 10;
        tpp.min = 0;
        interval.emplace_back(std::make_pair(tpp, tpp));
        tpp.hour = 18;
        interval.emplace_back(std::make_pair(tpp, tpp));

        for (int32_t i = 0 ; i < row ; i++) {
            std::cin >> begin.hour >> tp >> begin.min;
            std::cin >> end.hour >> tp >> end.min;
            std::getline(std::cin, str);

            interval.emplace_back(std::make_pair(begin, end));

            // std::cout << begin.hour << ":" << begin.min << std::endl;
            // std::cout << end.hour << ":" << end.min << std::endl;
        }

        std::sort(interval.begin(), interval.end(), compare());

        tim record;
        int32_t max = 0;
        for (int32_t i = 1 ; i < interval.size() ; i++) {
            int32_t be_beg = interval[i - 1].first.hour * 60 + interval[i - 1].first.min;
            int32_t be_end = interval[i - 1].second.hour * 60 + interval[i - 1].second.min;
            int32_t cur_beg = interval[i].first.hour * 60 + interval[i].first.min;
            int32_t cur_end= interval[i].second.hour * 60 + interval[i].second.min;

            if (cur_end < be_end) {
                interval[i].second = interval[i - 1].second;
            }

            if (cur_beg > be_end && cur_beg - be_end > max) {
                max = cur_beg - be_end;
                record = interval[i - 1].second;
            }
        }

        // for (auto [a, b] : interval) {
        //     std::cout << a.hour << ":" << a.min << " / ";
        //     std::cout << b.hour << ":" << b.min << "\n";
        // }
        int32_t ans_hour = max / 60;
        max %= 60;
        int32_t ans_min = max;
        
        printf("Day #%d: the longest nap starts at %d:%02d and will last for ", t, record.hour, record.min);

        if (ans_hour > 0) {
            printf("%d hours and %d minutes.\n", ans_hour, ans_min);
        } else {
            printf("%d minutes.\n", ans_min);
        }
        
        

    }



    return 0;
}


