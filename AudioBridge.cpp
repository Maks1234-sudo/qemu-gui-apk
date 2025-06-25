extern "C"
JNIEXPORT void JNICALL
Java_com_qemuhypergui_audio_AudioBridge_pushAudio(JNIEnv* env, jobject, jbyteArray data) {
    // Передать аудиобуфер из Android в QEMU
}
extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_qemuhypergui_audio_AudioBridge_pullAudio(JNIEnv* env, jobject) {
    // Получить аудиобуфер из QEMU для вывода на Android
}