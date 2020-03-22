// SfuServer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "common/slog.h"
#include "server_main.h"
//#include "common/bolt_logger.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_sinks.h>

#include <common/libclass.h>
void logtest()
{
  auto logger = spdlog::get("app_logger");
  logger->info("Log from application");
}
//https://stackoverflow.com/questions/30400286/logging-from-library-with-spdlog
void testLibLogFromApp()
{
  // create loggers
  auto appLogger = spdlog::stdout_logger_mt("app_logger");
  auto libLogger = spdlog::stdout_logger_mt(LibClass::loggerName());

  registerLogger(libLogger);

  // log from app
  logtest();

  // log from lib
 // LibClass lc;
 // lc.testLog();
}
int main(int argc, char** argv)
{
 /* TRSManager trs;
 
  trs.Init("D:\\ALEX");*/
    std::cout << "Hello World!\n";
  //  BLT_CORE_TRACE("hello");
   // SCommon::SLog::Init("");
 // logger->info("server begin...");
    testLibLogFromApp();
    /*
	1>------ 已启动生成: 项目: SfuServer, 配置: Debug Win32 ------
1>SfuServer.cpp
1>G:\RRRRRtc\licode-windows-commshare\onlyServer\common\slog.h(105,44): warning C4251: “Logger::text_log_”: class“std::shared_ptr<spdlog::logger>”需要有 dll 接口由 class“Logger”的客户端使用
1>G:\RRRRRtc\licode-windows-commshare\onlyServer\third_party\spdlog\include\spdlog\details\registry.h(33): message : 参见“std::shared_ptr<spdlog::logger>”的声明
1>G:\RRRRRtc\licode-windows-commshare\onlyServer\common\slog.h(106,47): warning C4251: “Logger::console_log_”: class“std::shared_ptr<spdlog::logger>”需要有 dll 接口由 class“Logger”的客户端使用
1>G:\RRRRRtc\licode-windows-commshare\onlyServer\third_party\spdlog\include\spdlog\details\registry.h(33): message : 参见“std::shared_ptr<spdlog::logger>”的声明
1>G:\RRRRRtc\licode-windows-commshare\onlyServer\common\libclass.h(31,43): warning C4251: “LibClass::m_logger”: class“std::shared_ptr<spdlog::logger>”需要有 dll 接口由 class“LibClass”的客户端使用
1>G:\RRRRRtc\licode-windows-commshare\onlyServer\third_party\spdlog\include\spdlog\details\registry.h(33): message : 参见“std::shared_ptr<spdlog::logger>”的声明
1>SfuServer.vcxproj -> G:\RRRRRtc\licode-windows-commshare\onlyServer\SfuServer\..\OutDir\Debug\SfuServer.exe
1>已完成生成项目“SfuServer.vcxproj”的操作。
========== 生成: 成功 1 个，失败 0 个，最新 0 个，跳过 0 个 ==========

    */ //虽然还是有上面的问题，但是还是很可以工作
	LibClass::getInstance()->getLogger()->info("iamspdlog");

    server_main(argc,argv);
 //   logger->info("server end...");
//    trs.Destroy();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
