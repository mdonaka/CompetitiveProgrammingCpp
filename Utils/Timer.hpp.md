---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Utils/Timer.hpp\"\n\uFEFF#pragma once\r\n\r\n#include <iostream>\r\
    \n#include <chrono>\r\n#include <list>\r\n#include <string_view>\r\n\r\nnamespace\
    \ Timer {\r\n\r\n    /**\r\n     * \u6642\u9593\u306E\u5358\u4F4D\u7FA4\r\n  \
    \   */\r\n    namespace UNITS {\r\n        struct NANO {\r\n            using\
    \ second = std::chrono::nanoseconds;\r\n            static constexpr long long\
    \ magnification = 1;\r\n            static constexpr std::string_view str = \"\
    ns\";\r\n        };\r\n        struct MICRO {\r\n            using second = std::chrono::microseconds;\r\
    \n            static constexpr long long magnification = 1000;\r\n           \
    \ static constexpr std::string_view str = \"\u03BCs\";\r\n        };\r\n     \
    \   struct MILLI {\r\n            using second = std::chrono::milliseconds;\r\n\
    \            static constexpr long long magnification = 1000000;\r\n         \
    \   static constexpr std::string_view str = \"ms\";\r\n        };\r\n        struct\
    \ SECOND {\r\n            using second = std::chrono::microseconds;\r\n      \
    \      static constexpr long long magnification = 1000000000;\r\n            static\
    \ constexpr std::string_view str = \"s\";\r\n        };\r\n    }\r\n\r\n    /**\r\
    \n     * \u6642\u9593\u306E\u51FA\u529B\r\n     */\r\n    template<class UNIT>\r\
    \n    void _print(long long time) {\r\n        std::cerr << time << UNIT::str\
    \ << std::endl;\r\n    }\r\n\r\n    /**\r\n     * \u7C21\u6613\u6642\u9593\u8A08\
    \u6E2C\u30AF\u30E9\u30B9\r\n     * \u958B\u59CB\u304B\u3089\u306E\u6642\u9593\u306E\
    \u307F\u8A08\u6E2C\r\n     */\r\n    class SimpleTimer {\r\n        std::chrono::system_clock::time_point\
    \ start;\r\n\r\n    public:\r\n        SimpleTimer() :start(std::chrono::system_clock::now())\
    \ {}\r\n        SimpleTimer& operator=(SimpleTimer&& tm) { start = std::move(tm.start);\
    \  return *this; }\r\n\r\n        template <class UNIT = std::chrono::nanoseconds>\r\
    \n        auto now() const {\r\n            const auto now = std::chrono::system_clock::now();\r\
    \n            return std::chrono::duration_cast<UNIT>(now - start).count();\r\n\
    \        }\r\n\r\n        template<class UNIT = UNITS::NANO>\r\n        auto print()\
    \ const {\r\n            _print<UNIT>(now<typename UNIT::second>());\r\n     \
    \   }\r\n    };\r\n\r\n    /**\r\n     * \u30E9\u30C3\u30D7\u4ED8\u304D\u6642\u9593\
    \u8A08\u6E2C\u30AF\u30E9\u30B9\r\n     */\r\n    class LapTimer {\r\n        std::list<long\
    \ long> lapTimeList;\r\n        SimpleTimer timer;\r\n    public:\r\n        LapTimer()\
    \ :timer(SimpleTimer()) {}\r\n\r\n        auto lap() {\r\n            lapTimeList.emplace_back(timer.now());\r\
    \n            timer = SimpleTimer();\r\n        }\r\n\r\n        template<class\
    \ UNIT = UNITS::NANO>\r\n        auto print() const {\r\n            for(auto&&\
    \ t : lapTimeList) {\r\n                _print<UNIT>(t / UNIT::magnification);\r\
    \n            }\r\n        }\r\n    };\r\n}\n"
  code: "\uFEFF#pragma once\r\n\r\n#include <iostream>\r\n#include <chrono>\r\n#include\
    \ <list>\r\n#include <string_view>\r\n\r\nnamespace Timer {\r\n\r\n    /**\r\n\
    \     * \u6642\u9593\u306E\u5358\u4F4D\u7FA4\r\n     */\r\n    namespace UNITS\
    \ {\r\n        struct NANO {\r\n            using second = std::chrono::nanoseconds;\r\
    \n            static constexpr long long magnification = 1;\r\n            static\
    \ constexpr std::string_view str = \"ns\";\r\n        };\r\n        struct MICRO\
    \ {\r\n            using second = std::chrono::microseconds;\r\n            static\
    \ constexpr long long magnification = 1000;\r\n            static constexpr std::string_view\
    \ str = \"\u03BCs\";\r\n        };\r\n        struct MILLI {\r\n            using\
    \ second = std::chrono::milliseconds;\r\n            static constexpr long long\
    \ magnification = 1000000;\r\n            static constexpr std::string_view str\
    \ = \"ms\";\r\n        };\r\n        struct SECOND {\r\n            using second\
    \ = std::chrono::microseconds;\r\n            static constexpr long long magnification\
    \ = 1000000000;\r\n            static constexpr std::string_view str = \"s\";\r\
    \n        };\r\n    }\r\n\r\n    /**\r\n     * \u6642\u9593\u306E\u51FA\u529B\r\
    \n     */\r\n    template<class UNIT>\r\n    void _print(long long time) {\r\n\
    \        std::cerr << time << UNIT::str << std::endl;\r\n    }\r\n\r\n    /**\r\
    \n     * \u7C21\u6613\u6642\u9593\u8A08\u6E2C\u30AF\u30E9\u30B9\r\n     * \u958B\
    \u59CB\u304B\u3089\u306E\u6642\u9593\u306E\u307F\u8A08\u6E2C\r\n     */\r\n  \
    \  class SimpleTimer {\r\n        std::chrono::system_clock::time_point start;\r\
    \n\r\n    public:\r\n        SimpleTimer() :start(std::chrono::system_clock::now())\
    \ {}\r\n        SimpleTimer& operator=(SimpleTimer&& tm) { start = std::move(tm.start);\
    \  return *this; }\r\n\r\n        template <class UNIT = std::chrono::nanoseconds>\r\
    \n        auto now() const {\r\n            const auto now = std::chrono::system_clock::now();\r\
    \n            return std::chrono::duration_cast<UNIT>(now - start).count();\r\n\
    \        }\r\n\r\n        template<class UNIT = UNITS::NANO>\r\n        auto print()\
    \ const {\r\n            _print<UNIT>(now<typename UNIT::second>());\r\n     \
    \   }\r\n    };\r\n\r\n    /**\r\n     * \u30E9\u30C3\u30D7\u4ED8\u304D\u6642\u9593\
    \u8A08\u6E2C\u30AF\u30E9\u30B9\r\n     */\r\n    class LapTimer {\r\n        std::list<long\
    \ long> lapTimeList;\r\n        SimpleTimer timer;\r\n    public:\r\n        LapTimer()\
    \ :timer(SimpleTimer()) {}\r\n\r\n        auto lap() {\r\n            lapTimeList.emplace_back(timer.now());\r\
    \n            timer = SimpleTimer();\r\n        }\r\n\r\n        template<class\
    \ UNIT = UNITS::NANO>\r\n        auto print() const {\r\n            for(auto&&\
    \ t : lapTimeList) {\r\n                _print<UNIT>(t / UNIT::magnification);\r\
    \n            }\r\n        }\r\n    };\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: Utils/Timer.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utils/Timer.hpp
layout: document
redirect_from:
- /library/Utils/Timer.hpp
- /library/Utils/Timer.hpp.html
title: Utils/Timer.hpp
---
