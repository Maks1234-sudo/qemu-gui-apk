cmake_minimum_required(VERSION 3.18)
project(qemuhypergui)
add_subdirectory(qemu)
add_library(qemuhypergui SHARED
    jni/ArchiveManager.cpp
    jni/VmManager.cpp
    jni/DisplayBridge.cpp
    jni/AudioBridge.cpp
    jni/PerfTuner.cpp
    # ...
)
target_link_libraries(qemuhypergui
    qemu_static
    android
    log
    GLESv3
    OpenSLES
    # ...
)