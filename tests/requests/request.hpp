#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include "HttpClient.h"

// Структура для хранения ответа сервера
struct ResponseData {
    std::string data;  // Буфер для данных
    long httpCode;     // Код состояния HTTP
};

// Функция для отправки GET-запроса
ResponseData sendGetRequest(const std::string& url);

#endif // REQUEST_H