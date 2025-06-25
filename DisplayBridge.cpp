#include <android/native_window_jni.h>
#include <GLES3/gl3.h>

class DisplayBridge {
    ANativeWindow* window;
    GLuint texture;
    int width, height;
public:
    void setSurface(JNIEnv* env, jobject surface) {
        window = ANativeWindow_fromSurface(env, surface);
        // Создать OpenGL контекст, framebuffer, texture
    }
    void updateFrame(const uint8_t* fb, int w, int h) {
        // Копировать данные из QEMU fb в OpenGL texture, вызвать отрисовку
    }
    void release() {
        // Освободить ресурсы
    }
};