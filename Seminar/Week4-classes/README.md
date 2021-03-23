# Задачи

Превърнете структурите от миналата седмица в класове.

```
class Person
{
    char *firstName;
    char *lastName;
    int age;
    bool isVIP;
};
```

```
class DebitCard
{
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
class BankAccount
{
    int money;
    char BIC[BIC_SIZE];
    char IBAN[IBAN_SIZE];
    Person* owner;
    DebitCard* debitCards;
};
```

За всеки клас напишете подходящи

<ul>
<li> конструктор по подразбиране
<li> конструктор с параметри
<li> копи конструктор
<li> оператор =
<li> деструктор
<li> getters and setters
<li> Функции за сериализация и десериализация в двоиче файл по подаден параметър името на файла.
</ul>

За `BankAccount` искаме и метод, който сортира всичките му дебитни карти, като за целта ще ти трябва предефиниран `operator==` за класа `DebitCard` (имплементацията оставявм вие да прецените - кога две дебитни карти имат равна стойност?).
