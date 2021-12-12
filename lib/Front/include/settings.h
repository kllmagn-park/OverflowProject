#pragma once

#include <iostream>

using namespace std;

namespace Settings {
    /*
    Основные настройки.
    */
    class General {
    public:
        static string site_title;
    };

    /*
    Настройки статических файлов.
    */
    class Static {
    public:
        static string static_dir;
    };

    /*
    Настройки шаблонов.
    */
    class Templates {
    public:
        static string templates_dir;
    };
};
