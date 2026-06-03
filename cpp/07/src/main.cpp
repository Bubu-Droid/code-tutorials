#include <iostream>

class Log {
public:
  int LogLevelError = 0;
  int LogLevelWarning = 1;
  int LogLevelInfo = 2;

private:
  int m_LogLevel = 2;

public:
  void SetLevel(int level) { m_LogLevel = level; }

  void Error(const char *message) {
    if (m_LogLevel >= 0) {
      std::cout << "[ERROR]: " << message << std::endl;
    }
  }
  void Warn(const char *message) {
    if (m_LogLevel >= 1) {
      std::cout << "[WARNING]: " << message << std::endl;
    }
  }
  void Info(const char *message) {
    if (m_LogLevel >= 2) {
      std::cout << "[INFO]: " << message << std::endl;
    }
  }
};

// this searches for the variable in other translation units
extern int s_Var1;

// this however does not work since we have the static keyword
// in the definition of the variable
extern int s_Var2;

int main() {
  Log log;
  log.SetLevel(log.LogLevelWarning);

  int code = 10;
  int &ref = code;

  log.Error("Hello");
  log.Warn("Hello");
  log.Info("Hello");

  std::cout << ref << std::endl;

  std::cout << s_Var1 << std::endl;
  // std::cout << s_Var2 << std::endl;

  std::cin.get();
}
