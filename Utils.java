public class Utils {
    static {
        System.loadLibrary("untarxz");
    }
    public static native boolean untarXz(String archive, String dest);
}