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
