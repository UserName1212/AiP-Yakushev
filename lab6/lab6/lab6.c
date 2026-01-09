#include "functions.h"
#include "book.h"

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "Rus"); //русский язык 
    printf("***************** Lab 6 *******************\n");

    Book* catalog = malloc(INITIAL_CAPACITY * sizeof(Book));
    if (catalog == NULL)
    {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    int count = 0;
    int capacity = INITIAL_CAPACITY;
    int choice;

    // Загрузка картотеки из файла при запуске
    if (!loadCatalogFromFile(&catalog, &count, &capacity, "catalog.txt"))
        printf("Info: Catalog loaded automatically.\n");

    do
    {
        printf("\n***************** MENU *******************\n");
        printf("1. Распечатать содержимое картотеки\n");
        printf("2. Ввести новую книгу\n");
        printf("3. Удалить книгу\n");
        printf("4. Записать картотеку в файл\n");
        printf("5. Считать картотеку из файла\n");
        printf("6. Сортировать картотеку\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf_s("%d", &choice);
        printf("******************************************\n");

        switch (choice)
        {
        case 1:
            printCatalog(catalog, count);
            break;

        case 2:
        {
            Book newBook;
            printf("Введите автора: ");
            scanf_s(" %[^\n]", newBook.author);

            printf("Введите название: ");
            scanf_s(" %[^\n]", newBook.title);

            printf("Введите год: ");
            scanf_s("%d", &newBook.year);

            printf("Введите цену: ");
            scanf_s("%lf", &newBook.price);

            printf("Введите категорию: ");
            scanf_s(" %[^\n]", newBook.category);

            // Очистка буфера ввода
            while (getchar() != '\n');

            if (!addBook(&catalog, &count, &capacity, &newBook))
                printf("Книга добавлена.\n");
            else
                printf("Не удалось добавить книгу.\n");

            break;
        }

        case 3:
        {
            if (count == 0)
            {
                printf("Невозможно провести операцию удаления: картотека пуста.\n");
                break;
            }
            int index;
            printf("Введите индекс книги для удаления (0-%d): ", count - 1);
            scanf_s("%d", &index);

            if (!removeBook(catalog, &count, index))
                printf("Книга удалена.\n");
            else
                printf("Ошибка: несуществующий индекс.\n");

            break;
        }

        case 4:
            if (count == 0)
            {
                printf("Невозможно провести операцию сохранения: картотека пуста.\n");
                break;
            }
            if (!saveCatalogToFile(catalog, count, "catalog.txt"))
                printf("Картотека сохранена в файл.\n");
            else
                printf("Не удалось сохранить картотеку.\n");

            break;

        case 5:
            if (!loadCatalogFromFile(&catalog, &count, &capacity, "catalog.txt"))
                printf("Картотека загружена из файла.\n");
            else
                printf("Не удалось загрузить картотеку. Возможно, файл не найден или пуст.\n");

            break;

        case 6:
        {
            if (count == 0)
            {
                printf("Невозможно провести операцию сортировки: картотека пуста.\n");
                break;
            }
            int sortChoice;
            printf("Выберите поле для сортировки:\n");
            printf("1. Автор\n2. Название\n3. Год\n4. Цена\n5. Категория\n");
            scanf_s("%d", &sortChoice);

            SortingType type;
            switch (sortChoice)
            {
            case 1: type = SORT_BY_AUTHOR; break;
            case 2: type = SORT_BY_TITLE; break;
            case 3: type = SORT_BY_YEAR; break;
            case 4: type = SORT_BY_PRICE; break;
            case 5: type = SORT_BY_CATEGORY; break;
            default: printf("Ошибка: несуществующий тип сортировки.\n"); continue;
            }

            sortCatalog(catalog, count, type);
            printf("Картотека отсортирована.\n");
            break;
        }

        case 0:
            printf("Выход.\n");
            break;

        default:
            printf("Ошибка: несуществующий вариант выбора.\n");
        }
    } while (choice != 0);

    freeCatalog(catalog);
    return 0;
}