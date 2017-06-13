# Android.mk 链接a文件使用
LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)
LOCAL_MODULE := libHello
LOCAL_C_INCLUDES := $(LOCAL_PATH)/sources
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/sources
LOCAL_SRC_FILES := sources/$(TARGET_ARCH_ABI)/libHello.a
include $(PREBUILT_STATIC_LIBRARY)


include $(CLEAR_VARS)
LOCAL_CPPFLAGS  := -std=c++14
LDFLAGS := -shared
LOCAL_LDFLAGS += -fuse-ld=bfd
LOCAL_MODULE           := JniDemo
LOCAL_SRC_FILES        :=   jni_dynamic.cpp
LOCAL_STATIC_LIBRARIES := libHello
include $(BUILD_SHARED_LIBRARY)
