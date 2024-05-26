#!/bin/bash

set -e  


sudo dpkg -i http-server-dcsa.deb


deb_pakage/bin/http-server &
server_pid=$!


timeout 10 nc -z 127.0.0.1 8080 > /dev/null 2>&1
if [ $? -eq 0 ]; then
  echo "Сервер запущен успешно!"

  
  ./build/AllTests
  test_result=$?


  kill $server_pid

  
  if [ $test_result -ne 0 ]; then
    echo "Тесты завершились с ошибкой!"
    exit $test_result
  else
    echo "Тесты прошли успешно!"
    exit 0
  fi
else
  echo "Ошибка запуска сервера!"
  kill $server_pid || true  
  exit 1
fi