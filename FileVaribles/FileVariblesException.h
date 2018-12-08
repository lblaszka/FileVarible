//
// Created by Łukasz Blaszka on 07.12.18.
//

#ifndef FILEVARIBLE_FILEVARIBLEEXCEPTION_H
#define FILEVARIBLE_FILEVARIBLEEXCEPTION_H

#include <iostream>
#include <exception>

class FileVariblesException : public std::exception
{
public:
    FileVariblesException( const std::string & );
    const char *what() const throw();

protected:
    std::string err;
};


#endif //FILEVARIBLE_FILEVARIBLEEXCEPTION_H
