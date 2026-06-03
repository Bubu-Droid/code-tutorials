#include <iostream>

class Log {
public:
  enum LogLevel : char { Error = 0, Warning = 1, Info = 2 };

private:
  LogLevel m_LogLevel = Info;

public:
  void SetLevel(LogLevel level) { m_LogLevel = level; }

  void LogError(const char *message) {
    if (m_LogLevel >= Error) {
      std::cout << "[ERROR]: " << message << std::endl;
    }
  }
  void LogWarn(const char *message) {
    if (m_LogLevel >= Warning) {
      std::cout << "[WARNING]: " << message << std::endl;
    }
  }
  void LogInfo(const char *message) {
    if (m_LogLevel >= Info) {
      std::cout << "[INFO]: " << message << std::endl;
    }
  }
};

int main() {
  Log log;
  log.SetLevel(Log::Warning);

  log.LogError("Hello");
  log.LogWarn("Hello");
  log.LogInfo("Hello");

  std::cin.get();
}
