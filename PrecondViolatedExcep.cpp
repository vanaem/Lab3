
#include "PrecondViolatedExcep.h"  

PrecondViolatedExcep::PrecondViolatedExcep(const std::string& message)
         : std::logic_error("Precondition Violated Exception: " + message){}