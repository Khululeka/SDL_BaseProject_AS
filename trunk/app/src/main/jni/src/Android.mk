LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL
SDL_IMAGE_PATH := ../SDL_image
SDL_MIXER_PATH := ../SDL2_mixer
SDL_TTF_PATH := ../SDL2_ttf

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include \
                    $(LOCAL_PATH)/$(SDL_IMAGE_PATH)/include \
                    $(LOCAL_PATH)/$(SDL_MIXER_PATH)/include \
                    $(LOCAL_PATH)/$(SDL_TTF_PATH)/include \
                    $(LOCAL_PATH)/cpp_files/SDL_Engine \
                    $(LOCAL_PATH)/cpp_files/SDL_Engine/Engine \

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_mixer SDL2_ttf

#SUPPORT_MP3_SMPEG := false




# include jsoncpp
#JSONCPP_PATH := cpp_files/ManagersAndControllers/jsoncpp
#LOCAL_C_INCLUDES := $(JSONCPP_PATH)/json
#LOCAL_SHARED_LIBRARIES := jsoncpp

#TODO move to here from application.mk?
# LOCAL_CPP_FEATURES += exceptions


#traverse all the directory and subdirectory
define walk
  $(wildcard $(1)) $(foreach e, $(wildcard $(1)/*), $(call walk, $(e)))
endef
#find all the file recursively under jni/
ALLFILES = $(call walk, $(LOCAL_PATH))
FILE_LIST := $(filter %.cpp, $(ALLFILES))

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
	$(FILE_LIST:$(LOCAL_PATH)/%=%)




LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

# for native asset manager
LOCAL_LDLIBS += -landroid


include $(BUILD_SHARED_LIBRARY)

