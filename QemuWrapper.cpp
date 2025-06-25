#include <android/native_window_jni.h>
#include <GLES2/gl2.h>
// ...

void QemuWrapper::setSurface(JNIEnv* env, jobject surface) {
    ANativeWindow* window = ANativeWindow_fromSurface(env, surface);
    // Настроить OpenGL ES контекст, рендерить framebuffer QEMU
    // (Пример кода OpenGL — по требованию)
}