
# Uncomment this if you're using STL in your project
# See CPLUSPLUS-SUPPORT.html in the NDK documentation for more information
APP_STL := stlport_static

#this does nothing! is overwritten from APP -> build.gradle
#APP_ABI := armeabi armeabi-v7a x86
#APP_ABI := armeabi-v7a x86
#APP_ABI := x86

# Min SDK level
APP_PLATFORM=android-10

# Enable c++11 extentions in source code
#APP_CPPFLAGS += -std=c++11  #was 14
APP_CPPFLAGS += -std=c++14  #was 14
# Enable c++17 extentions in source code
# APP_CPPFLAGS += -std=c++1z



APP_CPPFLAGS += -fexceptions

# for JSON-CPP does what?
APP_CPPFLAGS += -frtti
APP_ABI := armeabi-v7a
NDK_TOOLCHAIN_VERSION := 4.9
APP_STL := gnustl_shared

#APP_ALLOW_MISSING_DEPS=true

#inclde dirs
APP_CPPFLAGS += -Isrc/main/jni/src/cpp_files/SDL_Engine/Engine