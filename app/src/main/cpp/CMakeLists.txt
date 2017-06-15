# documentation: https://d.android.com/studio/projects/add-native-code.html

# 设置构建所需最小 cmake 版本
cmake_minimum_required(VERSION 3.4.1)

# 头文件所在位置
include_directories( ${CMAKE_SOURCE_DIR}/sources/ )

# 创建一个 lib，静态 or 动态，可创建多个
add_library( # lib名称
             JniDemo

             # lib类型
             SHARED

             # .c/cpp目录
             jni_dynamic.cpp )

# 搜索 NDK 指定 lib
find_library( # lib 路径变量的名称。
              log-lib

              # 查找指定 lib 名称
              log )


# 添加自己的 lib 库
add_library( libHello
             SHARED
             IMPORTED )
set_target_properties(
                    libHello

                    # 指定要定义的参数.
                    PROPERTIES IMPORTED_LOCATION

                    # 导入 lib 的路径
                    ${CMAKE_SOURCE_DIR}/sources/${ANDROID_ABI}/libHello.a)

# 链接库
target_link_libraries( # 指定目标 lib
                       JniDemo

                       # 自己的 lib
                       libHello

                       # NDK log lib  // find 的路径 ${log-lib}
                       log )