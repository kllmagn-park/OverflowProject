#include "settings.h"

namespace Settings {
    /*
    Основные настройки.
    */
    string General::site_title = "Общаги.Нет";

    /*
    Настройки статических файлов.
    */
    string Static::static_dir = "static";

    /*
    Настройки шаблонов.
    */
    string Templates::templates_dir = "templates";
}