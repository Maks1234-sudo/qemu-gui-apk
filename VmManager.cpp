#include <sys/wait.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <map>

class VirtualMachine {
public:
    pid_t pid;
    std::string name;
    std::string arch;
    std::string binPath;
    std::vector<std::string> args;
    int master_fd; // терминал для ввода

    bool start() {
        int master_fd;
        pid_t child = forkpty(&master_fd, nullptr, nullptr, nullptr);
        if (child == 0) {
            std::vector<char*> argv;
            argv.push_back(const_cast<char*>(binPath.c_str()));
            for (auto& a : args) argv.push_back(const_cast<char*>(a.c_str()));
            argv.push_back(nullptr);
            execv(binPath.c_str(), argv.data());
            _exit(1);
        }
        this->pid = child;
        this->master_fd = master_fd;
        return true;
    }
    void stop() { kill(pid, SIGTERM); }
    void sendCommand(const std::string& cmd) { write(master_fd, cmd.c_str(), cmd.size()); }
};

std::map<std::string, VirtualMachine> vms;

extern "C" JNIEXPORT void JNICALL
Java_com_qemuhypergui_vm_VmManager_startVm(JNIEnv *env, jobject, jstring name, jstring arch, jobjectArray args) {
    // Преобразовать аргументы, найти путь до бинарника QEMU (по arch), создать VM, добавить в vms
    // ...
}