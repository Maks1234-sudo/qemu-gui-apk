public class EmuSurfaceView extends SurfaceView implements SurfaceHolder.Callback {
    static {
        System.loadLibrary("qemugui");
    }
    public native void onSurfaceCreated(Surface surface);

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        onSurfaceCreated(holder.getSurface());
    }
}