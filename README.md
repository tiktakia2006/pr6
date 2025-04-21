# ПРАКТИЧНА РОБОТА 6

## ЗАВДАННЯ 1 (варіант 13)

## Умова
Напишіть сценарій, що виконує всі test cases під Valgrind та створює звіт по кожному з них.

## Код до завдання
### 13.c
```
#include <stdio.h>
#include <stdlib.h>

void run_valgrind_test(const char *test_case) {
    char command[512];
    snprintf(command, sizeof(command), "valgrind --leak-check=full --log-file=%s.valgrind.log ./%s", test_case, test_case);
    printf("Запуск тесту: %s\n", test_case);
    system(command);
}

int main() {
    const char *test_cases[] = {
        "test_case1",
        "test_case2",
        "test_case3",
        NULL
    };

    for (int i = 0; test_cases[i] != NULL; i++) {
        run_valgrind_test(test_cases[i]);
    }

    printf("Всі тести завершено.\n");

    return 0;
}

```

### test_case1.c
```
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int*)malloc(1000 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < 1000; i++) {
        arr[i] = i;
    }
    return 0;
}

```

### test_case2.c
```
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int*)malloc(2000 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < 2000; i++) {
        arr[i] = i;
    }
    free(arr);
    return 0;
}

```

### test_case3.c
```
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int*)malloc(0);
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Memory allocated successfully\n");
    free(arr);
    return 0;
}

```


## Опис програми
Цей сценарій на мові C автоматично запускає всі тестові кейси під Valgrind для перевірки витоків пам’яті. У функції run_valgrind_test формуються системні команди, які запускають кожен з тестів з опцією --leak-check=full, а результати записуються у відповідні .valgrind.log файли. Масив test_cases містить імена виконуваних файлів тестів. Основна програма по черзі проходить кожен тест, викликаючи функцію запуску, і після завершення усіх тестів виводить повідомлення про завершення. Такий підхід дозволяє централізовано виконувати тестування і зберігати окремі звіти по кожному кейсу. Це зручно для подальшого аналізу помилок і контролю якості коду.


У першому  тесті виділяється пам’ять під масив на 1000 елементів, але після виконання програми вона не звільняється. Це демонструє типову помилку - витік пам’яті. Valgrind зафіксує цю помилку та збереже звіт. Такий тест допомагає перевірити, чи система здатна виявити недбале поводження з пам’яттю.

У другому тесті також виділяється динамічна пам’ять, але після використання вона коректно звільняється через free(). Valgrind не покаже помилок, що демонструє приклад правильної роботи з пам’яттю. Цей тест потрібен для впевненості, що Valgrind нічого не знаходить там, де все зроблено вірно.

У третьому тесті, програма виконує malloc(0), тобто запитує 0 байтів пам’яті. Це крайній випадок, який іноді може призводити до неочікуваних ситуацій. Valgrind перевіряє, чи система правильно обробляє таку операцію без помилок. Тест показує уважність до нетипових сценаріїв.


Програма була успішно скомпільована та запущена. Всі три тест-кейси були виконані під Valgrind. Вивід підтверджує, що тести пройшли, і пам’ять у третьому кейсі була виділена успішно.

У test_case1 виявлено витік пам’яті - 4000 байт було виділено, але не звільнено (бо я не використав free як і хотів для прикладу). test_case2 не має витоків - вся виділена пам’ять була успішно звільнена. test_case3 також не має витоків - пам’ять повністю очищено після використання. Основна програма залишає пам’ять доступною, але не втрачає її, тому це не вважається помилкою. Valgrind успішно відпрацював для кожного тесту та надав детальні звіти.

Сценарій успішно запускає всі тестові файли (test_case1, test_case2, test_case3) під Valgrind і зберігає окремий лог-файл для кожного. Результати підтверджують, що перевірка на витоки пам’яті виконана коректно згідно з умовою.

## Результати програми
![image](https://github.com/user-attachments/assets/c863bbcc-750f-4f5f-9b91-e6bfb3e9f257)
![image](https://github.com/user-attachments/assets/c853cc4b-b2d2-4f8c-8537-b0edc77b1e32)
![image](https://github.com/user-attachments/assets/22fb5331-916e-4d8c-a2c8-cac33f26f4b8)
![image](https://github.com/user-attachments/assets/611d837f-b18e-44cd-ab7a-19ce594d3d33)
![image](https://github.com/user-attachments/assets/61b71940-1522-40b5-bac1-f357825fd1ad)




