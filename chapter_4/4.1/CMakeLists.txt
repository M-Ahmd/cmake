cmake_minimum_required(VERSION 3.15)
project(ExecutableModes CXX)

# 1. البرنامج الافتراضي الأساسي
# (هيتعمله بيلد تلقائياً كبرنامج سطر أوامر Console بيشتغل على كل المنصات)
add_executable(MyApp ./src/programm.cpp)

# 2. تطبيق مخصص لويندوز 
# (لو بتعمل بيلد على ويندوز: هيطلع برنامج واجهة رسومية GUI من غير شاشة سوداء)
# (لو بتعمل بيلد على لينكس/ماك: CMake هيتجاهل كلمة WIN32 تماماً وهيبنيه كبرنامج عادي)
add_executable(MyWindowsApp WIN32 ./src/programm.cpp)

# 3. حزمة تطبيق ماك 
# (لو بتعمل بيلد على ماك: هيطلعه في صيغة App Bundle يعني ملف .app)
# (لو بتعمل بيلد على لينكس/ويندوز: CMake هيتجاهل MACOSX_BUNDLE وهيبنيه كبرنامج عادي)
add_executable(MyMacApp MACOSX_BUNDLE ./src/programm.cpp)

# 4. أداة مستبعدة من البناء الافتراضي
# (كلمة EXCLUDE_FROM_ALL بتمنع أمر make من بناء البرنامج ده تلقائياً لتوفير الوقت)
# (عشان تبنيه لازم تكتب اسمه صراحة في الـ Terminal: make DevTool)
add_executable(DevTool EXCLUDE_FROM_ALL ./src/programm.cpp)
