#include <iostream> 
#include <string>
#include <windows.h> // Для Windows
#include <cstdlib>
#include <ctime>
#include <conio.h> 

// или #include <clocale> // Для macOS и Linux 
//вы дологовые закрываете? Нет только показываем! Красивое но грусное это моя строчка, иди на другую ... 


class Character {
private:
    std::string nickname;
    int health;
    int damage;
    int level;

public:
    // Конструктор
    Character(std::string nick, int hp, int dmg, int lvl) : nickname(nick), health(hp), damage(dmg), level(lvl) {}

    // Геттеры
    std::string getNickname() { return nickname; }
    int getHealth() { return health; }
    int getDamage() { return damage; }
    int getLevel() { return level; }

    // Сеттеры
    void setNickname(std::string nick) { nickname = nick; }
    void setHealth(int hp) { health = hp; }
    void setDamage(int dmg) { damage = dmg; }
    void setLevel(int lvl) { level = lvl; }

    // Метод для атаки другого персонажа
    void attack(Character& target) {
        target.health -= damage;
        std::cout << nickname << " атакует " << target.nickname << " и наносит " << damage << " единиц урона!" << std::endl;
    }

    // Метод для проверки, жив ли персонаж
    bool isAlive() {
        return health > 0;
    }
};

// Функция для генерации случайного числа в диапазоне [min, max]
int randomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}


int main() {
    system("chcp 1251");


    // Инициализация генератора случайных чисел
    srand(time(0));

    std::string heroNickname;
    int heroHealth, heroDamage;

    std::cout << "Введите никнейм героя: ";
    std::cin >> heroNickname;
    std::cout << "Введите количество жизней героя: ";
    std::cin >> heroHealth;
    std::cout << "Введите урон героя: ";
    std::cin >> heroDamage;
    std::cout << std::endl;
    Character hero(heroNickname, heroHealth, heroDamage, 1);

    // Создание врага с случайными характеристиками
    int enemyHealth = randomNumber(50, 100);
    int enemyDamage = randomNumber(5, 15);
    Character enemy("Враг", enemyHealth, enemyDamage, 1);


    while (hero.isAlive() && enemy.isAlive()) {
        std::cout << "У " << hero.getNickname() << " " << hero.getHealth() << " HP" << std::endl;
        std::cout << "У " << enemy.getNickname() << " " << enemy.getHealth() << " HP" << std::endl;
        std::cout << std::endl;
        hero.attack(enemy);
        if (!enemy.isAlive()) {
            std::cout << enemy.getNickname() << " был повержен!" << std::endl;
            break;
        }

        enemy.attack(hero);
        if (!hero.isAlive()) {
            std::cout << hero.getNickname() << " был повержен!" << std::endl;
            break;
        }
    }
    if (hero.getHealth() > 0)
    {

        std::cout << std::endl << "Вы встречаете Морячка, готовы принять смерть?" << std::endl;
        system("pause");
        std::cout << std::endl;


        enemyHealth = heroDamage + 1;
        enemyDamage = heroHealth + 1;
        Character goblin("Морячок", enemyHealth, enemyDamage, 1);

        while (hero.isAlive() && goblin.isAlive()) {
            std::cout << "У " << hero.getNickname() << " " << hero.getHealth() << " HP" << std::endl;
            std::cout << "У " << goblin.getNickname() << " " << goblin.getHealth() << " HP" << std::endl;
            std::cout << std::endl;
            hero.attack(goblin);
            if (!goblin.isAlive()) {
                std::cout << goblin.getNickname() << " был повержен!" << std::endl;
                break;
            }

            goblin.attack(hero);
            if (!hero.isAlive()) {
                std::cout << hero.getNickname() << " был повержен!" << std::endl;
                break;
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
