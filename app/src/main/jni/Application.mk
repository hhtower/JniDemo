APP_STL := gnustl_static
NDK_TOOLCHAIN_VERSION := 4.9
APP_CPPFLAGS := -fexceptions -frtti -fpermissive -std=c++14
 #允许异常功能，及运行时类型识别
#APP_CPPFLAGS +=-std=gnu++11 #允许使用c++11的函数等功能

#APP_CPPFLAGS :=  此项有效时表示宽松的编译形式，比如没有用到的代码中有错误也可以通过
APP_ABI := armeabi armeabi-v7a arm64-v8a mips mips64
#armeabi-v7a arm64-v8a x86 x86_64 mips64
APP_PLATFORM := android-14
APP_OPTIM := debug