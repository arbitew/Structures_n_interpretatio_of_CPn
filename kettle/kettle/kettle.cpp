// kettle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>


class Water {
public:
    int isboiled;
    Water() {
        this->isboiled = 0;
    }
};
class Kettle {
private:
    Water* this_water;
public:
    int isfull() {
        if (this_water != NULL) {
            return 1;
        }
    }
    Kettle() :
        this_water(NULL)
    {}
    void boil() {
        if (this_water != NULL) {
            this_water->isboiled = 1;
            std::cout << "it's boiled" << std::endl;
        }
        else {
            std::cout << "no water" << std::endl;
        }
    }
    void removeWater() {
        this_water = NULL;
        std::cout << "it's removed" << std::endl;
    }
    void fullIt(Water* water) {
        this->this_water = water;
    }
};
class Match {
private:
    int matches;
    
public:
    Match(int matches):
        matches(matches)
    {}
    int use_one() {
        if (matches != 0) {
            matches--;
            return 1;
        }
        return 0;
    }
};
class Sink {
private:
    std::vector <Water*> all_water;
    Kettle* this_kettle;
    
public:
    Sink(std::vector <Water*> all_water) :
        all_water(all_water),
        this_kettle(NULL)
    {}
    void putKettle(Kettle* kettle) {
        this->this_kettle = kettle;
    }
    void removeKettle() {
        this->this_kettle = NULL;
    }
    void fullKettle() {
        if (!all_water.empty() && !this_kettle->isfull()) {
            this->this_kettle->fullIt(all_water[all_water.size()-1]);
            std::cout << "it's filled" << std::endl;
        }
        else {
            std::cout << "no water" << std::endl;
        }
    }
};
class Cooker {
private:
    Match* this_matches;
    Kettle* this_kettle;
public:
    Cooker(Match* this_matches) :
        this_matches(this_matches),
        this_kettle(NULL)
    {}
    void putKettle(Kettle* kettle) {
        this->this_kettle = kettle;
    }
    void removeKettle() {
        this->this_kettle = NULL;
    }
    void boilKettle(){
        if (this_kettle != NULL) {
            this_kettle->boil();
        }
    }

    
};

int main()
{
    Match my_match(10);
    Kettle my_kettle;
    std::vector <Water*> the_water;   
    Water my_water;
    the_water.push_back(&my_water);
    Sink my_sink(the_water);
    my_sink.putKettle(&my_kettle);
    my_sink.fullKettle();
    my_sink.removeKettle();
    Cooker my_cooker(&my_match);
    my_cooker.putKettle(&my_kettle);
    my_cooker.boilKettle();
    my_cooker.removeKettle();
    my_kettle.removeWater();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
