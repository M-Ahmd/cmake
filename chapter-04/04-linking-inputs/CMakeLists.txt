add_executable(MyApp main.cpp)

target_link_libraries(MyApp
    PRIVATE
        # 1. مسار كامل لمكتبة جاهزة
        /opt/custom_libs/libSecret.so 
        
        # 2. اسم مجرد لمكتبة من النظام (سيترجمها الكومبايلر إلى -lpthread)
        pthread 
        
        # 3. علَم خاص باللينكر (استخدمنا PRIVATE كما حذر الكاتب لمنع توريثه)
        -Wl,--strip-all 
)