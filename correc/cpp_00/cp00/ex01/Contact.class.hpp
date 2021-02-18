#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>
# include <string>
# include <iomanip>
#include <stdio.h>

class Contact{

public:
    Contact(void);
    ~Contact(void);
    void    add();
    void    display_char(int i);
    void    print_all(void)const;

private:
	std::string info[11];

};

#endif