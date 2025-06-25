#pragma once
#include <string>
#include <fstream>

/**
 * @class Logger
 * @brief Singleton 클래스 Logger는 로그 메시지를 파일에 기록하기 위한 유틸리티 클래스입니다.
 *
 * Logger 클래스는 프로그램 전반에서 일관된 로그 기록을 관리하기 위해 싱글톤 패턴으로 설계되었습니다.
 * 로그를 텍스트 파일에 저장하며, 여러 클래스에서 사용될 수 있습니다.
 */
class Logger
{
private:
    std::ofstream logFile;
    static Logger* instance;

    Logger();
    
public:
    ~Logger();
    static Logger& getInstance();
    void log(const std::string& message);
};
