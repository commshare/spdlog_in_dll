#include "stdafx.h"
#include <iostream>
#include "libclass.h"

LibClass* LibClass::intance_ = nullptr;
const std::string myLoggerName = "lib_logger";

LibClass::LibClass()
{
  m_logger = spdlog::get(myLoggerName);
}

LibClass::~LibClass()
{
  if (intance_)
  {
    delete intance_;
    intance_ = nullptr;
  }
}

LibClass* LibClass::getInstance()
{
  if (intance_ == nullptr)
  {
    intance_ = new LibClass();
  }
  return intance_; 
}
std::string LibClass::loggerName()
{
  return myLoggerName;
}

void LibClass::testLog()
{
  m_logger->info("Log from library");
}
#define MAX_BUF_SIZE 2048

void LibClass::LOGI(const char* msg, ...)
{
  

  char buf[MAX_BUF_SIZE] = { 0 };

  va_list args, copy;
  va_start(args, msg);
  va_copy(copy, args);
  const int predicted_length = std::vsnprintf(nullptr, 0, msg, copy);
  va_end(copy);
  if (predicted_length + 1 > MAX_BUF_SIZE)
  {
	std::cout << " exeption mediaLog predicted_length insufficient " << predicted_length << std::endl;
	return;
  }
  if (predicted_length > 0)
  {
	const int actual_length =
	  std::vsnprintf(buf, predicted_length + 1, msg, args);
	if (actual_length > 0)
	{
	 // if (::SCommon::SLog::GetClientLogger() != nullptr)
	 // {
		//::SCommon::SLog::GetClientLogger()->info(buf);
	 // }
	 // else {
		//std::cout << "err spdclientlogger is nullptr" << std::endl;
	 // }
      m_logger->info(buf);
	}
	else
	{
	  std::cout << "medialog actual_length err " << actual_length << std::endl;
	}
  }
  else
  {
	std::cout << " exeption mediaLog length " << std::endl;;
  }
  va_end(args);
}
APPLIB_EXPORT void registerLogger(std::shared_ptr<spdlog::logger> logger)
{
  spdlog::register_logger(logger);
}