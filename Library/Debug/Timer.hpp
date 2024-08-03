#pragma once

#include <iostream>
#include <chrono>
#include <list>
#include <string_view>

namespace Timer {

    /**
     * 時間の単位群
     */
    namespace UNITS {
        struct NANO {
            using second = std::chrono::nanoseconds;
            static constexpr long long magnification = 1;
            static constexpr std::string_view str = "ns";
        };
        struct MICRO {
            using second = std::chrono::microseconds;
            static constexpr long long magnification = 1000;
            static constexpr std::string_view str = "μs";
        };
        struct MILLI {
            using second = std::chrono::milliseconds;
            static constexpr long long magnification = 1000000;
            static constexpr std::string_view str = "ms";
        };
        struct SECOND {
            using second = std::chrono::microseconds;
            static constexpr long long magnification = 1000000000;
            static constexpr std::string_view str = "s";
        };
    }

    /**
     * 時間の出力
     */
    template<class UNIT>
    void _print(long long time) {
        std::cerr << time << UNIT::str << std::endl;
    }

    /**
     * 簡易時間計測クラス
     * 開始からの時間のみ計測
     */
    class SimpleTimer {
        std::chrono::system_clock::time_point start;

    public:
        SimpleTimer() :start(std::chrono::system_clock::now()) {}
        SimpleTimer& operator=(SimpleTimer&& tm) { start = std::move(tm.start);  return *this; }

        template <class UNIT = std::chrono::nanoseconds>
        auto now() const {
            const auto now = std::chrono::system_clock::now();
            return std::chrono::duration_cast<UNIT>(now - start).count();
        }

        template<class UNIT = UNITS::NANO>
        auto print() const {
            _print<UNIT>(now<typename UNIT::second>());
        }
    };

    /**
     * ラップ付き時間計測クラス
     */
    class LapTimer {
        std::list<long long> lapTimeList;
        SimpleTimer timer;
    public:
        LapTimer() :timer(SimpleTimer()) {}

        auto lap() {
            lapTimeList.emplace_back(timer.now());
            timer = SimpleTimer();
        }

        template<class UNIT = UNITS::NANO>
        auto print() const {
            for(auto&& t : lapTimeList) {
                _print<UNIT>(t / UNIT::magnification);
            }
        }
    };
}