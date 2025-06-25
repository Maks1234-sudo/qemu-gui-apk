btnStart.setOnClickListener(v -> {
    // Проверка распаковки, запуск QEMU через JNI
});
btnStop.setOnClickListener(v -> {
    // Остановка QEMU процесса
});
terminalInput.setOnEditorActionListener((v, actionId, event) -> {
    // Отправка команд в QEMU через JNI
});