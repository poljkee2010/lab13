# Задание

Написать программы на **C++** для сериализации и десериализации структуры `Person`.

Структура `Person` определяется следующим образом:

```cpp
struct Email {
  std::string nickname;
  std::string server;
};

struct Person {
  std::string  first_name;
  std::string  last_name;
  Email        email;
  size_t       age;
  std::string  phone;
};
```
Формат сериализации и десериалиализации ***yaml***

```ShellSession
https://github.com/jbeder/yaml-cpp
```
Сборка:
```
$ cmake -H. -B_build
$ cmake --build _build
Заходим в "построенное"
$ cd _build/
$ ./pack <путь_к_файлу.yaml>
Вводим параметры
$ ./unpack <путь_к_файлу.yaml>
```

## Пример:
```
$ ./pack pack
Enter data to fields of the Person structure.
First name:
Alex
Last name:
Ananikyan
Email:
poljkee2010@gmail.com
Age:
19 
Phone:
8(495)328-96-92

$ ./unpack pack
[Person]
First name: Alex
Last name:  Ananikyan
Email:      poljkee2010@gmail.com
Age:        19
Phone:      8(495)328-96-92
```

## Проверка валидности через сайт http://www.yamllint.com/ :
```
First name: Alex
Last name: Ananikyan
Email: poljkee2010@gmail.com
Phone: 8(495)328-96-92
Age: 19
```
### Вывод:
``` 
--- 
Age: 19
Email: poljkee2010@gmail.com
? "First name"
: Alex
? "Last name"
: Ananikyan
Phone: 8(495)328-96-92
```
### Valid YAML!
