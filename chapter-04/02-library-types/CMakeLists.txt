cmake_minimum_required(VERSION 3.15)
project(LibraryModes CXX)

# 1. المكتبة الثابتة (STATIC)
# يتم دمج كود هذه المكتبة بالكامل داخل البرنامج التنفيذي الذي يستخدمها وقت البناء (Compile time).
# النتيجة على نظامك (أوبونتو): ملف بامتداد libMathStatic.a
add_library(MathStatic STATIC src/math.cpp)

# 2. المكتبة المشتركة (SHARED)
# تُبنى كملف منفصل، ويقرأ منها البرنامج التنفيذي وقت التشغيل (Runtime).
# النتيجة على نظامك (أوبونتو): ملف بامتداد libMathShared.so
add_library(MathShared SHARED src/math.cpp)

# 3. مكتبة الوحدة (MODULE)
# تشبه الـ SHARED، لكنها مخصصة لصناعة الإضافات (Plugins) التي يتم تحميلها برمجياً.
# هذه المكتبة لا يتم ربطها بالبرنامج مباشرة عبر أمر target_link_libraries.
# النتيجة على نظامك (أوبونتو): ملف بامتداد libMathModule.so
add_library(MathModule MODULE src/math.cpp)

# 4. المكتبة المرنة (بدون تحديد نوع) - الممارسة الأفضل (Best Practice)
# نوع هذه المكتبة يتحدد بناءً على متغير BUILD_SHARED_LIBS من سطر الأوامر.
add_library(MathFlexible src/math.cpp)