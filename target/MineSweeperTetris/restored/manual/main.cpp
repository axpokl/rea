// 人工核对版入口。依据：main.cpp:4 / 0x00422FF8 的 DWARF 与汇编。
// 原导出将两个互斥作用域中的 Lan/Window 栈槽合并，产生 w.pmenug 假字段。
// 实际偏移 252/256 对应 Lan::LAN_TITLE/LAN_RUNNING；已按类型布局修正。
// 保留调用顺序：读取标题 -> 读取消息 -> 弹框；释放互斥量 -> 析构窗口 -> 关闭句柄。
#include "../include/recovered_types.hpp"
#include "../include/globals.hpp"

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
    MainInstance = instance;
    HANDLE mutex = CreateMutexA(nullptr, TRUE, "MineSweeperRushMutex");

    // 任一条件成立都按已有实例处理。保留原程序未单独处理 CreateMutex 失败的行为。
    bool alreadyRunning = GetLastError() == ERROR_ALREADY_EXISTS
        || FindWindowA("MineSweeperRushClass", nullptr) != nullptr;

    if (alreadyRunning) {
        Lan language;
        const auto* title = language.getlan(language.LAN_TITLE);
        const auto* message = language.getlan(language.LAN_RUNNING);
        MsgBoxW(message, title, MB_ICONINFORMATION);
    } else {
        CheckAndProcessCabFile();
        Lan language; // 原程序确有此构造调用，虽然这个局部对象之后未直接使用。
        {
            Window window;
            window.loadall();
            while (IsWin()) {
                window.doaction();
                if (window.bd.addmask()) {
                    window.paintevent();
                    window.paintrefresh();
                }
                window.bd.sd.checkmusic();
                Delay(1);
            }
            ReleaseMutex(mutex);
        } // 对应原汇编中的 Window 析构调用。
    }
    CloseHandle(mutex);
    return 0;
}
