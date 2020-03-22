#ifndef LIBCLASS_H
#define LIBCLASS_H

#include <spdlog/spdlog.h>

#define BUILD_APPLIB_SHARED

#ifdef WIN32
#  ifdef BUILD_APPLIB_SHARED
#    define APPLIB_EXPORT __declspec(dllexport)
#  else
#    define APPLIB_EXPORT
#  endif //BUILD_APPLIB_SHARED
#else
#  define APPLIB_EXPORT
#endif // WIN32

class APPLIB_EXPORT LibClass
{
public:

  ~LibClass();
  static LibClass* getInstance();
  static std::string loggerName();
  std::shared_ptr<spdlog::logger> getLogger() {
    return m_logger;
  }
  void testLog();
  void LOGI(const char * msg, ...);
private:
  std::shared_ptr<spdlog::logger> m_logger;
  LibClass();
  static LibClass* intance_;
};

APPLIB_EXPORT void registerLogger(std::shared_ptr<spdlog::logger> logger);


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
//
//#define ZLOGI(msg, ...)                                                       \
//  do {                                                                        \
//    if (::SCommon::SLog::GetClientLogger())                                 \
//      ::SCommon::SLog::GetClientLogger()->warn(suffix(msg), ##__VA_ARGS__); \
//  } while (0)
//

#define ZLOGI(msg, ...)         LibClass::getInstance()->LOGI(LogSuffix(msg), ##__VA_ARGS__);
 
#define BLOGI(msg,...) LibClass::getInstance()->getLogger()->info(LogSuffix(msg), ##__VA_ARGS__);
#define BLOGW(msg,...) LibClass::getInstance()->getLogger()->warn(LogSuffix(msg), ##__VA_ARGS__);
#define BLOGE(msg,...) LibClass::getInstance()->getLogger()->error(LogSuffix(msg), ##__VA_ARGS__);
#define BLOGD(msg,...) LibClass::getInstance()->getLogger()->debug(LogSuffix(msg), ##__VA_ARGS__);
//#ifdef _DEBUG         //如果定义了_DEBUG
//#define new DEBUG_NEW //则定义new为DEBUG_NEW
//#undef THIS_FILE      //反定义，即清除THIS_FILE的宏定义
//static char THIS_FILE[] = __FILE__;
//#endif              
////结束宏定义


#endif //LIBCLASS_H

