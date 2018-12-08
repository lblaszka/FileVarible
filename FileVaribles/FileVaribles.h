//
// Created by Łukasz Blaszka on 07.12.18.
//

#ifndef FILEVARIBLE_FILEVARIBLES_H
#define FILEVARIBLE_FILEVARIBLES_H

#include <fstream>
#include <iostream>
#include <vector>
#include <memory>

#include "Varible.h"
#include "FileVariblesException.h"

class FileVaribles {
public:
    FileVaribles() = delete;
    FileVaribles( const std::string & );
    FileVaribles( const FileVaribles & );
    ~FileVaribles();

    void load();
    void save();

    bool exist( const std::string & name ) const;
    std::string getVarible( const std::string & name ) const;
    void setVarible( const std::string & name, const std::string & value );

    std::vector<Varible> * getVaribleVector() const;

private:
    Varible * findVarible( const std::string & name ) const;
    Varible * getVaribleFromString( const std::string & string );

    void addVarible( Varible * );
    void deleteVaribleList();

    std::string filePath;
    std::vector<Varible * > * varibleVector;

    friend std::ostream & operator<<( std::ostream & ostream, const FileVaribles & fileVaribles );
};



#endif //FILEVARIBLE_FILEVARIBLES_H
