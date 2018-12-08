# FileVarible
Simple read and write varibles to file.
####
## How use
### Simple program:
```c++
#include <iostream>
#include "FileVaribles/FileVaribles.h"

int main() 
{
    //Save varibles to text file
    FileVaribles fv1("./MyVariblesInFile.txt");
    fv1.setVarible("name of varible", "value of varible"); //save in memory varible
    fv1.save(); // Now create or override file and save varibles in text file
    
    //Load varibles from text file
    FileVaribles fv2("./MyVariblesInFile.txt");
    fv2.load(); // Now FileVaribles instance read text file and save in memory readed varibles.
    std::cout<<fv2.getVarible("name of varible"); // should write "value of varible"
    
    return 0;
}
```

### Safer code:
```c++
#include <iostream>
#include "FileVaribles/FileVaribles.h"

int main()
{
    //Save varibles to text file
    FileVaribles fv1("./MyVariblesInFile.txt");
    fv1.setVarible("name of varible", "value of varible");

    try
    {
        fv1.save(); // if FileVaribles instance can not save file throw FileVariblesException.
    }
    catch( std::exception exc )
    {
        std::cerr<< exc.what() <<std::endl;
    }

    //Load varibles from text file
    FileVaribles fv2("./MyVariblesInFile.txt");

    try
    {
        fv2.load(); // if FileVaribles instance can not read file throw FileVariblesException.
        std::cout<<fv2.getVarible("name of varible"); // if FileVaribles nod finded varibles with getted name throw FileVariblesException.
    }
    catch( std::exception exc )
    {
        std::cerr<< exc.what() <<std::endl;
    }


    return 0;
}
```
