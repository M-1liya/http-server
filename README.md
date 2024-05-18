# http-server-cpp

## Маршруты
- POST   /signup              - регистрация
- GET    /signin              - вход в аккаунт
- GET    /logout              - выход из аккаунта
- GET    /users/:guid              - получение пользователя по guid
- GET    /users/                   - получение списка всех пользователей
- PATCH  /users/:guid              - изменение пользователя по guid
- DELETE /users/:guid              - удаление пользователя по guid

## Exaples

- curl -X POST -H "Content-Type: application/json" --data @user1.json localhost:8080/signup

### For start:
In build directory
- cmake ..
- make
- ./http-server