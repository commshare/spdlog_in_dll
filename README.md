# spdlog_in_dll

- LibClass wrap spdlog in common.dll
- use common.dll
##  how to use
- import header libclass.h

```
#define BLOGI(msg,...) LibClass::getInstance()->getLogger()->info(LogSuffix(msg), ##__VA_ARGS__);
#define BLOGW(msg,...) LibClass::getInstance()->getLogger()->warn(LogSuffix(msg), ##__VA_ARGS__);
#define BLOGE(msg,...) LibClass::getInstance()->getLogger()->error(LogSuffix(msg), ##__VA_ARGS__);
#define BLOGD(msg,...) LibClass::getInstance()->getLogger()->debug(LogSuffix(msg), ##__VA_ARGS__);
```

- in other dll or exe call BLOGI
