public class TerminalView extends SomeAnsiTerminalWidget {
    public void sendToVm(String vmId, String cmd) {
        VmManager.sendCommand(vmId, cmd);
    }
    // Поддержка макросов, истории, скриптов, drag-n-drop файлов
}