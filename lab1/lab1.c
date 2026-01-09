#include <limits.h> // подключим библиотеку, в которой определён макрос UCHAR_MAX
#include <stddef.h> // а здесь определён тип size_t

int a = 512; // Глобальная переменная

int main()
{
    // 1. Типы переменных. Измените код так чтобы в результате вышло 1764
    unsigned int theUltimateAnswer = 42;
    theUltimateAnswer *= theUltimateAnswer;
    size_t maxValue = UCHAR_MAX; // будьте готовы объяснить эту строчку
    maxValue = maxValue;
    // 2. Циклы. Перепишите логику цикла while через цикл for.
    // Пояснение. Оператор && проверяет, истинны ли (т.е. отличны ли от нуля) оба выражения
    // если оба верны, возвращает истину, иначе ложь (ноль)

    
    /*int i = 0, j = 1, a = 0;
    while (i < 10)
    {
        while (j < 10) {
            a -= i * j;
            i += j;
            j += i;
        }
    }
    */
   /* int i = 0, j = 1, a = 0;
    while (i < 10 && j < 10)
    {

        a -= i * j;
        i += j;
        j += i;
    }
    */
    {
        int a = 0;
        for (int i = 0, j = 1; i < 10 && j < 10; i += j, j += i) {
            a -= i * j;
        }
    }
    //a = -17 
    
    // 3. Области видимости. Переписать код так, чтобы значение j, заданное
    // внутри области видимости, не потерялось и было прибавлено к `a`
    ++a; // то же, что a++
    a = 0;
    int j = 0; 
    {    // локальная область видимости
        int a = 3;
        int i = 2 + a;
        j = 1 + i;
    } 
    a += j;

    // 4. Спецификатор класса памяти static
    // Какое значение будут иметь переменные на каждой итерации цикла? Напишите в комментариях

    for (int i=0; i<3; i++)
	{
		static int nStatic = 100;
		int nLocal = 100;
		nStatic++;
		nLocal++;
        // i = 0: nStatic = 101, nLocal = 101
        // i = 1: nStatic = 102, nLocal = 101
        // i = 2: nStatic = 103, nLocal = 101
        // i = 3: nStatic = 104, nLocal = 101
	}

    // 5. Перечисления (enum)
    // исправьте код так, чтобы после исполнения строки color = -1
    // в переменной color действительно было значение -1

    enum eColor // объявление типа
    {
        GREEN = -1, 
        BLACK,
        BLUE,
        RED = 5,
        YELLOW,
        WHITE = RED + 4
    };

    enum eColor color; // объявление переменной типа enum eColor
    color = BLACK;
    color = BLUE;
    color = RED;
    color = WHITE;
    color = (enum eColor) 1; // работает
    color = (enum eColor) - 1; // не получается
    color = color;

    // 6. Оператор switch
    // Напишите фрагмент кода, который реализует с помощью switch
	// следующую логику: в переменной ch дано значение символа
	// - Если символ 'y' (т.е. yes) в любом регистре, то присвоить
	// переменной `у` значение переменной `x`
	// - Если символ 'n' (т.е. no) в любом регистре, то присвоить
	// переменной `у` значение (x * 2)
	// - Если любой другой симол, то завершить работу программы с ошибкой (вернуть -1)

    char ch = 'n', x = 5, y = 1;
    switch (ch) {
        case 'y':
            y = x;
            break; 
        case 'Y':
            y = x; 
            break;
        case 'n':
            y = x * 2; 
            break; 
        case 'N':
            y = x * 2;
            break; 
        case 5: 
            x = y;
           break;
     default: 
            return -1; 
    }

    return 0;
}
int fu(char ch, char x) {
    switch (ch) {
    case 'y':
        return x; 
    default:
        return -1; 
    }
    }