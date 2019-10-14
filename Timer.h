#pragma once

#include <iostream>
#include <chrono>

namespace Timer {

	/**
	 * 時間の単位群
	 */
	namespace UNITS {
		struct NANO {
			using second = std::chrono::nanoseconds;
			static constexpr char* str = "ns";
		};
		struct MICRO {
			using second = std::chrono::microseconds;
			static constexpr char* str = "μs";
		};
		struct MILLI {
			using second = std::chrono::milliseconds;
			static constexpr char* str = "ms";
		};
		struct SECOND {
			using second = std::chrono::microseconds;
			static constexpr char* str = "s";
		};
	}

	/**
	 * 時間の出力
	 */
	template<class UNIT>
	void _print(long long time) {
		std::cout << time << UNIT::str << std::endl;
	}

	/**
	 * 簡易時間計測クラス
	 * 開始からの時間のみ計測
	 */
	class SimpleTimer {
		const std::chrono::system_clock::time_point start;

		template <class UNIT>
		auto now() const {
			const auto now = std::chrono::system_clock::now();
			return std::chrono::duration_cast<UNIT>(now - start).count();
		}
	public:
		SimpleTimer() :start(std::chrono::system_clock::now()) {}

		template<class UNIT = UNITS::MICRO>
		auto print() const {
			_print<UNIT>(now<UNIT::second>());
		}
	};

}