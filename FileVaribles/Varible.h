//
// Created by Lukasz Blaszka on 07.12.18.
//

#ifndef FILEVARIBLE_VARIBLE_H
#define FILEVARIBLE_VARIBLE_H

#include <iostream>

class Varible {
private:
    std::string name;
    std::string value;

public:
    Varible() = delete;
    Varible( const std::string &, const std::string & );
    Varible( const Varible & );

    std::string getName() const ;
    std::string getValue() const ;

    void setValue(const std::string &);

    bool operator==( const std::string & ) const;
};

std::ostream&operator<<( std::ostream &, const Varible & );

#endif //FILEVARIBLE_VARIBLE_H
