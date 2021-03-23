# Условия

## Задача 1

Да се създада структура

```
struct Matrix {
    int rows, cols;
    int** matrix;
};
```

Както и помощни методи за нейното инициализиране, четене от текстови файл, записване в текстови файл и освобождаване на паметта.

Hint: Mожете да подавате поток като аргумент на функция.

```
void initializeMatrix(Matrix& m, int row, int cols);
void serializeMatrix(Matrix& m, std::ostream& os);
void deserializeMatrix(Matrix& m, std::istream& is);
void deleteMatrix(Matrix& m);
```

## Задача 2

Имате даден файл с текст и списък от думи. Вашата задача е да намерите всяко срещане на дума от списъка във файла (ред и колона).

За целта ще използваме следната структура.

```
struct Occurance {
    int row, col;
    char* word;
};
```

Нека се реализира динамичен контейнер на срещания на думи от списъка (по подобие на vector от Седмица 2), който пази крайната информация.
Запишете срещанията в текстови файл (сериализацията е по ваша преценка).

Примерен вход: inputFile.txt и думите "culpa", "adipisicing", "tempor"

Примерно съдържание на файла:

> Voluptate cupidatat ea exercitation culpa veniam tempor nostrud officia aliquip Lorem nulla.<br>Aute aliquip voluptate irure anim nostrud duis dolore consectetur nulla est ea cupidatat excepteur. Commodo nisi deserunt aute adipisicing cillum ullamco ut tempor.<br>
> Reprehenderit velit nisi non nisi nostrud exercitation duis cillum. <br>Esse dolore dolore commodo non velit qui tempor incididunt do laborum duis.<br> Voluptate consequat eu do adipisicing enim laboris.<br> Velit consectetur mollit deserunt deserunt.
> Mollit nulla aliqua dolor cupidatat irure ea.<br> Elit consectetur aute in enim velit sunt cillum. <br>Duis cillum aliqua id minim adipisicing ullamco nostrud nulla quis in ex anim.<br> Et labore nisi duis mollit incididunt cillum aliqua minim dolore.<br> Enim aliqua et minim consectetur officia.<br> Minim nulla labore aliqua nisi minim veniam irure nulla. <br>Est nulla tempor cillum nisi.<br>
> Et sunt ullamco pariatur veniam nostrud velit velit sit fugiat eiusmod.<br> Quis incididunt sint nostrud aliquip nisi ut reprehenderit labore.<br> Aliqua esse consectetur consectetur non in minim incididunt ad cillum. <br>Qui fugiat cupidatat deserunt exercitation ut. Amet <br>veniam eu in cillum esse deserunt. Nostrud laborum aliqua sint occaecat.

Примерен изход:

> 1-42-culpa <br>
> 1-56-tempor <br>
> 2-139-adipisicing <br>
> 2-164-tempor <br>
> и тн.

## Задача 3

### задача 3.1

Да се довършат структурите от примерите:

```
struct Person
{
    char *firstName;
    char *lastName;
    int age;
    bool isVIP;
};
```

```
struct DebitCard
{
    // master card, etc.
    char* type;
    char* expiryDate;
    char* CVV;
    char* number;
    char* ownerName;
    int yearlyFee;
    int cardLimit;
};
```

```
struct BankAccount
{
    int money;
    char BIC[BIC_SIZE];
    char IBAN[IBAN_SIZE];
    // тук искаме указател към собственика
    Person* owner;
    // тук искаме динамичен масив от кредитните карти, свързани с този акаунт
    DebitCard* debitCards;
};
```

###

Задача 3.2

Крайната ни цел е да имаме метод, който записва банковите акаунти в базата данни. Базата данни ще е двоичен файл с разширение \*.vdb.

`bool serializeBankAccount(const char*, const BankAccount&);`

Този метод трябва да добавя банков акаунт в края на файла, който ще ни случи като база данни, а не да изтрива или презаписва други банкви акаунти (на никого няма да му е готино да му изтрият акаунта).

###

Задача 3.3

След това искаме да имплементираме няколко функции за работа с тези банкови акаунти от файла. Операциите връщат true при успех и false при грешка.

// Чете всички банкови акаунти от файл с подаденото име и принтира информацията свързана с тях.

`bool getAll(const char*);`

// Принтира информацията свързана с банковите акаунти на хора с дадената фамилия.

`bool getByOwnerSurname(const char*, const char*);`

// Принтира информацията свързана с банковите акаунти всички ВИП хора.

`bool getAllVIP(const char*);`

// Презаписва n-тия банков акаунт във файла.

`bool updateNth(const char*, int, const BankAccount&);`

// Изтрива n-тия банков акаунт във файла.

`bool deleteNth(const char*, int);`

// Сортира и презаписва дебитните карти в банковите акаунти като ги сравнява по тип на базата на подадения comparator.

`bool sortByType(const char*, int (*comparator)(const char *, const char *));`
