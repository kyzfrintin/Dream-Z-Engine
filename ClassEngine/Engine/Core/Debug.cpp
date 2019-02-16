#include "Debug.h"


MessageType Debug::currentSeverity = MessageType::TYPE_NONE;


void Debug::DebugInit()
{
	std::ofstream out;
	out.open("GAME301Log.txt", std::ios::out);
	out.close();

	currentSeverity = MessageType::TYPE_FATALERROR;
}

void Debug::SetSeverity(MessageType type_)
{
	currentSeverity = type_;
}
void Debug::Log(MessageType type_,const std::string& message_,const std::string& fileName_,const int line_)
{
	if (type_ <= currentSeverity && currentSeverity > MessageType::TYPE_NONE)
	{
		std::ofstream file;
		file.open("GAME301Log.txt", std::ios::out| std::ios::app);
		file << message_ << " in file: " << fileName_ << "on line: " << line_ << std::endl;
		file.flush();
		file.close();
	}
}

void Debug::Info(const std::string& message_, const std::string& fileName_, const int line_)
{
	Log(MessageType::TYPE_INFO, "[INFO]: " + message_, fileName_, line_);
}
void Debug::Trace(const std::string& message_,const std::string& fileName_,const int line_)
{
	Log(MessageType::TYPE_TRACE, "[TRACE]: " + message_, fileName_, line_);

}
void Debug::Error(const std::string& message_,const std::string& fileName_,const int line_)
{
	Log(MessageType::TYPE_ERROR, "[ERROR]: " + message_, fileName_, line_);

}
void Debug::FatalError(const std::string& message_,const std::string& fileName_,const int line_)
{
	Log(MessageType::TYPE_FATALERROR, "[FATAL ERROR]: " + message_, fileName_, line_);

}
void Debug::Warning(const std::string& message_,const std::string& fileName_,const int line_)
{
	Log(MessageType::TYPE_WARNING, "[WARNING]: " + message_, fileName_, line_);

}