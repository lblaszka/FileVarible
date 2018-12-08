//
// Created by Łukasz Blaszka on 07.12.18.
//

#include "FileVaribles.h"

FileVaribles::FileVaribles( const std::string & filePath ): filePath(filePath)
{
    varibleVector = new std::vector<Varible *>();
}

FileVaribles::FileVaribles( const FileVaribles & fileVaribles )
{
    filePath = fileVaribles.filePath;

    varibleVector = new std::vector<Varible *>();

    for( auto& varible : *fileVaribles.varibleVector )
    {
        varibleVector->push_back( new Varible( *varible ) );
    }
}


FileVaribles::~FileVaribles()
{
    deleteVaribleList();
}

void FileVaribles::load()
{
    std::fstream file;
    file.open( filePath, std::ios::in );

    if( file.good() )
    {
        std::string line;
        while( std::getline( file, line ) )
        {
            addVarible( getVaribleFromString( line ) );
        }
    }
    else
        throw FileVariblesException("Can not load date from file.");
}

void FileVaribles::save()
{
    remove ( filePath.c_str() );

    std::fstream file;
    file.open( filePath, std::ios_base::app );

    if( file.good() )
    {
        for( auto varible : *varibleVector )
        {
            file<<*varible;
        }
        file.close();
    }
    else
        throw FileVariblesException("Can not save date to file.");
}

bool FileVaribles::exist(const std::string &name) const
{

    return findVarible( name ) != nullptr;
}

std::string FileVaribles::getVarible(const std::string &name) const
{
    return findVarible( name )->getValue();
}

void FileVaribles::setVarible(const std::string & name, const std::string &value)
{
    auto varible = findVarible( name );

    if( varible != nullptr )
        varible->setValue( value );
    else
        varibleVector->push_back( new Varible( name, value ) );
}

std::vector<Varible> * FileVaribles::getVaribleVector() const
{
    std::vector<Varible> * _varibleVector = new std::vector<Varible>();

    for( auto varible : *varibleVector )
    {
        _varibleVector->push_back( Varible( *varible ) );
    }

    return _varibleVector;
}

Varible *FileVaribles::findVarible( const std::string &name ) const
{
    for( auto varible : *varibleVector )
    {
        if( * varible == name )
        {
            return varible;
        }
    }

    return nullptr;
}

Varible *FileVaribles::getVaribleFromString(const std::string &string)
{

    size_t marks[4];

    marks[0] = string.find("\"");

    if( marks[0] == string.npos )
        return nullptr;

    for( unsigned it = 1; it < 4; it++ )
    {
        marks[it] = string.find( "\"", marks[it-1]+1 );

        if( marks[it] == string.npos)
            return nullptr;
    }

    return new Varible(string.substr( marks[0]+1, marks[1]-marks[0]-1 ), string.substr( marks[2]+1, marks[3]-marks[2]-1 ));

}

void FileVaribles::addVarible(Varible * varible )
{
    if( varible != nullptr )
        varibleVector->push_back( varible );
}

void FileVaribles::deleteVaribleList()
{
    for( auto& varible : *varibleVector )
    {
        delete varible;
    }

    delete varibleVector;
    varibleVector = new std::vector<Varible*>();
}

std::ostream & operator<<(std::ostream &ostream, const FileVaribles &fileVaribles)
{

    for( auto& varible: *fileVaribles.varibleVector )
    {
        ostream<< * varible;
    }

    return ostream;
}
