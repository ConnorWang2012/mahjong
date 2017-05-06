LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dlua_shared

LOCAL_MODULE_FILENAME := libcocos2dlua

LOCAL_CPP_EXTENSION := .cpp .cc .c

define list-all-files  
    $(wildcard $(1)) $(foreach e, $(wildcard $(1)/*), $(call list-all-files, $(e)))  
endef

LOCAL_SRC_FILES := \
../../../Classes/AppDelegate.cpp \
hellolua/main.cpp

MY_SRC_ROOT  = $(LOCAL_PATH)/../../../../../..
MY_ALL_FILES = $(call list-all-files, MY_SRC_ROOT/customer/src/cpp) 
MY_SRC_FILES = $(filter %.cpp %.cc %.c, $(MY_ALL_FILES))
LOCAL_SRC_FILES += $(MY_SRC_FILES:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes \
MY_SRC_ROOT/customer/src/cpp/data \
MY_SRC_ROOT/customer/src/cpp/data/3rd_party \
MY_SRC_ROOT/customer/src/cpp/logic/ai \
MY_SRC_ROOT/customer/src/cpp/logic/base \
MY_SRC_ROOT/customer/src/cpp/logic/constant \
MY_SRC_ROOT/customer/src/cpp/logic/lua_bind \
MY_SRC_ROOT/customer/src/cpp/logic/lua_include \
MY_SRC_ROOT/customer/src/cpp/logic/manager \
MY_SRC_ROOT/customer/src/cpp/logic/provider \
MY_SRC_ROOT/customer/src/cpp/logic/test \
MY_SRC_ROOT/customer/src/cpp/logic/tolua_include \
MY_SRC_ROOT/customer/src/cpp/logic/util \
MY_SRC_ROOT/customer/src/cpp/network \
MY_SRC_ROOT/customer/src/cpp/view \
MY_SRC_ROOT/customer/src/cpp/view/actor \
MY_SRC_ROOT/customer/src/cpp/view/base \
MY_SRC_ROOT/customer/src/cpp/view/constant \
MY_SRC_ROOT/customer/src/cpp/view/manager \
MY_SRC_ROOT/customer/src/cpp/view/provider \
MY_SRC_ROOT/customer/src/cpp/view/scene \
MY_SRC_ROOT/customer/src/cpp/view/test \
MY_SRC_ROOT/customer/src/cpp/view/ui \
MY_SRC_ROOT/customer/src/cpp/view/util

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END

LOCAL_STATIC_LIBRARIES := cocos2d_lua_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,scripting/lua-bindings/proj.android)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
