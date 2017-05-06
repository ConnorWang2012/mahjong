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

MY_ALL_FILES = $(call list-all-files, $(LOCAL_PATH)/../../../../../../customer/src/cpp) 
MY_SRC_FILES = $(filter %.cpp %.cc %.c, $(MY_ALL_FILES))
LOCAL_SRC_FILES += $(MY_SRC_FILES:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/data \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/data/3rd_party \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/logic/ai \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/logic/base \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/logic/constant \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/logic/lua_bind \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/logic/lua_include \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/logic/manager \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/logic/provider \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/logic/test \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/logic/tolua_include \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/logic/util \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/network \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/view \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/view/actor \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/view/base \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/view/constant \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/view/manager \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/view/provider \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/view/scene \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/view/test \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/view/ui \
$(LOCAL_PATH)/../../../../../../customer/src/cpp/view/util

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END

LOCAL_STATIC_LIBRARIES := cocos2d_lua_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,scripting/lua-bindings/proj.android)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
