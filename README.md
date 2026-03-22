# Part 1

1. Создайте пустой репозиторий на сервисе github.com (или gitlab.com, или bitbucket.com).

2. Выполните инструкцию по созданию первого коммита на странице репозитория, созданного на предыдущем шаге.

```bash
echo "lab02 hello world" > README.md
git add README.md
git commit -m "readme.md"
git branch -M main
git remote add lab02 https://github.com/dvorfe30-io/lab02.git  
git push -u lab02 main 
```

<details>
<summary>output</summary>

```bash
Username for 'https://github.com': dvorfe30-io
Password for 'https://dvorfe30-io@github.com':
Перечисление объектов: 3, готово.
Подсчет объектов: 100% (3/3), готово.
Запись объектов: 100% (3/3), 225 байтов | 225.00 КиБ/с, готово.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/dvorfe30-io/lab02.git  
 * [new branch]      main -> main
```

</details>

3. Создайте файл `hello_world.cpp` в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу **Hello world** на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку `using namespace std;`.

<details>
<summary>hello_world.cpp</summary>

```cpp
#include iostream
using namespace std; 
int main() {
    cout << "Hello world!" << endl; 
    return 0;
}
```

</details>

4. Добавьте этот файл в локальную копию репозитория.

```bash
git add hello_world.cpp
```

5. Закоммитьте изменения с _осмысленным_ сообщением.

```bash
git commit -m "add hello_world.cpp"
```

6. Измените исходный код так, чтобы программа через стандартный поток ввода запрашивала имя пользователя. А в стандартный поток вывода печаталось сообщение `Hello world from @name`, где `@name` — имя пользователя.

<details>
<summary>hello_world.cpp</summary>

```cpp
#include iostream
#include string
int main() {
    std::string name;
    
    std::cout << "Enter @name: ";
    std::cin >> name;
    
    std::cout << "Hello world from @" << name << std::endl;
    
    return 0;
}
```

</details>

7. Закоммитьте новую версию программы. Почему не надо добавлять файл повторно `git add`?
--a Автоматически добавляет в коммит все изменения в уже отслеживаемых файлах
```bash
git commit -am "added updated hello-world.cpp" 
```

```
[main 85bd1eb] added updated hello-world.cpp
 1 file changed, 10 insertions(+), 3 deletions(-)
```

8. Запушьте изменения в удалённый репозиторий.

```bash
git push lab02 main
```

<details>
<summary>output</summary>

```bash
Username for 'https://github.com': dvorfe30-io
Password for 'https://dvorfe30-io@github.com': 
Перечисление объектов: 7, готово.
Подсчет объектов: 100% (7/7), готово.
При сжатии изменений используется до 16 потоков
Сжатие объектов: 100% (6/6), готово.
Запись объектов: 100% (6/6), 762 байта | 762.00 КиБ/с, готово.
Total 6 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/dvorfe30-io/lab02.git  
   303da30..85bd1eb  main -> main
```

</details>

9. Проверьте, что история коммитов доступна в удалённом репозитории.
https://github.com/dvorfe30-io/lab02/blob/main/P1.9.png

# Part 2

1. В локальной копии репозитория создайте локальную ветку `patch1`.

```bash
git switch --create patch1
```

```
Переключились на новую ветку «patch1»
```

2. Внесите изменения в ветке `patch1` по исправлению кода и избавления от `using namespace std;`. // я ошибочно убрал `using namespace std` на 6 пункте первой части, т.к. не читал вторую часть, пришлось убрать некоторые пустые строки для изменения файла

<details>
<summary>hello_world.cpp</summary>

```cpp
#include iostream
#include string
int main() {
    std::string name;
    std::cout << "Enter @name: ";
    std::cin >> name;
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
```

</details>

<details>
<summary>git status</summary>

```bash
Текущая ветка: patch1
Изменения, которые не в индексе для коммита:
  (используйте «git add файл...», чтобы добавить файл в индекс)
  (используйте «git restore файл..», чтобы отменить изменения в рабочем каталоге)
	изменено:      hello_world.cpp
```

</details>

3. **commit**, **push** локальной ветки в удалённый репозиторий.

```bash
git commit -am "Это patch1 hello_world.cpp"
```

```
[patch1 9070ab0] Это patch1 hello_world.cpp
 1 file changed, 3 deletions(-)
```

```bash
git push -u lab02 patch1
```

<details>
<summary>output</summary>

```bash
Username for 'https://github.com': dvorfe30-io
Password for 'https://dvorfe30-io@github.com': 
Перечисление объектов: 5, готово.
Подсчет объектов: 100% (5/5), готово.
При сжатии изменений используется до 16 потоков
Сжатие объектов: 100% (3/3), готово.
Запись объектов: 100% (3/3), 349 байтов | 349.00 КиБ/с, готово.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
remote: 
remote: Create a pull request for 'patch1' on GitHub by visiting:
remote:      https://github.com/dvorfe30-io/lab02/pull/new/patch1  
remote: 
To https://github.com/dvorfe30-io/lab02.git  
 * [new branch]      patch1 -> patch1
branch 'patch1' set up to track 'lab02/patch1'.
```

</details>

4. Проверьте, что ветка `patch1` доступна в удалённом репозитории.

```bash
git branch
```

```
  main
* patch1
```

5. Создайте pull-request `patch1 -> main`.

6. В локальной копии в ветке `patch1` добавьте в исходный код комментарии.

<details>
<summary>hello_world.cpp</summary>

```cpp
#include iostream // для std::cout
#include string   // для std::string

int main() {
    std::string name;
    std::cout << "Enter @name: ";
    std::cin >> name;
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
```

</details>

7. **commit**, **push**.

```bash
git commit -am "Добавлены комментарии к hello_world.cpp"
```

<details>
<summary>output</summary>

```bash
[patch1 6fee835] Добавлены комментарии к hello_world.cpp
 1 file changed, 2 insertions(+), 2 deletions(-)
```

```bash
git push -u lab02 patch1
```

```bash
Username for 'https://github.com': dvorfe30-io
Password for 'https://dvorfe30-io@github.com': 
Перечисление объектов: 5, готово.
Подсчет объектов: 100% (5/5), готово.
При сжатии изменений используется до 16 потоков
Сжатие объектов: 100% (3/3), готово.
Запись объектов: 100% (3/3), 477 байтов | 477.00 КиБ/с, готово.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/dvorfe30-io/lab02.git  
   9070ab0..6fee835  patch1 -> patch1
branch 'patch1' set up to track 'lab02/patch1'.
```

</details>

8. Проверьте, что новые изменения есть в созданном на **шаге 5** pull-request.https://github.com/dvorfe30-io/lab02/blob/main/P2.8.png

9. В удалённом репозитории выполните слияние PR `patch1 -> main` и удалите ветку `patch1` в удалённом репозитории.

10. Локально выполните **pull**.

<details>
<summary>output</summary>

```bash
git switch main
```

```
Переключились на ветку «main»
Эта ветка соответствует «lab02/main».
```

```bash
git pull lab02 main
```

```
remote: Enumerating objects: 1, done.
remote: Counting objects: 100% (1/1), done.
remote: Total 1 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Распаковка объектов: 100% (1/1), 907 байтов | 907.00 КиБ/с, готово.
Из https://github.com/dvorfe30-io/lab02  
 * branch            main       -> FETCH_HEAD
   85bd1eb..27b77bd  main       -> lab02/main
Обновление 85bd1eb..27b77bd
Fast-forward
 hello_world.cpp | 7 ++-----
 1 file changed, 2 insertions(+), 5 deletions(-)
```

</details>

11. С помощью команды **git log** просмотрите историю в локальной версии ветки `main`.

<details>
<summary>output</summary>

```bash
commit 27b77bde8bd17b0f0add29cc31b1116f88a30f8a (HEAD -> main, lab02/main)
Merge: 85bd1eb 6fee835
Author: dvorfe30-io dvorfe30@gmail.com
Date:   Fri Mar 6 21:27:35 2026 +0300

    Merge pull request #1 from dvorfe30-io/patch1
    
    Это patch1 hello_world.cpp

commit 6fee83543dc060d17345e2249c84b4a335dda7f8 (lab02/patch1, patch1)
Author: dvorfe30-io dvorfe30@gmail.com
Date:   Fri Mar 6 21:19:58 2026 +0300

    Добавлены комментарии к hello_world.cpp

commit 9070ab06a6a08dcb08fc6336e156090da16bf146
Author: dvorfe30-io dvorfe30@gmail.com
Date:   Fri Mar 6 20:38:09 2026 +0300

    Это patch1 hello_world.cpp

commit 85bd1ebb122764b079339d2d0e8f25a58293f7fd
Author: dvorfe30-io dvorfe30@gmail.com
```

</details>

12. Удалите локальную ветку:

```bash
git branch --delete patch1
```

```
Ветка patch1 удалена (была 6fee835).
```

---

# Part 3

1. В локальной копии репозитория создайте локальную ветку `patch2`.

```bash
git switch --create patch2
```

```
Переключились на новую ветку «patch2»
```

2. Измените _code style_ с помощью утилиты [**clang-format**](http://clang.llvm.org/docs/ClangFormat.html). Например, используя опцию `-style=Mozilla`.

```bash
sudo apt install clang-format
```

<details>
<summary>output</summary>

```bash
Следующий пакет устанавливался автоматически и больше не требуется:
  linux-image-6.12.43+deb13-amd64
Для его удаления используйте «sudo apt autoremove».

Установка:
  clang-format

Установка зависимостей:
  clang-format-19  libclang-cpp19

Сводка:
  Обновление: 0, Установка: 3, Удаление: 0, Пропуск обновления: 0
  Объём загрузки: 13,3 MB
  Требуемое пространство: 71,4 MB / 188 GB доступно

Продолжить? [Д/н] Д
Пол:1 http://deb.debian.org/debian trixie/main amd64 libclang-cpp19 amd64 1:19.1.7-3+b1 [13,2 MB]
Пол:2 http://deb.debian.org/debian trixie/main amd64 clang-format-19 amd64 1:19.1.7-3+b1 [93,0 kB]
Пол:3 http://deb.debian.org/debian trixie/main amd64 clang-format amd64 1:19.0-63 [6 352 B]
Получено 13,3 MB за 16с (835 kB/s)                                             
Выбор ранее не выбранного пакета libclang-cpp19.
(Чтение базы данных … на данный момент установлен 276101 файл и каталог.)
Подготовка к распаковке …/libclang-cpp19_1%3a19.1.7-3+b1_amd64.deb …
Распаковывается libclang-cpp19 (1:19.1.7-3+b1) …
Выбор ранее не выбранного пакета clang-format-19.
Подготовка к распаковке …/clang-format-19_1%3a19.1.7-3+b1_amd64.deb …
Распаковывается clang-format-19 (1:19.1.7-3+b1) …
Выбор ранее не выбранного пакета clang-format:amd64.
Подготовка к распаковке …/clang-format_1%3a19.0-63_amd64.deb …
Распаковывается clang-format:amd64 (1:19.0-63) …
Настраивается пакет libclang-cpp19 (1:19.1.7-3+b1) …
Настраивается пакет clang-format-19 (1:19.1.7-3+b1) …
Настраивается пакет clang-format:amd64 (1:19.0-63) …
Обрабатываются триггеры для man-db (2.13.1-1) …
Обрабатываются триггеры для libc-bin (2.41-12+deb13u1) …
```

</details>

```bash
clang-format -style=Mozilla -i hello_world.cpp
```

3. **commit**, **push**, создайте pull-request `patch2 -> main`.

```bash
git commit -am "Меняем стиль с помощью clang-format"
```

```
[patch2 377f45a] Меняем стиль с помощью clang-format
 1 file changed, 10 insertions(+), 8 deletions(-)
```

```bash
git push -u lab02 patch2
```

<details>
<summary>output</summary>

```bash
Username for 'https://github.com': dvorfe30-io
Password for 'https://dvorfe30-io@github.com': 
Перечисление объектов: 5, готово.
Подсчет объектов: 100% (5/5), готово.
При сжатии изменений используется до 16 потоков
Сжатие объектов: 100% (3/3), готово.
Запись объектов: 100% (3/3), 478 байтов | 478.00 КиБ/с, готово.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
remote: 
remote: Create a pull request for 'patch2' on GitHub by visiting:
remote:      https://github.com/dvorfe30-io/lab02/pull/new/patch2  
remote: 
To https://github.com/dvorfe30-io/lab02.git  
 * [new branch]      patch2 -> patch2
branch 'patch2' set up to track 'lab02/patch2'.
```

</details>

4. В ветке **main** в удалённом репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.

<details>
<summary>hello_world.cpp изменённый</summary>

```cpp
#include <iostream // для std::cout, std::cin
#include <string>  // для std::string пупупу

int main() {
    std::string name;
    std::cout << "Enter @name: ";
    std::cin >> name;
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
```

</details>

5. Убедитесь, что в pull-request появились _конфликты_.

6. Для этого локально выполните **pull** + **rebase** (точную последовательность команд следует узнать самостоятельно). **Исправьте конфликты**.

```bash
git rebase lab02/main
```

<details>
<summary>output</summary>

```bash
Автослияние hello_world.cpp
КОНФЛИКТ (содержимое): Конфликт слияния в hello_world.cpp
error: не удалось применить коммит 377f45a... Меняем стиль с помощью clang-format
hint: Resolve all conflicts manually, mark them as resolved with
hint: "git add/rm conflicted_files", then run "git rebase --continue".
hint: You can instead skip this commit: run "git rebase --skip".
hint: To abort and get back to the state before "git rebase", run "git rebase --abort".
hint: Disable this message with "git config advice.mergeConflict false"
Не удалось применить коммит 377f45a... Меняем стиль с помощью clang-format
```

</details>

```bash
edit hello_world.cpp
git add hello_world.cpp
git rebase --continue
```

```
[отделённый HEAD daffab1] Меняем стиль с помощью clang-format
 1 file changed, 16 insertions(+), 9 deletions(-)
Успешно перемещён и обновлён refs/heads/patch2.
```

7. Сделайте _force push_ в ветку `patch2`:

```bash
git push --force lab02 patch2
```

<details>
<summary>output</summary>

```bash
Username for 'https://github.com': dvorfe30-io
Password for 'https://dvorfe30-io@github.com':
Перечисление объектов: 5, готово.
Подсчет объектов: 100% (5/5), готово.
При сжатии изменений используется до 16 потоков
Сжатие объектов: 100% (3/3), готово.
Запись объектов: 100% (3/3), 483 байта | 483.00 КиБ/с, готово.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/dvorfe30-io/lab02.git  
 + 377f45a...daffab1 patch2 -> patch2 (forced update)
```

</details>

8. Убедитесь, что в pull-request пропали конфликты.

9. Вмержите pull-request `patch2 -> main`.github.com/dvorfe30-io/lab02/blob/main/P3l.png
