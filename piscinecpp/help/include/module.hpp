/*
** EPITECH PROJECT, 2019
** module
** File description:
** module
*/

#ifndef _MODULE_HPP_
# define _MODULE_HPP_

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

class User {
public:
    User();
    ~User();

    int get_user();
protected:
private:
};

class Hostname {
public:
    Hostname();
    ~Hostname();

    int get_hostname();
protected:
private:
};

class OS_Version {
public:
    OS_Version();
    ~OS_Version();

    int get_os_version();
protected:
private:
};

class Date_and_Time {
public:
    Date_and_Time();
    ~Date_and_Time();

    int get_date_and_time();
protected:
private:
};

class RAM {
public:
    RAM();
    ~RAM();

    int get_info_ram();
protected:
private:
};

class CPU {
public:
    CPU();
    ~CPU();

    int get_info_cpu();
    int get_cpu_activity();
protected:
private:
};

int get_user();
int get_hostname();
int get_os_version();
int get_date_and_time();
int get_info_ram();
int get_info_cpu();
int get_cpu_activity();
int get_info_network();

#endif /*_MODULE_HPP_*/
