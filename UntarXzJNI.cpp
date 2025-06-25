#include <jni.h>
extern bool untar_xz(const char* archive_path, const char* dest_path);

extern "C" JNIEXPORT jboolean JNICALL
Java_com_example_qemugui_Utils_untarXz(JNIEnv* env, jclass,
                                       jstring archive, jstring dest) {
    const char* a = env->GetStringUTFChars(archive, nullptr);
    const char* d = env->GetStringUTFChars(dest, nullptr);
    bool ok = untar_xz(a, d);
    env->ReleaseStringUTFChars(archive, a);
    env->ReleaseStringUTFChars(dest, d);
    return ok ? JNI_TRUE : JNI_FALSE;
}