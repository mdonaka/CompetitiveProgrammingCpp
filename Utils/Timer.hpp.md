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
  bundledCode: "#line 1 \"Utils/Timer.hpp\"\n\uFEFF#pragma once\r\n#define IGNORE\r\
    \n#include <iostream>\r\n#include <chrono>\r\n#include <list>\r\n#include <string_view>\r\
    \n\r\nnamespace Timer {\r\n\r\n\t/**\r\n\t * \u6642\u9593\u306E\u5358\u4F4D\u7FA4\
    \r\n\t */\r\n\tnamespace UNITS {\r\n\t\tstruct NANO {\r\n\t\t\tusing second =\
    \ std::chrono::nanoseconds;\r\n\t\t\tstatic constexpr long long magnification\
    \ = 1;\r\n\t\t\tstatic constexpr std::string_view str = \"ns\";\r\n\t\t};\r\n\t\
    \tstruct MICRO {\r\n\t\t\tusing second = std::chrono::microseconds;\r\n\t\t\t\
    static constexpr long long magnification = 1000;\r\n\t\t\tstatic constexpr std::string_view\
    \ str = \"\u03BCs\";\r\n\t\t};\r\n\t\tstruct MILLI {\r\n\t\t\tusing second = std::chrono::milliseconds;\r\
    \n\t\t\tstatic constexpr long long magnification = 1000000;\r\n\t\t\tstatic constexpr\
    \ std::string_view str = \"ms\";\r\n\t\t};\r\n\t\tstruct SECOND {\r\n\t\t\tusing\
    \ second = std::chrono::microseconds;\r\n\t\t\tstatic constexpr long long magnification\
    \ = 1000000000;\r\n\t\t\tstatic constexpr std::string_view str = \"s\";\r\n\t\t\
    };\r\n\t}\r\n\r\n\t/**\r\n\t * \u6642\u9593\u306E\u51FA\u529B\r\n\t */\r\n\ttemplate<class\
    \ UNIT>\r\n\tvoid _print(long long time) {\r\n\t\tstd::cout << time << UNIT::str\
    \ << std::endl;\r\n\t}\r\n\r\n\t/**\r\n\t * \u7C21\u6613\u6642\u9593\u8A08\u6E2C\
    \u30AF\u30E9\u30B9\r\n\t * \u958B\u59CB\u304B\u3089\u306E\u6642\u9593\u306E\u307F\
    \u8A08\u6E2C\r\n\t */\r\n\tclass SimpleTimer {\r\n\t\tstd::chrono::system_clock::time_point\
    \ start;\r\n\r\n\tpublic:\r\n\t\tSimpleTimer() :start(std::chrono::system_clock::now())\
    \ {}\r\n\t\tSimpleTimer& operator=(SimpleTimer&& tm) { start = std::move(tm.start);\
    \  return *this; }\r\n\r\n\t\ttemplate <class UNIT = std::chrono::nanoseconds>\r\
    \n\t\tauto now() const {\r\n\t\t\tconst auto now = std::chrono::system_clock::now();\r\
    \n\t\t\treturn std::chrono::duration_cast<UNIT>(now - start).count();\r\n\t\t\
    }\r\n\r\n\t\ttemplate<class UNIT = UNITS::NANO>\r\n\t\tauto print() const {\r\n\
    \t\t\t_print<UNIT>(now<typename UNIT::second>());\r\n\t\t}\r\n\t};\r\n\r\n\t/**\r\
    \n\t * \u30E9\u30C3\u30D7\u4ED8\u304D\u6642\u9593\u8A08\u6E2C\u30AF\u30E9\u30B9\
    \r\n\t */\r\n\tclass LapTimer {\r\n\t\tstd::list<long long> lapTimeList;\r\n\t\
    \tSimpleTimer timer;\r\n\tpublic:\r\n\t\tLapTimer() :timer(SimpleTimer()) {}\r\
    \n\r\n\t\tauto lap() {\r\n\t\t\tlapTimeList.emplace_back(timer.now());\r\n\t\t\
    \ttimer = SimpleTimer();\r\n\t\t}\r\n\r\n\t\ttemplate<class UNIT = UNITS::NANO>\r\
    \n\t\tauto print() const {\r\n\t\t\tfor (auto&& t : lapTimeList) {\r\n\t\t\t\t\
    _print<UNIT>(t / UNIT::magnification);\r\n\t\t\t}\r\n\t\t}\r\n\t};\r\n}\n"
  code: "\uFEFF#pragma once\r\n#define IGNORE\r\n#include <iostream>\r\n#include <chrono>\r\
    \n#include <list>\r\n#include <string_view>\r\n\r\nnamespace Timer {\r\n\r\n\t\
    /**\r\n\t * \u6642\u9593\u306E\u5358\u4F4D\u7FA4\r\n\t */\r\n\tnamespace UNITS\
    \ {\r\n\t\tstruct NANO {\r\n\t\t\tusing second = std::chrono::nanoseconds;\r\n\
    \t\t\tstatic constexpr long long magnification = 1;\r\n\t\t\tstatic constexpr\
    \ std::string_view str = \"ns\";\r\n\t\t};\r\n\t\tstruct MICRO {\r\n\t\t\tusing\
    \ second = std::chrono::microseconds;\r\n\t\t\tstatic constexpr long long magnification\
    \ = 1000;\r\n\t\t\tstatic constexpr std::string_view str = \"\u03BCs\";\r\n\t\t\
    };\r\n\t\tstruct MILLI {\r\n\t\t\tusing second = std::chrono::milliseconds;\r\n\
    \t\t\tstatic constexpr long long magnification = 1000000;\r\n\t\t\tstatic constexpr\
    \ std::string_view str = \"ms\";\r\n\t\t};\r\n\t\tstruct SECOND {\r\n\t\t\tusing\
    \ second = std::chrono::microseconds;\r\n\t\t\tstatic constexpr long long magnification\
    \ = 1000000000;\r\n\t\t\tstatic constexpr std::string_view str = \"s\";\r\n\t\t\
    };\r\n\t}\r\n\r\n\t/**\r\n\t * \u6642\u9593\u306E\u51FA\u529B\r\n\t */\r\n\ttemplate<class\
    \ UNIT>\r\n\tvoid _print(long long time) {\r\n\t\tstd::cout << time << UNIT::str\
    \ << std::endl;\r\n\t}\r\n\r\n\t/**\r\n\t * \u7C21\u6613\u6642\u9593\u8A08\u6E2C\
    \u30AF\u30E9\u30B9\r\n\t * \u958B\u59CB\u304B\u3089\u306E\u6642\u9593\u306E\u307F\
    \u8A08\u6E2C\r\n\t */\r\n\tclass SimpleTimer {\r\n\t\tstd::chrono::system_clock::time_point\
    \ start;\r\n\r\n\tpublic:\r\n\t\tSimpleTimer() :start(std::chrono::system_clock::now())\
    \ {}\r\n\t\tSimpleTimer& operator=(SimpleTimer&& tm) { start = std::move(tm.start);\
    \  return *this; }\r\n\r\n\t\ttemplate <class UNIT = std::chrono::nanoseconds>\r\
    \n\t\tauto now() const {\r\n\t\t\tconst auto now = std::chrono::system_clock::now();\r\
    \n\t\t\treturn std::chrono::duration_cast<UNIT>(now - start).count();\r\n\t\t\
    }\r\n\r\n\t\ttemplate<class UNIT = UNITS::NANO>\r\n\t\tauto print() const {\r\n\
    \t\t\t_print<UNIT>(now<typename UNIT::second>());\r\n\t\t}\r\n\t};\r\n\r\n\t/**\r\
    \n\t * \u30E9\u30C3\u30D7\u4ED8\u304D\u6642\u9593\u8A08\u6E2C\u30AF\u30E9\u30B9\
    \r\n\t */\r\n\tclass LapTimer {\r\n\t\tstd::list<long long> lapTimeList;\r\n\t\
    \tSimpleTimer timer;\r\n\tpublic:\r\n\t\tLapTimer() :timer(SimpleTimer()) {}\r\
    \n\r\n\t\tauto lap() {\r\n\t\t\tlapTimeList.emplace_back(timer.now());\r\n\t\t\
    \ttimer = SimpleTimer();\r\n\t\t}\r\n\r\n\t\ttemplate<class UNIT = UNITS::NANO>\r\
    \n\t\tauto print() const {\r\n\t\t\tfor (auto&& t : lapTimeList) {\r\n\t\t\t\t\
    _print<UNIT>(t / UNIT::magnification);\r\n\t\t\t}\r\n\t\t}\r\n\t};\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: Utils/Timer.hpp
  requiredBy: []
  timestamp: '2022-08-30 05:07:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utils/Timer.hpp
layout: document
redirect_from:
- /library/Utils/Timer.hpp
- /library/Utils/Timer.hpp.html
title: Utils/Timer.hpp
---
