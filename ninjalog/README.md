#NinjaLog

A simple logging library. Part of the NinjaFramework.

###Dependancies

None

###Usage

```c++
using namespace NinjaFramework;

Log::Init(Log::Warning, std::cerr);
// Init has to be called to specify the level of logging and the stream to log to, any logs before this will be discarded
// The first parameter is the level of logging to write (any logs under this level will be ignored)
// The second parameter is the output stream to log to, and will work with any class that derives from ostream

log_debug << "This is a low level debug message" << std::endl;
log_info << "Here is some cool info for you" << std::endl;
log_warning << "Just a warning don't panic" << std::endl;
log_error << "Whoops, something has gone wrong" << std::endl;
// the 4 macros log_debug, log_info, log_warning and log_error return a ostream that are then written to with whatever you wish to log

Log::Close()
// Close the log cleaning up any in-memory buffers
```

**IMPORTANT:** If the stream passed into Log::Init() is a file stream it needs to be closed off seperately after Log::Close()
