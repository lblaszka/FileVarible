//
// Created by Łukasz Blaszka on 07.12.18.
//

#include "FileVariblesException.h"

FileVariblesException::FileVariblesException(const std::string & err ) : err(err) {}

const char *FileVariblesException::what() const throw()
{
    return err.c_str();
}

