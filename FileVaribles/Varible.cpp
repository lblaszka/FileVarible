//
// Created by Lukasz Blaszka on 07.12.18.
//

#include "Varible.h"

Varible::Varible( const std::string & name, const std::string & value ): name(name), value(value){}

Varible::Varible(const Varible & varible )
{
    name = std::string( varible.getName() );
    value = std::string( varible.getValue() );
}

std::string Varible::getName() const
{
    return name;
}

std::string Varible::getValue() const
{
    return value;
}

void Varible::setValue(const std::string &value)
{
    this->value = value;
}

bool Varible::operator==( const std::string & name ) const
{
    return ( this->name.compare( name ) == 0 );
}



std::ostream&operator<<( std::ostream & ostream, const Varible & varible )
{
    ostream << "\""+varible.getName()+"\"\""+varible.getValue()+"\"";
    ostream<<std::endl;
    return ostream;
}