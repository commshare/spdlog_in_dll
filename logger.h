//
// Created by zhangbin on 2020/6/8.
//

#ifndef HACKCOTURN_LOGGER_H
#define HACKCOTURN_LOGGER_H
#include <memory>
#include "spdlog/spdlog.h"
#include <string>

namespace HC
{
class HCLogger
{
public:
    ~HCLogger();
    static HCLogger* getInstance();
    static std::string loggerName();
   // std::shared_ptr<spdlog::logger> getLogger() {
    //    return m_logger;
   // }
    //void testLog();
    //void LOGI(const char * msg, ...);
private:
  //  std::shared_ptr<spdlog::logger> m_logger;
    HCLogger();
    static HCLogger* intance_;
};

//只要文件名
#define OS_WIN
#if defined(OS_WIN)
#define __FILENAME__ \
  (strrchr(__FILE__, '\\') ? (strrchr(__FILE__, '\\') + 1) : __FILE__)
#else
#define __FILENAME__ \
  (strrchr(__FILE__, '/') ? (strrchr(__FILE__, '/') + 1) : __FILE__)
#endif

//定义一个在日志后添加 文件名 函数名 行号 的宏定义
#ifndef LogSuffix
#define LogSuffix(msg)                     \
  std::string(msg)                      \
      .append("  <")                    \
      .append(__FILENAME__)             \
      .append("> <")                    \
      .append(__func__)                 \
      .append("> <")                    \
      .append(std::to_string(__LINE__)) \
      .append(">")                      \
      .c_str()
#endif
}
//a kind of api to print var log
//#define ZLOGI(msg, ...) HC::HCLogger::getInstance()->LOGI(LogSuffix(msg), ##__VA_ARGS__);


//wrap spdlog
#define LOGI(msg,...) spdlog::info(LogSuffix(msg), __VA_ARGS__)
#define LOGW(msg,...) spdlog::warn(LogSuffix(msg), __VA_ARGS__)
#define LOGE(msg,...) spdlog::error(LogSuffix(msg), __VA_ARGS__)
#define LOGD(msg,...) spdlog::debug(LogSuffix(msg), __VA_ARGS__)
//#define LOGI(msg,...)  HC::HCLogger::getInstance()->getLogger()->info(LogSuffix(msg), __VA_ARGS__)
//#define LOGW(msg,...)  HC::HCLogger::getInstance()->getLogger()->warn(LogSuffix(msg), ##__VA_ARGS__);
//#define LOGE(msg,...)  HC::HCLogger::getInstance()->getLogger()->error(LogSuffix(msg), ##__VA_ARGS__);
//#define LOGD(msg,...)  HC::HCLogger::getInstance()->getLogger()->debug(LogSuffix(msg), ##__VA_ARGS__);

#endif //HACKCOTURN_LOGGER_H
