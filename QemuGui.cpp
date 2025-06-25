#include <jni.h>
#include <string>
#include <thread>
#include "QemuWrapper.h"

static QemuWrapper* qemuInstance = nullptr;

extern "C" JNIEXPORT void JNICALL
Java_com_example_qemugui_QemuNative_startQemu(JNIEnv* env, jobject thiz, jstring args) {
    const char* qemuArgs = env->GetStringUTFChars(args, nullptr);
    if (qemuInstance) delete qemuInstance;
    qemuInstance = new QemuWrapper(qemuArgs);
    std::thread([=]() { qemuInstance->run(); }).detach();
    env->ReleaseStringUTFChars(args, qemuArgs);
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_qemugui_QemuNative_sendTerminalCommand(JNIEnv* env, jobject, jstring cmd) {
    if (qemuInstance) {
        const char* ccmd = env->GetStringUTFChars(cmd, nullptr);
        qemuInstance->sendCommand(ccmd);
        env->ReleaseStringUTFChars(cmd, ccmd);
    }
}