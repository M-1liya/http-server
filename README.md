# http-server-cpp

## Маршруты
- POST   /auth/signup              - регистрация
- GET    /auth/signin              - вход в аккаунт
- GET    /auth/logout              - выход из аккаунта
- GET    /users/:guid              - получение пользователя по guid
- GET    /users/                   - получение списка всех пользователей
- PATCH  /users/:guid              - изменение пользователя по guid
- DELETE /users/:guid              - удаление пользователя по guid
