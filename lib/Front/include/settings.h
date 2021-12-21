#pragma once

#include <iostream>

namespace Settings {
    /*
    Основные настройки.
    */
    class General {
    public:
        static std::string site_title;
    };

    /*
    Настройки статических файлов.
    */
    class Static {
    public:
        static std::string static_dir;
    };

    /*
    Настройки шаблонов.
    */
    class Templates {
    public:
        static std::string templates_dir;
    };
};
