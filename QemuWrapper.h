#pragma once
#include <string>

class QemuWrapper {
public:
    QemuWrapper(const std::string& args);
    ~QemuWrapper();

    void run();
    void sendCommand(const std::string& cmd);
    // методы для аудио, сети, устройств ...
private:
    std::string args_;
    // Дескрипторы терминала, аудио, сеть ...
};