# 1. الإعدادات الأساسية
cmake_minimum_required(VERSION 3.15)
project(ModernCMakeMasterclass CXX)

# ==========================================
# أولاً: بناء المكتبات (Defining Libraries)
# ==========================================

# 1. مكتبة ثابتة (STATIC): يتم دمج كودها بالكامل داخل أي برنامج يستخدمها.
add_library(LoggerLib STATIC src/logger.cpp)
set_target_properties(LoggerLib PROPERTIES POSITION_INDEPENDENT_CODE ON)

# 2. مكتبة مشتركة (SHARED): تُبنى كملف منفصل (.so في لينكس) يقرأ منه البرنامج وقت التشغيل.
add_library(MathLib SHARED src/math.cpp)

# 3. مكتبة واجهة (INTERFACE): مكتبة تتكون من Templates وملفات الهيدر فقط (بدون ملف .cpp).
# لاحظ أننا لا نكتب اسم ملف مصدري هنا، لأنها لا تُبنى أصلاً.
add_library(CacheLib INTERFACE)

# 4. مكتبة ثابتة أخرى سنستخدمها لاحقاً لربطها بالبرنامج.
add_library(UiLib STATIC src/ui.cpp)


# ==========================================
# ثانياً: ربط المكتبات ببعضها (Target Linking)
# ==========================================

# حالة PRIVATE: الاعتمادية المخفية
# MathLib تستخدم LoggerLib في ملف (math.cpp) وليس في الهيدر.
# النتيجة: من يستخدم MathLib لن يرث خصائص LoggerLib.
target_link_libraries(MathLib PRIVATE LoggerLib)

# حالة INTERFACE: كوبري التوريث
# CacheLib (التي لم تُبنى) تستخدم LoggerLib.
# النتيجة: أي برنامج يستخدم CacheLib، سيقوم CMake تلقائياً بتمرير LoggerLib له.
target_link_libraries(CacheLib INTERFACE LoggerLib)

# حالة PUBLIC: الاعتمادية المكشوفة
# UiLib تستخدم MathLib في ملف الهيدر (ui.hpp).
# النتيجة: من يستخدم UiLib سيرث تلقائياً مسارات وخصائص MathLib أيضاً.
target_link_libraries(UiLib PUBLIC MathLib)


# ==========================================
# ثالثاً: بناء البرامج التنفيذية (Executables)
# ==========================================

# 1. البرنامج الرئيسي للمشروع (برنامج سطر أوامر عادي)
add_executable(MyApp src/main.cpp)

# نربط البرنامج الرئيسي بالمكتبات
target_link_libraries(MyApp PRIVATE UiLib CacheLib)

# 💡 ماذا يحدث لـ MyApp وراء الكواليس بسبب أمر الربط السابق؟
# 1. سيتم ربطه بـ UiLib (مباشرة).
# 2. سيتم ربطه بـ MathLib (تلقائياً توريث من UiLib لأنها PUBLIC).
# 3. سيتم ربطه بـ CacheLib (مباشرة).
# 4. سيتم ربطه بـ LoggerLib (تلقائياً توريث من CacheLib لأنها INTERFACE).


# 2. أداة مطورين (مستبعدة من البناء الافتراضي)
# - EXCLUDE_FROM_ALL: لن يتم بناؤها إلا لو كتبت في الـ Terminal أمر `make DevTool`.
# - WIN32: لو تم بناؤها على ويندوز، ستعمل كواجهة رسومية (بدون شاشة سوداء). على لينكس سيتم تجاهل الكلمة.
add_executable(DevTool WIN32 EXCLUDE_FROM_ALL src/tool.cpp)