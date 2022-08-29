---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qiita.com/ykob/items/ab7f30c43a0ed52d16f2
  bundledCode: "#line 1 \"Library/PlaneGeometry/judgeIentersected.cpp\"\n/**\r\n *\
    \ \u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\r\n * https://qiita.com/ykob/items/ab7f30c43a0ed52d16f2\r\
    \n */\r\nbool judgeIentersected(double ax, double ay, double bx, double by,\r\n\
    \t\t\t\t\t   double cx, double cy, double dx, double dy) {\r\n\tauto ta = (cx\
    \ - dx) * (ay - cy) + (cy - dy) * (cx - ax);\r\n\tauto tb = (cx - dx) * (by -\
    \ cy) + (cy - dy) * (cx - bx);\r\n\tauto tc = (ax - bx) * (cy - ay) + (ay - by)\
    \ * (ax - cx);\r\n\tauto td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);\r\
    \n\r\n\t// return tc * td < 0 && ta * tb < 0;\r\n\treturn tc * td <= 0 && ta *\
    \ tb <= 0; // \u7AEF\u70B9\u3092\u542B\u3080\u5834\u5408\r\n};\n"
  code: "/**\r\n * \u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\r\n * https://qiita.com/ykob/items/ab7f30c43a0ed52d16f2\r\
    \n */\r\nbool judgeIentersected(double ax, double ay, double bx, double by,\r\n\
    \t\t\t\t\t   double cx, double cy, double dx, double dy) {\r\n\tauto ta = (cx\
    \ - dx) * (ay - cy) + (cy - dy) * (cx - ax);\r\n\tauto tb = (cx - dx) * (by -\
    \ cy) + (cy - dy) * (cx - bx);\r\n\tauto tc = (ax - bx) * (cy - ay) + (ay - by)\
    \ * (ax - cx);\r\n\tauto td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);\r\
    \n\r\n\t// return tc * td < 0 && ta * tb < 0;\r\n\treturn tc * td <= 0 && ta *\
    \ tb <= 0; // \u7AEF\u70B9\u3092\u542B\u3080\u5834\u5408\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/PlaneGeometry/judgeIentersected.cpp
  requiredBy: []
  timestamp: '2022-08-30 04:52:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/PlaneGeometry/judgeIentersected.cpp
layout: document
redirect_from:
- /library/Library/PlaneGeometry/judgeIentersected.cpp
- /library/Library/PlaneGeometry/judgeIentersected.cpp.html
title: Library/PlaneGeometry/judgeIentersected.cpp
---
