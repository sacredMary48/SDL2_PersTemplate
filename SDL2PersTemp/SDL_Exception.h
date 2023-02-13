#ifndef SDL_EXCEPTION_H
#define SDL_EXCEPTION_H
#include <exception>
//This is for stop and present the error how stop the app.

class SDL_Exception : public std::exception
{
public:
        SDL_Exception(const char *message) : message(message) {}
        virtual const char *what() const throw() {
            return message;
        }
        const char *message;
};

#endif // SDL_EXCEPTION_H
