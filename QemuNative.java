public class QemuNative {
    static {
        System.loadLibrary("qemugui");
    }
    public native void startQemu(String args);
    public native void sendTerminalCommand(String cmd);
}