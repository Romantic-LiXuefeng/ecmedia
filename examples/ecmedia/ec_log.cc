#include "ec_log.h"

ECLog::ECLog(char* log_path) {
  fstream_.open(log_path, std::fstream::out | std::fstream::binary);
  if (fstream_.is_open())
  {
    int i = 0;
    i = 1;
  } else {
    fstream_.open(".\111.txt");
  }
}
ECLog ::~ECLog() {
  if (fstream_.is_open()) {
    int i = 0;
    i = 1;
  }
  fstream_.close();
}
//��־��ʽ���ڴ˽ӿ��ж���
void ECLog::OnLogMessage(const std::string& message) {
  fstream_.write(message.c_str(), message.size());
}